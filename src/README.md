# Source Files (*.cxx); the main codebase for the physics simulation.

This directory contains the implementation files for the physics simulation. It details the operations and interactions that govern the simulated environment.

## Directory Structure
```
src/                // Source files (*.cxx); the main codebase for the physics simulation.
├── particle.cxx    // Implements the Particle class, including physics calculations.
├── simulation.cxx  // Implements the Simulation class, orchestrating the simulation process.
└── main.cxx        // Main entry point for the simulation application.
```

## Implementation Overview

### `particle.cxx`

**Particle Class** - Represents a single particle within the simulation. Each particle has properties such as mass, charge, lifetime, position, and velocity. The class provides methods to reset forces, set decay modes based on particle type, calculate and apply electromagnetic forces between particles, and update the particle's state over time.<br>

`addForce` - Implements Coulomb's law to compute the electromagnetic force between two charged particles.

<br>

### `simulation.cxx`

**Simulation Class** - Manages the overall simulation environment. It is responsible for simulating collisions, creating particles, computing forces between all particles, updating states of all particles, and handling particle decay.<br>

`simulateCollision` - Generates particles with predefined properties and random initial velocities.<br>

`computeForces` - Represents a core part of the simulation where the forces that govern particle motion will be calculated.<br>

`updateParticles` - Progresses the simulation by updating the state of all particles based on computed forces. <br>

`decayParticles` - Handles the decay process for unstable particles.

<br>

### `main.cxx`

*Application Entry Point* - Initializes a Simulation instance and runs a simple simulation step. This file outputs the properties of the generated particles to verify the simulation's execution.

<br>

For more detailed understanding of the simulation logic and the physics principles applied, refer to the in-line comments within each source file.
