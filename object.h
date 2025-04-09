#ifndef OBJECT_H
#define OBJECT_H

#include "core.h"
#include "precision.h"

using namespace wengine;

class Object
{
public:
    Object();
    Object(const Vector3 &p, const Vector3 &v, const Vector3 &a, const real iM, const real d = static_cast<real>(0.995))
        : m_position(p), m_velocity(v), m_acceleration(a), m_inverseMass(iM), m_damping(d) {}

    /**
     * Integrates the object forward in time by the given duration
     * using Newton-Euler integration method, which is a lineare approximation.
     */
    void integrate(real duration);

    void setPosition(const Vector3 &p) { m_position = p; }

    Vector3 getPosition() const { return m_position; }

    void setVelocity(const Vector3 &v) { m_velocity = v; }

    Vector3 getVelocity() const { return m_velocity; }

    void setAcceleration(const Vector3 &a) { m_acceleration = a; }

    Vector3 getAcceleration() const { return m_acceleration; }

    void setInverseMass(const real iM) { m_inverseMass = iM; }

    real getInverseMass() const { return m_inverseMass; }

    void setDamping(const real d) { m_damping = d; }

    real getDamping() const { return m_damping; }

private:
    /**
     * Linear position in world space
     */
    Vector3 m_position;

    /**
     * Linear velocity in world space
     */
    Vector3 m_velocity;

    /**
     * Acceleration of the object.
     * This value can be used to set acceleration due to gravity or any other constant acceleration
     */
    Vector3 m_acceleration;

    Vector3 m_forceAccum;

    /**
     * Inverse mass of object.
     * It is more useful to hold inverse mass, because integration is simpler and because
     * it is easier to set infinitv mass (immovable objects) and impossible to set zero mass (division by zero error).
     */
    real m_inverseMass;

    /**
     * Amount of damping applied to linear motion.
     * Required to remove energy added through numerical instability of the integrator
     */
    real m_damping;
};

#endif // OBJECT_H
