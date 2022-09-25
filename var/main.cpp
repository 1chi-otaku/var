#include <iostream>
#include "MyString.h"
#include "var.h"
using namespace std;


int main() {
	var a = 10, b = "120";
	var c = a + b;
	c.Print(); // Выведет 130
	cout << endl;
	c = b + a;
	c.Print(); // Выведет “12010”
	cout << endl;
	a = "Microsoft", b = "Windows";
	c = a * b;
	c.Print();    // Выведет “ioso”
	cout << endl;
	a = "Microsoft", b = "Windows";
	c = a / b;
	c.Print();    // Выведет “Mcrft”
	cout << endl;
	a = "Hello!";
	b = "Hello!";
	if (a == b) cout << "Equal\n"; else cout << "Not Equal\n";
	cout << endl;
	return 0;
}