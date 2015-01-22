/*
* Vector_double.cpp
* By Pedro Garate on 12/14/2014
* Description: ADT that manages a dynamic array of doubles.
*/
#include "Vector_double.h"

using namespace std;

// Default Constructor. If cap not specified use DEFAULT_CAPACITY
Vector_double::Vector_double(int cap)
{
	capacity = cap;
	size = 0;
	numbers = new double[cap];
}//end of Default Constructor

// Copy Constructor
Vector_double::Vector_double(const Vector_double& source)
{
	cout << "Copy Constructor called!" << endl;
	
	capacity = source.capacity;
	size = source.size;
	numbers = new double[source.capacity]; // deep copy
	
	for (int i = 0; i < size; i++)
		numbers[i] = source.numbers[i];
}//end of Copy Constructor

// Overloaded Assignment
Vector_double& Vector_double::operator=(const Vector_double& source)
{
	cout << "Overloaded Assignment called!" << endl;

	// check for self assignment
	// vd1 = vd1;
	if (this == &source)
		return *this;

	capacity = source.capacity;
	size = source.size;
	
	for (int i = 0; i < size; i++)
	    numbers[i] = source.numbers[i];

	return *this;
}//end of Overloaded Assignment

// Destructor
Vector_double::~Vector_double()
{
	cout << "Destructor called @ this memory location: " << this << endl;
	delete[] numbers;
}//end of Destructor

// what is the capacity?
int Vector_double::capacityCheck()
{
	return capacity;
}//end of capacityCheck

// is it empty?
bool Vector_double::empty()
{
	if (size == 0)
		return true;
	else return false;
}//end of empty

// Erase range (from startPos to endPos) 
void Vector_double::erase(int startPos, int endPos)
{
	if (endPos == 0)
		endPos = startPos;

	double* newArr = new double[capacity];
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (i < startPos - 1 || i > endPos - 1)
			newArr[j] = numbers[i];
		else
			j--;
	}//end for
	size = size - (endPos - startPos + 1);
	delete[] numbers;
	numbers = newArr;
}//end erase

// Insert at position
void Vector_double::insert(double nums[], int position, int numOfElements)
{
	size = size + numOfElements;
	while (size >= capacity)
		capacity = capacity * 2;
	
	double* newArr = new double[capacity];
	for (int i = 0, m = 0; i < size; i++, m++)
	{
		if (i != position - 1)
			newArr[i] = numbers[m];
		else
		{
			for (int j = position - 1, k=0; j < (position - 1 + numOfElements); j++,k++)
			{
				newArr[j] = nums[k];
				i=j;
			}//end for
			m--;
		}//end if-else
	}//end for
	delete[] numbers;
	numbers = newArr;
}//end of insert

// Delete at the end
void Vector_double::pop_back()
{
	erase(size);
}//end pop_back

// Add to the end
void Vector_double::push_back(double num)
{
	double newArr[1] = { num };
	insert(newArr, size + 1, 1);
}//end push_back

// Resize to newSize. if newSize > size use iniValue for new elements
void Vector_double::resize(int newSize, double iniValue)
{
	int temp = newSize - size;
	if (newSize < size)
	{
		erase(newSize + 1, size);
	}
	else if (newSize > size)
	{
		for (int i = 0; i < temp; i++)
			push_back(iniValue);
	}
}//end resize

// Discard excess capacity
void Vector_double::shrinkToFit()
{
	if (capacity > size)
	{
		double* newArr = new double[size];
		for (int i = 0; i < size; i++)
			newArr[i] = numbers[i];
		delete[] numbers;
		numbers = newArr;
		capacity = size;
	}
}//end shrinkToFit

// what is the size?
int Vector_double::sizeCheck()
{
	return size;
}//end sizeCheck

// Output elements
ostream& operator<<(ostream& os, const Vector_double& vd)
{
	os << "The vector's size is:     " << vd.size << endl;
	os << "The vector's capacity is: " << vd.capacity << endl;
	os << "The vector's elements are:" << endl;
	for (int i = 0; i < vd.size; i++)
		os << vd.numbers[i] << " ";
	os << endl;

	return os;
}//end operator<<
