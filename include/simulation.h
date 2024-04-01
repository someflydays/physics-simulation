#pragma once

#include "particle.h"   // Include the Particle class definition.
#include <vector>       // Required for using the std::vector container.
#include <random>       // Required for using std::default_random_engine.
#include <tuple>        // Required for using std::tuple.

// Manages the simulation of particles, including force calculation and state updates.
class Simulation {
public:
    std::vector<Particle> particles; // Container for all particles in the simulation
    void simulateCollision(); // Simulates a collision that generates a set number of particles.
    void computeForces(); // Computes the forces between all pairs of particles.
    size_t getParticleCount(); // Returns the number of particles in the simulation.
    std::vector<std::tuple<double, double, double>> getParticlePositions() const; // Returns the position of each particle in the simulation as vectors of triples.
    double getTotalLifetime() const; // Returns the sum of all particle lifetimes in the simulation.
    void updateParticles(double deltaTime); // Updates the state of all particles based on the computed forces and decay properties.
    void decayParticles(double deltaTime); // Checks for unstable particles and handles their decay.
    void createParticle(ParticleType type, double mass, double charge, double lifetime, double x, double y, double z); // Creates a particle and adds it to the simulation.

private:
    std::default_random_engine generator; // Used for generating random numbers (for particle velocities or positions).
};