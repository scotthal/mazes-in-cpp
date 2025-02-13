#ifndef _COORDINATE_H_
#define _COORDINATE_H_

namespace maze {

struct Coordinate {
  int x;
  int y;

  bool operator==(Coordinate const& rhs) const;
};

} // namespace maze

#endif // _COORDINATE_H_
