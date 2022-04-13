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

        Snake(int length, const std::string &color, const std::vector<std::pair<float, float>> &position);

        int getLength() const;

        void setLength(int length);

        const std::string &getColor() const;

        void setColor(const std::string &color);

        const std::vector<std::pair<float, float>> &getPosition() const;

        void setPosition(const std::vector<std::pair<float, float>> &position);

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
         * the vector that holds the position of each position of body
         */
         std::vector<std::pair<float, float>> position_;
    public:
    };

}