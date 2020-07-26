struct point {
    ld x, y;
    point() {};
    point(ld x, ld y):
            x(x), y(y)
    {}
};
 
point operator+(point p1, point p2) {
    return point(p1.x + p2.x, p1.y + p2.y);
}
 
point operator-(point p) {
    return point(-p.x, -p.y);
}
 
struct gvector {
    ld x, y;
    gvector() {};
    gvector(point a, point b):
            x(b.x - a.x), y(b.y - a.y)
    {}
    gvector(ld x, ld y):
            x(x), y(y)
    {}
    ld len() {
        return sqrt(x * x + y * y);
    }
};
 
ld operator%(gvector v1, gvector v2) {
    return v1.x * v2.y - v2.x * v1.y;
}
 
ld operator*(gvector v1, gvector v2) {
    return v1.x * v2.x + v1.y * v2.y;
}
 
gvector operator/(gvector v, ld k) {
    return gvector(v.x / k, v.y / k);
}
 
gvector operator/=(gvector v, ld k) {
    return gvector(v.x / k, v.y / k);
}
 
void normalize(gvector &a) {
    ld s = a.len();
    a /= s;
}
 
gvector operator+(gvector v1, gvector v2) {
    return gvector(v1.x + v2.x, v1.y + v2.y);
}
 
gvector operator-(gvector v) {
    return gvector(-v.x, -v.y);
}
 
gvector operator-(gvector v1, gvector v2) {
    return gvector(v1.x - v2.x, v1.y - v2.y);
}
 
ld ang_bet_vectors(gvector v1, gvector v2) {
    return atan2(v2 % v1, v2 * v1);
}
 
struct gline {
    ld a, b, c;
    gline () {}
    gline(point a, point b):
            a(b.y - a.y), b(a.x - b.x), c(-a.x * b.y + b.x * a.y)
    {}
};
 
ld dist_to_ln(point p, gline l) {
    return abs(p.x * l.a + p.y * l.b + l.c) / sqrt(l.a * l.a + l.b * l.b);
}
 
istream &operator>>(istream &is, point &a) {
    is >> a.x >> a.y;
    return is;
}
 
ostream &operator<<(ostream &os, const point &a) {
    os << a.x << ' ' << a.y << endl;
    return os;
}
 
istream &operator>>(istream &is, gvector &a) {
    is >> a.x >> a.y;
    return is;
}
 
ostream &operator<<(ostream &os, const gvector &a) {
    os << a.x << ' ' << a.y << '\n';
    return os;
}