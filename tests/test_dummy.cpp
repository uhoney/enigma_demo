#include <catch2/catch_test_macros.hpp>

#include "../src/dummy.h"

TEST_CASE("Dummy testit..", "[dummy]")
{
	REQUIRE(Dummy::summa_funktion_testausta(2, 3) == 5);
	REQUIRE(Dummy::summa_funktion_testausta(-1, 1) == 0);
}