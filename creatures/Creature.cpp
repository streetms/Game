//
// Created by konstantin on 23.08.22.
//

#include "creatures/Creature.h"
Creature::Creature(std::string_view path) : Object(path) {

}

void Creature::shot(Projectile::Type type) {
    projectiles.push_front({type,this});
}

void Creature::draw_projectiles(sf::RenderWindow& window) {
    auto cur = projectiles.begin();
    while (cur != projectiles.end()) {
        cur->update();
        auto t = cur;
        cur++;
        float x, y;
        std::tie(x,y) = t->Position();
        if (x <= 0 or x >= window.getSize().x) {
            projectiles.remove(*t);
        } else {
            window.draw(t->Sprite());
        }
    }
}


