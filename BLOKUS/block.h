#pragma once
#include "constants.h"
class Block{
private:
    int cur[2];
    int pos[5][2];
    BLOCKCOLOR color;
    int type;
    int state;
public:
    Block(const int cur_x = 0, const int cur_y = 0, BLOCKCOLOR color = GRAY, const int type = 0);
    Block(const Block& copyBlock);

    int getCurX() const;
    int getCurY() const;
    int getPos(const int index, bool isX) const;
    int getType() const;
    BLOCKCOLOR getColor() const;
    int getState() const;
    void setCur(const int x, const int y);
    void setColor(const BLOCKCOLOR color);
    void rotate(bool up);
    void move(const DIRECTION direction);

    void operator=(const Block& copy);
private:
    void setPos();
};
