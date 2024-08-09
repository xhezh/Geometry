#include "../line.h"
geometry::Line::Line(const Point& p1, const Point& p2) {
  a_ = p2.GetPosition().GetY() - p1.GetPosition().GetY();
  b_ = p1.GetPosition().GetX() - p2.GetPosition().GetX();
  c_ = -(a_ * p1.GetPosition().GetX() + b_ * p1.GetPosition().GetY());
}
geometry::Line::Line(int64_t a, int64_t b, int64_t c) : a_(a), b_(b), c_(c) {
}
geometry::IShape& geometry::Line::Move(const geometry::Vector& v) {
  c_ -= (a_ * v.GetX() + b_ * v.GetY());
  return *this;
}
bool geometry::Line::ContainsPoint(const Point& p) const {
  return a_ * p.GetPosition().GetX() + b_ * p.GetPosition().GetY() + c_ == 0;
}
bool geometry::Line::CrossesSegment(const Segment& seg) const {
  int64_t sign1 = a_ * seg.GetStart().GetPosition().GetX() + b_ * seg.GetStart().GetPosition().GetY() + c_;
  int64_t sign2 = a_ * seg.GetEnd().GetPosition().GetX() + b_ * seg.GetEnd().GetPosition().GetY() + c_;
  return sign1 * sign2 <= 0;
}
std::shared_ptr<geometry::IShape> geometry::Line::Clone() const {
  return std::make_shared<Line>(a_, b_, c_);
}
std::string geometry::Line::ToString() const {
  return "Line(" + std::to_string(a_) + ", " + std::to_string(b_) + ", " + std::to_string(c_) + ")";
}
