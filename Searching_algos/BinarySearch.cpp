#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;


int binarySearchIterative(int array[], int length, int key)
{
	int begin_index{0};
	int end_index{length};
	int middle_index{-1};

	while(begin_index <= end_index)
	{
		middle_index = (begin_index + end_index)/2;

		if(array[middle_index] == key)
			return middle_index;

		else if(key < array[middle_index])
			end_index = middle_index - 1;

		else
			begin_index = middle_index + 1;
	}
	return -1;
}

int binarySearchRecursive(int array[], int begin_index, int end_index, int key)
{
	int middle_index = (begin_index + end_index) / 2;

	if(begin_index > end_index)
		return -1;

	else if(key == array[middle_index])
		return middle_index;

	else if(key < array[middle_index])
		return binarySearchRecursive(array, begin_index, middle_index-1, key);

	else
		return binarySearchRecursive(array, middle_index+1, end_index, key);
}

void input(int array[], int length)
{
	cout << "\nEnter a sorted array to be searched:-" << endl;
	for(int i=0 ; i<length ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int array[n];

	input(array, n);

	int key;
	cout << "\nEnter the element you wanna find: ";
	cin >> key;

	int result{-1};

	if((result = binarySearchIterative(array, n-1 , key)) != -1)
	{
		cout << "\nThe element " << key << " is found at index " << result << endl;
	}
	else
	{
		cout << "\nThe element " << key << " was not found." << endl;
	}

	if((result = binarySearchRecursive(array, 0, n-1 , key)) != -1)
	{
		cout << "\nThe element " << key << " is found at index " << result << endl;
	}
	else
	{
		cout << "\nThe element " << key << " was not found." << endl;
	}
	return 0;
}

