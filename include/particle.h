#pragma once

#include <vector>   // Required for using the std::vector container.

// Defines the types of particles in the simulation.
// These are a few common hadrons that are significant for heavy ion collision studies.
enum class ParticleType {
    PION_POSITIVE,
    PION_NEGATIVE,
    PION_NEUTRAL,
    KAON_POSITIVE,
    KAON_NEGATIVE,
    PROTON
};

// Represents a decay mode.
struct DecayMode {
    ParticleType productType; // Type of decay product
    double branchingRatio;    // Probability of this decay mode
};

// Represents a particle in the simulation.
class Particle {
public:
    ParticleType type;
    double mass;           // Mass of the particle in electronvolts (GeV/c^2)
    double charge;         // Charge of the particle in elementary charge units (e)
    double lifetime;       // Lifetime of the particle in seconds (s), relevant for unstable particles
    std::vector<DecayMode> decayModes; // Possible decay modes, relevant for unstable particles
    double position[3];    // Position of the particle in 3D space (x, y, z), in meters (m), relative to an origin point in the simulated 3D space (0, 0, 0)
    double velocity[3];    // Velocity of the particle in 3D space (vx, vy, vz)
    double force[3];       // Net force acting on the particle (fx, fy, fz), in newtons (N)

    // Note: In this simulation, forces are used illustratively to affect particle movement.
    // In a detailed quantum model, I can instead focus on energy and momentum transfer between particles.

    // Constructor: Initializes a particle.
    Particle(ParticleType type, double m, double q, double lt, double x, double y, double z);

    void resetForce(); // Resets the net force on the particle to zero.
    void setDecayModes(); // Sets two possible decay modes for each particle type. (This is simplified for the purposes of this simulation).
    void addForce(Particle &other); // Calculates and adds the electromagnetic force exerted by another particle.
    void update(double deltaTime); // Updates the particle's state based on the net force acting on it and the elapsed time.
    bool isUnstable() const { return lifetime > 0; } // Checks the particle's lifetime property to determine if the particle is unstable and subject to decay.
};