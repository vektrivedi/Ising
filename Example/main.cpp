/**
 * Author: Vivek Trivedi
 * Date: July 29, 2016
 */
#include "SMNormalizer.h"
#include "IsingModel.h"
#include "DataHelper.h"
#include <iostream>
using namespace std;

//Sample code to compute the energy.
int main()
{
        //generate a random matrix.
	auto m = DataHelper::CreateRandomMatrix(1000, 1000);

	// instance of Sparse Matrix Normalizer.
	SMNormalizer sm;
        //feed the randomly generated matrix to SMNormalizer to normalize it.
	auto nsm = sm.normalize(m);

        //generate the 'S' vector to to feed it to Ising energy calculation.
	auto vecS = DataHelper::CreateRandomS(sm.GetMaxIndex() + 1);
        //Compute the energy using Ising Model.
	cout << "\nEnergy : " << IsingModel::computeEnergy(nsm, vecS) << "\n";

        cout << "\nPress any key end to end...";
        getchar();
	return 0;
}

