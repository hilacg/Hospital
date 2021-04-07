#include <iostream>
#include "departments.h"
#pragma warning(disable:4996)

using namespace std;

Department::Department(string& _name)  // constractor
{
	setName(_name);

}
Department::Department(ifstream & in)
{
	string name;
	in >> name;
	this->setName(name);
	
}
std::ifstream & operator>>(std::ifstream & in,  Department & dep)
{
	string name;
	in>> name;
	dep.setName(name);
	return in;
}
std::ostream & operator<<(std::ostream & os, const Department & dep)
{
	
	return dep.toOs(os);
}

//Department::Department(const Department& other) : name(nullptr), docList(nullptr), nurseList(nullptr) // copy constractor
//{
//	setName(other.name);
//	if (other.docList != nullptr)
//	{
//		for (int i = 0; i < other.docListLen; i++)
//		{
//			*(docList + i) = *(other.docList + i);
//		}
//	}
//}
Department::~Department() // distractor
{
	
}
bool Department::setName(string& name)throw (DepartmentException&)
{
	if (name.size()<= 0)
		throw DepartmentException();
	this->name = name;
	return true;
}

const string& Department::getName()const
{

	return name;
}

void Department::printPatients()const
{
	print<const Patient*>(patientList);
	

}
void Department::printDoctors()const
{
	print<const Doctor*>(docList);
}
void Department::printNurse()const
{
	print<const Nurse*>(nurseList);
}

void Department::printSurgeon()const
{
	print<const Surgeon*>(docList);
}


Department& Department::operator+=(Doctor& other)
{

	if (docList.size() == docList.max_size())
		resizeVector(docList);
	docList.push_back(&other);
	other.setDepartment(this);
	return *this;
}
Department& Department::operator+=(Nurse& other)
{
	if (nurseList.size() == nurseList.max_size())
		resizeVector(nurseList);
	nurseList.push_back(&other);
	other.setDepartment(this);
	return *this;
}
Department& Department::operator+=(Patient& other)
{
	if (nurseList.size() == patientList.max_size())
		resizeVector(nurseList);
	patientList.push_back(&other);
	return *this;
}
ostream & Department::saveToFile(ostream & os) const
{
	toOs(os);
	return os;
}
ostream & Department::toOs(ostream & os)const
{
	os << name;
	return os;
}
bool Department::operator==(const Department &other)
{
	return name.compare(other.name)==0;
}
void Department::show()
{
	cout << *this;
}
vector<const Doctor*>& Department::getDocList()
{
	return docList;
}
vector<const Nurse*>& Department::getNurseList()
{
	return nurseList;
}

void DepartmentException::show()
{
	cout << "Department name is invalid! \n";
}