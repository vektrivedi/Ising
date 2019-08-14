/**
 * Unit tests for SMNormalizer class.
 * this class facilitates the nomalization of sparse matrix.
 * Author: Vivek Trivedi
 * Date: July 29, 2016
 */
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "TestCommonHeader.h"
#include "MatrixEntry.h"
#include "SMNormalizer.h"
#include "DataHelper.h"

BOOST_AUTO_TEST_SUITE(SM_Normalizer)

BOOST_AUTO_TEST_CASE(SM_Normalizer_Test_Non_Zero)
{
	int maxI = 10, maxJ = 10;
	cout << "\t>> Creating matrix of size " << maxI << "x" << maxJ << " with 30% non-zero elements. \n";
	auto sm = DataHelper::CreateRandomMatrix(maxI, maxJ);
	SMNormalizer smNorm;
	auto smN = smNorm.normalize(sm);
	bool isZeroVal = false;
	for (auto mEntry : smN)
	{
		if (mEntry.Getvalue() == 0)
		{
			isZeroVal = true;
			break;
		}
	}
	BOOST_REQUIRE(isZeroVal == false);
}

//test: For any 0 <= a < r.size(): r[a].i <= r[a].j
BOOST_AUTO_TEST_CASE(SM_Normalizer_Test_i_lessThanEq_j)
{
	int maxI = 10, maxJ = 10;
	cout << "\t>> Creating matrix of size " << maxI << "x" << maxJ << ".\n";
	auto sm = DataHelper::CreateRandomMatrix(maxI, maxJ);
	SMNormalizer smNorm;
	auto smN = smNorm.normalize(sm);
	bool is_I_gt_J = false;
	for (auto mEntry : smN)
	{
		if (mEntry.Geti() > mEntry.Getj())
		{
			is_I_gt_J = true;
			break;
		}
	}
	BOOST_REQUIRE(is_I_gt_J == false);
}

//test: Unique cell indices
BOOST_AUTO_TEST_CASE(SM_Normalizer_Test_Unique_cell)
{
	int maxI = 100, maxJ = 100;
	bool bitMap[100][100] = { { false } };;
	cout << "\t>> Creating matrix of size " << maxI << "x" << maxJ << ".\n";
	auto sm = DataHelper::CreateRandomMatrix(maxI, maxJ);
	SMNormalizer smNorm;
	auto smN = smNorm.normalize(sm);
	bool isUnique = true;
	for (auto mEntry : smN)
	{
		if (bitMap[mEntry.Getj()][mEntry.Geti()])
		{
			isUnique = false;
			break;
		}
		bitMap[mEntry.Getj()][mEntry.Geti()] = true;
	}

	BOOST_REQUIRE(isUnique == true);
}

//test: lexicographically-ordered indices. For any 0 <= a < b < r.size():
// (r[a].i < r[b].i) || (r[a].i == r[b].i && r[a].j < r[b].j)
BOOST_AUTO_TEST_CASE(SM_Normalizer_Test_lex_ordered_indices)
{
	int maxI = 100, maxJ = 100;
	cout << "\t>> Creating matrix of size " << maxI << "x" << maxJ << ".\n";
	auto sm = DataHelper::CreateRandomMatrix(maxI, maxJ);
	SMNormalizer smNorm;
	auto smN = smNorm.normalize(sm);
	bool isOrdered = true;
	for (unsigned int idx = 0; idx < smN.size()-1; idx++)
	{
		if (smN[idx].Getj() > smN[idx + 1].Getj())
		{
			isOrdered = false;
			break;
		}
		else if (smN[idx].Getj() == smN[idx+1].Getj()) // if rows are same then check the order col
		{
			if (smN[idx].Geti() >= smN[idx + 1].Geti()) 
			{
				isOrdered = false;
				break;
			}
		}
	}
	BOOST_REQUIRE(isOrdered == true);
}

/*test:Same contents as input.  For any pair i < j, there is a single index a
*      such that r[a].i == i && r[a].j == j && r[a].value == v, where v is
*      the sum of all m[b].value where
*      (m[b].i == i && m[b].j == j) || (m[b].i == j && m[b].j == i), UNLESS
*       v == 0 (in accordance with condition 1).
*/
BOOST_AUTO_TEST_CASE(SM_Normalizer_Test_Same_Content_As_Input)
{
	int maxI = 100, maxJ = 100;
	double valueMap[100][100] = { { 0.0 } };;
	cout << "\t>> Creating matrix of size " << maxI << "x" << maxJ << ".\n";
	auto sm = DataHelper::CreateRandomMatrix(maxI, maxJ);
	for (auto mEntry : sm)
	{
		valueMap[mEntry.Getj()][mEntry.Geti()] += mEntry.Getvalue();
	}

	SMNormalizer smNorm;
	auto smN = smNorm.normalize(sm);
	bool isSame = true;
	for (auto mEntry : smN)
	{
		if (mEntry.Getvalue() != valueMap[mEntry.Getj()][mEntry.Geti()])
		{
			isSame = false;
			break;
		}
	}
	BOOST_REQUIRE(isSame == true);
}
BOOST_AUTO_TEST_SUITE_END()
