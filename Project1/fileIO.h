#ifndef _file
#define _file
#include "GlobalConsts.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "doctor.h"
#include "departments.h"
#include "Hospital.h"
#include "docResearcher.h"
#include "surgeon.h"
#include "surgeonResearcher.h"

using namespace std;

#include <map>
#include <exception>

enum className {
	department, researcher, doctor, docResearcher,surgeon,surgeonResearcher,nurse
};
className stringToEnum(string& str);
template<class TYPE>
void saveToFile(TYPE& vec, std::ofstream& outFile)
{
	int size = vec.size();
	outFile << size << " ";
	for (int i = 0; i < size; ++i)
	{
		outFile << typeid(*vec[i]).name() +TYPE_ID_CLASS_CUT << " ";
		(*vec[i]).saveToFile(outFile);
		outFile<< " "<<endl;
	
	}
};
void filter_blank_spaces(ifstream& in_stream);

void readFromFile(Hospital& hospital, std::ifstream& file);

#endif // !_file

