#pragma once
#include "ishape.h"
#include "point.h"
#include "segment.h"
namespace geometry {
class Circle : public IShape {
  Point center_;
  int64_t radius_;

 public:
  Circle() = default;
  Circle(const Point&, int64_t);
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::shared_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry