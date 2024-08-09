#include "../polygon.h"
geometry::Polygon::Polygon(const std::vector<Point>& vertices) : vertices_(vertices) {
}
geometry::IShape& geometry::Polygon::Move(const Vector& v) {
  for (Point& vertex : vertices_) {
    vertex.Move(v);
  }
  return *this;
}
bool geometry::Polygon::ContainsPoint(const Point& p) const {
  bool inside = false;
  int n = vertices_.size();
  for (int i = 0, j = n - 1; i < n; j = i++) {
    Point a = vertices_[i];
    Point b = vertices_[j];
    if (Segment(a, b).ContainsPoint(p)) {
      return true;
    }
    int64_t ax = a.GetPosition().GetX();
    int64_t ay = a.GetPosition().GetY();
    int64_t bx = b.GetPosition().GetX();
    int64_t by = b.GetPosition().GetY();
    int64_t px = p.GetPosition().GetX();
    int64_t py = p.GetPosition().GetY();
    if (by == ay) {
      continue;
    }
    bool ycond = ((ay > py) != (by > py));
    bool xcond = (px < (bx - ax) * (py - ay) / (by - ay) + ax);
    if (ycond && xcond) {
      inside = !inside;
    }
  }
  return inside;
}
bool geometry::Polygon::CrossesSegment(const Segment& seg) const {
  for (size_t i = 1; i < vertices_.size(); ++i) {
    Segment t(vertices_[i], vertices_[i - 1]);
    if (seg.CrossesSegment(t)) {
      return true;
    }
  }
  Segment t(vertices_[0], vertices_.back());
  return seg.CrossesSegment(t);
}
std::shared_ptr<geometry::IShape> geometry::Polygon::Clone() const {
  return std::make_shared<Polygon>(vertices_);
}
std::string geometry::Polygon::ToString() const {
  std::string result = "Polygon(";
  for (const Point& vertex : vertices_) {
    result += vertex.ToString() + ", ";
  }
  result.pop_back();
  result.pop_back();
  result += ")";
  return result;
}
