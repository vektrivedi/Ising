#include "SMNormalizer.h"

//based on Marshall's description.
/* normalize: returns a "normalized" version of a SparseMatrix suitable for
*     fast lookups.
*
* Return value r must satisfy these conditions:
*
* 1. For any 0 <= a < r.size(): r[a].i <= r[a].j && r[a].value != 0
*
* 2. Unique, lexicographically-ordered indices. For any 0 <= a < b < r.size():
*    (r[a].i < r[b].i) || (r[a].i == r[b].i && r[a].j < r[b].j)
*
* 3. Same contents as input.  For any pair i <= j, there is a single index a
*    such that r[a].i == i && r[a].j == j && r[a].value == v, where v is
*    the sum of all m[b].value where
*    (m[b].i == i && m[b].j == j) || (m[b].i == j && m[b].j == i), UNLESS
*    v == 0 (in accordance with condition 1).
*/
SparseMatrix SMNormalizer::normalize(const SparseMatrix& m)
{
	spMatrix.clear();
	map<uint32_t, SparseMatrix> rowQ;
	for (auto mEntry : m)
	{
		//condition-1
		if (mEntry.Geti() > mEntry.Getj() || mEntry.Getvalue() == 0.0)
			continue;

	//	cout << mEntry.ToString() << "\n";
		
		if (maxI < mEntry.Geti())
			maxI = mEntry.Geti();

		if (maxJ < mEntry.Getj())
			maxJ = mEntry.Getj();


		auto ser = rowQ.find(mEntry.Getj());
		if (ser != rowQ.end())
		{
			//condition-2
			auto lower = std::lower_bound(rowQ[mEntry.Getj()].begin(), rowQ[mEntry.Getj()].end(), mEntry.Geti(), MatrixEntry::iComparer());
			if (lower != rowQ[mEntry.Getj()].end())
			{
				if (lower->Geti() != mEntry.Geti())
					rowQ[mEntry.Getj()].insert(lower, mEntry);
				else //condition-3
					lower->Setvalue(lower->Getvalue() + mEntry.Getvalue());
			}
			else
				rowQ[mEntry.Getj()].push_back(mEntry);
		}
		else
		{
			SparseMatrix spMat;
			rowQ[mEntry.Getj()] = spMat;
			rowQ[mEntry.Getj()].push_back(mEntry);
		}
	}

	//merge all the slices to create a matrix
	for (auto row : rowQ)
		spMatrix.insert(spMatrix.end(), row.second.begin(), row.second.end());

	//cout << "\n============================\n";
	//for (auto mEntry : spMatrix)
	//	cout << mEntry.ToString() << "\n";

	return spMatrix;
}


