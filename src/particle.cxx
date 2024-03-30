#include "particle.h"   // Include the Particle class definition.
#include <cmath>        // For mathematical operations.

// Constructor: Initializes a particle.
Particle::Particle(ParticleType type, double m, double q, double lt, const std::vector<DecayMode>& dm, double x, double y, double z)
    : type(type), mass(m), charge(q), lifetime(lt), decayModes(dm) {
    position[0] = x;
    position[1] = y;
    position[2] = z;
    velocity[0] = 0.0;
    velocity[1] = 0.0;
    velocity[2] = 0.0;
    resetForce();
}

// Resets the net force on the particle to zero.
void Particle::resetForce() {
    force[0] = 0.0;
    force[1] = 0.0;
    force[2] = 0.0;
}

// Calculates and adds the electromagnetic force exerted by another particle.
// This is based on Coulomb's law, where the force magnitude is proportional to the product of the charges
// and inversely proportional to the square of the distance between the particles.
void Particle::addForce(const Particle& other) {
    double k_e = 8.9875517873681764e9; // Coulomb's constant in N m²/C²
    double dx = other.position[0] - position[0];
    double dy = other.position[1] - position[1];
    double dz = other.position[2] - position[2];
    double distanceSquared = dx*dx + dy*dy + dz*dz + 1e-10; // Add a small term to prevent division by zero.
    double forceMagnitude = k_e * charge * other.charge / distanceSquared;
    force[0] += forceMagnitude * dx / sqrt(distanceSquared);
    force[1] += forceMagnitude * dy / sqrt(distanceSquared);
    force[2] += forceMagnitude * dz / sqrt(distanceSquared);
}

// Updates the particle's state based on the net force acting on it and the elapsed time.
void Particle::update(double deltaTime) {
    // Update velocity based on force
    velocity[0] += force[0] * deltaTime / mass;
    velocity[1] += force[1] * deltaTime / mass;
    velocity[2] += force[2] * deltaTime / mass;
    
    // Update position based on velocity
    position[0] += velocity[0] * deltaTime;
    position[1] += velocity[1] * deltaTime;
    position[2] += velocity[2] * deltaTime;
}