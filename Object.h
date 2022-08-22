//
// Created by konstantin on 21.08.22.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <string_view>
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
class Object {
private:
    static std::map<std::string_view,sf::Texture> textures;
    sf::Texture* texture;
protected:
    bool solid;
    bool weighty;
    bool vulnerability;
    float _x = 0;
    float _y = 0;
    sf::Sprite sprite;
    float speed_ = 0;
    explicit Object (std::string_view path);
public:
    const int sprite_width = 32;
    const int sprite_height = 32;
    enum class State {move_left,move_right};
    State state;
    virtual void update() = 0;
    virtual void fell();
    bool is_solid();
    bool is_weighty();
    virtual ~Object() = default;
    std::pair <float,float> Position();
    virtual std::pair <int,int> Size() = 0;
    sf::Sprite Sprite();
    void set_position(float x, float y);
    void set_speed(float speed);
    float Speed();
};

#endif //GAME_OBJECT_H
