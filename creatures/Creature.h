//
// Created by konstantin on 23.08.22.
//

#ifndef GAME_CREATURE_H
#define GAME_CREATURE_H
#include <forward_list>
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "Map.h"
class Creature : public Object{
public:
    void draw_projectiles(sf::RenderWindow& window);
    virtual void shot(Projectile::Type type);
    explicit Creature(Map& map);
protected:
    Map* map_;
    int height;
    int max_height;
    bool life;
    float current_frame;
private:
    std::forward_list<Projectile> projectiles;

};


#endif //GAME_CREATURE_H
