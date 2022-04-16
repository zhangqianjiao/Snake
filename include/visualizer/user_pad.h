#pragma once
#include "iostream"
#include <cinder/app/App.h>
#include <glm/vec2.hpp>
#include <cstddef>
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "../core/snake.h"

namespace snakegame {

namespace visualizer {

/**
 * A sketchpad which will be displayed in the Cinder application and respond to
 * mouse events. Furthermore, the sketchpad can output its current state in the
 * same format as the Naive Bayes image data files.
 */
class Userpad {
 public:

  /**
   * Creates a sketchpad.
   * (Note that sketchpad pixels are larger than screen pixels.)
   *
   * @param top_left_corner     the screen coordinates of the top left corner of
   *                            the sketchpad
   * @param num_pixels_per_side the number of sketchpad pixels in one row/column
   *                            of the sketchpad
   * @param sketchpad_size      the side length of the sketchpad, measured in
   *                            screen pixels
   * @param brush_radius        the maximum distance (measured in sketchpad
   *                            pixels) from the brush that will be shaded
   */
  Userpad(const cinder::vec2 &top_left_corner,
          size_t num_pixels_per_side, double sketchpad_size, double brush_radius = 1.5)
      ;

  /**
   * Displays the current state of the sketchpad in the Cinder application.
   */
  void Draw();

    /**
   * Displays the current state of the sketchpad in the Cinder application.
   */
    void DrawSnake();

  /**
   * Set all of the sketchpad pixels to an unshaded state.
   */
    void Clear();

    Snake &getSnake();

    void setSnake(Snake &snake);


private:
  glm::vec2 top_left_corner_;

  size_t num_pixels_per_side_;

  /** Number of screen pixels in the width/height of one sketchpad pixel */
  double pixel_side_length_;

  double brush_radius_;

  Snake snake_;

  /**
   * record whether the position has part of snake
   */
    std::vector<std::vector<bool>> snake_vec_;

};

}  // namespace visualizer

}  // namespace snakegame
