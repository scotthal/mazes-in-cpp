#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "cell.h"
#include "coordinate.h"
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

static void rect(std::ostream &output, const std::string &fill, int x, int y,
                 int width, int height) {
  output << "<rect ";
  output << "fill=\"" << fill << "\" ";
  output << "x=\"" << x << "\" ";
  output << "y=\"" << y << "\" ";
  output << "width=\"" << width << "\" ";
  output << "height=\"" << height << "\" ";
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

static void render_cell_walls(maze::Maze &maze, int cell_width, int cell_height,
                              const std::string &stroke, int stroke_width,
                              std::ostream &output) {
  const int maze_width_cells = maze.width();
  const int maze_height_cells = maze.height();
  for (int y = 0; y < maze_height_cells; ++y) {
    for (int x = 0; x < maze_width_cells; ++x) {
      render_cell(output, maze.cell_at(x, y), cell_width, cell_height, stroke,
                  stroke_width);
    }
  }
}

static void render_maze_path(std::ostream &output, int cell_width,
                             int cell_height, const std::string &stroke,
                             int stroke_width,
                             std::vector<maze::Coordinate> path) {
  const int cell_half_width = cell_width / 2;
  const int cell_half_height = cell_height / 2;

  auto previous_coordinate = path.front();
  for (auto coordinate : path) {
    if (coordinate == previous_coordinate) {
      continue;
    }
    const int x1 = (previous_coordinate.x * cell_width) + cell_half_width;
    const int y1 = (previous_coordinate.y * cell_height) + cell_half_height;
    const int x2 = (coordinate.x * cell_width) + cell_half_width;
    const int y2 = (coordinate.y * cell_height) + cell_half_height;
    line(output, stroke, stroke_width, x1, y1, x2, y2);
  }
}

void svg(maze::Maze &maze, int cell_width, int cell_height,
         std::ostream &output) {
  const int maze_width_cells = maze.width();
  const int maze_height_cells = maze.height();
  const int maze_width = maze_width_cells * cell_width;
  const int maze_height = maze_height_cells * cell_height;
  svg_element_open(output, maze_width, maze_height);
  background(output, "white");
  render_cell_walls(maze, cell_width, cell_height, "black", 1, output);
  svg_element_close(output);
}

void svg_distance(maze::Maze &maze, int cell_width, int cell_height,
                  std::ostream &output) {
  const int maze_width_cells = maze.width();
  const int maze_height_cells = maze.height();
  const int maze_width = maze_width_cells * cell_width;
  const int maze_height = maze_height_cells * cell_height;
  const int root_x = maze_width_cells / 2;
  const int root_y = maze_height_cells / 2;
  if (!maze.cell_at(root_x, root_y).distances()) {
    maze.calculate_distances(root_x, root_y);
  }
  auto distances = maze.cell_at(root_x, root_y).distances().value();
  int max_distance = *std::max_element(distances.begin(), distances.end());
  double max_distance_double = static_cast<double>(max_distance);

  svg_element_open(output, maze_width, maze_height);
  background(output, "white");
  int overall_index = 0;
  for (int y = 0; y < maze_height_cells; ++y) {
    for (int x = 0; x < maze_width_cells; ++x) {
      double distance = static_cast<double>(distances[overall_index]);
      double intensity = (max_distance - distance) / max_distance_double;
      int dark = static_cast<int>(255 * intensity);
      int bright = static_cast<int>(128 + (127 * intensity));
      std::string fill = "rgb(" + std::to_string(dark) + " " +
                         std::to_string(bright) + " " + std::to_string(dark) +
                         ")";
      rect(output, fill, x * cell_width, y * cell_height, cell_width,
           cell_height);
      render_cell(output, maze.cell_at(x, y), cell_width, cell_height, "black",
                  1);
      ++overall_index;
    }
    svg_element_close(output);
  }
}
} // namespace maze_render
