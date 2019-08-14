/**
 * Unit tests for DataHelper class.
 * Author: Vivek Trivedi
 * Date: July 29, 2016
 */
#define BOOST_TEST_DYN_LINK
//
#include <boost/test/unit_test.hpp>
#include "TestCommonHeader.h"
#include "MatrixEntry.h"
#include "DataHelper.h"

BOOST_AUTO_TEST_SUITE(DataHelperTester)

/**
 * Unit test to verify the vector creation size
 */
BOOST_AUTO_TEST_CASE(DataHelper_Check_S_VectorCreation_size)
{
	int vsize = 10;
	cout << "\t>> Creating S vector of size " << vsize << "\n";

	auto vS = DataHelper::CreateRandomS(vsize);
	BOOST_CHECK_EQUAL(vS.size(), vsize);
}

/**
 * Unit test to verify the vector creation values(+1,-1).
 */
BOOST_AUTO_TEST_CASE(DataHelper_Check_S_VectorCreation_values)
{
	int vsize = 10;
	auto vS = DataHelper::CreateRandomS(vsize);
	bool bIsOtherThan1 = false;
	for (auto sValue : vS)
	{
		if (sValue != -1 && sValue != 1)
		{
			bIsOtherThan1 = true;
			break;
		}
	}
	BOOST_REQUIRE(bIsOtherThan1 == false);
}

/**
 * Unit test to verify the random matrix creation.
 */
BOOST_AUTO_TEST_CASE(DataHelper_Create_Randim_Matrix)
{
	int maxI = 10, maxJ = 10;
	auto vMatrix = DataHelper::CreateRandomMatrix(maxI, maxJ);
	cout << "\t>> Creating matrix of size " << maxI << "x" << maxJ << "\n";
	BOOST_CHECK_EQUAL(vMatrix.size(), (maxI * maxJ));
}

/**
 * Unit test to verify the matrix reading from the file.
 */
BOOST_AUTO_TEST_CASE(DataHelper_Read_Matrix_From_File)
{
	int maxI = 10, maxJ = 10;
	cout << "\t>> Creating matrix file of size " << maxI << "x" << maxJ << "\n";
	auto vMatrix = DataHelper::CreateRandomMatrix(maxI, maxJ, 44, true);
	cout << "\t>> Reading matrix file of size " << maxI << "x" << maxJ << "\n";
	auto rMatrix = DataHelper::ReadMatrixFromFile();
	BOOST_CHECK_EQUAL(rMatrix.size(), (maxI * maxJ));
}

BOOST_AUTO_TEST_SUITE_END()
