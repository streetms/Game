//
// Created by konstantin on 21.08.22.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <string_view>
#include <SFML/Graphics.hpp>
#include <map>
class Object {
private:
    static std::map<std::string_view,sf::Texture> textures;
protected:
    bool solid;
    bool weighty;
    float _x = 0;
    float _y = 0;
    sf::Texture* texture;
    sf::Sprite sprite;
    float speed = 0;
    explicit Object (std::string_view path);
    virtual void update() = 0;
    virtual void fell();
    bool is_solid();
    bool is_weighty();
};

#endif //GAME_OBJECT_H
