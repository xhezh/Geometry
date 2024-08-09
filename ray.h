#pragma once
#include "ishape.h"
#include "point.h"
#include "segment.h"
namespace geometry {
class Ray : public IShape {
  Point origin_;
  Point direction_;

 public:
  Ray() = default;
  Ray(const Point&, const Point&);
  Ray(const Point&, const Vector&);
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::shared_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry