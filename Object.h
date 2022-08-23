//
// Created by konstantin on 21.08.22.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <string_view>
#include <SFML/Graphics.hpp>
#include <map>
class Object {
public:
    enum class State {move_left,move_right};
    static void add_texture(std::string_view path);
    const int sprite_width = 48;
    const int sprite_height = 48;
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
    State get_state();
protected:
    State state;
    const sf::Texture& get_texture(std::string_view path);
    bool solid;
    bool weighty;
    bool vulnerability;
    float _x = 0;
    float _y = 0;
    sf::Sprite sprite;
    float speed_ = 0;
    explicit Object (std::string_view path);
    Object();
private:
    sf::Texture* texture_;
    static std::map<std::string_view,sf::Texture> textures;
    static sf::Texture load_texture_from_file(std::string_view path);
};

#endif //GAME_OBJECT_H
