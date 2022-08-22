//
// Created by konstantin on 20.08.22.
//

#ifndef GAME_HERO_H
#define GAME_HERO_H
#include <SFML/Graphics.hpp>
#include <forward_list>
#include <memory>
#include "Object.h"
#include "Projectile.h"
class Hero : public Object{
private:
    std::forward_list<std::unique_ptr<Projectile>> projectiles;
    int height;
    int max_height;
    bool life;
    float current_frame;
    std::array<sf::Rect<int>,11> move_right_frame= { sf::Rect(50,885,156,128),sf::Rect(210,885,150,128),sf::Rect(380,885,150,128),
                                                    sf::Rect(555,885,156,128),sf::Rect(736,885,156,128),sf::Rect(923,885,156,128),
                                                    sf::Rect(1105,885,156,128),sf::Rect(1280,885,156,128),sf::Rect(1465,885,156,128),
                                                     sf::Rect(1635,885,156,128),sf::Rect(1805,885,156,128)};
    std::array<sf::Rect<int>,11> move_left_frame= { sf::Rect(200,885,-156,128),sf::Rect(360,885,-150,128),sf::Rect(530,885,-150,128),
                                                     sf::Rect(711,885,-156,128),sf::Rect(892,885,-156,128),sf::Rect(1079,885,-156,128),
                                                     sf::Rect(1261,885,-156,128),sf::Rect(1436,885,-156,128),sf::Rect(1621,885,-156,128),
                                                     sf::Rect(1791,885,-156,128),sf::Rect(1961,885,-156,128)};
public:
    const int sprite_width = 48;
    const int sprite_height = 96;
    explicit Hero(std::string_view path);
    void update() override;
    std::pair <int,int> Size() override;
    std::forward_list<std::unique_ptr<Projectile>>& Projectiles();
    void shot(Projectile::Type type);
};


#endif //GAME_HERO_H
