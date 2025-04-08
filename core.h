#ifndef CORE_H
#define CORE_H

#include "precision.h"
#include <math.h>

namespace wengine {
    class Vector3
    {
    public:
        Vector3() : x(0), y(0), z(0) {}
        Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

        void invert()
        {
            x = -x;
            z = -z;
            y = -y;
        }

        real magnitude() const
        {
            return real_sqrt(x*x + y*y + z*z);
        }

        real squareMagnitude() const
        {
            return x*x + y*y + z*z;
        }

        void normalize()
        {
            real l = magnitude();
            if (l > 0)
            {
                (*this) *= (static_cast<real>(1)) / l;
            }
        }

        void operator*=(const real s)
        {
            x *= s;
            y *= s;
            z *= s;
        }

        Vector3 operator*(const real s) const
        {
            return Vector3(x*s, y*s, z*s);
        }

        void operator+=(const Vector3 &v)
        {
            x += v.x;
            z += v.z;
            y += v.y;
        }

        Vector3 operator+(const Vector3 &v) const
        {
            return Vector3(x+v.x, y+v.y, z+v.z);
        }

        void operator-=(const Vector3 &v)
        {
            x -= v.x;
            z -= v.z;
            y -= v.y;
        }

        Vector3 operator-(const Vector3 &v) const
        {
            return Vector3(x-v.x, y-v.y, z-v.z);
        }

        void addScaledVector(const Vector3 &v, real s)
        {
            x = v.x * s;
            y = v.y * s;
            z = v.z * s;
        }

        Vector3 vectorProduct(const Vector3 &v) const
        {
            return Vector3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
        }

        void vectorProduct(const Vector3 &v)
        {
            x = y*v.z - z*v.y;
            y = z*v.x - x*v.z;
            z = x*v.y - y*v.x;
        }

       real scalarProduct(const Vector3 &v) const
       {
           return x*v.x + y*v.y + z*v.z;
       }

       real operator*(const Vector3 &v) const
       {
           return x*v.x + y*v.y + z*v.z;
       }

       real getX() const
       {
           return x;
       }

       real getY() const
       {
           return y;
       }

       real getZ() const
       {
           return z;
       }

       void setX(const real s)
       {
           x = s;
       }

       void setY(const real s)
       {
           y = s;
       }

       void setZ(const real s)
       {
           z = s;
       }


    private:
        real x;
        real y;
        real z;
    };
}

#endif // CORE_H
