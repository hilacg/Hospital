#include "fileIO.h"



className stringToEnum(string & str)
{
	std::map<string, className> classMap;
	classMap["Department"] = department;
	classMap["Researcher"] = researcher;
	classMap["Doctor"] = doctor;
	classMap["DocResearcher"] = docResearcher;
	classMap["Surgeon"] = surgeon;
	classMap["SurgeonResearcher"] = surgeonResearcher;
	classMap["Nurse"] = nurse;
	return classMap[str];
}
void filter_blank_spaces(ifstream& in_stream)
{
	char next;
	in_stream.get(next);
	in_stream.ignore();
}

void readFromFile(Hospital& hospital , std::ifstream & file)
{
	bool fEOF = false;
	string sizeOfTypeSTR;
	string classType;
	string depName;
	if (file.eof())
		fEOF = true;
	else
		file >> sizeOfTypeSTR;
	while(!fEOF)
	{
		
		

		for (int i = 0; i < atoi(sizeOfTypeSTR.c_str()); ++i)
		{
			file >> classType;
			Doctor* staff=nullptr;
			Nurse* nurse = nullptr;
			if(classType.compare(typeid(Department).name()+TYPE_ID_CLASS_CUT)!=0)
				file >> depName;
			switch (stringToEnum(classType))
			{
			case 0:
			{
				hospital.departments.push_back(new Department(file));
			}
			break;
			/*case 1:
			{
				no need for doctor!
				staff = new Researcher(file);

			}
			break;*/
			case 2:
			{
				staff = new Doctor(file);
			}
			break;
			case 3:
			{
				staff = new DocResearcher(file);
			}
			break;
			case 4:
			{
				staff = new Surgeon(file);
			}
			break;
			case 5:
			{
				staff = new SurgeonResearcher(file);
			}
			break;
			case 6:
			{
				nurse = new Nurse(file);
			}
			break;
			default:
				break;
			}
			Department* dep = nullptr;
			if (staff || nurse)
			{
				for (auto obj : hospital.departments)
				{
					if (obj->getName().compare(depName) == 0)
						dep = obj;
				}
				if (dep)
					if (classType.compare("Nurse") == 0)
					{
						*dep += *nurse;
						hospital.nurses.push_back(nurse);
					}
					else
					{
						*dep += *staff;
						hospital.doctors.push_back(staff);
					}
			}
		}
		file >> sizeOfTypeSTR;

		if (file.eof())
			fEOF = true;
	} 
	
}
