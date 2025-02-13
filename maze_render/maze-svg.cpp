#include <iostream>

#include "maze-svg.h"
#include "maze.h"

namespace maze_render {

static void svg_element_open(std::ostream &output, int width, int height) {
  output << "<svg version=\"1.1\" ";
  output << "width=\"" << width << "\" ";
  output << "height=\"" << height << "\" ";
  output << "xmlns=\"http://www.w3.org/2000/svg\">\n";
}

static void svg_element_close(std::ostream &output) { output << "</svg>\n"; }

void svg(maze::Maze &maze, int cell_width, int cell_height,
         std::ostream &output) {
  const int maze_width = cell_width * maze.width();
  const int maze_height = cell_height * maze.height();
  svg_element_open(output, maze_width, maze_height);
  svg_element_close(output);
}

} // namespace maze_render
