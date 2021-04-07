#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include "Article.h"
Article::Article(const string& researchName,const string& _magName, const Date& date)throw(ArticleException):date(date)
{
	if (researchName.size() ==EMPTY)
	{
		throw ArticleException();
	}
	if ( _magName.size() == EMPTY)
	{
		throw MagazineException();
	}
	name = researchName;
		
	magName = _magName;
	
	
}
Article::~Article() 
{
	
	
}

Article::Article(ifstream & in)
{
	string artName, magName;
	in >> artName >> magName;
}

const string& Article::getName()const
{
	return name;
}
const string& Article::getMagName()const
{
	return magName;
}
const Date & Article::getDate()const
{
	return date;
}



std::ostream & operator<<(std::ostream & os, const Article & art)
{
 if (typeid(os) == typeid(ofstream))
	{
		os << art.name << " " << art.magName << " "<< art.date<< " ";
	}
	else
		os << " articale name: " << art.name << " magazin name: " << art.magName << art.date;
	return os;
}

void ArticleException::show() const
{
	cout << "Article name is invalid \n";
}

void MagazineException::show() const
{
	cout << "Magazine name is invalid \n";
}
