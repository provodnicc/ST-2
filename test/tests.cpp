// Copyright 2024 Pavel Smirnov
#include <gtest/gtest.h>
#include <cstdint>
#include "tasks.h"
#include "circle.h"

const double EPS = 1e-6;
const double PI = 3.14159;

TEST(Circle, checkCreatingWithPositiveRadius) {
    const double radius = 10.0;
    auto test_circle = Circle(radius);
    EXPECT_NEAR(test_circle.getRadius(), radius, EPS);
}

TEST(Circle, checkCreatingWithZeroRadius) {
    EXPECT_ANY_THROW(Circle(0.0));
}

TEST(Circle, checkCreatingWithNegativeRadius) {
    EXPECT_ANY_THROW(Circle(-5.0));
}

TEST(Circle, checkGettingArea) {
    auto test_circle = Circle(1.0);
    EXPECT_NEAR(test_circle.getArea(), PI, EPS);
}

TEST(Circle, checkGettingFerence) {
    auto test_circle = Circle(1.0);
    EXPECT_NEAR(test_circle.getFerence(), 2 * PI, EPS);
}

TEST(Circle, checkSettingPositiveRadius) {
    auto test_circle = Circle(1.0);
    test_circle.setRadius(2.0);
    EXPECT_NEAR(test_circle.getRadius(), 2.0, EPS);
    EXPECT_NEAR(test_circle.getArea(), 4 * PI, EPS);
    EXPECT_NEAR(test_circle.getFerence(), 4 * PI, EPS);
}

TEST(Circle, checkSettingZeroRadius) {
    auto test_circle = Circle(1.0);
    EXPECT_ANY_THROW(test_circle.setRadius(0.0));
}

TEST(Circle, checkSettingNegativeRadius) {
    auto test_circle = Circle(1.0);
    EXPECT_ANY_THROW(test_circle.setRadius(-1.0));
}

TEST(Circle, checkSettingPositiveArea) {
    auto test_circle = Circle(1.0);
    test_circle.setArea(4 * PI);
    EXPECT_NEAR(test_circle.getRadius(), 2.0, EPS);
    EXPECT_NEAR(test_circle.getArea(), 4 * PI, EPS);
    EXPECT_NEAR(test_circle.getFerence(), 4 * PI, EPS);
}

TEST(Circle, checkSettingZeroArea) {
    auto test_circle = Circle(1.0);
    EXPECT_ANY_THROW(test_circle.setArea(0.0));
}

TEST(Circle, checkSettingNegativeArea) {
    auto test_circle = Circle(1.0);
    EXPECT_ANY_THROW(test_circle.setArea(-1.0));
}

TEST(Circle, checkSettingPositiveFerence) {
    auto test_circle = Circle(1.0);
    test_circle.setFerence(4 * PI);
    EXPECT_NEAR(test_circle.getRadius(), 2.0, EPS);
    EXPECT_NEAR(test_circle.getArea(), 4 * PI, EPS);
    EXPECT_NEAR(test_circle.getFerence(), 4 * PI, EPS);
}

TEST(Circle, checkSettingZeroFerence) {
    auto test_circle = Circle(1.0);
    EXPECT_ANY_THROW(test_circle.setFerence(0.0));
}

TEST(Circle, checkSettingNegativeFerence) {
    auto test_circle = Circle(1.0);
    EXPECT_ANY_THROW(test_circle.setFerence(-1.0));
}

TEST(Circle, checkSettingBigRadius) {
    const double radius = 1.0;
    const double new_radius = 1500.0;
    auto test_circle = Circle(radius);
    test_circle.setRadius(new_radius);
    EXPECT_NEAR(test_circle.getRadius(), new_radius, EPS);
    EXPECT_NEAR(test_circle.getArea(), new_radius * new_radius * PI, EPS);
    EXPECT_NEAR(test_circle.getFerence(), 2 * new_radius * PI, EPS);
}

TEST(Circle, checkSettingBigFerence) {
    const double radius = 1.0;
    const double new_radius = 1000.0;
    auto test_circle = Circle(radius);
    test_circle.setFerence(new_radius);
    EXPECT_NEAR(test_circle.getFerence(), new_radius, EPS);
    EXPECT_NEAR(test_circle.getRadius(), new_radius / (2 * PI), EPS);
    EXPECT_NEAR(test_circle.getArea(),
                new_radius * (new_radius / (2 * PI)) / 2,
                EPS);
}

TEST(Circle, checkSettingBigArea) {
    const double radius = 1.0;
    const double new_radius = 1000.0;
    auto test_circle = Circle(radius);
    test_circle.setArea(new_radius);
    EXPECT_NEAR(test_circle.getArea(), new_radius, EPS);
    EXPECT_NEAR(test_circle.getRadius(), sqrt(new_radius / PI), EPS);
    EXPECT_NEAR(test_circle.getFerence(), sqrt(new_radius / PI) * 2 * PI, EPS);
}

TEST(Tasks, planetAndRopeSolve) {
    EXPECT_NEAR(solvePlanetAndRopeTask(6378100.0, 1.0), M_1_PI * 0.5, EPS);
}

TEST(Tasks, littleDataPlanetAndRopeSolve) {
    EXPECT_NEAR(solvePlanetAndRopeTask(1.0, 1.0), M_1_PI * 0.5, EPS);
}

TEST(Tasks, swimmingPoolSolve) {
    EXPECT_NEAR(solveSwimmingPoolTask(3.0, 1.0, 1000, 2000),
        23000 * PI,
        EPS);
}
