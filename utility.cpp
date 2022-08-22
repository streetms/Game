//
// Created by konstantin on 22.08.22.
//
#include <QFile>
#include "utility.h"
#include "Projectile.h"

constexpr static int WIDTH = 1280;
constexpr static int HEIGHT = 720;

sf::Texture load_texture_from_file(std::string_view path) {
    sf::Texture texture;
    QFile file;
    file.setFileName(path.data());
    file.open(QIODevice::ReadOnly);
    texture.loadFromMemory(file.readAll().data(),file.size());
    return texture;
}


void draw_projectiles(std::forward_list<std::unique_ptr<Projectile>>& projectiles, sf::RenderWindow& window) {
    auto cur = projectiles.begin();

    while (cur != projectiles.end()) {
        cur->get()->update();
        auto t = cur;
        cur++;
        float x, y;
        std::tie(x,y) = (*t).get()->Position();
        if (x <= 0 or x >= window.getSize().x) {
            projectiles.remove(*t);
        } else {
            window.draw(t->get()->Sprite());
        }
    }
}