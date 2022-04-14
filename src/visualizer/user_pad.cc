#include <visualizer/user_pad.h>
#include <ostream>

namespace snakegame {

namespace visualizer {

using glm::vec2;

Userpad::Userpad(const vec2 &top_left_corner,
                 size_t num_pixels_per_side, double sketchpad_size, double brush_radius)
    :
    top_left_corner_(top_left_corner), num_pixels_per_side_(num_pixels_per_side),
    pixel_side_length_(sketchpad_size / num_pixels_per_side), brush_radius_(brush_radius) {
    std::vector<std::pair<float, float>> snake_vec;
    std::pair<float, float> p1;
    p1.first = 0;

    p1.second = 0;
    snake_vec.push_back(p1);

    std::pair<float, float> p2;
    p2.first = 0;
    p2.second = 1;
    snake_vec.push_back(p2);
    snake_.setPosition(snake_vec);

    for (size_t row = 0; row < num_pixels_per_side_; ++row) {
        std::vector<bool> temp_vec;
        for (size_t col = 0; col < num_pixels_per_side_; ++col) {
            temp_vec.push_back(false);
        }
        snake_vec_.push_back(temp_vec);
    }


}


void Userpad::DrawSnake() {
    auto snake_vec = snake_.getPosition();
//    auto temp_snake_board =  snake_.getPosition();
    for(int i = 0; i < snake_vec.size(); i++) {
        snake_vec_[snake_vec[i].first][snake_vec[i].second] = true;
    }
    for (size_t row = 0; row < num_pixels_per_side_; ++row) {
        for (size_t col = 0; col < num_pixels_per_side_; ++col) {
            if (snake_vec_[row][col]) {
                vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
                                                              row * pixel_side_length_);

                vec2 pixel_bottom_right =
                        pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
                ci::gl::color(ci::Color::gray(0.3f));


                ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
                ci::gl::drawSolidRect(pixel_bounding_box);

                ci::gl::color(ci::Color("white"));
                ci::gl::drawStrokedRect(pixel_bounding_box);
            }
        }
    }

}

void Userpad::Draw() {
//    for (size_t row = 0; row < num_pixels_per_side_; ++row) {
//        for (size_t col = 0; col < num_pixels_per_side_; ++col) {
//
//
//            vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
//                                                          row * pixel_side_length_);
//
//            vec2 pixel_bottom_right =
//                    pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
//            ci::gl::color(ci::Color::gray(0.3f));
//
//
//            ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
//            ci::gl::drawSolidRect(pixel_bounding_box);
//
//            ci::gl::color(ci::Color("white"));
//            ci::gl::drawStrokedRect(pixel_bounding_box);
//
//
//        }
//    }
    DrawSnake();
}


void Userpad::Clear() {

}

}  // namespace visualizer

}  // namespace snakegame
