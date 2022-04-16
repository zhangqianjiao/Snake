#ifndef NAIVE_BAYES_IMAGE_H
#define NAIVE_BAYES_IMAGE_H

#endif //NAIVE_BAYES_IMAGE_H
#include <string>
#include <ostream>
#include <utility>
#include <map>
#include <vector>

namespace snakegame {
    class Snake {

    public:

        Snake();

        Snake(int length, const std::string &color, const std::vector<std::pair<int, int>> &position);

        int getLength() const;

        void setLength(int length);

        const std::string &getColor() const;

        void setColor(const std::string &color);

        const std::vector<std::pair<int, int>> &getPosition() const;

        void setPosition(std::vector<std::pair<int, int>> &position);

    private:

        /**
         * the length of the snake
         */
        int length_;

        /**
         * the color
         */
        std::string color_;

        /**
         * the vector that holds the position of each part of body
         * the head starts from the last position, tail is the first
         */
         std::vector<std::pair<int, int>> position_;
    public:
        std::pair<int, int> getHead() const;
    };

}