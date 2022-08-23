//
// Created by konstantin on 21.08.22.
//
#include <QFile>
#include "Object.h"
std::map<std::string_view,sf::Texture> Object::textures;

void Object::fell() {

}

Object::State Object::get_state() {
    return state;
}

Object::Object(std::string_view path){
    if (not path.empty()) {
        if (textures.find(path) == textures.end()) {
            textures.emplace(path, load_texture_from_file(path));
        }
        texture_ = &((*(textures.find(path))).second);
        sprite.setTexture(*texture_);
    }
}

bool Object::is_weighty() {
    return weighty;
}

bool Object::is_solid() {
    return solid;
}

std::pair<float, float> Object::Position() {
    return std::pair{_x,_y};
}
sf::Sprite Object::Sprite() {
    return sprite;
}

void Object::set_position(float x, float y) {
    sprite.setPosition(x,y);
    _x = x;
    _y = y;
}

void Object::set_speed(float speed) {
    speed_ = speed;
}

float Object::Speed(){
    return speed_;
}

void Object::add_texture(std::string_view path) {
    textures.emplace(path, load_texture_from_file(path));
}

const sf::Texture &Object::get_texture(std::string_view path) {
    return textures.find(path)->second;
}

Object::Object() {

}

sf::Texture Object::load_texture_from_file(std::string_view path) {
    sf::Texture texture;
    QFile file;
    file.setFileName(path.data());
    file.open(QIODevice::ReadOnly);
    texture.loadFromMemory(file.readAll().data(),file.size());
    return texture;
}
