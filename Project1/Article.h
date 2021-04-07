#ifndef __article
#define __article
#include "date.h"
#include <iostream>
#include "GlobalConsts.h"
class Article
{
public:
	Article(const string& researchName, const string& _magName,const Date & _date)throw(Exception);
	~Article();
	Article(ifstream& in);
	const string& getName()const;
	const string& getMagName()const;
	const Date& getDate()const;
	friend std::ostream& operator<<(std::ostream& os, const Article& art); 

private:
	string name;
	string magName;
	const Date date;

};

class ArticleException:public Exception
{
public:
	virtual void show() const;

};

class MagazineException: public ArticleException
{
public:
	virtual void show() const;

};


#endif // __article

