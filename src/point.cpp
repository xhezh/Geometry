#include "../point.h"
#include "../segment.h"
geometry::Point::Point(int64_t x, int64_t y) : position_(x, y) {
}
geometry::Point::Point(Vector v) : position_(v.GetX(), v.GetY()) {
}
geometry::Vector geometry::Point::GetPosition() const {
  return position_;
}
geometry::IShape& geometry::Point::Move(const Vector& v) {
  position_ = position_ + v;
  return *this;
}
bool geometry::Point::ContainsPoint(const Point& p) const {
  return position_ == p.position_;
}

bool geometry::Point::CrossesSegment(const Segment& seg) const {
  Vector ap(position_.GetX() - seg.GetStart().GetPosition().GetX(),
            position_.GetY() - seg.GetStart().GetPosition().GetY());
  Vector pb(position_.GetX() - seg.GetEnd().GetPosition().GetX(), position_.GetY() - seg.GetEnd().GetPosition().GetY());
  Vector ab(seg.GetEnd().GetPosition().GetX() - seg.GetStart().GetPosition().GetX(),
            seg.GetEnd().GetPosition().GetY() - seg.GetStart().GetPosition().GetY());
  double cross = ap.GetX() * pb.GetY() - ap.GetY() * pb.GetX();
  if (std::abs(cross) > 1e-10) {
    return false;
  }
  double AP_AB = ap.GetX() * ab.GetX() + ap.GetY() * ab.GetY();
  double PB_AB = pb.GetX() * ab.GetX() + pb.GetY() * ab.GetY();
  return AP_AB >= 0 && PB_AB <= 0;
}
std::shared_ptr<geometry::IShape> geometry::Point::Clone() const {
  return std::make_shared<Point>(position_.GetX(), position_.GetY());
}
std::string geometry::Point::ToString() const {
  return "Point(" + std::to_string(position_.GetX()) + ", " + std::to_string(position_.GetY()) + ")";
}
geometry::Vector geometry::Point::operator-(const Point& p) const {
  return Vector{position_.GetX() - p.position_.GetX(), position_.GetY() - p.position_.GetY()};
}
