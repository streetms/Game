//
// Created by konstantin on 22.08.22.
//

#ifndef GAME_PROJECTILE_H
#define GAME_PROJECTILE_H

#include "Projectile.h"
#include "Object.h"
class Projectile : public Object {
private:
    Object* parent_;
public:
    Projectile(std::string_view path, Object* parent);
    void update() override;
    const int sprite_width = 96;
    const int sprite_height = 48;
    std::pair <int,int> Size() override;
};


#endif //GAME_PROJECTILE_H
