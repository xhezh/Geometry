#include "../segment.h"
#include <algorithm>
geometry::Segment::Segment(const Point& start, const Point& end) : start_(start), end_(end) {
}
geometry::Point geometry::Segment::GetStart() const {
  return start_;
}
geometry::Point geometry::Segment::GetEnd() const {
  return end_;
}
geometry::IShape& geometry::Segment::Move(const Vector& v) {
  start_.Move(v);
  end_.Move(v);
  return *this;
}
bool geometry::Segment::ContainsPoint(const Point& p) const {
  Vector ap = p - start_;
  Vector pb = end_ - p;
  int64_t cross = ap ^ pb;
  int64_t dot = ap * pb;
  return cross == 0 && dot >= 0;
}
bool geometry::Segment::CrossesSegment(const Segment& seg) const {
  const Point& a = start_;
  const Point& b = end_;
  const Point& c = seg.GetStart();
  const Point& d = seg.GetEnd();
  Vector ab = b - a;
  Vector cd = d - c;
  Vector ac = c - a;
  Vector ad = d - a;
  Vector ca = a - c;
  Vector cb = b - c;
  int64_t ab_ac = ab ^ ac;
  int64_t ab_ad = ab ^ ad;
  int64_t cd_ca = cd ^ ca;
  int64_t cd_cb = cd ^ cb;
  if (ab_ac * ab_ad < 0 && cd_ca * cd_cb < 0) {
    return true;
  }
  return ContainsPoint(c) || ContainsPoint(d) || seg.ContainsPoint(a) || seg.ContainsPoint(b);
}
std::shared_ptr<geometry::IShape> geometry::Segment::Clone() const {
  return std::make_shared<Segment>(start_, end_);
}
std::string geometry::Segment::ToString() const {
  return "Segment(Point(" + std::to_string(start_.GetPosition().GetX()) + ", " +
         std::to_string(start_.GetPosition().GetY()) + "), Point(" + std::to_string(end_.GetPosition().GetX()) + ", " +
         std::to_string(end_.GetPosition().GetY()) + "))";
}
