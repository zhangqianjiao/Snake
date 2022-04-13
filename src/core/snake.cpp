#include "../../include/core/snake.h"



snakegame::Snake::Snake() {

}

snakegame::Snake::Snake(int length, const std::string &color, const std::vector<std::pair<float, float>> &position)
        : length_(length), color_(color), position_(position) {


}

int snakegame::Snake::getLength() const {
    return length_;
}

void snakegame::Snake::setLength(int length) {
    length_ = length;
}

const std::string &snakegame::Snake::getColor() const {
    return color_;
}

void snakegame::Snake::setColor(const std::string &color) {
    color_ = color;
}

const std::vector<std::pair<float, float>> &snakegame::Snake::getPosition() const {
    return position_;
}

void snakegame::Snake::setPosition(const std::vector<std::pair<float, float>> &position) {
    position_ = position;
}
