#include "var.h"
#include <cstdlib>

var::var(int value)
{
	str_var = "\0";
	int_var = value;
	d_var = 0;
	type = 1;
}

var::var(double value)
{
	str_var = "\0";
	d_var = value;
	int_var = 0;
	type = 2;
}

var::var(const char* value)
{
	str_var = value;
	int_var = 0;
	d_var = 0;
	type = 3;

}

void var::Print()
{
	switch (type)
	{
	case 1:
		cout << int_var; break;
	case 2:
		cout << d_var; break;
	case 3:
		str_var.Print(); break;
	}
}

var& var::operator=(int new_value){

	if (type == 2 || type == 3)
		type = 1;

	int_var = new_value;

	return *this;
}
var& var::operator=(double new_value)
{
	if (type == 1 || type == 3)
		type = 2;

	d_var = new_value;
		
	return *this;
}
var& var::operator=(const char* new_value) {
	if (type == 1 || type == 2)
		type = 3;

	str_var = new_value;

	return *this;
}

var var::operator+(int value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.int_var = temp.int_var + value;
		break;

	case 2:
		temp.d_var = temp.d_var + value;
		break;

	case 3:
		char buffer[32];
		_itoa_s(value, buffer, 10);
		temp.str_var.MyStrCat(buffer);
		break;
	}
	return temp;
}
var var::operator+(double value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.type = 2;
		temp.d_var = int_var + value;
		break;

	case 2:
		temp.d_var = d_var + value;
		break;
	case 3:
		char buffer[32];
		snprintf(buffer, 32, "%lf", value);
		temp.str_var.MyStrCat(buffer);
		break;
	}
	return temp;
}
var var::operator+(const char* value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.int_var += atoi(value);
		break;
	case 2:
		temp.d_var += atof(value);
		break;
	case 3:
		temp.str_var.MyStrCat(value);
		break;
	}
	return temp;
}

var var::operator-(int value)
{
	var temp(*this);
	switch (type)
	{
	case 1:
		temp.int_var -= value;
		break;

	case 2:
		temp.d_var -= value;
		break;

	case 3:
		char buffer[32];
		_itoa_s(value, buffer, 10);
		temp.str_var.MyStrCat(buffer);
		break;
	}
	return temp;
}
var var::operator-(double value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.type = 2;
		temp.d_var = int_var - value;
		break;

	case 2:
		temp.d_var = d_var - value;
		break;
	case 3:
		char buffer[32];
		snprintf(buffer, 32, "%lf", value);
		temp.str_var.MyStrCat(buffer);
		break;
	}
	return temp;
}
var var::operator-(const char* value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.int_var -= atoi(value);
		break;
	case 2:
		temp.d_var -= atof(value);
		break;
	case 3:
		temp.str_var.MyStrCat(value);
		break;
	}
	return temp;
}

var var::operator*(int value)
{
	var temp(*this);
	switch (type)
	{
	case 1:
		temp.int_var *= value;
		break;

	case 2:
		temp.d_var *= value;
		break;

	case 3:
		char buffer[32];
		_itoa_s(value, buffer, 10);
		temp.str_var.MyStrCat(buffer);
		break;
	}
	return temp;
}
var var::operator*(double value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.type = 2;
		temp.d_var = int_var * value;
		break;

	case 2:
		temp.d_var = d_var * value;
		break;
	case 3:
		char buffer[32];
		snprintf(buffer, 32, "%lf", value);
		temp.str_var.MyStrCat(buffer);
		break;
	}
	return temp;
}
var var::operator*(const char* value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.int_var *= atoi(value);
		break;
	case 2:
		temp.d_var *= atof(value); 
		break;
	case 3: 
		char buffer[64];
		int k = 0;
		for (int i = 0; i < temp.str_var.MyStrLen(); i++)
		{
			for (int j = 0; j < strlen(value); j++)
			{
				if (value[j] == temp.str_var[i]) {
					buffer[k] = value[j];
					k++;
				}
			}
		}
		buffer[k] = '\0';
		temp.str_var = buffer;
		break;
	}
	return temp;
}

var var::operator/(int value)
{
	var temp(*this);
	switch (type)
	{
	case 1:
		temp.int_var /= value;
		break;

	case 2:
		temp.d_var /= value;
		break;

	case 3:
		char buffer[32];
		_itoa_s(value, buffer, 10);
		temp.str_var.MyStrCat(buffer);
		break;
	}
	return temp;
}
var var::operator/(double value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.type = 2;
		temp.d_var = int_var / value;
		break;

	case 2:
		temp.d_var = d_var / value;
		break;
	case 3:
		char buffer[32];
		snprintf(buffer, 32, "%lf", value);
		temp.str_var.MyStrCat(buffer);
		break;
	}
	return temp;
}
var var::operator/(const char* value)
{
	var temp(*this);

	switch (type)
	{
	case 1:
		temp.int_var /= atoi(value);
		break;
	case 2:
		temp.d_var /= atof(value);
		break;
	case 3:
		bool isAps = true;
		char buffer[64];
		int k = 0;
		for (int i = 0; i < temp.str_var.MyStrLen(); i++)
		{
			for (int j = 0; j < strlen(value); j++)
			{
				if (value[j] == temp.str_var[i]) {
					isAps = false;
					break;
				}
			}
			if (isAps) {
				buffer[k] = temp.str_var[i];
				k++;
			}
			isAps = true;
		}
		buffer[k] = '\0';
		temp.str_var = buffer;
		break;
	}
	return temp;
}


