
/************************************************************************************************************************

Name: Mohamed Picault                      Z#:23204935
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:Feb 17, 2020                Due Time:11:59 PM
Total Points: 20
Assignment #: Assignment_3.cpp

Description:
The purpose of this program is to request three numerical value from the user and calculate those three values to return
the semi-parameter and area of a triangle. Note: should your semi-parameter be equal to one of your side you area will be zero
and if your semi-parameter value is less than one of the sides you will get a -nan for your error due to you can square a negative number 
*************************************************************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

//include function prototypes
void Computer(double, double, double, double&, double& );

void Compute (double side_a, double side_b, double side_c, double& area, double& semi_p){
  semi_p = (side_a + side_b + side_c)/2.0;
  area = sqrt(semi_p * (semi_p- side_a) * (semi_p - side_b) * (semi_p - side_c));
}



int main( ){
  double a, b, c, area, semi_p;
  char answr;
  cout << "Would you like to know the area and semi_parameter of a triangle? Y/N\n";
  cin >> answr;

  if (answr == 'y' || answr == 'Y'){
    while(answr == 'Y' || answr == 'y'){
            cout << "Please enter three values for each side of the triangle.\n";
            cin >> a >> b >> c;
            if ((a + b ) > c && !((a + b) == c)){
                Compute(a, b, c, area, semi_p);
                cout.setf(ios::showpoint);
                cout.precision(2);
                cout.setf(ios::fixed);
                cout << "Side A:\t\tSide B:\t\tSide C:\t\tArea:\tSemi-parameter:\n";
                cout << a <<"\t\t" << b << "\t\t" << c << "\t\t" << area << "\t" << semi_p << endl;
                cout << "would you like to compute again? Y/N" << endl;
                cin >> answr;
                if (answr == 'Y' || answr == 'y'){
                    main();
                }
                else if (answr == 'n' || answr == 'N'){ // safety net for incorrect response
                    cout << "Thanky you for playing!";
                    return 0;
                }
                else{
                    cout << "Incorrect answer! Please enter one of the following, (Y/N) or will terminate program.\n";
                    cin >> answr;
                }

            }
            else{//safety net for when three input values dont meet the if condition
                cout<< "Invalid Input, would you like to try again? Y/N, (incorrect repsonse will terminate program)\n";
                cin >> answr;
            }

        }
        if (answr == 'N' || answr == 'n'){//safety net for when response doesnt meet the while condition
            cout << "Thank you for playing!";
            return 0;
        }
        else{
            cout << "TERMINATING PROGRAM!!\n";
            return 0;
        }

    }
    else if (answr == 'n' || answr == 'N'){//safety net for when response doesnt meet the first if condition
        cout << "Thank you for playing!";
        return 0;
    }
    else{
        cout << "Incorrect answer! Please enter one of the following, Y/N.\n";
        main();
    }
    return 0;
}
