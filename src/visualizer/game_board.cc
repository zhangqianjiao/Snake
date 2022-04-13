#include <visualizer/game_board.h>

namespace snakegame {

namespace visualizer {

SnakeGame::SnakeGame()
    : sketchpad_(glm::vec2(kMargin, kMargin), kImageDimension,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

}

void SnakeGame::draw() {
  ci::Color8u background_color(255, 246, 148);  // light yellow
  ci::gl::clear(background_color);

  sketchpad_.Draw();

  ci::gl::drawStringCentered(
      "SNAKE",
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));

}

void SnakeGame::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RETURN: {

    }
    case 8:

      break;
  }
}

}  // namespace visualizer

}  // namespace snakegame
