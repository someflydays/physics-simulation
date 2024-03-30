#include "particle.h"   // Include the Particle class definition.
#include "simulation.h" // Include the Simulation class definition.

// Simulates a collision that generates a set number of particles.
void Simulation::simulateCollision() {
    // This is a simplified approach; actual collisions would generate particles based on more complex dynamics.

    // Parameters for particles generated in a typical Pb-Pb collision.
    double pionMass = 0.13957; // in electronvolts (GeV/c^2)
    double kaonMass = 0.49367; // in electronvolts (GeV/c^2)
    double protonMass = 0.93827; // in electronvolts (GeV/c^2)

    // In this simulation, all particles are produced with random initial velocities.
    std::uniform_real_distribution<double> velocityDist(-0.1, 0.1);

    // Create particles - creating one of each type, for demonstration.
    createParticle(ParticleType::PION_POSITIVE, pionMass, +1, 0, {}, 0, 0, 0); // Stable in this context
    createParticle(ParticleType::KAON_POSITIVE, kaonMass, +1, 1.24e-8, {}, 0, 0, 0); // Example lifetime
    createParticle(ParticleType::PROTON, protonMass, +1, 0, {}, 0, 0, 0); // Stable
}

// Creates a particle and adds it to the simulation.
void Simulation::createParticle(ParticleType type, double mass, double charge, double lifetime, const std::vector<DecayMode>& decayModes, double x, double y, double z) {
    // Particle creation with random initial velocity for demonstration.
    std::uniform_real_distribution<double> velocityDist(-0.1, 0.1);
    double vx = velocityDist(generator);
    double vy = velocityDist(generator);
    double vz = velocityDist(generator);

    // I may pass in specific initial positions later (x, y, z), but for now I'll set them to zero.
    Particle newParticle(type, mass, charge, lifetime, decayModes, 0, 0, 0);
    newParticle.velocity[0] = vx;
    newParticle.velocity[1] = vy;
    newParticle.velocity[2] = vz;
    particles.push_back(newParticle);
}

// Computes the forces between all pairs of particles.
void Simulation::computeForces() {
    // Placeholder for any interaction forces between particles.
}

// Updates the state of all particles based on the computed forces.
void Simulation::updateParticles(double deltaTime) {
    for (auto& particle : particles) {
        particle.update(deltaTime);
    }
    decayParticles(deltaTime);
}

// Checks for unstable particles and handles their decay.
void Simulation::decayParticles(double deltaTime) {
    // Iterate through all particles to check their lifetime and possibly decay them.
    for (auto& particle : particles) {
        // Check if particle is unstable and should decay.
        if (particle.isUnstable()) {
            // Decrease lifetime by deltaTime as a placeholder for decay logic.
            // This simplifies decay to a decrease in lifetime without actual transformation or removal.
            particle.lifetime -= deltaTime;

            // Placeholder for comprehensive decay logic, involving decay mode selection and particle transformation or removal.
        }
    }
}