#include <iostream>
#include <string>

#include "cell.h"
#include "maze-svg.h"
#include "maze.h"

namespace maze_render {

static void svg_element_open(std::ostream &output, int width, int height) {
  output << "<svg version=\"1.1\" ";
  output << "width=\"" << width << "\" ";
  output << "height=\"" << height << "\" ";
  output << "xmlns=\"http://www.w3.org/2000/svg\">\n";
}

static void background(std::ostream &output, const std::string &color) {
  output << "<rect ";
  output << "width=\"100%\" height=\"100%\" ";
  output << "fill=\"" << color << "\" ";
  output << "/>\n";
}

static void line(std::ostream &output, const std::string &stroke,
                 int stroke_width, int x1, int y1, int x2, int y2) {
  output << "<line ";
  output << "stroke=\"" << stroke << "\" ";
  output << "stroke-width=\"" << stroke_width << "\" ";
  output << "x1=\"" << x1 << "\" ";
  output << "y1=\"" << y1 << "\" ";
  output << "x2=\"" << x2 << "\" ";
  output << "y2=\"" << y2 << "\" ";
  output << "/>\n";
}

static void render_cell(std::ostream &output, maze::Cell &&cell, int cell_width,
                        int cell_height, const std::string &stroke,
                        int stroke_width) {
  int x_offset = cell.x() * cell_width;
  int y_offset = cell.y() * cell_height;

  if (!cell.links().east) {
    line(output, stroke, stroke_width, x_offset + cell_width,
         y_offset + cell_height, x_offset + cell_width, y_offset);
  }
  if (!cell.links().north) {
    line(output, stroke, stroke_width, x_offset, y_offset + cell_height,
         x_offset + cell_width, y_offset + cell_height);
  }
  if (!cell.links().south) {
    line(output, stroke, stroke_width, x_offset, y_offset,
         x_offset + cell_width, y_offset);
  }
  if (!cell.links().west) {
    line(output, stroke, stroke_width, x_offset, y_offset + cell_height,
         x_offset, y_offset);
  }
}

static void svg_element_close(std::ostream &output) { output << "</svg>\n"; }

void svg(maze::Maze &maze, int cell_width, int cell_height,
         std::ostream &output) {
  const int maze_width_cells = maze.width();
  const int maze_height_cells = maze.height();
  const int maze_width = maze_width_cells * cell_width;
  const int maze_height = maze_height_cells * cell_height;
  svg_element_open(output, maze_width, maze_height);
  background(output, "white");
  for (int y = 0; y < maze_height_cells; ++y) {
    for (int x = 0; x < maze_width_cells; ++x) {
      render_cell(output, maze.cell_at(x, y), cell_width, cell_height, "black",
                  1);
    }
  }
  svg_element_close(output);
}

} // namespace maze_render
