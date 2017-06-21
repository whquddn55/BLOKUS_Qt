#pragma once
#include "block.h"
#include "ui_mainwindow.h"
#include "constants.h"

class User{
private:
    BLOCKCOLOR color;
    Block selectedBlock;
    int score;
    bool end;
public:
    User();
    ~User();
    Block& getSelectedBlock() { return selectedBlock; }
    const Block& getSelectedBlock() const { return selectedBlock; }
    BLOCKCOLOR getColor() const { return color; }
    int getScore() const { return score; }
    void setColor(const BLOCKCOLOR color);
    void setEnd(const bool end);
    void selectBlock(const Block& block);
    void addScore(const int score);
    bool isEnd() const { return end; }


};
