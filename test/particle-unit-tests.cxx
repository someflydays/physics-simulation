// This file uses the Googletest framework to unit-test the C++ code found in physics-simulation/src/particle.cxx

// Each class in particle.cxx (that contains one or more methods) has its own Googletest fixture.
// Each method is given one or more individual tests (located within the corresponding class's fixture). 
// Each individual test checks one specific functionality of the corresponding method.

// The naming convention for testing a method is as follows: TEST_F([ClassName]Test, [methodName][SpecificFunctionalityBeingTested])

#include "particle.h"
#include <gtest/gtest.h>

// Test fixture for the Particle class
class ParticleTest : public ::testing::Test {
protected:

    // Declare class members.
    std::unique_ptr<Particle> p1, p2, p3, p4; // Smart pointers faciliate automatic memory management.

    void SetUp() override {
        // Initialize four particles for force calculations.
        p1 = std::make_unique<Particle>(ParticleType::PROTON, 0.938, +1.0, 0.0, 0.0, 0.0, 0.0); // Stable particle
        p2 = std::make_unique<Particle>(ParticleType::PROTON, 0.938, +1.0, 0.0, 1.0, 0.0, 0.0); // Stable particle
        p3 = std::make_unique<Particle>(ParticleType::KAON_POSITIVE, 0.493, +1.0, 1.24e-8, 0.0, 0.0, 0.0); // Unstable particle
        p4 = std::make_unique<Particle>(ParticleType::PION_NEGATIVE, 0.13957, -1.0, 2.6e-8, -1.0, 0.0, 0.0); // Unstable particle
    }

};

// Testing Particle class constructor
// This test also implicitly tests the setDecayModes() method, which is called in the Particle class constructor.
TEST_F(ParticleTest, ConstructorInitializesCorrectly) {

    // Check the initialization of p1.
    EXPECT_EQ(p1->type, ParticleType::PROTON) << "Particle's type is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p1->mass, 0.938) << "Particle's mass is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p1->charge, +1.0) << "Particle's charge is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p1->lifetime, 0.0) << "Particle's lifetime is not intialized as expected.";
    EXPECT_TRUE(p1->decayModes.empty()) << "Stable particle's decayModes are not intialized as expected (struct is not empty).";
    EXPECT_DOUBLE_EQ(p1->position[0], 0.0) << "Particle's x position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p1->position[1], 0.0) << "Particle's y position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p1->position[2], 0.0) << "Particle's z position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p1->velocity[0], 0.0) << "Particle's velocity in x direction (vx) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p1->velocity[1], 0.0) << "Particle's velocity in y direction (vy) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p1->velocity[2], 0.0) << "Particle's velocity in z direction (vz) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p1->force[0], 0.0) << "Particle's force in x direction (fx) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p1->force[1], 0.0) << "Particle's force in y direction (fy) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p1->force[2], 0.0) << "Particle's force in z direction (fz) is not initialized as expected.";

    // Check the initialization of p2.
    EXPECT_EQ(p2->type, ParticleType::PROTON) << "Particle's type is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p2->mass, 0.938) << "Particle's mass is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p2->charge, +1.0) << "Particle's charge is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p2->lifetime, 0.0) << "Particle's lifetime is not intialized as expected.";
    EXPECT_TRUE(p2->decayModes.empty()) << "Stable particle's decayModes are not intialized as expected (struct is not empty).";
    EXPECT_DOUBLE_EQ(p2->position[0], 1.0) << "Particle's x position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p2->position[1], 0.0) << "Particle's y position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p2->position[2], 0.0) << "Particle's z position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p2->velocity[0], 0.0) << "Particle's velocity in x direction (vx) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p2->velocity[1], 0.0) << "Particle's velocity in y direction (vy) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p2->velocity[2], 0.0) << "Particle's velocity in z direction (vz) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p2->force[0], 0.0) << "Particle's force in x direction (fx) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p2->force[1], 0.0) << "Particle's force in y direction (fy) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p2->force[2], 0.0) << "Particle's force in z direction (fz) is not initialized as expected.";

    // Check the initialization of p3.
    EXPECT_EQ(p3->type, ParticleType::KAON_POSITIVE) << "Particle's type is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p3->mass, 0.493) << "Particle's mass is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p3->charge, +1.0) << "Particle's charge is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p3->lifetime, 1.24e-8) << "Particle's lifetime is not intialized as expected.";
    EXPECT_FALSE(p3->decayModes.empty()) << "Unstable particle's decayModes are not intialized as expected (struct is empty).";
    EXPECT_EQ(p3->decayModes.size(), 2u) << "Unstable particle should have two decay modes. This one has " << p3->decayModes.size();
    EXPECT_EQ(p3->decayModes[0].productType, ParticleType::PION_POSITIVE) << "Unstable particle's decayModes are not intialized as expected (first decayMode of KAON_POSITIVE should produce PION_POSITIVE).";
    EXPECT_DOUBLE_EQ(p3->decayModes[0].branchingRatio, 0.63) << "Unstable particle's decayModes are not intialized as expected (branching ratio for firstDecay mode of KAON_POSITIVE should be 0.63).";
    EXPECT_EQ(p3->decayModes[1].productType, ParticleType::PION_NEUTRAL) << "Unstable particle's decayModes are not intialized as expected (second decay mode of KAON_POSITIVE should produce PION_NEUTRAL).";
    EXPECT_DOUBLE_EQ(p3->decayModes[1].branchingRatio, 0.21) << "Unstable particle's decayModes are not intialized as expected (branching ratio for second decay mode of KAON_POSITIVE should be 0.21).";
    EXPECT_DOUBLE_EQ(p3->position[0], 0.0) << "Particle's x position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p3->position[1], 0.0) << "Particle's y position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p3->position[2], 0.0) << "Particle's z position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p3->velocity[0], 0.0) << "Particle's velocity in x direction (vx) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p3->velocity[1], 0.0) << "Particle's velocity in y direction (vy) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p3->velocity[2], 0.0) << "Particle's velocity in z direction (vz) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p3->force[0], 0.0) << "Particle's force in x direction (fx) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p3->force[1], 0.0) << "Particle's force in y direction (fy) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p3->force[2], 0.0) << "Particle's force in z direction (fz) is not initialized as expected.";

    // Check the initialization of p4.
    EXPECT_EQ(p4->type, ParticleType::PION_NEGATIVE) << "Particle's type is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p4->mass, 0.13957) << "Particle's mass is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p4->charge, -1.0) << "Particle's charge is not intialized as expected.";
    EXPECT_DOUBLE_EQ(p4->lifetime, 2.6e-8) << "Particle's lifetime is not intialized as expected.";
    EXPECT_FALSE(p4->decayModes.empty()) << "Unstable particle's decayModes are not intialized as expected (struct is empty).";
    EXPECT_EQ(p4->decayModes.size(), 2u) << "Unstable particle should have two decay modes. This one has " << p4->decayModes.size();
    EXPECT_EQ(p4->decayModes[0].productType, ParticleType::KAON_NEGATIVE) << "Unstable particle's decayModes are not intialized as expected (first decayMode of PION_NEGATIVE should produce KAON_NEGATIVE).";
    EXPECT_DOUBLE_EQ(p4->decayModes[0].branchingRatio, 0.2) << "Unstable particle's decayModes are not intialized as expected (branching ratio for firstDecay mode of PION_NEGATIVE should be 0.2).";
    EXPECT_EQ(p4->decayModes[1].productType, ParticleType::PROTON) << "Unstable particle's decayModes are not intialized as expected (second decay mode of PION_NEGATIVE should produce PROTON).";
    EXPECT_DOUBLE_EQ(p4->decayModes[1].branchingRatio, 0.1) << "Unstable particle's decayModes are not intialized as expected (branching ratio for second decay mode of PION_NEGATIVE should be 0.1).";
    EXPECT_DOUBLE_EQ(p4->position[0], -1.0) << "Particle's x position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p4->position[1], 0.0) << "Particle's y position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p4->position[2], 0.0) << "Particle's z position is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p4->velocity[0], 0.0) << "Particle's velocity in x direction (vx) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p4->velocity[1], 0.0) << "Particle's velocity in y direction (vy) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p4->velocity[2], 0.0) << "Particle's velocity in z direction (vz) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p4->force[0], 0.0) << "Particle's force in x direction (fx) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p4->force[1], 0.0) << "Particle's force in y direction (fy) is not initialized as expected.";
    EXPECT_DOUBLE_EQ(p4->force[2], 0.0) << "Particle's force in z direction (fz) is not initialized as expected.";
}

// Testing resetForce()
TEST_F(ParticleTest, resetForceSetsForceToZero) {
    p1->force[0] = 10.0; // Set a non-zero force.
    p1->force[1] = 20.0;
    p1->force[2] = 30.0;
    p1->resetForce(); // This should set the force back to zero.
    EXPECT_DOUBLE_EQ(p1->force[0], 0.0) << "Particle's force in x direction (fx) was not reset to zero.";
    EXPECT_DOUBLE_EQ(p1->force[1], 0.0) << "Particle's force in y direction (fy) was not reset to zero.";
    EXPECT_DOUBLE_EQ(p1->force[2], 0.0) << "Particle's force in z direction (fz) was not reset to zero.";
    
    p2->force[0] = 10.0;
    p2->force[1] = 20.0;
    p2->force[2] = 30.0;
    p2->resetForce();
    EXPECT_DOUBLE_EQ(p2->force[0], 0.0) << "Particle's force in x direction (fx) was not reset to zero.";
    EXPECT_DOUBLE_EQ(p2->force[1], 0.0) << "Particle's force in y direction (fy) was not reset to zero.";
    EXPECT_DOUBLE_EQ(p2->force[2], 0.0) << "Particle's force in z direction (fz) was not reset to zero.";

    p3->force[0] = 10.0;
    p3->force[1] = 20.0;
    p3->force[2] = 30.0;
    p3->resetForce();
    EXPECT_DOUBLE_EQ(p3->force[0], 0.0) << "Particle's force in x direction (fx) was not reset to zero.";
    EXPECT_DOUBLE_EQ(p3->force[1], 0.0) << "Particle's force in y direction (fy) was not reset to zero.";
    EXPECT_DOUBLE_EQ(p3->force[2], 0.0) << "Particle's force in z direction (fz) was not reset to zero.";

    p4->force[0] = 10.0;
    p4->force[1] = 20.0;
    p4->force[2] = 30.0;
    p4->resetForce();
    EXPECT_DOUBLE_EQ(p4->force[0], 0.0) << "Particle's force in x direction (fx) was not reset to zero.";
    EXPECT_DOUBLE_EQ(p4->force[1], 0.0) << "Particle's force in y direction (fy) was not reset to zero.";
    EXPECT_DOUBLE_EQ(p4->force[2], 0.0) << "Particle's force in z direction (fz) was not reset to zero.";
}

// Testing addForce()
TEST_F(ParticleTest, addForceUsesCoulombsLaw) {
    p4->addForce(*p3);
    double expectedForceMagnitude = -8987551786.0200424; // This value was calculated using Coulomb's Law.
    EXPECT_DOUBLE_EQ(p4->force[0], expectedForceMagnitude) << "Particle's force in x direction was not added as expected.";
    p4->addForce(*p2);
    expectedForceMagnitude = -11234439732.777828; // This value was calculated using Coulomb's Law.
    EXPECT_DOUBLE_EQ(p4->force[0], expectedForceMagnitude) << "Particle's force in x direction was not added as expected.";
}

// Testing addForce()
TEST_F(ParticleTest, addForceChangesForceOfBothParticlesBeingAdded) {
    // Newton's third law
    p4->addForce(*p3);
    double expectedForceMagnitude = 8987551786.0200424; // This value was calculated using Coulomb's Law. It is the opposite of the force exerted on p4.
    EXPECT_DOUBLE_EQ(p3->force[0], expectedForceMagnitude) << "addForce() did not change the force of both particles as expected.";
    p4->addForce(*p2);
    expectedForceMagnitude = 2246887946.7577853; // This value was calculated using Coulomb's Law.
    EXPECT_DOUBLE_EQ(p2->force[0], expectedForceMagnitude) << "addForce() did not change the force of both particles as expected.";
}

// Testing update()
TEST_F(ParticleTest, updatePositionAndVelocityStaySameWhenNoForceAdded) {
    double initialPosition[3] = {p1->position[0], p1->position[1], p1->position[2]}; // [0.0, 0.0, 0.0]
    double initialVelocity[3] = {p1->velocity[0], p1->velocity[1], p1->velocity[2]}; // [0.0, 0.0, 0.0]
    p1->update(1); // Update particle for 1 second with no force applied.
    EXPECT_DOUBLE_EQ(initialPosition[0], p1->position[0]) << "update() changed the particle's x position even though no force was added.";
    EXPECT_DOUBLE_EQ(initialPosition[1], p1->position[1]) << "update() changed the particle's y position even though no force was added.";
    EXPECT_DOUBLE_EQ(initialPosition[2], p1->position[2]) << "update() changed the particle's z position even though no force was added.";
    EXPECT_DOUBLE_EQ(initialVelocity[0], p1->velocity[0]) << "update() changed the particle's velocity in the x direction even though no force was added.";
    EXPECT_DOUBLE_EQ(initialVelocity[1], p1->velocity[1]) << "update() changed the particle's velocity in the y direction even though no force was added.";
    EXPECT_DOUBLE_EQ(initialVelocity[2], p1->velocity[2]) << "update() changed the particle's velocity in the z direction even though no force was added.";
}

// Testing update()
TEST_F(ParticleTest, updatePositionChangesAsExpectedWhenForceAdded) {
    p4->addForce(*p3);
    p3->update(1); // Update p3 for 1 second with force applied.
    p4->update(1); // Update p4 for 1 second with force applied.
    EXPECT_DOUBLE_EQ(p3->position[0], 18230328166.369255) << "update() did not change the particle's x position as expected given the added force.";
    EXPECT_DOUBLE_EQ(p3->position[1], 0.0) << "update() changed the particle's y position even though no force was added in that direction.";
    EXPECT_DOUBLE_EQ(p3->position[2], 0.0) << "update() changed the particle's z position even though no force was added in that direction.";
    EXPECT_DOUBLE_EQ(p4->position[0], -64394581831.049744) << "update() did not change the particle's x position as expected given the added force.";
    EXPECT_DOUBLE_EQ(p4->position[1], 0.0) << "update() changed the particle's y position even though no force was added in that direction.";
    EXPECT_DOUBLE_EQ(p4->position[2], 0.0) << "update() changed the particle's z position even though no force was added in that direction.";
}

// Testing update()
TEST_F(ParticleTest, updateVelocityChangesAsExpectedWhenForceAdded) {
    p3->addForce(*p4);
    p3->update(1); // Update p3 for 1 second with force applied.
    p4->update(1); // Update p4 for 1 second with force applied.
    EXPECT_DOUBLE_EQ(p3->velocity[0], 18230328166.369255) << "update() did not change the particle's velocity in the x direction as expected given the added force.";
    EXPECT_DOUBLE_EQ(p3->velocity[1], 0.0) << "update() did not change the particle's velocity in the y direction as expected given the added force.";
    EXPECT_DOUBLE_EQ(p3->velocity[2], 0.0) << "update() did not change the particle's velocity in the z direction as expected given the added force.";
    EXPECT_DOUBLE_EQ(p4->velocity[0], -64394581830.049744) << "update() did not change the particle's velocity in the x direction as expected given the added force.";
    EXPECT_DOUBLE_EQ(p4->velocity[1], 0.0) << "update() did not change the particle's velocity in the y direction as expected given the added force.";
    EXPECT_DOUBLE_EQ(p4->velocity[2], 0.0) << "update() did not change the particle's velocity in the z direction as expected given the added force.";
}

// Testing isUnstable()
TEST_F(ParticleTest, isUnstableAccuratelyAssessesStabilityBasedOnLifetimeProperty) {
    EXPECT_FALSE(p1->isUnstable()); // p1 is a stable particle with a lifetime of 0.0
    EXPECT_FALSE(p2->isUnstable()); // p2 is a stable particle with a lifetime of 0.0
    EXPECT_TRUE(p3->isUnstable()); // p3 is an unstable particle with a lifetime of 1.24e-8
    EXPECT_TRUE(p4->isUnstable()); // p4 is an unstable particle with a lifetime of 2.6e-8
}