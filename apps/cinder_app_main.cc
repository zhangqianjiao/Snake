#include <visualizer/game_board.h>

using snakegame::visualizer::SnakeGame;

void prepareSettings(SnakeGame::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(SnakeGame, ci::app::RendererGl, prepareSettings);
