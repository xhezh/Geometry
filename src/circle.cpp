#include "../circle.h"
#include <cmath>
geometry::Circle::Circle(const Point& center, int64_t radius) : center_(center), radius_(radius) {
}
geometry::IShape& geometry::Circle::Move(const Vector& v) {
  center_.Move(v);
  return *this;
}
bool geometry::Circle::ContainsPoint(const Point& p) const {
  Vector diff = p - center_;
  return diff.GetX() * diff.GetX() + diff.GetY() * diff.GetY() <= radius_ * radius_;
}
bool geometry::Circle::CrossesSegment(const Segment& seg) const {
  Vector diff1 = seg.GetEnd() - center_;
  if (diff1.GetX() * diff1.GetX() + diff1.GetY() * diff1.GetY() == radius_ * radius_) {
    return true;
  }
  Vector diff2 = seg.GetStart() - center_;
  if (diff2.GetX() * diff2.GetX() + diff2.GetY() * diff2.GetY() == radius_ * radius_) {
    return true;
  }
  if (ContainsPoint(seg.GetStart()) && ContainsPoint(seg.GetEnd())) {
    return false;
  }
  double x1 = seg.GetStart().GetPosition().GetX();
  double y1 = seg.GetStart().GetPosition().GetY();
  double x2 = seg.GetEnd().GetPosition().GetX();
  double y2 = seg.GetEnd().GetPosition().GetY();
  double xc = center_.GetPosition().GetX();
  double yc = center_.GetPosition().GetY();
  x1 -= xc;
  y1 -= yc;
  x2 -= xc;
  y2 -= yc;
  double dx = x2 - x1;
  double dy = y2 - y1;
  double a = dx * dx + dy * dy;
  double b = 2. * (x1 * dx + y1 * dy);
  double c = x1 * x1 + y1 * y1 - radius_ * radius_;
  if (-b < 0) {
    return c <= 0;
  }
  if (-b < (2. * a)) {
    return (4. * a * c - b * b) <= 0;
  }
  return (a + b + c) <= 0;
}
std::shared_ptr<geometry::IShape> geometry::Circle::Clone() const {
  return std::make_shared<Circle>(center_, radius_);
}
std::string geometry::Circle::ToString() const {
  return "Circle(" + center_.ToString() + ", " + std::to_string(radius_) + ")";
}
