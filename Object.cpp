//
// Created by konstantin on 21.08.22.
//

#include "Object.h"
#include "utility.h"
void Object::fell() {

}

Object::Object(std::string_view path){
    if (textures.find(path) == textures.end()) {
        textures.emplace(path,load_texture_from_file(path));
        texture = &((*(textures.find(path))).second);
    }
}

bool Object::is_weighty() {
    return weighty;
}

bool Object::is_solid() {
    return solid;
}
std::map<std::string_view,sf::Texture> Object::textures;