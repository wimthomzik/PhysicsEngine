#include "particle.h"
#include <assert.h>

using namespace wengine;

/**
 * The Newton-Euler method assumes that for the duration the velocity and acceleration does not 
 * change. That is just an approximation, because in the real world these values are continuous. 
 */

void Particle::integrate(real duration)
{
    // Ensures that integration step is meaningful
    assert(duration > static_cast<real>(0.0));

    // Update position
    m_position.addScaledVector(m_velocity, duration);
    m_position.addScaledVector(m_acceleration, duration * duration * static_cast<real>(0.5));

    // Calculate acceleration using the accumulated force
    Vector3 resultingAcc = m_acceleration;
    resultingAcc.addScaledVector(m_forceAccum, m_inverseMass);

    // Update linear velocity from the acceleration
    m_velocity.addScaledVector(resultingAcc, duration);

    // Impose drag
    m_velocity *= real_pow(m_damping, duration);
}
