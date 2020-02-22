
/************************************************************************************************************************

Name: Mohamed Picault                      Z#:23204935
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:Feb 10, 2020                Due Time:11:59 PM
Total Points: 20
Assignment #: Assignment_3.cpp

Description:

The program's purpose to to take in the values/data stored in a .txt files and transfer them within variables thought the use of the input 
function from the file i/o library, where they will later be used for calculation and displaying.
*************************************************************************************************************************/



#include <iostream>
#include <string>
#include <fstream>  //include the library for file i/o
using namespace std;


//Prototypes for your functions: input, output, and process will go here

void input(ifstream &, string &, string &, double &, double &, int &);
void output(string, string, double, double, int, double, double, double, double);
void process(double, double, int, double &, double &, double &, double &);



//Name:  input
//Precondition:the parameters arent yet to be initialized
//Postcondition:the parameters of the varaible are initialized
//Description: This function takes in the stored information on the. txt file and transfers it to local variables within thr main function.

void input(ifstream & in, string & cell_number, string & item_number, double & quantity, double & price, int & processing_plant) // call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> cell_number;
	in >> item_number; 
	in >> quantity; 
	in >> price;
	in >> processing_plant;

}


//Name:  output
//Description: This function use the decimal manipulation function to formate
//the number with the desired decimal palce.
void output(string cell_number, string item_number, double quantity, double price, int processing_plant, double tax_rate, double order_tax, double net_cost, double total_cost)
{

	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	
	cout << cell_number << "\t";
	cout << item_number << "\t";
	cout << quantity << "\t";
	cout << price << "\t";
	cout << processing_plant << "\t";
	cout << tax_rate << "\t";
	cout << order_tax << "\t";
	cout << net_cost << "\t";
	cout << total_cost << "\t\n";

}


void process(double quantity, double price, int processing_plant, double& tax_rate, double& order_tax, double& net_cost, double& total_cost)
{
	
	
	if ( 0 <= processing_plant && processing_plant <= 50)
	{
		tax_rate = 6.0;
	}
	else if (51 <= processing_plant && processing_plant <= 110 )
	{
		tax_rate = 7.0;
	}
	else if (111 <= processing_plant && processing_plant <= 200)
	{
		tax_rate = 8.0;
	}
	else if (201 <= processing_plant && processing_plant <= 500 )
	{
		tax_rate = 9.0;
	}
	else if (processing_plant > 500)
	{
		tax_rate = 11.0;
	}
	order_tax = quantity * price * (tax_rate / 100.0);
	net_cost = quantity * price;
	total_cost = net_cost + order_tax;

}

//Here is your driver to test the program
int main()
{
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;

	ifstream in;    //declaring an input file stream
	in.open("purchase_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{

			input(in, cell_number, item_number, quantity, price, processing_plant);
			process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
			output(cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
		}
	}

	in.close();

	return 0;
}


