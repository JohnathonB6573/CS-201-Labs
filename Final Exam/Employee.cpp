//Johnathon Brumfield
// 07/27/2022
// Exam 2

#include <string>
#include "Employee.h"
using namespace std;

// Constructor
Employee::Employee(int id, string myName) {
	employeeID = id;
	name = myName;
	balance = 0.00;
	payRate = 10.00;
}

// Getter to return the employee ID
int Employee::getEmployeeID() {
	return employeeID;
}

// Getter to return the current pay rate
double Employee::getPayRate() {
	return payRate;
}

// Getter to return the current amount of pay earned
double Employee::getBalance() {
	return balance;
}

// Getter to get Employee's name
string Employee::getName() {
	return name;
}

// Function to give the raise. It takes in a percent in whole numbers 
// (ex: 5 for 5%)
void Employee::giveRaise(int rate) {
	payRate = (.01 * rate) * payRate + payRate;
}

// Pays the employee
void Employee::pay() {
	balance += payRate;
}

// Fires the Employee
void Employee::fire() {
	employed = false;
	payRate = 0;
}

// Returns if the Employee is currently employed
bool Employee::isEmployed() {
	return employed;
}