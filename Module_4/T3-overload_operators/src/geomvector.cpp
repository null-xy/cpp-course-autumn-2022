#include "geomvector.hpp"

// Implement operators here


GeomVector GeomVector::operator+(const GeomVector& a) {
    return GeomVector(a.x_ + x_, a.y_ + y_, a.z_ + z_);
}

GeomVector operator*(double a, const GeomVector& b) {
    return GeomVector(a * b.x_, a * b.y_, a * b.z_);
}

std::ostream &operator<<(std::ostream& out, const GeomVector& a) {
    out << "(" << a.x_ << ", " << a.y_ << ", " << a.z_ << ")";
    return out;
}

double GeomVector::Length() const {
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}
GeomVector operator/(const GeomVector& b, double a){
    return GeomVector(b.x_/a, b.y_/a, b.z_/a);
}
bool operator>(const GeomVector& a, const GeomVector& b){
    return a.Length()>b.Length();
}
bool operator<(const GeomVector& a, const GeomVector& b){
    return a.Length()<b.Length();
}
bool operator==(const GeomVector& a, const GeomVector& b){
    return a.x_==b.x_ && a.y_==b.y_ && a.z_==b.z_;
}
bool operator!=(const GeomVector& a, const GeomVector& b){
    return a.x_!=b.x_ || a.y_!=b.y_ || a.z_!=b.z_;
}