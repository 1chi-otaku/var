#pragma once
#include "MyString.h"
class var
{
	int int_var;
	double d_var;
	MyString str_var;

	unsigned short type;


public:
	var(int);
	var(double);
	var(const char*);

	void Print();

	var& operator=(int);
	var& operator=(double);
	var& operator=(const char*);

	var operator+(int)const;
	var operator+(double)const;
	var operator+(const char*)const;

	var operator-(int)const;
	var operator-(double)const;
	var operator-(const char*)const;

	var operator*(int)const;
	var operator*(double)const;
	var operator*(const char*)const;

	var operator/(int)const;
	var operator/(double)const;
	var operator/(const char*)const;

	var& operator+=(int);
	var& operator+=(double);
	var& operator+=(const char*);

	var& operator-=(int);
	var& operator-=(double);
	var& operator-=(const char*);

	var& operator*=(int);
	var& operator*=(double);
	var& operator*=(const char*);

	var& operator/=(int);
	var& operator/=(double);
	var& operator/=(const char*);

	bool operator>(int)const;
	bool operator>(double)const;
	bool operator>(const char*)const;

	bool operator<(int)const;
	bool operator<(double)const;
	bool operator<(const char*)const;

	bool operator>=(int)const;
	bool operator>=(double)const;
	bool operator>=(const char*)const;

	bool operator<=(int)const;
	bool operator<=(double)const;
	bool operator<=(const char*)const;

	bool operator==(int)const;
	bool operator==(double)const;
	bool operator==(const char*)const;
	
	bool operator!=(int)const;
	bool operator!=(double)const;
	bool operator!=(const char*)const;









};

