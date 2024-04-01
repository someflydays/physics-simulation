// This file uses the Googletest framework to unit-test the C++ code found in physics-simulation/src/simulation.cxx

// Each class in simulation.cxx (that contains one or more methods) has its own Googletest fixture.
// Each method is given one or more individual tests (located within the corresponding class's fixture). 
// Each individual test checks one specific functionality of the corresponding method.

// The naming convention for testing initialization of a class is as follows: TEST_F([ClassName]Test, Initialization)
// The naming convention for testing a method is as follows: TEST_F([ClassName]Test, [methodName][SpecificFunctionalityBeingTested])

#include "simulation.h"
#include "particle.h"
#include <gtest/gtest.h>
#include <memory>

// Test fixture for the Simulation class
class SimulationTest : public ::testing::Test {
protected:

    std::unique_ptr<Simulation> simulation;

    void SetUp() override {
        simulation = std::make_unique<Simulation>();
    }

};

TEST_F(SimulationTest, Initialization) {
    size_t particleCount = simulation->getParticleCount();
    EXPECT_EQ(particleCount, 0) << "Simulation not initialized as expected. This simulation should have no particles initially, but it has " << particleCount << "particles.";
}

// Testing simulateCollision()
TEST_F(SimulationTest, simulateCollisionCreatesParticles) {
    simulation->simulateCollision();
    EXPECT_GE(simulation->getParticleCount(), 3) << "simulateCollision() did not create at least 3 particles as expected.";
}

// Testing simulateCollision()
TEST_F(SimulationTest, simulateCollisionCreatesParticlesWithExpectedProperties) {
    simulation->simulateCollision();

    // Expected properties for each particle type.
    struct ParticleExpectation {
        ParticleType type;
        double mass;
        double charge;
        double lifetime;
    };

    std::vector<ParticleExpectation> expectedParticles = {
        {ParticleType::PION_POSITIVE, 0.13957, +1.0, 0.0},
        {ParticleType::KAON_POSITIVE, 0.49367, +1.0, 1.24e-8},
        {ParticleType::PROTON, 0.93827, +1.0, 0.0}
    };

    // Iterate over each expected particle and check properties.
    for (size_t i = 0; i < expectedParticles.size(); ++i) {
        const auto& particle = simulation->particles[i];
        const auto& exp = expectedParticles[i];

        EXPECT_EQ(particle.type, exp.type) << "Particle " << i << "'s type does not match expectation.";
        EXPECT_DOUBLE_EQ(particle.mass, exp.mass) << "Particle " << i << "'s mass does not match expectation.";
        EXPECT_DOUBLE_EQ(particle.charge, exp.charge) << "Particle " << i << "'s charge does not match expectation.";
        EXPECT_DOUBLE_EQ(particle.lifetime, exp.lifetime) << "Particle " << i << "'s lifetime does not match expectation.";

        // Check if the velocity is within the expected range
        EXPECT_TRUE(particle.velocity[0] >= -0.1 && particle.velocity[0] <= 0.1) << "Particle velocity x is out of range for particle " << i;
        EXPECT_TRUE(particle.velocity[1] >= -0.1 && particle.velocity[1] <= 0.1) << "Particle velocity y is out of range for particle " << i;
        EXPECT_TRUE(particle.velocity[2] >= -0.1 && particle.velocity[2] <= 0.1) << "Particle velocity z is out of range for particle " << i;
    }
}

// Testing computeForces()
TEST_F(SimulationTest, computeForcesNoCrash) {
    simulation->simulateCollision();
    EXPECT_NO_THROW(simulation->computeForces()) << "computeForces() has thrown an exception.";
}

// Testing computeForces()
TEST_F(SimulationTest, computeForcesComputesAsExpected) {
    // TODO
}

// Testing updateParticles()
TEST_F(SimulationTest, updateParticlesProgressesSimulation) {
    simulation->simulateCollision();
    auto initialPositions = simulation->getParticlePositions();
    simulation->updateParticles(0.1); // Progress the simulation by a step of 0.1 seconds.
    auto updatedPositions = simulation->getParticlePositions();

    bool positionsChanged = false;
    for (size_t i = 0; i < initialPositions.size(); ++i) {
        if (initialPositions[i] != updatedPositions[i]) {
            positionsChanged = true;
            break;
        }
    }
    
    EXPECT_TRUE(positionsChanged) << "updateParticles did not change the positions of particles.";
}

// Testing updateParticles()
TEST_F(SimulationTest, updateParticlesUpdatesVelocitiesBasedOnForce) {
    // TODO
}

// Testing updateParticles()
TEST_F(SimulationTest, updateParticlesUpdatesPositionsBasedOnForce) {
    // TODO
}

// Testing decayParticles() implicitly within updateParticles()
TEST_F(SimulationTest, decayParticlesReducesLifetimeOrRemovesParticles) {
    simulation->simulateCollision();
    double initialLifetimeSum = simulation->getTotalLifetime();
    simulation->updateParticles(1.0); // Progress the simulation by a step of 1 second.
    double updatedLifetimeSum = simulation->getTotalLifetime();

    EXPECT_LT(updatedLifetimeSum, initialLifetimeSum) << "decayParticles did not reduce the total lifetime sum or remove particles.";
}

// Testing decayParticles() implicitly within updateParticles()
TEST_F(SimulationTest, decayParticlesSelectsValidDecayMode) {
    // TODO
}

// Testing decayParticles()
TEST_F(SimulationTest, decayParticlesDecaysParticlesAsExpected) {
    // TODO
}

// Testing createParticle()
TEST_F(SimulationTest, createParticleIncreasesParticleCount) {
    simulation->createParticle(ParticleType::PION_POSITIVE, 0.13957, +1, 0, 0, 0, 0);
    EXPECT_EQ(simulation->getParticleCount(), 1) << "createParticle did not increase particle count by 1.";
}

// Testing createParticle()
TEST_F(SimulationTest, createParticleInitializesParticleAsExpected) {
    // TODO
}