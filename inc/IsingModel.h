/**
 * Declaration of IsingModel class.
 * This class facilitates the Ising model energy computaiton.
 * Author: Vivek Trivedi
 * Date: July 29, 2016
 */
#ifndef ISING_MODEL_H_INCLUDED
#define ISING_MODEL_H_INCLUDED

#include "SMNormalizer.h"

class IsingModel
{
public :
	static double computeEnergy(const SparseMatrix& m, const std::vector<int>& s);
};

#endif
