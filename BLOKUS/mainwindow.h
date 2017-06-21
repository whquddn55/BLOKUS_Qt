#pragma once
#include <QMainWindow>
#include <cstring>
#include <QLabel>
#include <QWheelEvent>
#include "ui_mainwindow.h"
#include "table.h"
#include "user.h"
#include "constants.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Table gameTable;
    User user[4];
    QLabel* a_PixmapLabel[4][3][7]; // Data of TableWidge
    QLabel* selected_PixmapLabel;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void deleteTableWidgetPix(const int index, int type);
    void setSelectedTableWidgetPix(int index, int type);
    void setTableWidget();
    void turnOver() const;
    void endGame() const;

    void wheelEvent(QWheelEvent *event);
private slots:
    void on_gameTableWidget_cellEntered(int row, int column);
    void on_gameTableWidget_cellClicked(int row, int column);
    void on_tableWidget_1_cellClicked(int row, int column);
    void on_tableWidget_2_cellClicked(int row, int column);
    void on_tableWidget_3_cellClicked(int row, int column);
    void on_tableWidget_4_cellClicked(int row, int column);
    void on_endButton_1_clicked(bool checked);
    void on_endButton_2_clicked(bool checked);
    void on_endButton_3_clicked(bool checked);
    void on_endButton_4_clicked(bool checked);
};
