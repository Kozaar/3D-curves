#ifndef CURVES_H_
#define CURVES_H_

struct point3D {
    double x;
    double y;
    double z;
};

class TCurve {
public:
    TCurve(const double &radiusX, const double &radiusY, const double &radiusZ) : rx_(radiusX), ry_(radiusY), rz_(radiusZ) {};
    virtual ~TCurve() = default;

    virtual auto coordinate(double t) -> point3D = 0;
    virtual auto derivate(double t) -> point3D = 0;  //  вектор задается конечной точкой (начальная всегда 0,0,0), поэтому результат тоже point3D

protected:
    double rx_;
    double ry_;
    double rz_;
};

class THelix : public TCurve {
public:
    THelix(const double &radiusX, const double &radiusY, const double &radiusZ);
    ~THelix() = default;

    auto coordinate(double t) -> point3D override;
    auto derivate(double t) -> point3D override;

};

class TEllipce : public THelix {
public:
    TEllipce(const double &radiusX, const double &radiusY);
    ~TEllipce() = default;

    auto coordinate(double t) -> point3D override;
    auto derivate(double t) -> point3D override;
};

class TCircle : public TEllipce {
public:
    TCircle(const double &radius);
    ~TCircle() = default;

    auto coordinate(double t) -> point3D override;
    auto derivate(double t) -> point3D override;
};


#endif  //  CURVES_H_