#pragma once
#include "ishape.h"
#include "point.h"
#include "segment.h"
namespace geometry {
class Line : public IShape {
  int64_t a_, b_, c_;

 public:
  Line() = default;
  Line(const Point&, const Point&);
  Line(int64_t a, int64_t b, int64_t c);
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::shared_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry