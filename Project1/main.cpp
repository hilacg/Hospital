#pragma warning(disable:4996)
#include <iostream>
#include<string>
#include "Header.h"
#include "Hospital.h"
using namespace std;
void main() 
{
	Hospital hospital;
	ifstream file(FILE_NAME);
	readFromFile(hospital, file);
	cout << "Welcome to Nala hospital \n \n";
	initDepartment(hospital);
	initNurse(hospital);
	initDoctor(hospital);
	mainChoice(hospital);
}







