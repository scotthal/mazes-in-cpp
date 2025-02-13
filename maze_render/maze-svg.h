#ifndef _MAZE_SVG_H_
#define _MAZE_SVG_H_

#include <iostream>

#include "maze.h"

namespace maze_render {
void svg(maze::Maze &maze, std::ostream &output);
} // namespace maze_render

#endif // _MAZE_SVG_H_
