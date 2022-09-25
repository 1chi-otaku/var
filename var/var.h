#pragma once
#include "MyString.h"
class var
{
	int int_var;	// Field for int var.
	double d_var;	// Field for double var.
	MyString str_var;	//Filed for string var.

	unsigned short type;	//Field that clarifies the type of var.


public:
	var(int);	//Sets type to 1.
	var(double);	//Sets type to 2.
	var(const char*);	//Sets type to 3.

	void Print();	//Prints the current var.

	var& operator=(int);	//Operator = for var + int case.
	var& operator=(double);		//Operator = for var + double case.
	var& operator=(const char*);	//Operator = for var + string case.

	var operator+(int)const;	//Operator + for var + int case.
	var operator+(double)const;		//Operator + for var + double case.
	var operator+(const char*)const;	//Operator + for var + string case.

	var operator-(int)const;	//Operator - for var - int case.
	var operator-(double)const;		//Operator - for var - double case.
	var operator-(const char*)const;	//Operator - for var - string case.

	var operator*(int)const;	//Operator * for var * int case.
	var operator*(double)const;		//Operator * for var * double case.
	var operator*(const char*)const;	//Operator * for var * string case.

	var operator/(int)const;	//Operator / for var + int case.
	var operator/(double)const;		//Operator / for var + double case.
	var operator/(const char*)const;	//Operator / for var + string case.

	var& operator+=(int);	//Operator += for var += int case.
	var& operator+=(double);	//Operator += for var += double case.
	var& operator+=(const char*);	//Operator += for var += string case.

	var& operator-=(int);	//Operator /= for var -= int case.
	var& operator-=(double);	//Operator /= for var -= double case.
	var& operator-=(const char*);	 //Operator /= for var -= string case.

	var& operator*=(int);	//Operator *= for var *= int case.
	var& operator*=(double);	//Operator *= for var *= double case.
	var& operator*=(const char*);	//Operator *= for var *= string case.

	var& operator/=(int);	//Operator /= for var /= int case.
	var& operator/=(double);	//Operator / for var /= double case.
	var& operator/=(const char*);	//Operator / for var /= string case.

	bool operator>(int)const;	//Operator > for var > int case.
	bool operator>(double)const;	//Operator > for var > double case.
	bool operator>(const char*)const;	//Operator > for var > string case.

	bool operator<(int)const;	//Operator < for var < int case.
	bool operator<(double)const;	//Operator < for var < double case.
	bool operator<(const char*)const;	//Operator < for var < string case.

	bool operator>=(int)const;	//Operator >= for var >= int case.
	bool operator>=(double)const;	//Operator >= for var >= double case.
	bool operator>=(const char*)const;	//Operator >= for var >= string case.

	bool operator<=(int)const;	//Operator <= for var <= int case.
	bool operator<=(double)const;	//Operator <= for var <= double case.
	bool operator<=(const char*)const;	//Operator <= for var <= string case.

	bool operator==(int)const;	//Operator == for var == int case.
	bool operator==(double)const;	//Operator == for var == double case.
	bool operator==(const char*)const;	//Operator == for var == string case.
	
	bool operator!=(int)const;	//Operator != for var != int case.
	bool operator!=(double)const;	//Operator != for var != double case.
	bool operator!=(const char*)const;	//Operator != for var != string case.

	var operator+(var)const;	//Operator + for var + var case.
	var operator-(var)const;	//Operator - for var - var case.
	var operator*(var)const;	//Operator * for var * var case.
	var operator/(var)const;	//Operator / for var / var case.

	bool operator>(var)const;	//Operator > for var > var case.
	bool operator<(var)const;	//Operator < for var < var case.
	bool operator==(var)const;	//Operator == for var == var case.
	bool operator!=(var)const;	//Operator != for var != var case.

	operator int() const;	//Variable transformation to int.
	operator double()const;		//Variable transformation to double.
	operator const char *()const;	//Variable transformation to string.


};



