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

**Particle Class** - Represents a single particle within the simulation. Each particle has properties such as mass, charge, lifetime, position, and velocity. The class provides methods to reset forces, set decay modes based on particle type, calculate and apply electromagnetic forces between particles, and update the particle's state over time.

**Physics Calculations** - The `addForce` method implements Coulomb's law to compute the electromagnetic force between two charged particles. The force calculation considers the inverse square of the distance between particles and their charges. This implementation also adheres to Newton's third law by applying equal and opposite forces to both particles involved.

### `simulation.cxx`

**Simulation Class** - Manages the overall simulation environment. It is responsible for simulating collisions, creating particles, computing forces between all particles, updating states of all particles, and handling particle decay. 

**Collision Simulation** - The `simulateCollision` method demonstrates a simplified approach to simulating particle collisions. It generates particles with predefined properties and random initial velocities.

**Particle Interactions** - The `computeForces` method is a placeholder for future implementations of interaction forces between all particle pairs. It represents a core part of the simulation where the forces that govern particle motion will be calculated.

**Updating the Simulation** - The `updateParticles` method progresses the simulation by updating the state of all particles based on computed forces. It also calls `decayParticles` to handle the decay process for unstable particles.

### `main.cxx`

**Application Entry Point** - Initializes a `Simulation` instance and runs a simple simulation step to illustrate the functionality. It outputs the properties of the generated particles to verify the simulation's execution.

## Physics Concepts

The simulation employs fundamental physics concepts, primarily focusing on Coulomb's law for electromagnetic interactions and basic principles of motion. These concepts are simplified to create a computationally feasible and educational simulation environment that demonstrates the dynamics of particle physics.

For more detailed understanding of the simulation logic and the physics principles applied, refer to the in-line comments within each source file.