#include "DataHelper.h"

string DataHelper::DumpFileName = "SparseMatrix";
const string DataHelper::DumpFileNameExt = ".csv";


/*********************************************************************************
* reads a matrix from the file.
* each entry of the matrix cell should be in "i,j,value" format.
***********************************************************************************/
SparseMatrix DataHelper::ReadMatrixFromFile()
{
	SparseMatrix spRead;
	string line;
	int filePostFix = 1;
	ifstream myfile(DumpFileName + DumpFileNameExt);
	while (filePostFix > 0)
	{
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				MatrixEntry m(line);
				spRead.push_back(m);
				//cout << line << '\n';
			}
			myfile.close();
			string nextFileName = DumpFileName + std::to_string(filePostFix) + DumpFileNameExt;
			myfile.open(nextFileName);
			filePostFix++;
		}
		else
			filePostFix = 0;
	}
	return spRead;

}

/*********************************************************************************
* Generates a random matrix and based on 'fillDensityPercentage' value populates 
* the matrix with non-zero value.
***********************************************************************************/
SparseMatrix DataHelper::CreateRandomMatrix(uint32_t rows, uint32_t cols, uint32_t seedVal, bool bDumpToFile, string fileName, double fillDensityPercentage)
{
	SparseMatrix spRead;
	int fillNumber = (int)(rows*cols* fillDensityPercentage / 100);
	int count_num = 0;

	std::mt19937 randomGenerator;
	randomGenerator.seed(seedVal);
	std::uniform_int_distribution<uint32_t> uint_distRows(0, rows - 1);
	std::uniform_int_distribution<uint32_t> uint_distCols(0, cols - 1);
	std::uniform_int_distribution<uint32_t> uint_dist10000(0, 10000);

	ofstream myfile;
	if (bDumpToFile)
	{
		if (fileName.size()>0)
			DataHelper::DumpFileName = fileName;
		myfile.open(DumpFileName + DumpFileNameExt);
		if (!myfile.is_open())
			bDumpToFile = false;
	}

	for (unsigned int i = 0; i < rows*cols; i++)
	{
		auto randomI = uint_distRows(randomGenerator);
		auto randomJ = uint_distCols(randomGenerator);
		auto randomValue = uint_dist10000(randomGenerator);
		if (randomValue > 0)
			count_num++;

		if (count_num >= fillNumber)
			randomValue = 0;

		if (randomI >= rows || randomJ >= cols)
			cout << randomI << "-" << randomJ;

		MatrixEntry mEntry(randomI, randomJ, randomValue);
		spRead.push_back(mEntry);
		if (bDumpToFile)
			myfile << mEntry.ToString() << "\n";
	}
	if (bDumpToFile)
		myfile.close();

	return spRead;

}

/*********************************************************************************
* Generates a 'S' vector to feed to Ising energy calculator.
***********************************************************************************/
vector<int> DataHelper::CreateRandomS(uint32_t size)
{
	vector<int> vRandomS;
	for (uint32_t i = 0; i < size; i++)
	{
		int randomNum = rand() % 2;
		vRandomS.push_back(randomNum ? +1 : -1);
	}
	return vRandomS;
}
