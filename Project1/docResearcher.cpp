#pragma warning(disable:4996)

#include <iostream>

#include "docResearcher.h"



std::ostream & DocResearcher::saveToFile(ostream & os)const
{
	Staff::toOs(os);
	Researcher::toOs(os);
	Doctor::toOs(os);
	return os;
}
DocResearcher::DocResearcher(Doctor& doc, Researcher& res) :Researcher(res), Doctor(doc),Staff(doc)
{
	
}
DocResearcher::~DocResearcher()
{

}

DocResearcher::DocResearcher(DocResearcher & other):Researcher(other),Doctor(other),Staff(other)
{

}

DocResearcher::DocResearcher(ifstream & in) : Staff(in), Researcher(in), Doctor(in)
{

}



void DocResearcher::show()
{
	cout << (Staff&)(*this) << " " << (Doctor&)(*this) << " " << (Researcher&)(*this);
}

string & DocResearcher::className()
{
	return string(typeid(*this).name() +TYPE_ID_CLASS_CUT);
}


std::ostream& operator << (std::ostream& os, const DocResearcher & res)
{
	((Staff&)res).toOs(os);
	((Researcher&)res).toOs(os);
	((Doctor&)res).toOs(os);
	return os;
}
