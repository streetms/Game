//
// Created by konstantin on 20.08.22.
//

#ifndef GAME_HERO_H
#define GAME_HERO_H
#include <SFML/Graphics.hpp>

class Hero {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int height;
    int max_height;
    bool life;
    float current_frame;
    float _x;
    float _y;
    float speed;
    std::array<sf::Rect<int>,11> move_right_frame= { sf::Rect(50,885,150,130),sf::Rect(210,885,150,130),sf::Rect(380,885,150,130),
                                                    sf::Rect(555,885,156,130),sf::Rect(736,885,156,130),sf::Rect(923,885,156,130),
                                                    sf::Rect(1105,885,156,130),sf::Rect(1280,885,156,130),sf::Rect(1465,885,156,130),
                                                     sf::Rect(1635,885,156,130),sf::Rect(1805,885,156,130)};
    std::array<sf::Rect<int>,11> move_left_frame= { sf::Rect(200,885,-150,130),sf::Rect(360,885,-150,130),sf::Rect(530,885,-150,130),
                                                     sf::Rect(711,885,-156,130),sf::Rect(892,885,-156,130),sf::Rect(1079,885,-156,130),
                                                     sf::Rect(1261,885,-156,130),sf::Rect(1436,885,-156,130),sf::Rect(1621,885,-156,130),
                                                     sf::Rect(1791,885,-156,130),sf::Rect(1961,885,-156,130)};
public:
    explicit Hero(std::string_view path);
    sf::Sprite Sprite();
    void set_position(float x, float y);
    void update();
};


#endif //GAME_HERO_H
