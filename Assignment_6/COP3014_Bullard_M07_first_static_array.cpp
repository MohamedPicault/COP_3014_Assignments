#include <iostream>
using namespace std;

const int SIZE = 10;

void Print(const int myArray[], const int count)
{  //note: myArray and count will not change inside this function

	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << myArray[i] << endl;
	}
	cout << endl;
}


void Insert(int myArray[], int  & count, const int key)
{//note: myArray and count will change, but key will not
	if (count < SIZE) //checking to see if the array is full
	{
		myArray[count] = key;
		count++;
	}
	else
	{
		cout << "myArray is full\n" << endl;
	}
}

int Search(int myArray[], const int & count, const int key)
{
	for (int i = 0; i < count; i++)
	{
		if (myArray[i] == key) //key found in the array
		{
			return i;   //return loc in myArray
		}
	}
	return -1; //item not found
}


void Remove(int myArray[], int & count, const int key)
{

	if (count == 0)
	{
		cout << "Array Empty " << endl;
	}
	else
	{
		int loc = Search(myArray, count, key);

		if (loc != -1)
		{
			for (int i = loc; i < count - 1; i++) //why count-1?
			{
				myArray[i] = myArray[i + 1]; //shifting down
			}
			count--;
		}
	}
}

int main()
{
	int count = 0;
	int myArray[SIZE] = { 0,0,0,0,0,0,0,0,0,0 };

	cout << "----------------------------------------\n";
	cout << "Testing Remove: Removing from empty array\n";
	Print(myArray, count);
	Remove(myArray, count, 40);
	Print(myArray, count);
	cout << "----------------------------------------\n";

	cout << "----------------------------------------\n";
	cout << "Testing Insert: Inserting in empty list\n";
	Insert(myArray, count, 40);
	Print(myArray, count);
	cout << "----------------------------------------\n";

	cout << "----------------------------------------\n";
	cout << "Testing Insert: after several inserts\n";
	Insert(myArray, count, -40);
	Insert(myArray, count, 111);
	Insert(myArray, count, 66);
	Insert(myArray, count, 999);
	Insert(myArray, count, 55);
	Print(myArray, count);
	cout << "----------------------------------------\n";

	int key = 15;
	int location = Search(myArray, count, key);

	cout << "----------------------------------------\n";
	cout << "Testing Search: key not in array\n";
	if (location == -1)
	{
		cout << key<<" was not found in myArray\n";
	}
	else
	{
		cout << key << " was found in myArray at location <<location<<\n";
	}
	cout << "----------------------------------------\n";

	key = 55;
	location = Search(myArray, count, key);

	cout << "----------------------------------------\n";
	cout << "Testing Search: key in array\n";
	if (location == -1)
	{
		cout << key << " was not found in myArray\n";
	}
	else
	{
		cout << key << " was found in myArray at location <<location<<\n";
	}
	cout << "----------------------------------------\n";

	cout << "Testing Remove: Remove lst element\n";
	Print(myArray, count);
	Remove(myArray, count, 40);
	Print(myArray, count);
	cout << "----------------------------------------\n";

	cout << "----------------------------------------\n";
	cout << "Testing Remove: Remove last element\n";
	Print(myArray, count);
	Remove(myArray, count, 55);
	Print(myArray, count);
	cout << "----------------------------------------\n";

	cout << "----------------------------------------\n";
	cout << "Testing Remove: Removing element between 1st and last\n";
	Print(myArray, count);
	Remove(myArray, count,66);
	Print(myArray, count);
	cout << "----------------------------------------\n";

	return 0;
}