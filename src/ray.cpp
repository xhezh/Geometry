#include "../ray.h"
geometry::Ray::Ray(const Point& start, const Point& end) : origin_(start), direction_(Vector(end - start)) {
}
geometry::Ray::Ray(const Point& start, const Vector& v) : origin_(start), direction_(v) {
}
geometry::IShape& geometry::Ray::Move(const Vector& v) {
  origin_.Move(v);
  return *this;
}
bool geometry::Ray::ContainsPoint(const Point& p) const {
  int64_t x_p = p.GetPosition().GetX();
  int64_t y_p = p.GetPosition().GetY();
  int64_t x_o = origin_.GetPosition().GetX();
  int64_t y_o = origin_.GetPosition().GetY();
  int64_t x_d = direction_.GetPosition().GetX();
  x_d += origin_.GetPosition().GetX();
  int64_t y_d = direction_.GetPosition().GetY();
  y_d += origin_.GetPosition().GetY();
  if (((x_p - x_o) * (y_d - y_o) == (x_d - x_o) * (y_p - y_o)) && (x_p - x_o) * (x_d - x_o) >= 0 &&
      ((y_d - y_o) * (y_p - y_o) >= 0)) {
    return true;
  }
  return false;
}
bool geometry::Ray::CrossesSegment(const Segment& seg) const {
  Vector ab = seg.GetEnd() - seg.GetStart();
  Vector ao = origin_.GetPosition() - seg.GetStart().GetPosition();
  int64_t num = ao ^ ab;
  int64_t denom = direction_.GetPosition() ^ ab;
  if (denom == 0) {
    return num == 0;
  }
  double t = -static_cast<double>(num) / denom;
  double s = static_cast<double>(ao ^ direction_.GetPosition()) / denom;
  return (t >= 0 && s >= 0 && s <= 1) || ContainsPoint(seg.GetStart()) || ContainsPoint(seg.GetEnd());
}
std::shared_ptr<geometry::IShape> geometry::Ray::Clone() const {
  return std::make_shared<Ray>(origin_, direction_.GetPosition());
}
std::string geometry::Ray::ToString() const {
  return "Ray(" + origin_.ToString() + ", Vector(" + std::to_string(direction_.GetPosition().GetX()) + ", " +
         std::to_string(direction_.GetPosition().GetY()) + "))";
}
