#include <QLabel>
#include <cstring>
#include <queue>
#include "ui_mainwindow.h"
#include "table.h"
#include "constants.h"
using std::queue;
extern queue<int> turn;

Table::Table(Ui::MainWindow* const ui)
    :ui(ui){
    for(int i = 0; i < MAX_Y; i++)
        for(int j = 0; j < MAX_X; j++)
             a_PixmapLabel[i][j] = new QLabel();
    set();
}
Table::~Table(){ }

void Table::set(){
    for(int i = 0; i < MAX_Y; i++)
        for(int j = 0; j < MAX_X; j++)
            table[i][j] = GRAY;
}


void Table::print() const {
    for (int i = 0; i < MAX_Y; i++)
        for (int j = 0; j < MAX_X; j++){
           printCell(i,j);
           ui->gameTableWidget->setCellWidget(i,j,a_PixmapLabel[i][j]);
        }
}

bool Table::addBlock(const Block& block){
    if ( checkValid(block) == true ) {
        for(int i = 0; i < 5; i++)
            table[block.getPos(i,false)][block.getPos(i,true)] = block.getColor();
        print();
        return true;
    }
    else
        return false;
}

void Table::addselectedBlock(Block& selectedBlock, int x, int y) {
    static int prevPos[5][2];

    for(int i = 0; i < 5; i++) {
        if ( !checkBound(prevPos[i][0], prevPos[i][1]) )
            continue;
        printCell(prevPos[i][0],prevPos[i][1]);
    }

    selectedBlock.setCur(x,y);
    printBlock(selectedBlock);

    for(int i = 0; i < 5; i++) {
        prevPos[i][0] = selectedBlock.getPos(i,false);
        prevPos[i][1] = selectedBlock.getPos(i,true);
    }
}

// private
void Table::printCell(int i, int j) const {
    switch(table[i][j]){
    case BLUE:
        a_PixmapLabel[i][j]->setPixmap(QPixmap(PIX_BLUE));
        break;
    case RED:
        a_PixmapLabel[i][j]->setPixmap(QPixmap(PIX_RED));
        break;
    case GREEN:
        a_PixmapLabel[i][j]->setPixmap(QPixmap(PIX_GREEN));
        break;
    case YELLOW:
        a_PixmapLabel[i][j]->setPixmap(QPixmap(PIX_YELLOW));
        break;
    case GRAY:
        a_PixmapLabel[i][j]->setPixmap(QPixmap(PIX_GRAY));
        break;
    }
}

void Table::printBlock(const Block& block) const {
    for(int i = 0; i < 5; i++){
        int column = block.getPos(i,true);
        int row = block.getPos(i,false);
        if ( !checkBound(row, column) )
            continue;

        switch(block.getColor()){
        case BLUE:
            a_PixmapLabel[row][column]->setPixmap(QPixmap((checkValid(block) == true ? PIX_BLUE :
                                                    (table[row][column] == BLUE ? PIX_BLUE_BLUE :
                                                      (table[row][column] == RED ? PIX_BLUE_RED :
                                                        (table[row][column] == GREEN ? PIX_BLUE_GREEN :
                                                          (table[row][column] == YELLOW ? PIX_BLUE_YELLOW :PIX_BLUE_T)))))));
            break;
        case RED:
            a_PixmapLabel[row][column]->setPixmap(QPixmap((checkValid(block) == true ? PIX_RED :
                                                   (table[row][column] == BLUE ? PIX_RED_BLUE :
                                                     (table[row][column] == RED ? PIX_RED_RED :
                                                       (table[row][column] == GREEN ? PIX_RED_GREEN :
                                                         (table[row][column] == YELLOW ? PIX_RED_YELLOW :PIX_RED_T)))))));
            break;
        case GREEN:
            a_PixmapLabel[row][column]->setPixmap(QPixmap((checkValid(block) == true ? PIX_GREEN :
                                                       (table[row][column] == BLUE ? PIX_GREEN_BLUE :
                                                         (table[row][column] == RED ? PIX_GREEN_RED :
                                                           (table[row][column] == GREEN ? PIX_GREEN_GREEN :
                                                             (table[row][column] == YELLOW ? PIX_GREEN_YELLOW :PIX_GREEN_T)))))));
            break;
        case YELLOW:
            a_PixmapLabel[row][column]->setPixmap(QPixmap((checkValid(block) == true ? PIX_YELLOW :
                                                       (table[row][column] == BLUE ? PIX_YELLOW_BLUE :
                                                         (table[row][column] == RED ? PIX_YELLOW_RED :
                                                           (table[row][column] == GREEN ? PIX_YELLOW_GREEN :
                                                             (table[row][column] == YELLOW ? PIX_YELLOW_YELLOW : PIX_YELLOW_T)))))));
            break;
        case GRAY:
            a_PixmapLabel[row][column]->setPixmap(QPixmap(PIX_GRAY));
            break;
        }
    }
}

bool Table::checkValid(const Block& block) const {
    bool flag = false;
    for(int i = 0; i < 5; i++){
        int column = block.getPos(i,true);
        int row = block.getPos(i,false);

        if ( !checkBound(row, column) )
            return false;

        if( (checkBound(row, column + 1) && table[row][column + 1] == block.getColor()) ||
            (checkBound(row, column - 1) && table[row][column - 1] == block.getColor()) ||
            (checkBound(row + 1, column) && table[row + 1][column] == block.getColor()) ||
            (checkBound(row - 1, column) &&table[row - 1][column] == block.getColor()) ||
            table[row][column] != GRAY)
            return false;

        switch(turn.front()) {
        case 0:
            if ( column == 0 && row == 0 )
                flag = true;
            break;
        case 1:
            if ( column == MAX_X - 1 && row == 0 )
                flag = true;
            break;
        case 2:
            if ( column == MAX_X - 1 && row == MAX_Y - 1 )
                flag = true;
            break;
        case 3:
            if ( column == 0 && row == MAX_X - 1 )
                flag = true;
            break;
        default:
            break;
        }


        if((checkBound(row - 1, column - 1) && table[row - 1][column - 1] == block.getColor()) ||
           (checkBound(row - 1, column + 1) && table[row - 1][column + 1] == block.getColor()) ||
           (checkBound(row + 1, column - 1) && table[row + 1][column - 1] == block.getColor()) ||
           (checkBound(row + 1, column + 1) && table[row + 1][column + 1] == block.getColor()))
            flag = true;
    }
    return flag;
}

bool Table::checkBound(const int row, const int column) const {
    if( row >= 0 && row < MAX_X && column >= 0 && column < MAX_X)
        return true;

    return false;
}
