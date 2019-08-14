/**
 * Declaration of SPNormalizer class.
 * This class facilitates the normalization of a sparse matrix.
 * Author: Vivek Trivedi
 * Date: July 29, 2016
 */
#ifndef SPARSE_MATRIX_H_INCLUDED
#define SPARSE_MATRIX_H_INCLUDED

#include <vector>
#include <string>
#include <random>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "MatrixEntry.h"

typedef std::vector<MatrixEntry> SparseMatrix;


class SMNormalizer
{
private:
	SparseMatrix spMatrix;
	uint32_t maxI = 0;
	uint32_t maxJ = 0;
public :
	//returns max i value
	uint32_t GetMaxi() { return maxI; }
	//returns max j value
	uint32_t GetMaxj() { return maxJ; }
	uint32_t GetMaxIndex() { return std::max(GetMaxi(), GetMaxj()); }
	SparseMatrix normalize(const SparseMatrix& m);
};

#endif
