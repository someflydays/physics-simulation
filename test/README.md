# Test Scripts and Files

This directory's unit-tests ensure the correctness and stability of the physics simulation code. Utilizing the GoogleTest framework, these tests validate the functionality of individual components and their interactions within the simulation.

<br>

**`particle-unit-tests.cxx`** - Focus on the `Particle` class, ensuring that particles are initialized correctly, forces are computed according to Coulomb's law, and particles' states are updated accurately over simulation steps.

**`simulation-unit-tests.cxx`** - Focus on the `Simulation` class, testing the simulation's initialization, creation of particles upon collisions, computation of forces, updates of particles' positions and velocities, and the decay of unstable particles.

<br>

## Naming Conventions

Tests are named following the pattern `TEST_F([ClassName]Test, [methodName][SpecificBehaviorBeingTested])`, making it clear which method is being tested and what specific behavior or condition is under examination.

<br>

## Executing Tests

Tests can be compiled and run as part of the project's build process. Instructions for manually running unit-tests are detailed in the project's `physics-simulation/docs/README.md` file.
<br>

The unit-tests are also compiled and run within the initial GitHub Actions Continuous Integration (CI) pipeline found in `physics-simulation/.github/workflows/ci.yaml`. This pipeline is executed upon every push to the main branch and upon every pull request targeting the main branch. 

<br>
