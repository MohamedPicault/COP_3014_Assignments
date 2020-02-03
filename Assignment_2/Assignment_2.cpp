

//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name: Mohamed R. Picault                                 Z#:23204935
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:Feb 03, 2020                      Due Time: 11:59 PM
Total Points: 20
Assignment #: amazon_orders.cpp

Description:
this program is created to gather data from current record (order record) and process theose records and formate them in the desired formate
*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class order_record
{
public:// making the attributes of the class order_record accessible when called
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


//Prototypes for your functions: input, output, and process will go here

void input(ifstream &, order_record &);
void output(const order_record &);
void process(order_record &);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, item_number, quantity, price, processing_plant ) 
//from data file order record (p_record).

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream & infile, order_record & customer_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{// function is getting the data through file input and store those values into the class variables through the use of the object customer_record
	infile >> customer_record.cell_number;
	infile >> customer_record.item_number;
	infile >> customer_record.quantity;
	infile >> customer_record.price;
	infile >> customer_record.processing_plant;

	//add more code to read the rest of the fields (item_number, quantity, price and processing_plant) into the
	// customer_record
	
}



void output(const order_record & customer_record)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.

	/********************************************/
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	// print the value of the object properties input from the input file
	cout << customer_record.cell_number << "\t";
	cout << customer_record.item_number << "\t";
	cout << customer_record.quantity << "\t";
	cout << customer_record.price << "\t";
	cout << customer_record.processing_plant << "\t";
	cout << customer_record.tax_rate << "\t";
	cout << customer_record.order_tax << "\t";
	cout << customer_record.net_cost << "\t";
	cout << customer_record.total_cost << "\t\n";
	//add more code to print all the fields in the order record
	

}

///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//Note: there is one 1 input/output parameter
void process(order_record& customer_record)
{
	//Here I created local variables to the function process,
	//to that the calculation is easy to read.
	
	
	double taxRate;
	double orderTax;
	double netCost;
	double totalCost;
	double quantity = customer_record.quantity;
	double price = customer_record.price;
	int processPlant = customer_record.processing_plant;

	

	if (processPlant >= 0 && processPlant <= 50)
	{
		taxRate = 6.0;
	}
	else if (processPlant >= 51 && processPlant <= 110)
	{
		taxRate = 7.0;
	}
	else if (processPlant >= 111 && processPlant <= 200)
	{
		taxRate = 8.0;
	}
	else if (processPlant >= 201 && processPlant <= 500)
	{
		taxRate = 9.0;
	}
	else if (processPlant > 500)
	{
		taxRate = 11.0;
	}

	customer_record.tax_rate = taxRate;
	orderTax = quantity * price * (taxRate / 100);
	customer_record.order_tax = orderTax;
	netCost = quantity * price;
	customer_record.net_cost = netCost;
	totalCost = netCost + orderTax;
	customer_record.total_cost = totalCost;



}

//Here is your driver to test the program
int main()
{

	order_record customer_record;

	ifstream infile;    //declaring an input file stream
	infile.open("Purchase_data_Assignment2.txt");
	
	if (infile.fail())
	{
		cout << "Input file did not open correctly" << endl;

	}
	else
	{
		while (!infile.eof())
		{
			input(infile, customer_record);
			process(customer_record);
			output(customer_record);
		}
		
		
	}

	infile.close();

	return 0;
}


