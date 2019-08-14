#include "IsingModel.h"

//Based on Marshall's description
/* computeEnergy: returns the energy of an Ising problem at a given state
*
* energy = (sum over i of h_i * s_i) + (sum over i, j of J_ij * s_i * s_j)
* Treat diagonal entries of m (i.e. when m[a].i == m[a].j) as h values,
* other entries as J.
*
* Do not assume anything about the contents of m.  In particular, m is not
* necessarily normalized.  You may assume all entries of s are +1 or -1.
*/
double IsingModel::computeEnergy(const SparseMatrix& m, const std::vector<int>& s)
{
	double retValue = 0.0;
	double hValue = 0;
	double jValue=0;


	SMNormalizer sm;
	auto normalizedMatrix = sm.normalize(m);

	if (s.size() <= sm.GetMaxIndex())
	{
		cout << "ERROR: Insufficient 'S' elemtns.\n";
		return 0; //this will lead to array out-of-bound
	}

	for (auto mEntry : normalizedMatrix)
	{
		if (mEntry.Geti() == mEntry.Getj())
			hValue += (mEntry.Getvalue()*s[mEntry.Geti()]);
		else
			jValue += (mEntry.Getvalue() * s[mEntry.Geti()] * s[mEntry.Getj()]);
	}

	retValue = hValue + jValue;

	return retValue;
}

