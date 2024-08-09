#pragma once
#include <vector>

#include "ishape.h"
#include "point.h"
#include "segment.h"
namespace geometry {
class Polygon : public IShape {
  std::vector<Point> vertices_;

 public:
  Polygon() = default;
  explicit Polygon(const std::vector<Point>&);
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::shared_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry