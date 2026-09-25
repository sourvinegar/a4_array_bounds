#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "array/array_bounds.hpp"

TEST_CASE("empty array")
{
    int a[] = {};
    int n = 0;
    int t = 3;
    REQUIRE(dsac::array::lower_bound_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::lower_bound(a, n, t) == 0);
    REQUIRE(dsac::array::upper_bound_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::upper_bound(a, n, t) == 0);
    REQUIRE(dsac::array::frequency_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::frequency(a, n, t) == 0);
}

TEST_CASE("1 element array")
{
    int a[] = {1};
    int n = 1;
    int t = 3;
    REQUIRE(dsac::array::lower_bound_iterative(a, n, t) == 1);
    REQUIRE(dsac::array::lower_bound(a, n, t) == 1);
    REQUIRE(dsac::array::upper_bound_iterative(a, n, t) == 1);
    REQUIRE(dsac::array::upper_bound(a, n, t) == 1);
    REQUIRE(dsac::array::frequency_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::frequency(a, n, t) == 0);
}

TEST_CASE("target smaller than every element")
{
    int a[] = {4, 5, 8};
    int n = 3;
    int t = 3;
    REQUIRE(dsac::array::lower_bound_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::lower_bound(a, n, t) == 0);
    REQUIRE(dsac::array::upper_bound_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::upper_bound(a, n, t) == 0);
    REQUIRE(dsac::array::frequency_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::frequency(a, n, t) == 0);
}

TEST_CASE("target larger than every element")
{
    int a[] = {4, 5, 8};
    int n = 3;
    int t = 10;
    REQUIRE(dsac::array::lower_bound_iterative(a, n, t) == 3);
    REQUIRE(dsac::array::lower_bound(a, n, t) == 3);
    REQUIRE(dsac::array::upper_bound_iterative(a, n, t) == 3);
    REQUIRE(dsac::array::upper_bound(a, n, t) == 3);
    REQUIRE(dsac::array::frequency_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::frequency(a, n, t) == 0);
}

TEST_CASE("target equal to first element")
{
    int a[] = {4, 5, 8};
    int n = 3;
    int t = 4;
    REQUIRE(dsac::array::lower_bound_iterative(a, n, t) == 0);
    REQUIRE(dsac::array::lower_bound(a, n, t) == 0);
    REQUIRE(dsac::array::upper_bound_iterative(a, n, t) == 1);
    REQUIRE(dsac::array::upper_bound(a, n, t) == 1);
    REQUIRE(dsac::array::frequency_iterative(a, n, t) == 1);
    REQUIRE(dsac::array::frequency(a, n, t) == 1);
}

TEST_CASE("target equal to last element")
{
    int a[] = {4, 5, 8};
    int n = 3;
    int t = 8;
    REQUIRE(dsac::array::lower_bound_iterative(a, n, t) == 2);
    REQUIRE(dsac::array::lower_bound(a, n, t) == 2);
    REQUIRE(dsac::array::upper_bound_iterative(a, n, t) == 3);
    REQUIRE(dsac::array::upper_bound(a, n, t) == 3);
    REQUIRE(dsac::array::frequency_iterative(a, n, t) == 1);
    REQUIRE(dsac::array::frequency(a, n, t) == 1);
}

TEST_CASE("multiple duplicate values")
{
    int a[] = {4, 5, 6, 6, 8, 8};
    int n = 6;
    int t = 6;
    REQUIRE(dsac::array::lower_bound_iterative(a, n, t) == 2);
    REQUIRE(dsac::array::lower_bound(a, n, t) == 2);
    REQUIRE(dsac::array::upper_bound_iterative(a, n, t) == 4);
    REQUIRE(dsac::array::upper_bound(a, n, t) == 4);
    REQUIRE(dsac::array::frequency_iterative(a, n, t) == 2);
    REQUIRE(dsac::array::frequency(a, n, t) == 2);
}

TEST_CASE("target occurring exactly once")
{
    int a[] = {4, 5, 6, 8, 8};
    int n = 5;
    int t = 6;
    REQUIRE(dsac::array::lower_bound_iterative(a, n, t) == 2);
    REQUIRE(dsac::array::lower_bound(a, n, t) == 2);
    REQUIRE(dsac::array::upper_bound_iterative(a, n, t) == 3);
    REQUIRE(dsac::array::upper_bound(a, n, t) == 3);
    REQUIRE(dsac::array::frequency_iterative(a, n, t) == 1);
    REQUIRE(dsac::array::frequency(a, n, t) == 1);
}



