# Header Files for the Project's C++ Code

This directory contains header files defining the classes and functions used in the physics simulation. 

## Directory Structure

```
include/            // Header files for the project's C++ code.
├── particle.h      // Declares the Particle class with properties and methods for particles in the simulation.
└── simulation.h    // Declares the Simulation class managing the simulation and particle interactions.
```

## File Descriptions

### `particle.h`

This header file declares the `Particle` class. The class represents a single particle within the simulation. Each particle has properties such as mass, charge, lifetime, position, and velocity. The class also provides methods to reset forces, set decay modes based on particle type, calculate and apply electromagnetic forces between particles, and update the particle's state over time.<br>

**`resetForce`** - Resets the cumulative force acting on the particle to zero, preparing it for the next simulation step.<br>
**`setDecayModes`** - Initializes possible decay modes for unstable particles, simplifying actual quantum decay processes for feasability.<br>
**`addForce`** - Implements the electromagnetic interaction between particles based on Coulomb's law.<br>
**`update`** - Advances the state of the particle based on the current forces and elapsed time, simulating movement and decay.

### `simulation.h`

This header file declares the `Simulation` class, which manages the overall simulation environment. It is responsible for simulating collisions, creating particles, computing forces between all particles, updating states of all particles, and handling particle decay.<br>

**`simulateCollision`** - Simulates a collision that generates a set number of particles.<br>
**`computeForces`** - Computes the forces between all pairs of particles, using their electromagnetic properties.<br>
**`getParticleCount`** - Returns the number of particles in the simulation.<br>
**`getParticlePositions`** - Returns the position of each particle in the simulation as vectors of triples.<br>
**`getTotalLifetime`** - Returns the sum of all particle lifetimes in the simulation.<br>
**`updateParticles`** - Updates the state of all particles based on the computed forces and decay properties.<br>
**`decayParticles`** - Checks for unstable particles and handles their decay.<br>
**`createParticle`** - Creates a particle and adds it to the simulation.
