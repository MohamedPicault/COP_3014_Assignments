/*
Name:Mohamed Picault       Z#: Z23204935
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  03/14/2020           Due Time: 11:59 PM
Total Points: 10
Assignment #: Assignment_6.cpp

Description:

*************************************************************************************************************************/



#include <iostream>
#include <string>
#include <fstream>  
using namespace std;

const int SIZE = 50; //const mean that this array is a static array


class order_record
{
public:
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
};


//Prototypes for your functions: input, output, process and tally_inventory will go here

void input(order_record  INV[ ], int & count);
void output(const order_record  INV[], const int  count);
void process(order_record  INV[], const int  count);
double tally_inventory(const order_record  INV[], const int count);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: the variables have not been initialized
//Postcondition: The variables are now initialized.
//Description:  Read contents from data file

//*************************************************************************************

void input(order_record  INV[], int & count)
{
	//declare an ifstream
	ifstream in;
	//open the ifstream with the data file name
	in.open("purchase_data_Assignment6.txt");
	//use a while loop to read the data into the array INV
	if (in.fail())
	{
		cout << "The files does not exist or name spelled incorrectly" << endl;
	}
	else
	{
		while (!in.eof() && count < SIZE)
		{
			in 	>> INV[count].cell_number; 	
			in 	>> INV[count].item_number; 	
			in	>> INV[count].quantity;		
			in 	>> INV[count].price; 		
			in	>> INV[count].processing_plant;
				//add more code to read the contents of the data file into the array
			/*cout << INV[count].cell_number 	<< "\t" << INV[count].item_number 	<<"\t"
				 << INV[count].quantity 	<< "\t" << INV[count].price 		<<"\t"
				 <<INV[count].processing_plant <<endl;*/
			//comment text above is cout test to see if information is able to print on screen correctly.
			count++;
		}
		in.close();
	}
	
}

///*************************************************************************************
//Name:  output
//Precondition: All variables are initialized
//Postcondition: All variables are initialized.
//Description:  Prints the array to a datafile
//*************************************************************************************

void output(const order_record INV[ ], const int count)
{
	
	ofstream out;
	out.open("purchase_data.txt");

	out.setf(ios::showpoint); //remember, we are using out instead of cout
	out.precision(2);
	out.setf(ios::fixed);

	if (out.fail())
	{
		cout << "File does not exist or spelled incorrectly.";
	}
	else
	{		

		for(int i=0;i<count; i++)
		{
			/*cout << INV[i].cell_number 		<< "\t" << INV[i].item_number 	<< "\t"
				 << INV[i].quantity 		<< "\t" << INV[i].price 		<< "\t"
				 << INV[i].processing_plant << "\t" << INV[i].tax_rate		<< "\t"
				 << INV[i].order_tax 		<< "\t" << INV[i].net_cost		<< "\t"
				 << INV[i].total_cost 		<<endl;*/ 
			//test to make sure the data is printed on the scren correctly
			out << INV[i].cell_number 		<<"\t"	<< INV[i].item_number 	<<"\t"
				<< INV[i].quantity			<<"\t" 	<< INV[i].price			<<"\t"
				<< INV[i].processing_plant 	<<"\t"	<< INV[i].tax_rate 		<<"\t"
				<< INV[i].order_tax 		<<"\t"	<< INV[i].net_cost 		<<"\t"
				<< INV[i].total_cost<<endl; 	
		}
		out.close();
	}	
}

///*************************************************************************************
//Name:  process
//Precondition: cell_number, item_number, quantity, price, and processing_plant initialized.
// tax_rate, tax_cost, net_cost, and total_cost not initialized.
//Postcondition: all variables are now initialized
//Description:  calculate tax rate, tax cost, net cost, and total cost.
//*************************************************************************************

void process(order_record INV[ ], const int count)
{
	//Remember to modify the code for an array
	//Hints: 
	//use a for loop to print the data in the array INV
	for(int i=0; i<count; i++)// do not use SIZE
	{
		
		//calculate tax_rate, order tax, net cost, and total cost
		if (0 <= INV[i].processing_plant && INV[i].processing_plant <= 50)
		{
			INV[i].tax_rate = 0.06;	
		}
		else if (51 <= INV[i].processing_plant && INV[i].processing_plant <= 110)
		{
			INV[i].tax_rate = 0.07;
		}
		else if (111 <= INV[i].processing_plant && INV[i].processing_plant <= 200)
		{
			INV[i].tax_rate = 0.08;
		}
		else if (201 <= INV[i].processing_plant && INV[i].processing_plant <= 500)
		{
			INV[i].tax_rate = 0.09;
		}
		else if (500 < INV[i].processing_plant)
		{
			INV[i].tax_rate = 0.11;
		}
		INV[i].order_tax = INV[i].quantity * INV[i].price * INV[i].tax_rate;
		INV[i].net_cost = INV[i].quantity * INV[i].price;
		INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
		/*cout << INV[i].tax_rate << "\t";
		cout << INV[i].order_tax << "\t";
		cout << INV[i].net_cost << "\t";
		cout << INV[i].total_cost << endl;*/
		//block comment above is used to see the result value

	}
	

}

///*************************************************************************************
//Name:  tally_results
//Precondition: the values of total cost should have been assigned
//Postcondition: average is decalred and initialized
//Description: calculates the average of the total order cost
//*************************************************************************************
double tally_inventory(const order_record  INV[], const int  count)
{
	double average = 0.0; 
	for (int i = 0; i < count; i++)
	{
		average += INV[i].total_cost;
	}
	average /= count;

	
	return average;
}

int main()
{
	int count = 0;
	order_record INV[SIZE]; 

	input(INV, count);
	process(INV, count);
	output(INV, count);
	cout << "Average Total Order Cost = " << tally_inventory(INV, count) << endl; 

	return 0;
}