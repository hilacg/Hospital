#include <iostream>
#include "initHospital.h"
#include "doctor.h"

using namespace std;

std::ostream & Doctor::saveToFile(ostream & os)const
{
	Staff::toOs(os);
	toOs(os);
	return os;
}

Doctor::Doctor(Staff& staff , string&  speciality) : Staff(staff)
{
	setSpeciality(speciality);
}
Doctor::Doctor(ifstream & in) : Staff(in)
{
	in >> *this;
}
Doctor::Doctor(const Doctor& other) : Staff(other)
{
	setSpeciality(other.speciality);
}
Doctor::Doctor(Doctor&& other):Staff(other)
{
	setSpeciality(other.speciality);
	other.speciality;
}
void Doctor::show()const
{
	
	cout << (Staff&)(*this) << " " << *this;
	
}

string& Doctor::className()
{
	return string(typeid(*this).name() +TYPE_ID_CLASS_CUT);
}

Doctor::~Doctor()
{
}

bool Doctor::setSpeciality(const string&   _spec)throw(DoctorSpecException&)
{
	if (_spec.size() == 0)
		throw DoctorSpecException();
	speciality = _spec;
	return true;
	
}
const string&  Doctor::getSpeciality()const
{
	return speciality;
}

bool Doctor::setDepartment(Department* dep)
{
	this->department = dep;
	return true;
}

std::ostream & operator<<(std::ostream & os, const Doctor & doc)
{
	((Staff&)doc).toOs(os);
	doc.toOs(os);
	return os;
}
ostream& Doctor::toOs(ostream& os)const
{
 if (typeid(os) == typeid(ofstream))
	{
		os << speciality<< " " ;
	}
	else
		os << "Speciality: " << speciality << " Department: " << *department<< " ";
	return os;

}
std::ifstream & operator >> (std::ifstream & in, Doctor & doc)
{
	string spc;
	in >> spc;
	doc.setSpeciality(spc);
	return in;
}

void DoctorSpecException::show() const
{
	cout << "Speciality is invalid!";
}
