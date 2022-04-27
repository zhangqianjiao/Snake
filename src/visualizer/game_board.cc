#include <visualizer/game_board.h>

namespace snakegame {

    namespace visualizer {

        SnakeGame::SnakeGame()
                : Userpad_(glm::vec2(kMargin, kMargin), kImageDimension,
                           kWindowSize - 2 * kMargin) {
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

        }

        void SnakeGame::draw() {
            if (!gameover) {
//
                ci::Color8u background_color(255, 246, 148);  // light yellow
                ci::gl::clear(background_color);

                Userpad_.Draw();

                ci::gl::drawStringCentered(
                        "SNAKE",
                        glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));
            } else {
                ci::gl::drawStringCentered(
                        "GAME OVER",
                        glm::vec2(kWindowSize / 2 , kMargin / 2 + 250), ci::Color("black"));
            }

        }


        void SnakeGame::KeyDown() {
            std::cout << "KeyDown" << "\n";
            auto snake_vec = Userpad_.getSnake().getPosition();
            auto head = Userpad_.getSnake().getHead();
            auto next_pos = std::pair<int, int>(head.first + 1, head.second);
            if (EatFood(next_pos, Userpad_.getFood(), snake_vec)) {
                return;
            }
            // 第一位获得新值 第二位=原来一地位
            for (int i = 0; i < snake_vec.size() - 1; i++) {
                auto last_item = snake_vec[i + 1];
                snake_vec[i] = last_item;
                std::cout << "snake " << i << ": " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";
            }

            // move head to upper, move left part to previous one
            head.first +=1;
            snake_vec[snake_vec.size() - 1] = head;

            for (int i = 0; i < snake_vec.size(); i++) {
                std::cout << "snake: " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";
            }
            (Userpad_.getSnake()).setPosition(snake_vec);
            gameover = !(Userpad_.getSnake()).checkPos();
        }

        void SnakeGame::KeyUp() {
            std::cout << "KeyUp" << "\n";
            auto snake_vec = Userpad_.getSnake().getPosition();
            auto head = Userpad_.getSnake().getHead();
            auto next_pos = std::pair<int, int>(head.first - 1, head.second);
            if (EatFood(next_pos, Userpad_.getFood(), snake_vec)) {
                return;
            }
            // 第一位获得新值 第二位=原来一地位
            for (int i = 0; i < snake_vec.size() - 1; i++) {
                auto last_item = snake_vec[i + 1];
                snake_vec[i] = last_item;
                std::cout << "snake " << i << ": " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";
            }

            // move head to upper, move left part to previous one
            head.first -=1;
            snake_vec[snake_vec.size() - 1] = head;

            for (int i = 0; i < snake_vec.size(); i++) {
                std::cout << "snake: " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";

            }

            (Userpad_.getSnake()).setPosition(snake_vec);
            gameover = !(Userpad_.getSnake()).checkPos();
        }

        void SnakeGame::KeyLeft() {
            std::cout << "KeyLeft" << "\n";
            auto snake_vec = Userpad_.getSnake().getPosition();
            auto head = Userpad_.getSnake().getHead();
            auto next_pos = std::pair<int, int>(head.first, head.second - 1);
            if (EatFood(next_pos, Userpad_.getFood(), snake_vec)) {
                return;
            }

            // 第一位获得新值 第二位=原来一地位
            for (int i = 0; i < snake_vec.size() - 1; i++) {
                auto last_item = snake_vec[i + 1];
                snake_vec[i] = last_item;
                std::cout << "snake " << i << ": " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";
            }

            // move head to upper, move left part to previous one
            head.second -=1;
            snake_vec[snake_vec.size() - 1] = head;

            for (int i = 0; i < snake_vec.size(); i++) {
                std::cout << "snake: " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";

            }

            (Userpad_.getSnake()).setPosition(snake_vec);
            gameover = !(Userpad_.getSnake()).checkPos();

        }

        void SnakeGame::KeyRight() {
            std::cout << "KeyRight" << "\n";
            auto snake_vec = Userpad_.getSnake().getPosition();
            auto head = Userpad_.getSnake().getHead();
            auto next_pos = std::pair<int, int>(head.first, head.second + 1);
            if (EatFood(next_pos, Userpad_.getFood(), snake_vec)) {
                return;
            }

            // 第一位获得新值 第二位=原来一地位
            for (int i = 0; i < snake_vec.size() - 1; i++) {
                auto last_item = snake_vec[i + 1];
                snake_vec[i] = last_item;
                std::cout << "snake " << i << ": " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";
            }

            // move head to upper, move left part to previous one
            head.second +=1;
            snake_vec[snake_vec.size() - 1] = head;

            for (int i = 0; i < snake_vec.size(); i++) {
                std::cout << "snake: " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";

            }

            (Userpad_.getSnake()).setPosition(snake_vec);
            gameover = !(Userpad_.getSnake()).checkPos();

        }

        bool SnakeGame::EatFood(std::pair<int, int> next_pos, std::pair<int, int> food, std::vector<std::pair<int, int>> &snake_vec) {
            if (next_pos.first == food.first && next_pos.second == food.second) {
                this->Userpad_.setFood(std::pair<int, int>(-1, -1));
                snake_vec.push_back(next_pos);
                for (int i = 0; i < snake_vec.size(); i++) {
                    std::cout << "snake after eat: " << snake_vec[i].first << " , " << snake_vec[i].second << "\n";

                }
                (Userpad_.getSnake()).setPosition(snake_vec);
                return true;
            }
            return false;
        }



        void SnakeGame::keyDown(ci::app::KeyEvent event) {
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_UP: {
                    this->KeyUp();
                    break;
                }
                case 274: {
                    this->KeyDown();
                    break;
                }
                case ci::app::KeyEvent::KEY_LEFT: {
                    this->KeyLeft();
                    break;
                }
                case ci::app::KeyEvent::KEY_RIGHT: {
                    this->KeyRight();
                    break;
                }
            }
        }

    }  // namespace visualizer

}  // namespace snakegame
