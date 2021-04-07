#ifndef _INIT_HOS
#define _INIT_HOS

#include <string>
#include <iostream>
#include "Hospital.h"
#include "Staff.h"
#include "Doctor.h"
#include "docResearcher.h"
#include "surgeonResearcher.h"
#include "fileIO.h"
#include "Utils.h"
using namespace std;
const int PATIENT_SUB_INDEX = 3001;
const int DOCTOR = 1;
const int RESEARCHER = 2;
const int SURGEON = 3;
const int AOTA = 4;
const int DOC_RESEARCHER = 5;
const int MIN_NUM_OF_TYPE = 0;

Staff staffQA();

int surQA();

void initResearcher(Hospital & hos);

void initDepartment(Hospital& hospital);
void mainChoice(Hospital&);
bool setNewVisit(Hospital& hospital, const int& depNum, const int& indexP);
void addNewPatient(Hospital& hospital);
void searchPatient(vector<Patient*>& patients);
Department * departmentQA();



void initDoctor(Hospital& hospital);



void initNurse(Hospital&);

int nurseQA();
void printRes(Hospital& hos);






int departmentChoice(vector<Department*>& departments);




void addArticlePromptUser(Staff& researcher);
Article * articleQA();


void printStaff(Hospital & hos);


int researcherChoice(Hospital& hospital );
void compareResearcher(Hospital& hospital);


#endif // !_INIT_HOS