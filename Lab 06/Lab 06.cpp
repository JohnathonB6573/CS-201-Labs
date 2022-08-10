#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{
    
    int option = 1, i = 0;
    vector<double> miles, gallons;
    double MPG;

    while (option == 1) {//keeps looping until the user is done making tanks

        double m = -1, g = -1;//initialization
        miles.resize(i + 1);
        gallons.resize(i + 1);
        
        while (m < 0) {
            m = GetMiles(); //gets miles
        }

        cout << "You entered " << m << " miles.\n\n";

        while (g < 0) {
            g = GetGallons(); //gets gallons
        }

        cout << "You entered " << g << " gallons.\n\n";

        miles.at(i) = m;
        gallons.at(i) = g;//stores the user data

        while (option == 1) {
            cout << "Would you like to enter another tank?\n2.yes\n3.no\n";//promopts the user if they want to enter another tank
            cin >> option;
            cout << endl;
        }

        if (option == 2) {
            i++;// if the user selected yes it increments so the vector can be fixed and reruns the data collection
            option = 1;
        }
    }

     MPG = GetMPG(miles, gallons);//gets miles per gallon

     cout << "Your total miles per gallon was " << MPG << "\nThanks for using the best program ever made";
}
