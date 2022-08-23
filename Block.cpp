//
// Created by konstantin on 20.08.22.
//

#include "Block.h"


Block::Block() : Object(){
    sprite.setOrigin(sprite_width/2,sprite_height/2);
}

void Block::update() {

}

Block::Block(char ch) : Block(){
    *this = ch;
}
Block::Block(const Block& other) : Block(){

}
void Block::operator=(const char ch) {
    switch (ch) {
        case '#' :
            sprite.setTexture(get_texture(":/images/wall.png"));
            solid = true;
            destructible = true;
            break;
    }
}
