#include "block.h"
#include "constants.h"

Block::Block(const int cur_x, const int cur_y, BLOCKCOLOR color , const int type)
    : type(type), color(color), state(0){
    cur[0] = cur_x;
    cur[1] = cur_y;
    setPos();
}
Block::Block(const Block& copyBlock)
    :type(copyBlock.type), color(copyBlock.color){
    cur[0] = copyBlock.cur[0];
    cur[1] = copyBlock.cur[1];
    for(int i = 0; i < 5; i++){
        pos[i][0] = copyBlock.pos[i][0];
        pos[i][1] = copyBlock.pos[i][1];
    }
    state = copyBlock.state;
    setPos();
}

int Block::getCurX() const {
    return cur[0];
}
int Block::getCurY() const {
    return cur[1];
}
int Block::getPos(const int index, bool isX) const {
    return (isX == true ? pos[index][1] : pos[index][0]);
}
BLOCKCOLOR Block::getColor() const {
    return color;
}
int Block::getType() const {
    return type;
}
int Block::getState() const{
    return state;
}
void Block::setCur(const int x, const int y) {
    cur[0] = x;
    cur[1] = y;
    setPos();
}
void Block::setColor(const BLOCKCOLOR color){
    this->color = color;
}

void Block::rotate(bool up) {
    switch(type){
    case 1:
        state = 0;
        break;
    case 2:
        state = ((up == true? ( state >= 1 ? 0 : state + 1 ) : (state <= 0 ? 1 : state - 1)));
        break;
    case 3:
        state = ((up == true? ( state >= 3 ? 0 : state + 1 ) : (state <= 0 ? 3 : state - 1)));
        break;
    case 4:
        state = ((up == true? ( state >= 1 ? 0 : state + 1 ) : (state <= 0 ? 1 : state - 1)));
        break;
    case 5:
        state = ((up == true? ( state >= 3 ? 0 : state + 1 ) : (state <= 0 ? 3 : state - 1)));
        break;
    case 6:
        state = ((up == true? ( state >= 7 ? 0 : state + 1 ) : (state <= 0 ? 7 : state - 1)));
        break;
    case 7:
        state = ((up == true? ( state >= 3 ? 0 : state + 1 ) : (state <= 0 ? 3 : state - 1)));
        break;
    case 8:
        state = ((up == true? ( state >= 1 ? 0 : state + 1 ) : (state <= 0 ? 1 : state - 1)));
        break;
    case 9:
        state = 0;
        break;
    case 10:
        state = ((up == true? ( state >= 3 ? 0 : state + 1 ) : (state <= 0 ? 3 : state - 1)));
        break;
    case 11:
        state = ((up == true? ( state >= 7 ? 0 : state + 1 ) : (state <= 0 ? 7 : state - 1)));
        break;
    case 12:
        state = ((up == true? ( state >= 7 ? 0 : state + 1 ) : (state <= 0 ? 7 : state - 1)));
        break;
    case 13:
        state = ((up == true? ( state >= 7 ? 0 : state + 1 ) : (state <= 0 ? 7 : state - 1)));
        break;
    case 14:
        state = 0;
        break;
    case 15:
        state = ((up == true? ( state >= 3 ? 0 : state + 1 ) : (state <= 0 ? 3 : state - 1)));
        break;
    case 16:
        state = ((up == true? ( state >= 7 ? 0 : state + 1 ) : (state <= 0 ? 7 : state - 1)));
        break;
    case 17:
        state = ((up == true? ( state >= 3 ? 0 : state + 1 ) : (state <= 0 ? 3 : state - 1)));
        break;
    case 18:
        state = ((up == true? ( state >= 3 ? 0 : state + 1 ) : (state <= 0 ? 3 : state - 1)));
        break;
    case 19:
        state = ((up == true? ( state >= 3 ? 0 : state + 1 ) : (state <= 0 ? 3 : state - 1)));
        break;
    case 20:
        state = ((up == true? ( state >= 7 ? 0 : state + 1 ) : (state <= 0 ? 7 : state - 1)));
        break;
    case 21:
        state = ((up == true? ( state >= 1 ? 0 : state + 1 ) : (state <= 0 ? 1 : state - 1)));
        break;
    }
}

void Block::move(const DIRECTION direction) {
    switch(direction){
    case UP:
        for(int i = 0; i < 5; i++)
            pos[i][1]++;
        break;
    case DOWN:
        for(int i = 0; i < 5; i++)
            pos[i][1]--;
        break;
    case RIGHT:
        for(int i = 0; i < 5; i++)
            pos[i][0]++;
        break;
    case LEFT:
        for(int i = 0; i < 5; i++)
            pos[i][0]--;
        break;
    }
}

void Block::operator=(const Block& copy){
    cur[0] = copy.cur[0];
    cur[1] = copy.cur[1];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 2; j++)
            pos[i][j] = copy.pos[i][j];
    color = copy.color;
    type = copy.type;
    state = copy.state;
}

// private
void Block::setPos(){
    switch(type) {
    case 1:
        pos[0][0] = cur[0];
        pos[0][1] = cur[1];

        pos[1][0] = cur[0];
        pos[1][1] = cur[1];
        pos[2][0] = cur[0];
        pos[2][1] = cur[1];
        pos[3][0] = cur[0];
        pos[3][1] = cur[1];
        pos[4][0] = cur[0];
        pos[4][1] = cur[1];
        break;
    case 2:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            break;
        }
        pos[2][0] = cur[0];
        pos[2][1] = cur[1];
        pos[3][0] = cur[0];
        pos[3][1] = cur[1];
        break;
    case 3:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            break;
        }
        pos[3][0] = cur[0];
        pos[3][1] = cur[1];
        pos[4][0] = cur[0];
        pos[4][1] = cur[1];
        break;
    case 4:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            break;
        }
        pos[3][0] = cur[0];
        pos[3][1] = cur[1];
        pos[4][0] = cur[0];
        pos[4][1] = cur[1];
        break;
    case 5:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1] - 1;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1] - 1;
            break;
        }
        pos[4][0] = cur[0];
        pos[4][1] = cur[1];
        break;
    case 6:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            break;
        case 4:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            break;
        case 5:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            break;
        case 6:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            break;
        case 7:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            break;
        }
        pos[4][0] = cur[0];
        pos[4][1] = cur[1];
        break;
    case 7:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            break;
        }
        pos[4][0] = cur[0];
        pos[4][1] = cur[1];
        break;
    case 8:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 2;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 2;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            break;
        }
        pos[4][0] = cur[0];
        pos[4][1] = cur[1];
        break;
    case 9:
        pos[0][0] = cur[0];
        pos[0][1] = cur[1];
        pos[1][0] = cur[0] - 1;
        pos[1][1] = cur[1];
        pos[2][0] = cur[0] - 1;
        pos[2][1] = cur[1] + 1;
        pos[3][0] = cur[0];
        pos[3][1] = cur[1] + 1;
        pos[4][0] = cur[0];
        pos[4][1] = cur[1];
        break;
    case 10:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1] + 1;
            break;
        }
        break;
    case 11:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] - 1;
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] + 1;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 4:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] - 1;
            break;
        case 5:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1];
            break;
        case 6:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] + 1;
            break;
        case 7:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1];
            break;

        }
        break;
    case 12:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1];
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 4:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 5:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 6:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 7:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1] + 1;
            break;
        }
        break;
    case 13:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] + 2;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] - 2;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] - 2;
            pos[4][1] = cur[1];
            break;
        case 4:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] + 2;
            break;
        case 5:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        case 6:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] - 2;
            break;
        case 7:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] - 2;
            pos[4][1] = cur[1];
            break;
        }
        break;
    case 14:
        pos[0][0] = cur[0];
        pos[0][1] = cur[1];
        pos[1][0] = cur[0] - 1;
        pos[1][1] = cur[1];
        pos[2][0] = cur[0];
        pos[2][1] = cur[1] - 1;
        pos[3][0] = cur[0];
        pos[3][1] = cur[1] + 1;
        pos[4][0] = cur[0] + 1;
        pos[4][1] = cur[1];
        break;
    case 15:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 2;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 2;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 2;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] - 2;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 2;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] + 2;
            break;
        }
        break;
    case 16:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] + 2;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] - 2;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] - 2;
            pos[4][1] = cur[1];
            break;
        case 4:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] + 2;
            break;
        case 5:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        case 6:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] - 2;
            break;
        case 7:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] - 2;
            pos[4][1] = cur[1];
            break;
        }
        break;
    case 17:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        }
        break;
    case 18:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        }
        break;
    case 19:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] + 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] + 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        }
        break;
    case 20:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 2;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] - 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        case 2:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] - 2;
            break;
        case 3:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 2;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] - 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 4:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] + 2;
            pos[3][0] = cur[0] - 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] - 1;
            pos[4][1] = cur[1] - 1;
            break;
        case 5:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] + 1;
            pos[2][0] = cur[0] - 1;
            pos[2][1] = cur[1] + 1;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        case 6:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 2;
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        case 7:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 2;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0] + 1;
            pos[4][1] = cur[1] + 1;
            break;
        }
        break;
    case 21:
        switch(state) {
        case 0:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0];
            pos[1][1] = cur[1] - 1;
            pos[2][0] = cur[0];
            pos[2][1] = cur[1] - 2;
            pos[3][0] = cur[0];
            pos[3][1] = cur[1] + 1;
            pos[4][0] = cur[0];
            pos[4][1] = cur[1] + 2;
            break;
        case 1:
            pos[0][0] = cur[0];
            pos[0][1] = cur[1];
            pos[1][0] = cur[0] - 1;
            pos[1][1] = cur[1];
            pos[2][0] = cur[0] - 2;
            pos[2][1] = cur[1];
            pos[3][0] = cur[0] + 1;
            pos[3][1] = cur[1];
            pos[4][0] = cur[0] + 2;
            pos[4][1] = cur[1];
            break;
        }
        break;
    }
}
