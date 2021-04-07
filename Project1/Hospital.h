#pragma warning(disable:4996)

#ifndef _HOS
#define _HOS
#include "GlobalConsts.h"
#include <string>
#include <vector>
#include "departments.h"
#include "doctor.h"
#include "researcher.h"
#include "nurse.h"

 
class Hospital
{
public:
	Hospital();
	~Hospital();
	
	
	vector<Department*> departments;
	vector<Nurse*> nurses;
	vector<Doctor*> doctors;
	vector<Patient*> patients;
	vector<Researcher*> researchers;
	
};


#endif // !_HOS


