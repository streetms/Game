//
// Created by konstantin on 20.08.22.
//

#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H
#include "Object.h"
class Block : public Object {
    Block(std::string_view path);
    Block();
};


#endif //GAME_BLOCK_H
