
#pragma warning(disable:4996)

#ifndef __Dep
#define __Dep
#include "GlobalConsts.h"
#include "Exception.h"
#include "Utils.h"
#include"staff.h"
#include "doctor.h"
#include "nurse.h"
#include "patient.h"
#include "surgeon.h"
#include "researcher.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
class Department
{

public:
	Department(string& _name);
	Department(ifstream& in);
	~Department();
	bool setName(string& _name)throw (Exception&);

	const string& getName()const;

	void printPatients()const;
	void printDoctors()const;
	void printNurse()const;
	void printSurgeon()const;

	Department& operator+=(Doctor& other);
	Department& operator+=(Nurse& other);
	Department& operator+=(Patient& other);
	virtual ostream& saveToFile(ostream& os)const;
	friend std::ostream & operator<<(std::ostream & os, const Department & dep);
 ostream & toOs(ostream & os)const;

	virtual bool operator==(const Department&);
	vector<const Doctor*>& getDocList();
	vector<const Nurse*>& getNurseList();

	void show();


private:
	vector<const Doctor*> docList;
	vector<const Nurse*> nurseList;
	vector<const Patient*> patientList;
	

	string name;
};

class DepartmentException :virtual public Exception
{
public:
	virtual void show();
};

#endif // _Dep


