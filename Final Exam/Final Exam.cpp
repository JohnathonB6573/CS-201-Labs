//Johnathon Brumfield
// 07/27/2022
// Exam 2
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include "Employee.h"

using namespace std;

int main()
{
    vector<Employee*> Employees;
    string fname, lname, t, fullname;
    int pay, id;
    ifstream fin;
    ofstream fout;//initialization

    fin.open("input.txt");
    fout.open("output.txt");//file open

    if (fin.is_open()) {
        while (!fin.eof()) {
            fin >> t;
            if (t == "NEW") {
                fin >> id >> fname >> lname;//scans all necessary items to make the employee
                fullname = fname + lname;
                Employee* em = new Employee(id, fullname);// allocates memory for a new employee
                Employees.push_back(em);//adds the employee to the list              
            }
            else if (t == "RAISE") {
                fin >> id >> pay;
                int j;
                for (int i = 0; i < Employees.size(); i++) {
                    if (Employees.at(i)->getEmployeeID() == id) {//loop through the employees and finds the target
                        j = i;
                    }
                }
                Employees[j]->giveRaise(pay);//fives them a pay raise
            }
            else if (t == "PAY") {
                for (int i = 0; i < Employees.size(); i++) {//loops through the employees
                    Employees[i]->pay();//pays the employees
                }
            }
            else if (t == "FIRE") {
                fin >> id;
                int j;
                for (int i = 0; i < Employees.size(); i++) {
                    if (Employees.at(i)->getEmployeeID() == id) {//loop through the employees and finds the target
                        j = i;
                    }
                }
                Employees.at(j)->fire();//fires the certain employee
            }
        }
        fin.close();//closes the input file
    }
    else {
        cout << "Input file could not be opened!\n";
    }

    for (int i = 0; i < Employees.size(); i++) {
        fout << Employees.at(i)->getName() << ", ID Number " << Employees.at(i)->getEmployeeID() << ":" << endl;
        if (Employees.at(i)->getPayRate() > 0) {
            fout << "Current pay rate: $" << Employees.at(i)->getPayRate() << endl;
        }
        else {
            fout << "Not employed with the company.\n";
        }
        fout << "Pay earned to date: $" << Employees.at(i)->getBalance() << endl << endl;
    }

    fout.close();//file close
}