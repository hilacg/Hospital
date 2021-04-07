#ifndef __doc
#define __doc
#include <iostream>
#include "staff.h"
#include "Exception.h"
#include <string>
#include <fstream>
class Department;
class Doctor: virtual public Staff
{
	
protected:
	string speciality;

public:
	
	virtual std::ostream& saveToFile(ostream& os)const;

	Doctor(Staff& staff,string&  speciality);
	Doctor(ifstream& in);
	virtual ~Doctor();
	bool setSpeciality(const string&  _spec)throw(Exception&); 
	const string&  getSpeciality()const;
	bool setDepartment(Department*);
 ostream & toOs(ostream & os)const;
	friend std::ostream& operator<<(std::ostream& os, const Doctor& doc);
	friend std::ifstream& operator>>(std::ifstream& os, Doctor& doc);

	Doctor(const Doctor & other);

	Doctor(Doctor && other);

	virtual void show()const;
	virtual string& className();


};
class DoctorSpecException: public Exception
{
public:
	virtual void show()const;

};

#endif // __doc

