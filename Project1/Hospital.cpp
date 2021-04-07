#include "Hospital.h"

Hospital::Hospital()

{}

Hospital::~Hospital()
{

	for (auto obj : departments)
		delete obj;
	for (auto obj : nurses)
		delete obj;
	for (auto obj : patients)
		delete obj;
	for (auto obj : researchers)
		delete obj;
	for (auto obj : doctors)
		delete obj;


}
