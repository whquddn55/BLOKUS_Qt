#pragma once
#include <QLabel>
#include "ui_mainwindow.h"
#include "block.h"
#include "user.h"
#include "constants.h"

class Table{
private:
    Ui::MainWindow* const ui;
    QLabel* a_PixmapLabel[MAX_X][MAX_Y];
    BLOCKCOLOR table[MAX_X][MAX_Y];
public:
    Table(Ui::MainWindow* const ui);
    ~Table();

    void set();
    void print() const;
    bool addBlock(const Block& block);
    void addselectedBlock(Block& selectedBlock, int x, int y);
private:
    void printCell(int i, int j) const;
    void printBlock(const Block &block) const;
    bool checkValid(const Block& block) const;
    bool checkBound(const int row, const int column) const;
};

