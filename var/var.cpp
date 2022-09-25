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

var var::operator+(int value)const
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
var var::operator+(double value)const
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
var var::operator+(const char* value)const
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

var var::operator-(int value)const
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
var var::operator-(double value)const
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
var var::operator-(const char* value)const
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

var var::operator*(int value)const
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
var var::operator*(double value)const
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
var var::operator*(const char* value)const
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

var var::operator/(int value)const
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
var var::operator/(double value)const
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
var var::operator/(const char* value)const
{
	var temp(*this);

	switch (type)
	{
	case 1:
		char buffer[32];
		_itoa_s(int_var, buffer, 10);
		temp.str_var.MyStrCat(buffer);
		break;
	case 2:
		char buffer2[32];
		snprintf(buffer2, 32, "%lf",d_var);
		temp.str_var.MyStrCat(buffer2);
		break;
	case 3:
		bool isAps = true;
		char buffer3[64];
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
				buffer3[k] = temp.str_var[i];
				k++;
			}
			isAps = true;
		}
		buffer3[k] = '\0';
		temp.str_var = buffer3;
		break;
	}
	return temp;
}

var& var::operator+=(int value)
{
	switch (type)
	{
	case 1:
		int_var += value;
		break;

	case 2:
		d_var += value;;
		break;

	case 3:
		char buffer[32];
		_itoa_s(value, buffer, 10);
		str_var.MyStrCat(buffer);
		break;
	}
	return *this;
}
var& var::operator+=(double value)
{
	switch (type)
	{
	case 1:
		type = 2;
		d_var = int_var + value;
		break;

	case 2:
		d_var += value;
		break;
	case 3:
		char buffer[32];
		snprintf(buffer, 32, "%lf", value);
		str_var.MyStrCat(buffer);
		break;
	}
	return *this;
}
var& var::operator+=(const char* value)
{
	switch (type)
	{
	case 1:
		int_var += atoi(value);
		break;
	case 2:
		d_var += atof(value);
		break;
	case 3:
		str_var.MyStrCat(value);
		break;
	}
	return *this;
}

var& var::operator-=(int value)
{
	switch (type)
	{
	case 1:
		int_var -= value;
		break;

	case 2:
		d_var -= value;
		break;

	case 3:
		char buffer[32];
		_itoa_s(value, buffer, 10);
		str_var.MyStrCat(buffer);
		break;
	}
	return *this;
}
var& var::operator-=(double value)
{
	switch (type)
	{
	case 1:
		type = 2;
		d_var = int_var - value;
		break;

	case 2:
		d_var -= value;
		break;
	case 3:
		char buffer[32];
		snprintf(buffer, 32, "%lf", value);
		str_var.MyStrCat(buffer);
		break;
	}
	return *this;
}
var& var::operator-=(const char* value)
{
	switch (type)
	{
	case 1:
		int_var -= atoi(value);
		break;
	case 2:
		d_var -= atof(value);
		break;
	case 3:
		str_var.MyStrCat(value);
		break;
	}
	return *this;
}

var& var::operator*=(int value)
{
	switch (type)
	{
	case 1:
		int_var *= value;
		break;

	case 2:
		d_var *= value;
		break;

	case 3:
		char buffer[32];
		_itoa_s(value, buffer, 10);
		str_var.MyStrCat(buffer);
		break;
	}
	return *this;
}
var& var::operator*=(double value)
{
	switch (type)
	{
	case 1:
		type = 2;
		d_var = int_var * value;
		break;

	case 2:
		d_var = d_var * value;
		break;
	case 3:
		char buffer[32];
		snprintf(buffer, 32, "%lf", value);
		str_var.MyStrCat(buffer);
		break;
	}
	return *this;
}
var& var::operator*=(const char* value)
{
	switch (type)
	{
	case 1:
		int_var *= atoi(value);
		break;
	case 2:
		d_var *= atof(value);
		break;
	case 3:
		char buffer[64];
		int k = 0;
		for (int i = 0; i < str_var.MyStrLen(); i++)
		{
			for (int j = 0; j < strlen(value); j++)
			{
				if (value[j] == str_var[i]) {
					buffer[k] = value[j];
					k++;
				}
			}
		}
		buffer[k] = '\0';
		str_var = buffer;
		break;
	}
	return *this;
}

var& var::operator/=(int value)
{
	switch (type)
	{
	case 1:
		int_var /= value;
		break;

	case 2:
		d_var /= value;
		break;

	case 3:
		char buffer[32];
		_itoa_s(value, buffer, 10);
		str_var.MyStrCat(buffer);
		break;
	}
	return *this;
}
var& var::operator/=(double value)
{
	switch (type)
	{
	case 1:
		type = 2;
		d_var = int_var /= value;
		break;

	case 2:
		d_var = d_var /= value;
		break;
	case 3:
		char buffer[32];
		snprintf(buffer, 32, "%lf", value);
		str_var.MyStrCat(buffer);
		break;
	}
	return *this;
}
var& var::operator/=(const char* value)
{
	switch (type)
	{
	case 1:
		int_var /= atoi(value);
		break;
	case 2:
		d_var /= atof(value);
		break;
	case 3:
		bool isAps = true;
		char buffer[64];
		int k = 0;
		for (int i = 0; i < str_var.MyStrLen(); i++)
		{
			for (int j = 0; j < strlen(value); j++)
			{
				if (value[j] == str_var[i]) {
					isAps = false;
					break;
				}
			}
			if (isAps) {
				buffer[k] = str_var[i];
				k++;
			}
			isAps = true;
		}
		buffer[k] = '\0';
		str_var = buffer;
		break;
	}
	return *this;
}

bool var::operator>(int value) const
{
	switch (type)
	{
	case 1:
		if (int_var > value)return 1;
		else return 0;

	case 2:
		if (d_var > value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() > value) return 1;
		else return 0;
	}
}
bool var::operator>(double value) const
{
	switch (type)
	{
	case 1:
		if (int_var > value)return 1;
		else return 0;

	case 2:
		if (d_var > value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() > value) return 1;
		else return 0;
	}
}
bool var::operator>(const char* value) const
{
	switch (type)
	{
	case 1:
		if (int_var > strlen(value)) return 1;
		else return 0;

	case 2:
		if (int(d_var)> strlen(value))return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() > strlen(value)) return 1;
		else return 0;
	}
}

bool var::operator<(int value) const
{
	switch (type)
	{
	case 1:
		if (int_var < value)return 1;
		else return 0;

	case 2:
		if (d_var < value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() < value) return 1;
		else return 0;
	}
}
bool var::operator<(double value) const
{
	switch (type)
	{
	case 1:
		if (int_var < value)return 1;
		else return 0;

	case 2:
		if (d_var < value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() < value) return 1;
		else return 0;
	}
}
bool var::operator<(const char* value) const
{
	switch (type)
	{
	case 1:
		if (int_var < strlen(value)) return 1;
		else return 0;

	case 2:
		if (int(d_var) < strlen(value))return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() < strlen(value)) return 1;
		else return 0;
	}
}

bool var::operator>=(int value) const
{
	switch (type)
	{
	case 1:
		if (int_var >= value)return 1;
		else return 0;

	case 2:
		if (d_var >= value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() >= value) return 1;
		else return 0;
	}
}
bool var::operator>=(double value) const
{
	switch (type)
	{
	case 1:
		if (int_var >= value)return 1;
		else return 0;

	case 2:
		if (d_var >= value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() >= value) return 1;
		else return 0;
	}
}
bool var::operator>=(const char* value) const
{
	switch (type)
	{
	case 1:
		if (int_var >= strlen(value)) return 1;
		else return 0;

	case 2:
		if (int(d_var) >= strlen(value))return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() >= strlen(value)) return 1;
		else return 0;
	}
}

bool var::operator<=(int value) const
{
	switch (type)
	{
	case 1:
		if (int_var <= value)return 1;
		else return 0;

	case 2:
		if (d_var <= value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() <= value) return 1;
		else return 0;
	}
}
bool var::operator<=(double value) const
{
	switch (type)
	{
	case 1:
		if (int_var <= value)return 1;
		else return 0;

	case 2:
		if (d_var <= value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() <= value) return 1;
		else return 0;
	}
}
bool var::operator<=(const char* value) const
{
	switch (type)
	{
	case 1:
		if (int_var <= strlen(value)) return 1;
		else return 0;

	case 2:
		if (int(d_var) <= strlen(value))return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() <= strlen(value)) return 1;
		else return 0;
	}
}

bool var::operator==(int value) const
{
	switch (type)
	{
	case 1:
		if (int_var == value)return 1;
		else return 0;

	case 2:
		if (d_var == value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() == value) return 1;
		else return 0;
	}
}
bool var::operator==(double value) const
{
	switch (type)
	{
	case 1:
		if (int_var == value)return 1;
		else return 0;

	case 2:
		if (d_var == value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() == value) return 1;
		else return 0;
	}
}
bool var::operator==(const char* value) const
{
	switch (type)
	{
	case 1:
		if (int_var == strlen(value)) return 1;
		else return 0;

	case 2:
		if (int(d_var) == strlen(value))return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() == strlen(value)) return 1;
		else return 0;
	}
}

bool var::operator!=(int value) const
{
	switch (type)
	{
	case 1:
		if (int_var != value)return 1;
		else return 0;

	case 2:
		if (d_var != value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() != value) return 1;
		else return 0;
	}
}
bool var::operator!=(double value) const
{
	switch (type)
	{
	case 1:
		if (int_var != value)return 1;
		else return 0;

	case 2:
		if (d_var != value)return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() != value) return 1;
		else return 0;
	}
}
bool var::operator!=(const char* value) const
{
	switch (type)
	{
	case 1:
		if (int_var != strlen(value)) return 1;
		else return 0;

	case 2:
		if (int(d_var) != strlen(value))return 1;
		else return 0;
	case 3:
		if (str_var.MyStrLen() != strlen(value)) return 1;
		else return 0;
	}
}

var var::operator+(var var2) const
{
	var temp(*this);
	switch (type)
	{
	case 1:
		switch (var2.type)
		{
		case 1:
			temp.int_var += var2.int_var;
			break;
		case 2:
			temp.d_var += var2.d_var;
			break;
		case 3:
			temp.int_var += atoi(var2.str_var);
			break;
		}

	case 2:
		switch (var2.type)
		{
		case 1:
			temp.type = 2;
			temp.d_var = var2.int_var + d_var;
			break;
		case 2:
			temp.d_var += var2.d_var;
			break;
		case 3:
			temp.d_var += atof(var2.str_var);
			break;
		}

	case 3:
		switch (var2.type)
		{
		case 1:
			char buffer[32];
			_itoa_s(var2.int_var, buffer, 10);
			temp.str_var.MyStrCat(buffer);
			break;
		case 2:
			char buffer2[32];
			snprintf(buffer2, 32, "%lf", var2.d_var);
			temp.str_var.MyStrCat(buffer2);
			break;
		case 3:
			temp.str_var.MyStrCat(var2.str_var);
			break;
		}
	}
	return temp;
}
var var::operator-(var var2) const
{
	var temp(*this);
	switch (type)
	{
	case 1:
		switch (var2.type)
		{
		case 1:
			temp.int_var -= var2.int_var;
			break;
		case 2:
			temp.d_var -= var2.d_var;
			break;
		case 3:
			temp.int_var -= atoi(var2.str_var);
			break;
		}

	case 2:
		switch (var2.type)
		{
		case 1:
			temp.type = 2;
			temp.d_var = var2.int_var - d_var;
			break;
		case 2:
			temp.d_var -= var2.d_var;
			break;
		case 3:
			temp.d_var -= atof(var2.str_var);
			break;
		}

	case 3:
		switch (var2.type)
		{
		case 1:
			char buffer[32];
			_itoa_s(var2.int_var, buffer, 10);
			temp.str_var.MyStrCat(buffer);
			break;
		case 2:
			char buffer2[32];
			snprintf(buffer2, 32, "%lf", var2.d_var);
			temp.str_var.MyStrCat(buffer2);
			break;
		case 3:
			temp.str_var.MyStrCat(var2.str_var);
			break;
		}
	}
	return temp;
}
var var::operator*(var var2) const
{
	var temp(*this);
	switch (type)
	{
	case 1:
		switch (var2.type)
		{
		case 1:
			temp.int_var *= var2.int_var;
			break;
		case 2:
			temp.d_var *= var2.d_var;
			break;
		case 3:
			temp.int_var *= atoi(var2.str_var);
			break;
		}

	case 2:
		switch (var2.type)
		{
		case 1:
			temp.type = 2;
			temp.d_var = var2.int_var * d_var;
			break;
		case 2:
			temp.d_var *= var2.d_var;
			break;
		case 3:
			temp.d_var *= atof(var2.str_var);
			break;
		}

	case 3:
		switch (var2.type)
		{
		case 1:
			char buffer[32];
			_itoa_s(var2.int_var, buffer, 10);
			temp.str_var.MyStrCat(buffer);
			break;
		case 2:
			char buffer2[32];
			snprintf(buffer2, 32, "%lf", var2.d_var);
			temp.str_var.MyStrCat(buffer2);
			break;
		case 3:
			char buffer3[64];
			int k = 0;
			for (int i = 0; i < temp.str_var.MyStrLen(); i++)
			{
				for (int j = 0; j < strlen(var2.str_var); j++)
				{
					if (var2.str_var[j] == temp.str_var[i]) {
						buffer3[k] = var2.str_var[j];
						k++;
					}
				}
			}
			buffer3[k] = '\0';
			temp.str_var = buffer3;
			break;
		}
	}
	return temp;
}
var var::operator/(var var2) const
{
	var temp(*this);
	switch (type)
	{
	case 1:
		switch (var2.type)
		{
		case 1:
			temp.int_var /= var2.int_var;
			break;
		case 2:
			temp.d_var /= var2.d_var;
			break;
		case 3:
			temp.int_var /= atoi(var2.str_var);
			break;
		}

	case 2:
		switch (var2.type)
		{
		case 1:
			temp.type = 2;
			temp.d_var = var2.int_var / d_var;
			break;
		case 2:
			temp.d_var /= var2.d_var;
			break;
		case 3:
			temp.d_var /= atof(var2.str_var);
			break;
		}

	case 3:
		switch (var2.type)
		{
		case 1:
			char buffer[32];
			_itoa_s(var2.int_var, buffer, 10);
			temp.str_var.MyStrCat(buffer);
			break;
		case 2:
			char buffer2[32];
			snprintf(buffer2, 32, "%lf", var2.d_var);
			temp.str_var.MyStrCat(buffer2);
			break;
		case 3:
			bool isAps = true;
			char buffer3[64];
			int k = 0;
			for (int i = 0; i < temp.str_var.MyStrLen(); i++)
			{
				for (int j = 0; j < strlen(var2.str_var); j++)
				{
					if (var2.str_var[j] == temp.str_var[i]) {
						isAps = false;
						break;
					}
				}
				if (isAps) {
					buffer3[k] = temp.str_var[i];
					k++;
				}
				isAps = true;
			}
			buffer3[k] = '\0';
			temp.str_var = buffer3;
			break;
		}
	}
	return temp;
}

bool var::operator>(var var2) const
{
	switch (type)
	{
	case 1:
		switch (var2.type)
		{
		case 1:
			if (int_var > var2.int_var)return 1;
			else return 0;
		case 2:
			if (int_var > var2.d_var)return 1;
			else return 0;
		case 3:
			if (int_var > var2.str_var.MyStrLen()) return 1;
			else return 0;
		}
		break;
	case 2:
		switch (var2.type)
		{
		case 1:
			if (d_var > var2.d_var)return 1;
			else return 0;
		case 2:
			if (d_var > var2.d_var)return 1;
			else return 0;
		case 3:
			if (int(d_var) > var2.str_var.MyStrLen())return 1;
			else return 0;
		}
		break;
	case 3:
		switch (var2.type)
		{
		case 1:
			if (str_var.MyStrLen() > var2.int_var) return 1;
			else return 0;
		case 2:
			if (str_var.MyStrLen() > int(var2.d_var)) return 1;
			else return 0;
		case 3:
			if (str_var.MyStrLen() > var2.str_var.MyStrLen()) return 1;
			else return 0;
		}
	}
	return 0;
}
bool var::operator<(var var2) const
{
	switch (type)
	{
	case 1:
		switch (var2.type)
		{
		case 1:
			if (int_var < var2.int_var)return 1;
			else return 0;
		case 2:
			if (int_var < var2.d_var)return 1;
			else return 0;
		case 3:
			if (int_var < var2.str_var.MyStrLen()) return 1;
			else return 0;
		}
		break;
	case 2:
		switch (var2.type)
		{
		case 1:
			if (d_var < var2.d_var)return 1;
			else return 0;
		case 2:
			if (d_var < var2.d_var)return 1;
			else return 0;
		case 3:
			if (int(d_var) < var2.str_var.MyStrLen())return 1;
			else return 0;
		}
		break;
	case 3:
		switch (var2.type)
		{
		case 1:
			if (str_var.MyStrLen() < var2.int_var) return 1;
			else return 0;
		case 2:
			if (str_var.MyStrLen() < int(var2.d_var)) return 1;
			else return 0;
		case 3:
			if (str_var.MyStrLen() < var2.str_var.MyStrLen()) return 1;
			else return 0;
		}
	}
	return 0;
}
bool var::operator==(var var2) const
{
	switch (type)
	{
	case 1:
		switch (var2.type)
		{
		case 1:
			if (int_var == var2.int_var)return 1;
			else return 0;
		case 2:
			if (int_var == var2.d_var)return 1;
			else return 0;
		case 3:
			if (int_var == var2.str_var.MyStrLen()) return 1;
			else return 0;
		}
		break;
	case 2:
		switch (var2.type)
		{
		case 1:
			if (d_var == var2.d_var)return 1;
			else return 0;
		case 2:
			if (d_var == var2.d_var)return 1;
			else return 0;
		case 3:
			if (int(d_var) == var2.str_var.MyStrLen())return 1;
			else return 0;
		}
		break;
	case 3:
		switch (var2.type)
		{
		case 1:
			if (str_var.MyStrLen() == var2.int_var) return 1;
			else return 0;
		case 2:
			if (str_var.MyStrLen() == int(var2.d_var)) return 1;
			else return 0;
		case 3:
			if (str_var.MyStrLen() == var2.str_var.MyStrLen()) return 1;
			else return 0;
		}
	}
	return 0;
}
bool var::operator!=(var var2) const
{
	switch (type)
	{
	case 1:
		switch (var2.type)
		{
		case 1:
			if (int_var != var2.int_var)return 1;
			else return 0;
		case 2:
			if (int_var != var2.d_var)return 1;
			else return 0;
		case 3:
			if (int_var != var2.str_var.MyStrLen()) return 1;
			else return 0;
		}
		break;
	case 2:
		switch (var2.type)
		{
		case 1:
			if (d_var != var2.d_var)return 1;
			else return 0;
		case 2:
			if (d_var != var2.d_var)return 1;
			else return 0;
		case 3:
			if (int(d_var) != var2.str_var.MyStrLen())return 1;
			else return 0;
		}
		break;
	case 3:
		switch (var2.type)
		{
		case 1:
			if (str_var.MyStrLen() != var2.int_var) return 1;
			else return 0;
		case 2:
			if (str_var.MyStrLen() != int(var2.d_var)) return 1;
			else return 0;
		case 3:
			if (str_var.MyStrLen() != var2.str_var.MyStrLen()) return 1;
			else return 0;
		}
	}
	return 0;
}

var::operator int() const
{
	if (type == 3) {
		return atof(str_var);
	}
	else if(type == 1)
		return int(d_var);
	
	return int_var;
}
var::operator double() const
{
	if (type == 3) {
		return atoi(str_var);
	}
	else if (type == 2) {
		return double(int_var);
	}
	return d_var;
}
var::operator const char*() const
{
	if (type == 1) {
		char buffer[32];
		_itoa_s(int_var, buffer, 10);
		return buffer;
	}
	else if (type == 2) {
		char buffer2[32];
		snprintf(buffer2, 32, "%lf", d_var);
		return buffer2;
	}
	return str_var;

}


