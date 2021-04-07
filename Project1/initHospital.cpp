
#include "initHospital.h"

void initResearcher(Hospital& hos)
{
	bool isValid = false;
	Researcher* res;
	do
	{
		try
		{
			res = new  Researcher(staffQA());
			isValid = true;
			addArticlePromptUser(*res);
			hos.researchers.push_back(res);	
		}
		catch (StaffNameException& e)
		{

			e.show();
		}
	} while (!isValid);
}
void initDepartment(Hospital& hospital)
{
	
	int input;
	Department* dep;
	cout << "how many departments to add?\n";
	cin >> input;
	while (input < MIN_NUM_OF_TYPE)
	{
		cout << "incorect number please insert a new one: \n";
		cin >> input;

	}
	cin.ignore(NAME_LENGTH, '\n');

	for (unsigned int  i = 0; i < input; i)
	{
		cout << "Department number " << i + 1 << ":\n";
		try
		{
			vector<Department*>::iterator itr = hospital.departments.begin();
			vector<Department*>::iterator endItr = hospital.departments.end();
			dep = departmentQA();
			
			if (find(itr, endItr, dep)==endItr)
			{
				hospital.departments.push_back(dep);
				++i;
			}
			else
			{
				cout << "The department already exists! \n";
			}
			
		}
		catch (DepartmentException& e)
		{
			e.show();
		}
		cout << "\n---------------- \n";

	}
}
/*
bool isDepExists(Department& dep,Department** depList,int& numOfDep)
{
	bool res = false;
	for (int i = 0; i < numOfDep; i++)
	{
		res = strcmp(dep.getName(), depList[i]->getName())==0;
	}
	return res;
}
*/
Department* departmentQA()
{
	string pName;
	cout << "name: ";
	getline(cin,pName);
	return new Department(pName);
}
/*
bool addDepToList(Department & dep, Department ** (&depList), int & departmentListSize, int & numOfDepartments)
{
	if (numOfDepartments == departmentListSize)
	{
		if (numOfDepartments == EMPTY)
		{
			depList = new Department*[sizeof(Department*) * 2];
			departmentListSize = 2;
		}
		else
		{
			resizeArrDep(departmentListSize, depList);
		}
	}
	depList[numOfDepartments++] = &dep;
	return true;

}
void resizeArrDep(int & size, Department ** (&arr))// resizing departent array
{
	Department** t = arr;
	Department** tempArr = new Department*[sizeof(Department*)*size * 2];
	for (unsigned int  i = 0; i < size; i++)
	{
		*(tempArr + i) = *(arr + i);
		*(arr + i) = nullptr;
	}
	size *= 2;
	arr = tempArr;
	delete[]t;
}
*/
//---------------------------------------------------------------------------


void initDoctor(Hospital& hospital)
{

	int input, type;
	cout << "how many doctors to add?";
	cin >> input;
	while (input < MIN_NUM_OF_TYPE)
	{
		cout << "incorect number please insert a new one: \n";
		cin >> input;

	}
	for (unsigned int i = 0; i < input; i++)
	{
		bool isValid = false;
		do
		{
			try
			{
				string pSpec;
				cout << "doctor number" << i + 1 << " : " << endl;

				cout << "select type of doctor: \n 1.doctor\n 2.researcher\n 3.surgeon\n 4.all of the above" << endl;
				do
				{
					cin >> type;
					if(type > 4 || type < 1)
					{
						cout << "did not specify the corect choice!" << endl;
					}
				} while (type > 4 || type < 1);
				Staff staff = staffQA();
				cout << "Speciality: ";
				getline(cin, pSpec);
				Doctor* doc = new Doctor(staff, pSpec);
				
					switch (type)
					{
					case DOCTOR: {}
								 break;
					case RESEARCHER:
					{
						DocResearcher* DR = new DocResearcher(*doc, Researcher(staff));
						addArticlePromptUser(*DR);
						doc = DR;
					}
					break;



					case SURGEON:
					{
						Surgeon* sur = new Surgeon(*doc);
						sur->setNumOfSur(surQA());
						doc = sur;
					}
					break;



					case AOTA: {
						DocResearcher DR(*doc, Researcher(staff));
						Surgeon sur(*doc);
						sur.setNumOfSur(surQA());
						doc = new SurgeonResearcher(sur, DR);
						addArticlePromptUser(*doc);

					}
							   break;
					default: { 
						
					}
							 break;
					}
				
				*(hospital.departments[departmentChoice(hospital.departments)]) += *doc;
				hospital.doctors.push_back(doc);
				isValid = true;
			}
			catch (StaffNameException& e) 
			{
				e.show();
			}
			catch (DoctorSpecException& e)
			{
				e.show();
			}
			catch (SurgenException& e)
			{
				e.show();
			}
		} while (!isValid);
	}
}
Staff staffQA()
{
	string pName;

	cout << "name: ";
	cin.ignore(NAME_LENGTH, '\n');
	getline(cin,pName);
	return Staff(pName);

}
int surQA()
{
	int numOfSur;
	cout << "how many surgerys did the surgeon preform: ";
	do
	{
		cin >> numOfSur;
	} while (numOfSur<EMPTY);
	return numOfSur;
}
/*
bool addDocToList(Doctor & doc, Doctor ** (&docList), int & docListSize, int & numOfDocs, Department **(&departments), const int & numOfDepartments)
{
	if (numOfDocs == docListSize)
	{
		if (numOfDocs == EMPTY)
		{
			docList = new Doctor*[sizeof(Doctor*) * 2]{ nullptr };
			docListSize = 2;
		}
		else
		{
			resizeArrDoc(docListSize, docList);
		}
	}
	docList[numOfDocs++] = &doc;
	*departments[departmentChoice(departments, numOfDepartments)]+=doc;
	return true;

}
void resizeArrDoc(int & size, Doctor **(&arr))// resizing doctor array
{
	Doctor** t = arr;
	Doctor** tempArr = new Doctor*[sizeof(Doctor*)*size * 2];
	for (unsigned int  i = 0; i < size; i++)
	{
		*(tempArr + i) = *(arr + i);
		*(arr + i) = nullptr;
	}
	size *= 2;
	arr = tempArr;
	delete[]t;
}
*/
//-----------------------------------------------------------------------
void initNurse(Hospital& hospital)
{

	int input;
	cout << "how many nurses to add?";
	cin >> input;
	while (input < MIN_NUM_OF_TYPE)
	{
		cout << "incorect number please insert a new one: \n";
		cin >> input;

	}
	for (unsigned int  i = 0; i < input; i++)
	{
		bool isValid = false;
		cout << "nurse number" << i + 1 << " : ";
		do
		{
			try {
				Nurse* nurse = new Nurse(staffQA());
				nurse->setYearOfExp(nurseQA());
				*(hospital.departments[departmentChoice(hospital.departments)]) += *nurse;
				hospital.nurses.push_back(nurse);
				isValid = true;
			}
			catch (StaffNameException& e)
			{
				e.show();
			}
			catch (NurseExeption& e)
			{
				e.show();
			}
		} while (!isValid);
		
		cout << "\n---------------- \n";

	}
}
int nurseQA()
{
	int  years;


	cout << "years of expertise: ";
	cin >> years;
	while (years < MIN_YEAR_NUMBER)
	{
		cout << "years is incorrect reenter years: \n";
		cin >> years;

	}
	return years;
}

void addArticlePromptUser(Staff& researcher)
{
	Researcher* tempRes = dynamic_cast<Researcher*>(&researcher);
	if (tempRes)
	{
		int input;

		cout << "how many articles to add? ";
		cin >> input;
		while (input < MIN_NUM_OF_TYPE)
		{
			cout << "incorect number please insert a new one: \n";
			cin >> input;

		}
		for (unsigned int i = 0; i < input; i++)
		{
			cout << "article number" << i + 1 << ": \n";

			tempRes->addArticle(articleQA());
			cout << "---------------- \n";

		}
	}
	else
		throw;

}

Article* articleQA()
{
	bool isValid = false;
	int  year,month,day;
	string pName, pSpec;
	do
	{
		try
		{
			cout << "name: ";
			cin.ignore(NAME_LENGTH, '\n');
			getline(cin,pName);
			
			cout << "magazine name: ";
			getline(cin,pSpec);	

			cout << "date of publication ( day month year) order: ";
			cin >> day >> month >> year;
			Article* article = new Article(pName, pSpec, Date(day, month, year));
			isValid = true;
			return article;
		}
		catch (DateException& e)
		{
			cout << typeid(Article).name() << " with error ";
			e.show();

		}
		catch (ArticleException& e)
		{
			cout << typeid(Article).name() << " with error ";
			e.show();

		}
		catch (MagazineException& e)
		{
			cout << typeid(Article).name() << " with error ";
			e.show();

		}

	} while (!isValid);
	return nullptr;
}
int menuPrint()
{
	int input;
	cout << endl << "----------------------------------------\n" <<
		"Please enter your desired action\n" <<
		"press 0 to clear the screen\n" <<
		"press 1 to add a new department\n" <<
		"press 2 to add new doctors\n" <<
		"press 3 to add a new nurse\n" <<
		"press 4 to add a patient\n" <<
		"press 5 to add a new researcher\n" <<
		"press 6 to print a department's patient list\n" <<
		"press 7 to print all of the hospital's medical staff\n" <<
		"press 8 to print all of the hospital's research team\n" <<
		"press 9 to search a patient\n" <<
		"press 10 to compare between two researcher's artical numbers\n"
		"press -1 to exit\n";
	cin >> input;
	cout << endl << "-----------------------------------------" << endl;
	return input;
}
void mainChoice(Hospital& hospital)
{
	int depNum;
	int select = INIT_POS;
	Department* dep;

	while (select != EXIT)
	{
		select = menuPrint();

		switch (select)
		{
		case CLEAR_SCREEN:
		{
			system("CLS");
		}
		break;
		case NEW_DEPARTMENT:
		{

			initDepartment(hospital);
		}
		break;
		case NEW_DOCTOR:
		{
			initDoctor(hospital);
		}
		break;
		case NEW_NURSE:
		{
			initNurse(hospital);

		}
		break;
		case ADD_PATIENT:
		{
			addNewPatient(hospital);
		}
		break;
		case NEW_RESEARCHER:
		{
			initResearcher(hospital);
		}
		break;
		case PRINT_DEP_PATIENTS_LIST:
		{
			depNum = departmentChoice(hospital.departments);
			cout << "The departments's patients are:\n";
			hospital.departments[depNum]->printPatients();
		}
		break;
		case PRINT_MEDICAL_STAFF:
		{
			printStaff(hospital);
		}
		break;
		case PRINT_RESEARCH_TEAM:
		{
			printRes(hospital);
		}
		break;
		case SEARCH_PATIENT:
		{
			searchPatient(hospital.patients);
		}
		break;
		case COMPARE_RESEARCHERS:
		{
			compareResearcher(hospital);
		}
		case EXIT:
		{
			ofstream outFile(FILE_NAME, ios::trunc);
			saveToFile(hospital.departments, outFile);
			saveToFile(hospital.doctors, outFile);
			saveToFile(hospital.nurses, outFile);
			outFile.close();
			
		}
			break;
		default: {cout << "incorect input please choose from the folowing options\n"; }
		}

	}
}
int departmentChoice(vector<Department*>& departments)
{
	int depNum;
	cout << "please choose a department number:\n";
	print<Department*>(departments, true);
	cin >> depNum;
	while (depNum<EMPTY || depNum>departments.size())
	{
		cout << "no department like that exists please select from the list above \n";
		cin >> depNum;
	}
	return depNum - 1;
}


void printStaff(Hospital& hos)
{
	print<Doctor*>(hos.doctors);
	print<Nurse*>(hos.nurses);
}
void printRes(Hospital& hos)
{
	print<Researcher*>(hos.doctors);
	print<Researcher*>(hos.researchers);
}

void printSurgeonList(Doctor**(&doc), const int& numOfDoc)
{
	Surgeon* temp;
	bool found;
	if (numOfDoc != EMPTY)
	{

		cout << "The hospital's surgeons are:\n";
		for (unsigned int i = 0; i < numOfDoc; i++)
		{
			temp = dynamic_cast<Surgeon*>(doc[i]);
			if (temp)
			{
				cout << i + 1 << ": ";
				temp->show();
				cout << endl;
				found = true;
			}
		}
	}
	if (!found)
	{
		cout << "There are no surgeons in the hospital\n";
	}
}

bool DoesSurExist(Doctor**(&doc), const int& numOfDoc)
{
	Surgeon* temp;
	bool found = false;
	if (numOfDoc != EMPTY)
	{

		for (unsigned int i = 0; i < numOfDoc; i++)
		{
			temp = dynamic_cast<Surgeon*>(doc[i]);
			if (temp)
			{
				return true;
			}
		}
	}
	return false;
}

int researcherChoice(Hospital& hos)
{
	int numOfDoc = hos.doctors.size();
	int numOfRes = hos.researchers.size();
	int resId;
	Researcher* temp;

	cout << "please type the desired researcher's number:\n";
	if (numOfRes > EMPTY)
		print<Researcher*>(hos.researchers, true);
	if (numOfDoc > EMPTY)
			print<DocResearcher*>(hos.doctors, true,numOfRes);
	cin >> resId;
	while (resId<EMPTY || resId>numOfDoc+numOfRes)
	{
		cout << "no researcher like that exists please select from the list above \n";
		cin >> resId;
	}
	return resId;

}

void compareResearcher(Hospital& hos)
{
	int res1, res2;
	Researcher* temp1;
	Researcher* temp2;

	int numOfDoc = hos.doctors.size();
	int numOfRes = hos.researchers.size();

	res1 = researcherChoice(hos);
	res2 = researcherChoice(hos);

	if (res1 > numOfRes)
	{
		temp1 = dynamic_cast<Researcher*>(hos.doctors[res1-numOfRes-1]);
	}
	else 
	{
		temp1 = hos.researchers[res1-1];
	}
	if (res2 > numOfRes)
	{
		temp2 = dynamic_cast<Researcher*>(hos.doctors[res2 - numOfRes-1]);
	}
	else
	{
		temp2 = hos.researchers[res2-1];
	}
	if (temp1 && temp2)
	{
		if (*temp1 > *temp2)
			cout << temp1->getName() << " has more articals than " << temp2->getName() << endl;
		else if (*temp1 < *temp2)
			cout << temp2->getName() << " has more articals than " << temp1->getName() << endl;
		else
			cout << temp1->getName() << " and " << temp2->getName() << " has the same number of articals\n";
	}
	else
		cout << "InValid choice\n";
}


