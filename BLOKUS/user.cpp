#include "user.h"
#include "table.h"
#include "constants.h"

User::User()
    : selectedBlock(), color(BLUE), score(0), end(false) { }

User::~User(){

}

void User::setColor(const BLOCKCOLOR color){
    this->color = color;
}
void User::setEnd(const bool end){
    this->end = end;
}

void User::selectBlock(const Block& block) {
    selectedBlock = block;
}

void User::addScore(const int score){
    this->score += score;
}
