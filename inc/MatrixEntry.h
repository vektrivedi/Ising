/**
 * Declaration of Matrixentry class.
 * This class represnt a single cell in a matrix.
 * Author: Vivek Trivedi
 * Date: July 29, 2016
 */
#ifndef MATRIX_ENTRY_H_INCLUDED
#define MATRIX_ENTRY_H_INCLUDED


#include <string.h>

using namespace std;

class MatrixEntry
{
private:
	uint32_t i = 0;
	uint32_t j = 0;
	double value = 0.0;

public:
	uint32_t Geti() { return i; }
	uint32_t Getj() { return j; }
	double Getvalue() { return value; }
	void Setvalue(double newVal) { value = newVal; }

	/*********************************************************************************
	* constructor.
	***********************************************************************************/
	MatrixEntry(uint32_t iVal, uint32_t jVal, double val)
	{
		this->i = iVal < 0 ? 0 : iVal;;
		this->j = jVal < 0 ? 0 : jVal;
		this->value = val;
	}

	/*********************************************************************************
	* constructor.
	***********************************************************************************/
	MatrixEntry(string valAsStr)
	{
		ParseValues(valAsStr);
	}

	/*********************************************************************************
	* The function retruns stringfy version of the values.
	***********************************************************************************/
	string ToString()
	{
		return std::to_string(i) + "," + std::to_string(j) + "," + std::to_string(value);
	}


	/*********************************************************************************
	* The function parses string to get i,j,value.
	***********************************************************************************/
	void ParseValues(string valAsString)
	{
		try
		{
			string parseStr = valAsString;
			char *p = strtok((char*)parseStr.c_str(), ",");
			i = stoi(p);
			p = strtok(NULL, ",");
			j = stoi(p);
			p = strtok(NULL, " ");
			value = stod(p);
		}
		catch (...)
		{
			throw;
		}
	}


	//The instance of tiis class can be fed to functions that are defined <algorithm> to facilitate i value comparision.
	class iComparer
	{
	public:
		bool operator() (MatrixEntry & left, uint32_t right)
		{
			return left.Geti() < right;
		}
	};

	//The instance of tiis class can be fed to functions that are defined <algorithm> to facilitate j value comparision.
	class jComparer
	{
	public:
		bool operator() (MatrixEntry & left, uint32_t right)
		{
			return left.Getj() < right;
		}
	};
};

#endif
