/*
* Vector_doubleTEST.cpp
* By Pedro Garate on 12/14/2014
* Description: Test program for Vector_double ADT.
*/

#include "Vector_double.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "VECTOR DOUBLES PROGRAM" << endl;
	double numbers1[] = { 13.5, 2.7, 6.8, 40.5 };
	double numbers2[] = { 5.13, 7.2, 8.6 };
	
	//testing default constructor	
	Vector_double vd1;
	Vector_double vd2(2);
	cout << "vector1:" << endl << vd1;
	cout << "vector2:" << endl << vd2;

	vd1.insert(numbers1, 1, 4);
	vd2.insert(numbers2, 1, 3);
	cout << "vector1:" << endl << vd1 << endl;
	cout << "vector2:" << endl << vd2 << endl;

	//testing overloaded assignment operator and copy constructor
	Vector_double vd3 = vd1; // copy constructor
	Vector_double vd4;
	vd4 = vd2;// overloaded assignment operator
	cout << "vector3:" << endl << vd3 << endl;
	cout << "vector4:" << endl << vd4 << endl;

	//testing capacity and size
	cout << "vector1 capacity is " << vd1.capacityCheck()
		<< "and its size is " << vd1.sizeCheck() << endl;

	//testing empty
	cout << "vector2 is empty: ";
	if (vd2.empty() == false)
		cout << "NO." << endl;
	else cout << "YES." << endl;

	//testing erase
	cout << "vector1:" << endl << vd1 << endl;
	cout << "after erasing elements 2 and 3" << endl;
	vd1.erase(2, 3);
	cout << "vector1:" << endl << vd1 << endl;

	//testing insert
	cout << "vector2:" << endl << vd2 << endl;
	cout << "after inserting 5.5 and 9.69 at position 2" << endl;
	double numbers3[] = { 5.5, 9.69 };
	vd2.insert(numbers3, 2, 2);
	cout << "vector2:" << endl << vd2 << endl;

	//testing pop_back and push_back
	cout << "vector1:" << endl << vd1 << endl;
	cout << "after pop_back" << endl;
	vd1.pop_back();
	cout << "vector1:" << endl << vd1 << endl;
	cout << "after push_back" << endl;
	vd1.push_back(4.63);
	cout << "vector1:" << endl << vd1 << endl;

	//testing resize
	cout << "vector1:" << endl << vd1 << endl;
	cout << "after resize to 10" << endl;
	vd1.resize(10, 999.99);
	cout << "vector1:" << endl << vd1 << endl;
	cout << "vector2:" << endl << vd2 << endl;
	cout << "after resize to 1" << endl;
	vd2.resize(1);
	cout << "vector2:" << endl << vd2 << endl;
	
	//testing shrink to fit
	cout << "vector1:" << endl << vd1 << endl;
	cout << "after shrink to fit" << endl;
	vd1.shrinkToFit();
	cout << "vector1:" << endl << vd1 << endl;

	return EXIT_SUCCESS;
}//end main
