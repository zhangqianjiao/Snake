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

}

void Userpad::Draw() {

}


void Userpad::Clear() {

}

}  // namespace visualizer

}  // namespace snakegame
