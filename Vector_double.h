/*
* Vector_double.h
* By Pedro Garate on 12/14/2014
* Description: ADT that manages a dynamic array of doubles.
*/

#ifndef VECTOR_DOUBLE_
#define VECTOR_DOUBLE_

#include <iostream>

class Vector_double
{
	// Output elements
	friend std::ostream& operator<<(std::ostream& os, const Vector_double& vd);

private:
	// Data members
	int capacity;
	int size;
	double* numbers;

public:
	static const int DEFAULT_CAPACITY = 5;
	static const int DEFAULT_INITIAL_VALUE = 0;
	// Default Constructor
	Vector_double(int cap = DEFAULT_CAPACITY);
	// Copy Constructor
	Vector_double(const Vector_double& source);
	// Overloaded Assignment
	Vector_double& operator=(const Vector_double& source);
	// Destructor
	~Vector_double();
	// what is the capacity?
	int capacityCheck();
	// is it empty?
	bool empty();
	// Erase at position
	void erase(int startPos, int endPos = DEFAULT_INITIAL_VALUE);
	// Insert at position
	void insert(double nums[], int position, int numOfElements);
	// Delete at the end
	void pop_back();
	// Add to the end
	void push_back(double num);
	// Resize to newSize. if newSize > size use iniValue for new elements
	void resize(int newSize, double iniValue = DEFAULT_INITIAL_VALUE);
	// Discard excess capacity
	void shrinkToFit();
	// what is the size?
	int sizeCheck();

};// end of Vector_double

#endif /* VECTOR_DOUBLE_ */
