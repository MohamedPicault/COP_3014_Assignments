/*
Mohamed R. Picault	        Total Points:  10
Due Date:  01/27/2020
Course:  C0P3014
Assignment:  Assignment 1
Professor: Dr. Lofton Bullard

Description: (Your program description goes here -- what it does--In the program we processed....
The program will calculate the cost of making a phone call base on the number of relay stations are used and the duration of the call.

*/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class

using namespace std;

double tax_per_call(double numb_relay) //function that pass tha amount of relays and return the corresponding tax rate
{
	double taxRate;


	if (1 <= numb_relay && numb_relay <= 5)
	{
		taxRate = 1.0 / 100.0;
	}
	else if (6 <= numb_relay && numb_relay <= 11)
	{
		taxRate = 3.0 / 100.0;
	}
	else if (12 <= numb_relay && numb_relay <= 20)
	{
		taxRate = 5.0 / 100.0;
	}
	else if (21 <= numb_relay && numb_relay <= 50)
	{
		taxRate = 8.0 / 100.0;
	}
	else if (numb_relay > 50)
	{
		taxRate = 12.0 / 100;
	}
	else
	{
		taxRate = 0;

	}
	return taxRate;



}

double TotalCost_per_Call(double numb_relay, double call_duration)//function that performs calculation of total cost per call
{
	double totalcost_call, callTax, netcost_call;

	netcost_call = (numb_relay / 50.0) * 0.40 * call_duration;
	callTax = netcost_call * tax_per_call(numb_relay);
	totalcost_call = netcost_call + callTax;
	return totalcost_call;

}


void Phone_call()//Introduction function, that prompts user whether the user wants to make a phone call.
{
	string user_response;
	double call_duration, netcost_call, callTax, numb_relay;
	long long cell_phone_number;

	cout << "Do you wish to make a phone call? Y/N\n";
	cin >> user_response;

	while (user_response == "Y" || user_response == "y")
	{
		cout << "Please enter the cell phone#, # of relay stations, and length of call.\n";
		cin >> cell_phone_number;
		cin >> numb_relay;
		cin >> call_duration;

		cout << "Cell phone# \t= " << cell_phone_number << endl;
		cout << "# of Relays \t= " << numb_relay << endl;
		cout << "Time \t\t= " << call_duration << endl;
		cout << fixed;
		cout.precision(2);
		netcost_call = (numb_relay / 50.0) * 0.40 * call_duration;
		cout << "Net cost \t= " << netcost_call << endl;
		cout << "Tax rate \t= " << tax_per_call(numb_relay) << endl;
		callTax = netcost_call * tax_per_call(numb_relay);
		cout << "call tax \t= " << callTax << endl;
		cout << "Total call cost = " << TotalCost_per_Call(numb_relay, call_duration) << endl;
		cout << "Do you want to make another call? Y/N\n";
		cin >> user_response;
	}
	//incase user's input is either no or not one of the suggested
	if (user_response == "N" || user_response == "n")
	{
		return;
	}
	else
	{
		cout << "Invaild input!! Please enter correct suggested input Y/N\n";
		Phone_call();
	}
}


int main()
{
	Phone_call();

	return  0;
}
