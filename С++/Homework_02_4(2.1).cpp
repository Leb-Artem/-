#include <iostream>

class Quaternion {
public:
    double x, y, z, w;
};

class Point {
    double x, y, z;
public:

    void move(double X, double Y, double Z) {
        x = X; y = Y; z = Z;
    }
    double getX() const { return x;}
    double getY() const {return y;}
    double getZ() const {return z;}
};

class Balvec : public Point {
    double vx, vy, vz;

    void accelerate(double VX, double VY, double VZ) {
        vx += VX;
        vy += VY;
        vz += VZ;
    };
    double getVx() const { return vx; }
    double getVy() const { return vy; }
    double getVz() const { return vz; }
};

class Object : public Balvec {
    Quaternion q;
public:
    void rotate(const Quaternion& Q) {
        
        double xt, yt, zt;
        xt = q.w * getX() + q.y * getZ() - q.z * getY();
        yt = q.w * getY() - q.x * getZ() + q.z * getX();
        zt = q.w * getZ() + q.x * getY() - q.y * getX();
        move(xt, yt, zt);
    }
    const Quaternion& orientation() const {return q;}
};

int main() {
}