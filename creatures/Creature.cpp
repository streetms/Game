//
// Created by konstantin on 23.08.22.
//

#include "creatures/Creature.h"

void Creature::shot(Projectile::Type type) {
    map_->add_object(new Projectile(type,this));
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

Creature::Creature(Map &map) {
    map_ = &map;
    map.add_object(this);
}


