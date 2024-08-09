#pragma once
#include "ishape.h"
#include "point.h"
namespace geometry {
class Segment : public IShape {
  Point start_;
  Point end_;

 public:
  Segment() = default;
  Segment(const Point&, const Point&);
  Point GetStart() const;
  Point GetEnd() const;
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::shared_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry