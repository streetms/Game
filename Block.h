//
// Created by konstantin on 20.08.22.
//

#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H
#include "Object.h"
class Block : public Object {
public:
    enum class Type{empty,wall};
    bool solid;
    bool destructible;
    Block();
    Block(char ch);
    Block(const Block& other);
    void operator=(const char ch);
    void update() override;
private:
    const int sprite_width = 48;
    const int sprite_height = 48;
};


#endif //GAME_BLOCK_H
