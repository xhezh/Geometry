#include "../vector.h"
geometry::Vector::Vector(int64_t x, int64_t y) : x_(x), y_(y) {
}
int64_t geometry::Vector::GetX() const {
  return x_;
}
int64_t geometry::Vector::GetY() const {
  return y_;
}
std::string geometry::Vector::ToString() const {
  return "Vector(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}
geometry::Vector geometry::Vector::operator+() const {
  return *this;
}
geometry::Vector geometry::Vector::operator-() const {
  return Vector{-x_, -y_};
}
geometry::Vector geometry::Vector::operator+(const Vector& other) const {
  return Vector{x_ + other.x_, y_ + other.y_};
}
geometry::Vector geometry::Vector::operator-(const Vector& other) const {
  return Vector{x_ - other.x_, y_ - other.y_};
}
geometry::Vector geometry::Vector::operator*(int64_t scalar) const {
  return Vector{x_ * scalar, y_ * scalar};
}
geometry::Vector geometry::Vector::operator/(int64_t scalar) const {
  return Vector{x_ / scalar, y_ / scalar};
}
geometry::Vector& geometry::Vector::operator+=(const Vector& other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}
geometry::Vector& geometry::Vector::operator-=(const Vector& other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}
geometry::Vector& geometry::Vector::operator*=(int64_t scalar) {
  x_ *= scalar;
  y_ *= scalar;
  return *this;
}
geometry::Vector& geometry::Vector::operator/=(int64_t scalar) {
  x_ /= scalar;
  y_ /= scalar;
  return *this;
}
int64_t geometry::Vector::operator^(const Vector& other) const {
  return x_ * other.y_ - y_ * other.x_;
}
int64_t geometry::Vector::operator*(const Vector& other) const {
  return x_ * other.x_ + y_ * other.y_;
}
bool geometry::Vector::operator==(const Vector& other) const {
  return x_ == other.x_ && y_ == other.y_;
}
bool geometry::Vector::operator!=(const Vector& other) const {
  return !(*this == other);
}
