#include <iostream>
#include "../../include/core/snake.h"



snakegame::Snake::Snake() {

}

snakegame::Snake::Snake(int length, const std::string &color, const std::vector<std::pair<int, int>> &position)
        : length_(length), color_(color), position_(position) {


}

std::pair<int, int> snakegame::Snake::getHead() const {
    return position_[position_.size() - 1];
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

const std::vector<std::pair<int, int>> &snakegame::Snake::getPosition() const {
    return position_;
}

void snakegame::Snake::setPosition(std::vector<std::pair<int, int>> &position) {
    position_ = position;
}

bool snakegame::Snake::checkPos() {

    std::map<std::pair<int, int>, int> freq_map;
    for (int i = 0; i < this->position_.size(); i++) {
        if (this->position_[i].first < 0 || this->position_[i].first > 27
            || this->position_[i].second < 0 || this->position_[i].second > 27) {
            return false;
        }

        // find
        if (freq_map.find(this->position_[i]) != freq_map.end()) {
            freq_map[this->position_[i]] += 1;
//            std::cout << "Keyf: " << this->position_[i].first << " " << this->position_[i].second << " ; value: " <<  freq_map[this->position_[i]] << "\n";
        } else { // not find
            freq_map[this->position_[i]] = 1;
//            std::cout << "Keynf: " << this->position_[i].first << " " << this->position_[i].second << " ; value: " <<  freq_map[this->position_[i]] << "\n";

        }


    }

    std::map<std::pair<int, int>, int>::iterator it;
    for (it = freq_map.begin(); it != freq_map.end(); it ++) {
        if (it->second > 1) {
            return false;
        }
    }

    return true;
}
