#pragma once
#ifndef _glob
#define _glob
#include <string>
using namespace std;

const int EMPTY = 0;
const int NAME_LENGTH = 20;
const int START = 0;
const int EXIT = -1;
const int INIT_POS = -2;
const int CLEAR_SCREEN = 0;
const int NEW_DEPARTMENT = 1;
const int NEW_DOCTOR = 2;
const int NEW_NURSE = 3;
const int ADD_PATIENT = 4;
const int NEW_RESEARCHER = 5;
const int PRINT_DEP_PATIENTS_LIST = 6;
const int PRINT_MEDICAL_STAFF = 7;
const int PRINT_RESEARCH_TEAM = 8;
const int SEARCH_PATIENT = 9;
const int COMPARE_RESEARCHERS = 10;
const int TYPE_ID_CLASS_CUT = 6;
const int MALE = 0;
const int FEMALE = 1;
const int SURGERY = 0;
const int EXAMINATION = 1;

const int RES_DOC = 0;
const int RES_NURSE = 1;

const int FASTING = 1;
const int NOT_FASTING = 0;

const int DOC_ID = 1000;
const int NURSE_ID = 2000;
const int PATIENT_ID = 3000;
const int ID_LIMIT = 4000;
const int NURSE_CHOICE = 100;
const string FILE_NAME = "PROJ1.txt";

#endif