#ifndef _ARR
#define _ARR
#include "GlobalConsts.h"
#include "Exception.h"
template<class T,class Cast>
void printArray(T& arr,bool count=false,int start =0)
{
	
	for (int i = 0; i < arr.getLSize(); i++)
	{
		
		auto temp = arr[i];
		if (temp)
		{
			if (count)
				cout << start++ << ": ";
			
			cout <<*temp<< endl;
		}
		
	}
	
};

template<class T>
class Array
{
public:
	Array();
	~Array();
	bool add(T& obj);
	T& removeObj(T&);
	bool deleteObj(T&);
	int findObj(T&);
	void printArray()const throw(Exception&);
	bool isEmpty();
	int getPSize()const ;
	int getLSize()const ;
	T& getObj(int index)const;
	virtual T& operator[](const int index)const;
	//void iter(void(&func)(T& obj), bool counter = false, int start = 0);
private:
	void resizeArray();
	T* arr;
	int logical;
	int physical;
};


template<class T>
Array<T>::Array():logical(EMPTY),physical(EMPTY),arr(nullptr)
{}
template<class T>
Array<T>::~Array()
{
	for (int i = 0; i < logical; i++)
	{
		delete arr[i];
	}
	delete arr;
}
template<class T>
bool Array<T>::add(T & obj)
{
	if (logical == physical)
		this->resizeArray();

	arr[logical++] = obj;

	return true;
}
template<class T>
void Array<T>::resizeArray()
{
	if (physical == 0)
		physical = 1;
	physical *= 2;
	T* toDel = arr;
	T* temp = new T[physical];
	for (int i = 0; i < logical; i++)
	{
		temp[i] = (arr)[i];
		(arr)[i] = nullptr;
	}
	delete toDel;
	arr = temp;
}
template<class T>
T & Array<T>::removeObj(T & obj)
{
	int index = findObj(obj, index);
	if (index != -1)
	{
		for (int i = index; i < logical - 1; i++)
			arr[i] = arr[i + 1];
		arr[i] = nullptr;
		logical--;
		return obj;
	}
}
template<class T>
bool Array<T>::deleteObj(T & obj)
{
	delete removeObj(obj)
	return true;
}
template<class T>
int Array<T>::findObj(T &obj)
{
	int index = 0;
	int found = false;
	while (!found&&index<logical)
	{
		if (arr[index] == obj)
			return index;
		index++;
	}
	return -1;
}
template<class T>
void Array<T>::printArray()const throw(Exception&)
{
	if (logical == 0)
		throw PrintArrayException();
	for (int i = 0; i < logical; i++)
	{
		cout << i + 1 << ": " << *arr[i] << " \n";
	}
}
template<class T>
bool Array<T>::isEmpty()
{
	return logical==EMPTY;
}

template<class T>
int Array<T>::getPSize()const
{
	return physical;
}
template<class T>
int Array<T>::getLSize()const
{
	return logical;
}

template<class T>
 T & Array<T>::getObj(int index)const
{
	 return arr[index];
}

 template<class T>
 T & Array<T>::operator[](const int index)const
 {
	 return arr[index];
 }



 class PrintArrayException : public Exception
 {
 public:
	 virtual void show();

 };



#endif // !_ARR

