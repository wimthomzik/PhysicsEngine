#ifndef CORE_H
#define CORE_H

#include "precision.h"
#include <math.h>

namespace wengine {
    class Vector3
    {
    public:
        Vector3() : m_x(0), m_y(0), m_z(0) {}
        Vector3(const real x, const real y, const real z) : m_x(x), m_y(y), m_z(z) {}

        void invert()
        {
            m_x = -m_x;
            m_z = -m_z;
            m_y = -m_y;
        }

        real magnitude() const
        {
            return real_sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
        }

        real squareMagnitude() const
        {
            return m_x*m_x + m_y*m_y + m_z*m_z;
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
            m_x *= s;
            m_y *= s;
            m_z *= s;
        }

        Vector3 operator*(const real s) const
        {
            return Vector3(m_x*s, m_y*s, m_z*s);
        }

        void operator+=(const Vector3 &v)
        {
            m_x += v.getX();
            m_z += v.getZ();
            m_y += v.getY();
        }

        Vector3 operator+(const Vector3 &v) const
        {
            return Vector3(m_x+v.getX(), m_y+v.getY(), m_z+v.getZ());
        }

        void operator-=(const Vector3 &v)
        {
            m_x -= v.getX();
            m_z -= v.getZ();
            m_y -= v.getY();
        }

        Vector3 operator-(const Vector3 &v) const
        {
            return Vector3(m_x-v.getX(), m_y-v.getY(), m_z-v.getZ());
        }

        void addScaledVector(const Vector3 &v, real s)
        {
            m_x = v.getX() * s;
            m_y = v.getY() * s;
            m_z = v.getZ() * s;
        }

        Vector3 vectorProduct(const Vector3 &v) const
        {
            return Vector3(m_y*v.getZ() - m_z*v.getY(), m_z*v.getX() - m_x*v.getZ(), m_x*v.getY() - m_y*v.getX());
        }

        void vectorProduct(const Vector3 &v)
        {
            m_x = m_y*v.getZ() - m_z*v.getY();
            m_y = m_z*v.getX() - m_x*v.getZ();
            m_z = m_x*v.getY() - m_y*v.getX();
        }

       real scalarProduct(const Vector3 &v) const
       {
           return m_x*v.getX() + m_y*v.getY() + m_z*v.getZ();
       }

       real operator*(const Vector3 &v) const
       {
           return m_x*v.getX() + m_y*v.getY() + m_z*v.getZ();
       }

       real getX() const { return m_x; }

       real getY() const { return m_y; }

       real getZ() const { return m_z; }

       void setX(const real s) { m_x = s; }

       void setY(const real s) { m_y = s; }

       void setZ(const real s) { m_z = s; }


    private:
        real m_x;
        real m_y;
        real m_z;
    };
}

#endif // CORE_H
