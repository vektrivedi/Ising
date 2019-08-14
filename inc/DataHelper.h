/**
 * Declaration of DataHelper class.
 * This class facilitates the test-data creation.
 * Author: Vivek Trivedi
 * Date: July 29, 2016
 */
#ifndef SM_DATA_HELPER_H_INCLUDED
#define SM_DATA_HELPER_H_INCLUDED

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

#include "SMNormalizer.h"

class DataHelper
{
private:
	static  const string DumpFileNameExt;// = ".csv";
	static  string DumpFileName;// = "SparseMatrix";
public:

	static SparseMatrix ReadMatrixFromFile();
	static SparseMatrix CreateRandomMatrix(uint32_t rows, uint32_t cols, uint32_t seedVal=rand(), bool bDumpToFile=false, string fileName="SparseMatrix", double fillDensityPercentage=30.0);
	static vector<int> CreateRandomS(uint32_t size = 10000);
	static string GetRandomMatrixDiskFileName() { return DumpFileName + DumpFileNameExt; }
};

#endif
