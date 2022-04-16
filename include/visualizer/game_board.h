#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "user_pad.h"

namespace snakegame {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class SnakeGame : public ci::app::App {
 public:
  SnakeGame();

  void draw() override;

  void keyDown(ci::app::KeyEvent event) override;

  // TODO: Delete this comment. Feel free to play around with these variables
  // provided that you can see the entire UI on your screen.
  const double kWindowSize = 875;
  const double kMargin = 100;
  const size_t kImageDimension = 28;

    /**
     * handle the key down process
     */
    void KeyDown();

    /**
     * handle the key up process
     */
    void KeyUp();
    /**
     * handle the key left process
     */
    void KeyLeft();
    /**
     * handle the key right process
     */
    void KeyRight();

 private:
  Userpad Userpad_;
};

}  // namespace visualizer

}  // namespace snakegame
