//
// Created by konstantin on 20.08.22.
//

#include "Block.h"

Block::Block(std::string_view path) : Object(path) {

}

Block::Block() : Object(""){
    solid = true;

}
