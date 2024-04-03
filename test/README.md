# Test Scripts and Files

This directory encompasses unit and integration tests to ensure the correctness and stability of the physics simulation code. Utilizing the GoogleTest framework, the tests validate the functionality of individual components and their interactions within the simulation.

## Overview

The test suite is divided into unit tests for individual classes (`Particle` and `Simulation`) and integration tests that examine the interaction between these components under various conditions. The tests aim to verify both the logical correctness of the simulation and the adherence to physical laws it models.

### Unit-Tests

**`particle-unit-tests.cxx`** - Focus on the `Particle` class, ensuring that particles are initialized correctly, forces are computed according to Coulomb's law, and particles' states are updated accurately over simulation steps.

**`simulation-unit-tests.cxx`** - Focus on the `Simulation` class, testing the simulation's initialization, the creation of particles upon collisions, the computation of forces, updates of particles' positions and velocities, and the decay of unstable particles.

### Integration Tests

Integration tests are planned for future development to test the simulation as a whole, including scenarios involving complex interactions.

<br>

## Test Organization

Each test file follows a structured format:

**`SetUp` Method** - Prepares the necessary environment or conditions before each test. For `ParticleTest`, this includes initializing particles with specific attributes. For `SimulationTest`, it involves creating a new simulation instance.

**Test Fixtures** - Provide a common testing framework for a group of related tests, ensuring they operate under consistent conditions. They leverage GoogleTest's `TEST_F` macro.

**Assertions** - Check for expected outcomes within tests. These range from equality checks (`EXPECT_EQ`) to condition validations (`EXPECT_TRUE` or `EXPECT_NO_THROW`).

<br>

## Naming Conventions

Tests are named following the pattern `TEST_F([ClassName]Test, [methodName][SpecificFunctionalityBeingTested])`, making it clear which method is being tested and what specific behavior or condition is under examination.

<br>

## Executing Tests

Tests can be compiled and run as part of the project's build process. Instructions for manually running unit-tests are detailed in the project's `physics-simulation/docs/README.md` file.
<br>

The unit-tests are also compiled and run within the initial GitHub Actions Continuous Integration (CI) pipeline found in `physics-simulation/.github/workflows/ci.yaml`. This pipeline is executed upon every push to the main branch, and upon pull requests targeting main, to catch issues early in the development cycle. In the settings for this repository, I have configured a Branch Protection Rule (for the main branch) that ensures pushes and pull requests only proceed if the unit-tests pass.

<br>

## Future Directions

**Expanding Test Coverage** - Future developments will include more comprehensive tests, especially integration tests that fully explore the interactions within the simulation.

**Performance Testing** - As the simulation grows in complexity, performance tests will be added to ensure that the simulation remains efficient and scalable.

**Continuous Integration (CI)** - Tests are planned to be integrated into a Jenkins pipeline, configured as an option that can be selected or automated.

