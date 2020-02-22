
 /**

Name: Mohamed R. Picault                                 Z#:23204935
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:Feb 24, 2020                      Due Time: 11:59 PM
Total Points: 20
Assignment #: amazon_orders.cpp

Description:
this program is created to gather data from current record (order record) and process theose records and formate them in the desired formate
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;


class orderRecords
{
    public:
    string cellNumber;
    string itemNumber;
    double itemCount;
    double price;
    int processPlant;
    double taxRate;
    double orderTax;
    double netCost;
    double totalCost;

};

void input(ifstream&, orderRecords&);
//precondition: file must exist in order to retreived data to be stored
//postcondition: attributes are being stored with their respected data and creates a output text file name Customer inovice
// to store the values in a external file
void process(orderRecords&);
//precondition: attributes must have required data in order to be processed
//postcondition: the tax will be determined from the current stored data in the attributes
void output(orderRecords&, ofstream&);
//precondition: values stored in each attributes
//postcondition: values are then stored into the order record (customer_invoice.txt) and printed on the screen



//extracts the data from file and transfers information into the attributes within the class
void input(ifstream& inputFile, orderRecords& customer)
{
    inputFile >> customer.cellNumber;
    inputFile >> customer.itemNumber;
    inputFile >> customer.itemCount;
    inputFile >> customer.price;
    inputFile >> customer.processPlant;

}

//determines the tax and additional calculations
void process(orderRecords& customer)
{
    if (customer.processPlant >= 0 && customer.processPlant <= 50)
    {
        customer.taxRate = 6.0;
    
   }
   else if (customer.processPlant >= 51 && customer.processPlant <= 110)
   {
       customer.taxRate = 7.0;     

   }
   else if (customer.processPlant >= 111 && customer.processPlant <= 200)
   {
       customer.taxRate = 8.0;
   }
   else if (customer.processPlant >= 201 && customer.processPlant <= 500)
   {
       customer.taxRate = 9.0;
   }
   else if (customer.processPlant > 500)
   {
       customer.taxRate = 11.0;
   }

    customer.orderTax = customer.itemCount * customer.price * (customer.taxRate/100.0);
    customer.netCost = customer.itemCount * customer.price;
    customer.totalCost = customer.netCost + customer.orderTax;
    
   
   
   
   
    
}

//prints the results of each attributes on the screen and store them within the customers inovice text file
void output(orderRecords& customer, ofstream& outputFile)
{
    cout << fixed;
    cout.precision(2);

    cout << customer.cellNumber<< "\t" << customer.itemNumber << "\t"
         << customer.itemCount << "\t" << customer.price      << "\t"
         << customer.taxRate   << "\t" << customer.orderTax   << "\t"
         << customer.netCost; 
    cout.width(9);
    cout << customer.totalCost << endl;
    
    outputFile << customer.cellNumber << "\t" << customer.itemNumber << "\t"
               << customer.itemCount  << "\t" << customer.price      << "\t"
               << customer.taxRate    << "\t" << customer.orderTax   << "\t"
               << customer.netCost    << "\t" << customer.totalCost  << endl;


}


int main()
{
    orderRecords customer;

    ifstream inputFile; //declaring an input file stream
    ofstream outputFile; //declaring an outputfile stream
    inputFile.open("purchase_data_Assignment5.txt");
    outputFile.open("Customer_invoice.txt");
    if ( inputFile.fail() && outputFile.fail())
    {
        cout << "The File does not exist or incorrect name of file.";
        exit(1);
    }
    else
    {
        while (!inputFile.eof())
        {
            input(inputFile, customer);
            process(customer);
            output(customer, outputFile);
        }
        
    }
    inputFile.close();
    outputFile.close();
    
    return 0;
    
}

