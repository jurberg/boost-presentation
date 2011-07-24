/*
 * Boosting your C++ Development with Boost
 */
#define BOOST_TEST_MODULE Boosting_Your_CPP_Development
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Simplest)
{
    BOOST_CHECK((2 + 2) == 4); // continues on error
    BOOST_REQUIRE((2 + 2) == 4); // throws an error
	if ((2 + 2) != 4) BOOST_ERROR("Ouch..."); // continues on error
    if ((2 + 2) != 4) BOOST_FAIL("Ouch..."); // throws an error
    if ((2 + 2) != 4) throw "Ouch..."; // throws an error
    BOOST_CHECK_MESSAGE((2 + 2) == 4, "(2 + 2) == 4"); // continues on error
    BOOST_CHECK_EQUAL((2 + 2), 4); // continues on error
}
