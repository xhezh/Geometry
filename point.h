#pragma once
#include "ishape.h"
namespace geometry {
class Point : public IShape {
  Vector position_;

 public:
  Point() = default;
  Point(int64_t, int64_t);
  explicit Point(Vector v);
  Vector GetPosition() const;
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::shared_ptr<IShape> Clone() const override;
  std::string ToString() const override;
  Vector operator-(const Point&) const;
};
}  // namespace geometry