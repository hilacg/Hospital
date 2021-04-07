
#ifndef __Dresearcher
#define __Dresearcher
#include "researcher.h"
#include "doctor.h"
#include <string>
using namespace std;
class DocResearcher :virtual public Researcher, virtual public Doctor
{
public:
	virtual std::ostream& saveToFile(ostream& os)const;

	DocResearcher( Doctor& doc, Researcher& res);
	virtual ~DocResearcher();
	DocResearcher(DocResearcher& other);
	DocResearcher(ifstream& in);
	
	friend ostream& operator << (ostream& os, const DocResearcher& res);

	virtual void show();
	virtual string& className();


protected:
	
};



#endif // _Dresercher

