#include "particle.h"   // Include the Particle class definition.
#include <cmath>        // For mathematical operations.

// Constructor: Initializes a particle.
Particle::Particle(ParticleType type, double m, double q, double lt, double x, double y, double z)
    : type(type), mass(m), charge(q), lifetime(lt) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
    this->velocity[0] = 0.0;
    this->velocity[1] = 0.0;
    this->velocity[2] = 0.0;
    resetForce();
    if (isUnstable()) {
        setDecayModes();
    }
    else {
        decayModes = {};
    }
}

// Resets the net force on the particle to zero.
void Particle::resetForce() {
    this->force[0] = 0.0;
    this->force[1] = 0.0;
    this->force[2] = 0.0;
}

// Sets two possible decay modes for each particle type. This will be called if the particle is unstable.
// In a true particle physics context, decay modes are quite varied and dependent on many factors.
// For simplicity, I will choose representative decay modes.
void Particle::setDecayModes() {
    if (type == ParticleType::PION_POSITIVE) {
        decayModes = {
            {ParticleType::KAON_POSITIVE, 0.2},
            {ParticleType::PROTON, 0.1}
        };
    } else if (type == ParticleType::PION_NEGATIVE) {
        decayModes = {
            {ParticleType::KAON_NEGATIVE, 0.2},
            {ParticleType::PROTON, 0.1}
        };
    } else if (type == ParticleType::PION_NEUTRAL) {
        decayModes = {
            {ParticleType::PION_POSITIVE, 0.5}, // In reality, neutral pions decay into photons, but this is a simplification.
            {ParticleType::PION_NEGATIVE, 0.5}
        };
    } else if (type == ParticleType::KAON_POSITIVE) {
        decayModes = {
            {ParticleType::PION_POSITIVE, 0.63},
            {ParticleType::PION_NEUTRAL, 0.21}
        };
    } else if (type == ParticleType::KAON_NEGATIVE) {
        decayModes = {
            {ParticleType::PION_NEGATIVE, 0.63},
            {ParticleType::PION_NEUTRAL, 0.21}
        };
    } else if (type == ParticleType::PROTON) {
        decayModes = {
            // Protons are stable for all practical purposes in this context.
            // So, they do not have decay modes in this simplified simulation.
        };
    }
}

// Calculates and adds the electromagnetic force exerted by another particle.
// This is based on Coulomb's law, where the force magnitude is proportional to the product of the charges
// and inversely proportional to the square of the distance between the particles.
void Particle::addForce(Particle& other) {
    const double k_e = 8.9875517873681764e9; // Coulomb's constant in N m^2/C^2
    double dx = other.position[0] - this->position[0];
    double dy = other.position[1] - this->position[1];
    double dz = other.position[2] - this->position[2];
    double distanceSquared = dx*dx + dy*dy + dz*dz + 1e-10; // Add a small term to prevent division by zero when calculating forceMagnitude.
    double distance = sqrt(distanceSquared);
    double forceMagnitude = k_e * this->charge * other.charge / distanceSquared;

    // Calculate force components
    double fx = forceMagnitude * dx / distance;
    double fy = forceMagnitude * dy / distance;
    double fz = forceMagnitude * dz / distance;

    // Apply force components to this particle.
    this->force[0] += fx;
    this->force[1] += fy;
    this->force[2] += fz;

    // Apply equal and opposite force to the other particle.
    other.force[0] -= fx;
    other.force[1] -= fy;
    other.force[2] -= fz;
}

// Updates the particle's state based on the net force acting on it and the elapsed time.
void Particle::update(double deltaTime) {
    // Update velocity based on force: F = m * a, or a = F / m
    this->velocity[0] += (this->force[0] / this->mass) * deltaTime ;
    this->velocity[1] += (this->force[1] / this->mass) * deltaTime ;
    this->velocity[2] += (this->force[2] / this->mass) * deltaTime ;
    
    // Update position based on velocity
    this->position[0] += this->velocity[0] * deltaTime;
    this->position[1] += this->velocity[1] * deltaTime;
    this->position[2] += this->velocity[2] * deltaTime;

    // Reset the force after updating to prepare for the next simulation step.
    resetForce();
}