#include "particle.h"       // Include the Particle class definition.
#include "simulation.h"     // Include the Simulation class definition.
#include <numeric>          // Required for using std::accumulate (in getTotalLifetime())
#include <tuple>            // Required for using std::tuple.

// Simulates a collision that generates three particles.
void Simulation::simulateCollision() {

    // Parameters for particles generated in a typical Pb-Pb collision.
    double pionMass = 0.13957; // in electronvolts (GeV/c^2)
    double kaonMass = 0.49367; // in electronvolts
    double protonMass = 0.93827; // in electronvolts

    // In this simulation, all particles are produced with random initial velocities within a range.
    std::uniform_real_distribution<double> velocityDist(-0.1, 0.1);

    // Create particles. Since we are simulating the result of a collision, these particles are created at the same intial position.
    createParticle(ParticleType::PION_POSITIVE, pionMass, +1.0, 0.0, 0.0, 0.0, 0.0); // Stable particle with a lifetime of 0.0
    createParticle(ParticleType::KAON_POSITIVE, kaonMass, +1.0, 1.24e-8, 0.0, 0.0, 0.0); // Unstable particle with a lifetime of 1.24e-8
    createParticle(ParticleType::PROTON, protonMass, +1, 0.0, 0.0, 0.0, 0.0); // Stable particle with a lifetime of 0.0
}

// Creates a particle and adds it to the simulation.
void Simulation::createParticle(ParticleType type, double mass, double charge, double lifetime, double x, double y, double z) {

    std::uniform_real_distribution<double> velocityDist(-0.1, 0.1);
    double vx = velocityDist(generator);
    double vy = velocityDist(generator);
    double vz = velocityDist(generator);

    // TODO: I may pass in specific initial positions later (x, y, z), but for now I'll set them to zero.
    Particle newParticle(type, mass, charge, lifetime, 0.0, 0.0, 0.0);
    newParticle.velocity[0] = vx;
    newParticle.velocity[1] = vy;
    newParticle.velocity[2] = vz;
    particles.push_back(newParticle);
}

// Computes the forces between all pairs of particles.
void Simulation::computeForces() {
    // TODO
}

// Returns the number of particles in the simulation.
size_t Simulation::getParticleCount() {
    return particles.size();
}

// Returns the position of each particle in the simulation as vectors of triples.
std::vector<std::tuple<double, double, double>> Simulation::getParticlePositions() const {
    std::vector<std::tuple<double, double, double>> positions;
    for (const auto& particle : particles) {
        positions.emplace_back(particle.position[0], particle.position[1], particle.position[2]);
    }
    return positions;
}

// Returns the sum of all particle lifetimes in the simulation.
double Simulation::getTotalLifetime() const {
    // Use std::accumulate to sum up the lifetimes.
    double totalLifetime = std::accumulate(particles.begin(), particles.end(), 0.0,
            [](double sum, const Particle& particle) {
            return sum + particle.lifetime;
            });
    return totalLifetime;
}

// Updates the state of all particles based on the computed forces and decay properties.
void Simulation::updateParticles(double deltaTime) {
    for (auto& particle : particles) {
        particle.update(deltaTime);
    }
    decayParticles(deltaTime);
}

// Checks for unstable particles and handles their decay.
void Simulation::decayParticles(double deltaTime) {
    // Iterate through all particles.
    for (auto& particle : particles) {
        // Check if particle is unstable and should decay.
        if (particle.isUnstable()) {
            // For now, decrease lifetime by deltaTime as a placeholder for simplified decay logic.
            particle.lifetime -= deltaTime;

            // TODO: Comprehensive decay logic, involving decay mode selection and particle transformation or removal.
        }
    }
}