#pragma once

#include "particle.h"   // Include the Particle class definition.
#include <vector>       // Required for using the std::vector container.
#include <random>       // Required for using std::default_random_engine.

// Manages the simulation of particles, including force calculation and state updates.
class Simulation {
public:
    std::vector<Particle> particles; // Container for all particles in the simulation
    void simulateCollision(); // // Simulates a collision that generates a set number of particles.
    void computeForces(); // Computes the forces between all pairs of particles.
    void updateParticles(double deltaTime); // Updates the state of all particles based on the computed forces.
    void decayParticles(double deltaTime); // Checks for unstable particles and handles their decay.

private:
    std::default_random_engine generator; // Used for generating random numbers (for particle velocities or positions).

    // Creates a particle and adds it to the simulation.
    // Parameters define the particle's type, physical properties, initial position, and possible decay modes.
    void createParticle(ParticleType type, 
                        double mass, 
                        double charge, 
                        double lifetime, 
                        const std::vector<DecayMode>& decayModes, 
                        double x, double y, double z);
};