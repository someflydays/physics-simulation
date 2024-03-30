#include "simulation.h" // Include the Simulation class definition.
#include <iostream>     // Include iostream for console output.
#include <iomanip>      // Include iomanip for controlling output formatting (setting precision).

int main() {
    Simulation sim; // Create a new simulation instance.
    
    // Simulate a collision which generates particles.
    sim.simulateCollision();

    // Run a simple simulation step.
    sim.computeForces();
    sim.updateParticles(0.01); // Update with a small time step.

    // Output properties of generated particles to verify that particles have been added and updated.
    for (const auto& particle : sim.particles) {
        std::cout << "Particle Type: ";
        switch (particle.type) {
            case ParticleType::PION_POSITIVE: std::cout << "Pion (+)"; break;
            case ParticleType::PION_NEGATIVE: std::cout << "Pion (-)"; break;
            case ParticleType::PION_NEUTRAL:  std::cout << "Pion (0)"; break;
            case ParticleType::KAON_POSITIVE: std::cout << "Kaon (+)"; break;
            case ParticleType::KAON_NEGATIVE: std::cout << "Kaon (-)"; break;
            case ParticleType::PROTON:        std::cout << "Proton"; break;
            default:                          std::cout << "Unknown"; break;
        }
        std::cout << std::fixed << std::setprecision(5) // Set precision to 5 for more significant digits.
                  << ", Mass: " << particle.mass 
                  << ", Charge: " << particle.charge 
                  << std::setprecision(2) // Reset precision to 2 for position
                  << ", Position: (" 
                  << particle.position[0] << ", " 
                  << particle.position[1] << ", " 
                  << particle.position[2] << ")"
                  << std::endl;
    }

    return 0;
}