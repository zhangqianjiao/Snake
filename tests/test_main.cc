#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../include/core/snake.h"
using namespace snakegame;
TEST_CASE("test the snake itself") {

    SECTION("generate snake and check length") {

        std::vector<std::pair<int, int>> snake_vec;
        std::pair<int, int> p1;
        p1.first = 5;
        p1.second = 0;
        snake_vec.push_back(p1);

        std::pair<int, int> p2;
        p2.first = 5;
        p2.second = 1;
        snake_vec.push_back(p2);

        std::pair<int, int> p3;
        p3.first = 5;
        p3.second = 2;
        snake_vec.push_back(p3);

        std::pair<int, int> p4;
        p4.first = 5;
        p4.second = 3;
        snake_vec.push_back(p4);

        std::pair<int, int> p5;
        p5.first = 5;
        p5.second = 4;
        snake_vec.push_back(p5);
        Snake snake;
        snake.setPosition(snake_vec);
        REQUIRE(snake.getPosition().size() == 5);

    }

    SECTION("generate snake and check getting itself") {
        std::vector<std::pair<int, int>> snake_vec;
        std::pair<int, int> p1;
        p1.first = 5;
        p1.second = 0;
        snake_vec.push_back(p1);

        std::pair<int, int> p2;
        p2.first = 5;
        p2.second = 1;
        snake_vec.push_back(p2);


        Snake snake;
        snake.setPosition(snake_vec);
        auto snake_vec_res = snake.getPosition();

        REQUIRE(snake_vec_res[0].first == 5);
        REQUIRE(snake_vec_res[0].second == 0);
        REQUIRE(snake_vec_res[1].first == 5);
        REQUIRE(snake_vec_res[1].second == 1);
    }

    SECTION("checkPos to ensure it detects eating itself correctly") {

        std::vector<std::pair<int, int>> snake_vec;
        std::pair<int, int> p1;
        p1.first = 5;
        p1.second = 0;
        snake_vec.push_back(p1);

        std::pair<int, int> p2;
        p2.first = 5;
        p2.second = 1;
        snake_vec.push_back(p2);

        Snake snake;
        snake.setPosition(snake_vec);
        REQUIRE(snake.checkPos());
    }

    SECTION("checkPos to ensure it detects eating itself") {

        std::vector<std::pair<int, int>> snake_vec;
        std::pair<int, int> p1;
        p1.first = 5;
        p1.second = 0;
        snake_vec.push_back(p1);

        std::pair<int, int> p2;
        p2.first = 5;
        p2.second = 1;
        snake_vec.push_back(p2);

        std::pair<int, int> p3;
        p3.first = 5;
        p3.second = 1;
        snake_vec.push_back(p3);

        Snake snake;
        snake.setPosition(snake_vec);
        REQUIRE(snake.checkPos() == false);
    }

    SECTION("checkPos to ensure it stay inside the map") {

        std::vector<std::pair<int, int>> snake_vec;
        std::pair<int, int> p1;
        p1.first = 5;
        p1.second = 0;
        snake_vec.push_back(p1);

        std::pair<int, int> p2;
        p2.first = 5;
        p2.second = -1;
        snake_vec.push_back(p2);

        Snake snake;
        snake.setPosition(snake_vec);
        REQUIRE(snake.checkPos() == false);
    }

    SECTION("check color of the snake") {

        std::vector<std::pair<int, int>> snake_vec;
        std::pair<int, int> p1;
        p1.first = 5;
        p1.second = 0;
        snake_vec.push_back(p1);

        std::pair<int, int> p2;
        p2.first = 5;
        p2.second = -1;
        snake_vec.push_back(p2);

        Snake snake;
        snake.setPosition(snake_vec);
        snake.setColor("white");

        REQUIRE(snake.getColor() == "white");
    }
}