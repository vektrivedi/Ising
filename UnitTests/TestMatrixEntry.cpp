/**
 * Unit tests for MatrixEntry class.
 * Author: Vivek Trivedi
 * Date: July 29, 2016
 */
#define BOOST_TEST_DYN_LINK

#include "TestCommonHeader.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_suite.hpp>
#include "MatrixEntry.h"
#include "DataHelper.h"

BOOST_AUTO_TEST_SUITE(MatrixEntryTester)

/**
 * Unit test to verify the constructor of MatrixEntry.
 */
BOOST_AUTO_TEST_CASE(MatrixEntry_ChechIJIndex)
{
	MatrixEntry mEntry(10, 10, 0);
	BOOST_REQUIRE(mEntry.Geti() == 10);
	BOOST_REQUIRE(mEntry.Getj() == 10);
}

/**
 * Unit test to verify the set/get for value field of MatrixEntry.
 */
BOOST_AUTO_TEST_CASE(MatrixEntry_ChechValue)
{
	MatrixEntry mEntry(10, 10, 20);
	BOOST_REQUIRE(mEntry.Getvalue() == 20);
	mEntry.Setvalue(40);
	BOOST_REQUIRE(mEntry.Getvalue() == 40);
}

/**
 * Unit test to verify the parsing of MarixEntry from string value.
 */
BOOST_AUTO_TEST_CASE(MatrixEntry_ParseStringValueToMatrixEntry)
{
	std::string strMatValue = "10,20,100";
	MatrixEntry mEntry(11, 11, 120);
	mEntry.ParseValues(strMatValue);
	BOOST_REQUIRE(mEntry.Geti() == 10);
	BOOST_REQUIRE(mEntry.Getj() == 20);
	BOOST_REQUIRE(mEntry.Getvalue() == 100);

	MatrixEntry mEntry1("11, 21, 120");
	BOOST_REQUIRE(mEntry1.Geti() == 11);
	BOOST_REQUIRE(mEntry1.Getj() == 21);
	BOOST_REQUIRE(mEntry1.Getvalue() == 120);

}

/**
 * Unit test to verify the MarixEntry's tosring() method.
 */
BOOST_AUTO_TEST_CASE(MatrixEntry_ToString)
{
	MatrixEntry mEntry(11, 21, 120);
	auto toStr = mEntry.ToString();
	auto pos = toStr.find("11,21,120");
	BOOST_REQUIRE(pos==0);
}

BOOST_AUTO_TEST_SUITE_END()
