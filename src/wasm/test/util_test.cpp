#include "../deps/tinycpptest/TinyCppTest.hpp"
#include "../include/util.h"
#include "../include/math/triangulate-with-boundaries.h"

using namespace webifc;

TEST(TriangleWalkInnerEdge)
{
	glm::dvec2 a(0.0, 0.0);
	glm::dvec2 b(1.0, 0.0);
	glm::dvec2 c(0.5, 1.0);

	glm::dvec2 d(0.5, 0);
	glm::dvec2 e(0.5, 0.5);

	auto tris = triangulate(a, b, c, std::vector<glm::dvec2>{ d, e });

	ASSERT_EQ(tris.size(), 4);
}

TEST(TriangleWalkOuterEdge)
{
	glm::dvec2 a(0.0, 0.0);
	glm::dvec2 b(1.0, 0.0);
	glm::dvec2 c(0.0, 1.0);

	glm::dvec2 d(0.25, 0);

	auto tris = triangulate(a, b, c, std::vector<glm::dvec2>{ d });

	ASSERT_EQ(tris.size(), 2);
}

TEST (TriangleAreaTest)
{
	glm::dvec3 a (0.0, 0.0, 0.0);
	glm::dvec3 b (1.0, 0.0, 0.0);
	glm::dvec3 c (0.0, 1.0, 0.0);
	ASSERT_EQ_EPS (areaOfTriangle (a, b, c), 0.5, EPS_TINY);
}

TEST(TriangleWalkCenter)
{
	glm::dvec2 a(0.0, 0.0);
	glm::dvec2 b(1.0, 0.0);
	glm::dvec2 c(0.0, 1.0);

	glm::dvec2 d(0.25, 0.25);

	auto tris = triangulate(a, b, c, std::vector<glm::dvec2>{ d });

	ASSERT_EQ(tris.size(), 3);
}

TEST(NewTest)
{
	// load model
	// get mesh for line
	// compute volume
	// check volume
}

