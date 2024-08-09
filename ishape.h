#pragma once
#include <memory>

#include "vector.h"
namespace geometry {
class Point;
class Segment;
class IShape {
 public:
  virtual ~IShape() = default;
  virtual IShape& Move(const Vector&) = 0;
  virtual bool ContainsPoint(const Point&) const = 0;
  virtual bool CrossesSegment(const Segment&) const = 0;
  virtual std::shared_ptr<IShape> Clone() const = 0;
  virtual std::string ToString() const = 0;
};
}  // namespace geometry