//
// Created by konstantin on 22.08.22.
//
#include "utility.h"
#include <QFile>
sf::Texture load_texture_from_file(std::string_view path){
    sf::Texture texture;
    QFile file;
    file.setFileName(path.data());
    file.open(QIODevice::ReadOnly);
    texture.loadFromMemory(file.readAll().data(),file.size());
    return texture;
}