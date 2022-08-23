//
// Created by konstantin on 23.08.22.
//

#ifndef GAME_CREATURE_H
#define GAME_CREATURE_H
#include <forward_list>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Projectile.h"
class Creature : public Object{
public:
    Creature(std::string_view path);
    void draw_projectiles(sf::RenderWindow& window);
    virtual void shot(Projectile::Type type);
protected:
    int height;
    int max_height;
    bool life;
    float current_frame;
private:
    std::forward_list<std::unique_ptr<Projectile>> projectiles;

};


#endif //GAME_CREATURE_H
