#pragma once
#include <string>
namespace geometry {
class Vector {
  int64_t x_;
  int64_t y_;

 public:
  Vector() = default;
  Vector(int64_t, int64_t);
  int64_t GetX() const;
  int64_t GetY() const;
  std::string ToString() const;
  Vector operator+() const;
  Vector operator-() const;
  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
  Vector operator*(int64_t) const;
  Vector operator/(int64_t) const;
  Vector& operator+=(const Vector&);
  Vector& operator-=(const Vector&);
  Vector& operator*=(int64_t);
  Vector& operator/=(int64_t);
  int64_t operator^(const Vector&) const;
  int64_t operator*(const Vector&)const;
  bool operator==(const Vector&) const;
  bool operator!=(const Vector&) const;
};
}  // namespace geometry