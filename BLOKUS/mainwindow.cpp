#include <QMessageBox>
#include <queue>
#include <cstdio>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
using std::queue;
queue<int> turn;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gameTable(ui)
{
    ui->setupUi(this);
    ui->gameTableWidget->setMouseTracking(true);

    turn.push(0);
    turn.push(1);
    turn.push(2);
    turn.push(3);

    // setTableWidget;
    for(int i =0; i < 3; i++)
        for(int j = 0; j < 7; j++)
            for(int k = 0;k < 4; k++)
                a_PixmapLabel[k][i][j] = new QLabel();
    setTableWidget();
    selected_PixmapLabel = new QLabel();
    //

    // setGameTableWidget;
    gameTable.print();
    //

    // setUserColor;
    user[0].setColor(BLUE);
    user[1].setColor(RED);
    user[2].setColor(GREEN);
    user[3].setColor(YELLOW);
    //
}

MainWindow::~MainWindow() {
    for(int i =0; i < 3; i++)
        for(int j = 0; j < 7; j++)
            for(int k = 0;k < 4; k++)
                delete a_PixmapLabel[k][i][j];

    delete selected_PixmapLabel;

    delete ui;
}

void MainWindow::deleteTableWidgetPix(const int index, int type) {
    char buff[100];
    char tmp[100];
    int row = (type - 1) / 7;
    int column = (type - 1) % 7;
    switch(index){
    case 0:
        sprintf(tmp,"/blue/b%dd.png",type);
        strcpy(buff,PIX_PATH);
        strcat(buff,tmp);
        a_PixmapLabel[index][row][column]->setPixmap((QPixmap(buff)));
        break;
    case 1:
        sprintf(tmp,"/red/r%dd.png",type);
        strcpy(buff,PIX_PATH);
        strcat(buff,tmp);
        a_PixmapLabel[index][row][column]->setPixmap((QPixmap(buff)));
        break;
    case 2:
        sprintf(tmp,"/green/g%dd.png",type);
        strcpy(buff,PIX_PATH);
        strcat(buff,tmp);
        a_PixmapLabel[index][row][column]->setPixmap((QPixmap(buff)));
        break;
    case 3:
        sprintf(tmp,"/yellow/y%dd.png",type);
        strcpy(buff,PIX_PATH);
        strcat(buff,tmp);
        a_PixmapLabel[index][row][column]->setPixmap((QPixmap(buff)));
        break;
    }
}

void MainWindow::setSelectedTableWidgetPix(int index, int type){
    int row = (type - 1) / 7;
    int column = (type - 1) % 7;
    selected_PixmapLabel->setPixmap(*a_PixmapLabel[index][row][column]->pixmap());
    ui->selectedTableWidget->setCellWidget(0,0,selected_PixmapLabel);
}

void MainWindow::setTableWidget(){
    char buff[100];
    char tmp[100];
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <7; j++){
            cnt++;
            sprintf(tmp,"/blue/b%d.png",cnt);
            strcpy(buff,PIX_PATH);
            strcat(buff,tmp);
            a_PixmapLabel[0][i][j]->setPixmap(QPixmap(buff));
            sprintf(tmp,"/red/r%d.png",cnt);
            strcpy(buff,PIX_PATH);
            strcat(buff,tmp);
            a_PixmapLabel[1][i][j]->setPixmap(QPixmap(buff));
            sprintf(tmp,"/green/g%d.png",cnt);
            strcpy(buff,PIX_PATH);
            strcat(buff,tmp);
            a_PixmapLabel[2][i][j]->setPixmap(QPixmap(buff));
            sprintf(tmp,"/yellow/y%d.png",cnt);
            strcpy(buff,PIX_PATH);
            strcat(buff,tmp);
            a_PixmapLabel[3][i][j]->setPixmap(QPixmap(buff));
            ui->tableWidget_1->setCellWidget(i,j,a_PixmapLabel[0][i][j]);
            ui->tableWidget_2->setCellWidget(i,j,a_PixmapLabel[1][i][j]);
            ui->tableWidget_3->setCellWidget(i,j,a_PixmapLabel[2][i][j]);
            ui->tableWidget_4->setCellWidget(i,j,a_PixmapLabel[3][i][j]);
        }
    }
}

void MainWindow::wheelEvent(QWheelEvent *event){
    static int cnt = 0; // Prevnet wheel double click.
    if ( cnt++ == 0)
        return;
    else
        cnt = 0;

    int angle = event->delta();
    if ( angle > 0)
        user[turn.front()].getSelectedBlock().rotate( true ) ;
    else
        user[turn.front()].getSelectedBlock().rotate( false );
    gameTable.addselectedBlock(user[turn.front()].getSelectedBlock(), user[turn.front()].getSelectedBlock().getCurX(), user[turn.front()].getSelectedBlock().getCurY());
}

void MainWindow::turnOver() const {
    int tmp = turn.front();
    turn.pop();

    if( user[tmp].isEnd() == true){
        if( turn.size() == 0)
            endGame();
        return;
    }

    turn.push(tmp);
}

void MainWindow::endGame() const {
    char msg[100] = "winner : ";
    char tmp[20];
    int maxScore = 0;
    for(int i = 0; i < 4; i++)
        if( user[i].getScore() > maxScore )
            maxScore = user[i].getScore();
    for(int i = 0; i < 4; i++)
        if( user[i].getScore() == maxScore ){
                sprintf(tmp,"user %d ",i + 1);
                strcat(msg,tmp);
            }
    sprintf(tmp, "[score : %d]\n", maxScore);
    strcat(msg, tmp);

    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

void MainWindow::on_gameTableWidget_cellEntered(int row, int column){
    if (user[turn.front()].getSelectedBlock().getType() == 0)
        return;
    gameTable.addselectedBlock(user[turn.front()].getSelectedBlock(), row, column);
}

void MainWindow::on_gameTableWidget_cellClicked(int row, int column){
    if (user[turn.front()].getSelectedBlock().getType() == 0)
        return;
    if ( gameTable.addBlock(user[turn.front()].getSelectedBlock()) == true ) {
        deleteTableWidgetPix(turn.front(), user[turn.front()].getSelectedBlock().getType());

        int score;
        int type = user[turn.front()].getSelectedBlock().getType();
        if (type == 1)
            score = 1;
        else if (type == 2)
            score = 2;
        else if (type == 3 || type == 4)
            score = 3;
        else if (type >= 5 && type <= 9)
            score = 4;
        else
            score = 5;

        user[turn.front()].addScore(score);

        char buff[100];
        switch(turn.front()){
        case 0:
            sprintf(buff,"점수 : %d",user[turn.front()].getScore());
            ui->scoreLabel_1->setText(buff);
            break;
        case 1:
            sprintf(buff,"점수 : %d",user[turn.front()].getScore());
            ui->scoreLabel_2->setText(buff);
            break;
        case 2:
            sprintf(buff,"점수 : %d",user[turn.front()].getScore());
            ui->scoreLabel_3->setText(buff);
            break;
        case 3:
            sprintf(buff,"점수 : %d",user[turn.front()].getScore());
            ui->scoreLabel_4->setText(buff);
            break;
        }

        user[turn.front()].getSelectedBlock() = Block(-1,-1);
        turnOver();
    }
}

void MainWindow::on_tableWidget_1_cellClicked(int row, int column){
    if (turn.front() != 0)
        return;

    user[0].selectBlock(Block(0,0,user[0].getColor(),row * 7 + column + 1));
    setSelectedTableWidgetPix(0,row * 7 + column + 1);
}

void MainWindow::on_tableWidget_2_cellClicked(int row, int column){
    if (turn.front() != 1)
        return;

    user[1].selectBlock(Block(0,0,user[1].getColor(),row * 7 + column + 1));
    setSelectedTableWidgetPix(1,row * 7 + column + 1);
}

void MainWindow::on_tableWidget_3_cellClicked(int row, int column){
    if (turn.front() != 2)
        return;

    user[2].selectBlock(Block(0,0,user[2].getColor(),row * 7 + column + 1));
    setSelectedTableWidgetPix(2,row * 7 + column + 1);
}

void MainWindow::on_tableWidget_4_cellClicked(int row, int column){
    if (turn.front() != 3)
        return;

    user[3].selectBlock(Block(0,0,user[3].getColor(),row * 7 + column + 1));
    setSelectedTableWidgetPix(3,row * 7 + column + 1);
}

void MainWindow::on_endButton_1_clicked(){
    QMessageBox msgBox;
    if (turn.front() != 0){
        msgBox.setText("자기 턴에만 기권할 수 있습니다.");
        msgBox.exec();
    }
    else {
        msgBox.setText("정말로 \n기권하시겠습니까?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Save);

        int result = msgBox.exec();
        switch(result){
        case QMessageBox::Yes:
            user[0].setEnd(true);
            ui->endButton_1->setEnabled(false);
            ui->scoreLabel_1->setEnabled(false);
            user[turn.front()].getSelectedBlock() = Block(-1,-1);
            turnOver();
            break;
        default:
            return;
        }
    }
}

void MainWindow::on_endButton_2_clicked(){
    QMessageBox msgBox;
    if (turn.front() != 1){
        msgBox.setText("자기 턴에만 기권할 수 있습니다.");
        msgBox.exec();
    }
    else {
        msgBox.setText("정말로 \n기권하시겠습니까?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Save);

        int result = msgBox.exec();
        switch(result){
        case QMessageBox::Yes:
            user[1].setEnd(true);
            ui->endButton_2->setEnabled(false);
            ui->scoreLabel_2->setEnabled(false);
            user[turn.front()].getSelectedBlock() = Block(-1,-1);
            turnOver();
            break;
        default:
            return;
        }
    }
}

void MainWindow::on_endButton_3_clicked(){
    QMessageBox msgBox;
    if (turn.front() != 2){
        msgBox.setText("자기 턴에만 기권할 수 있습니다.");
        msgBox.exec();
    }
    else {
        msgBox.setText("정말로 \n기권하시겠습니까?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Save);

        int result = msgBox.exec();
        switch(result){
        case QMessageBox::Yes:
            user[2].setEnd(true);
            ui->endButton_3->setEnabled(false);
            ui->scoreLabel_3->setEnabled(false);
            user[turn.front()].getSelectedBlock() = Block(-1,-1);
            turnOver();
            break;
        default:
            return;
        }
    }
}

void MainWindow::on_endButton_4_clicked(){
    QMessageBox msgBox;
    if (turn.front() != 3){
        msgBox.setText("자기 턴에만 기권할 수 있습니다.");
        msgBox.exec();
    }
    else {
        msgBox.setText("정말로 \n기권하시겠습니까?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Save);

        int result = msgBox.exec();
        switch(result){
        case QMessageBox::Yes:
            user[3].setEnd(true);
            ui->endButton_4->setEnabled(false);
            ui->scoreLabel_4->setEnabled(false);
            user[turn.front()].getSelectedBlock() = Block(-1,-1);
            turnOver();
            break;
        default:
            return;
        }
    }
}

