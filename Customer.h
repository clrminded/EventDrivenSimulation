/* Author: Christopher Liudahl-Rackley
 * Date: 12/3/2021
 * Class: CS300
 * Assignment 5
 * Description: This is the class definition to what a customer is. During
 * the simulation a customer will have an arrival time, and a transaction 
 * time. The start time of each customer gets updated every time they get added to the line.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

using namespace std;

// Every customer has an arrival time and a transaction time
class Customer {
private:
    int startTime;
    int arrivalTime;
    int transactionTime;

public:
    Customer();
    Customer(const int, const int);
    Customer(const Customer&);
    ~Customer();
    Customer& operator=(const Customer&);

    friend ostream& operator<<(ostream& os, Customer& _customer) {
        os << _customer.getStartTime() <<_customer.getArrivalTime() << _customer.getTransactionTime();
        return os;
    }

    int getStartTime();
    int getArrivalTime();
    int getTransactionTime();

    void setStartTime(const int);
    void setArrivalTime(const int);
    void setTransactionTime(const int);
};

// ---------------------- BIG THREE -------------------------------------
// default
Customer::Customer():startTime(0), arrivalTime(0), transactionTime(0) {}

//@param arr: is the arrivalTime: @type int
//@param depart: is the departureTime: @type int
Customer::Customer(const int a, const int t):startTime(0), arrivalTime(a), transactionTime(t) {}

// call copy assignment operator
Customer::Customer(const Customer& other) {
    *this = other;
}

// dont need to destroy anything since theres no dangling pointers
Customer::~Customer() {}

// copy assignment operator
Customer& Customer::operator=(const Customer& other) {
    startTime = other.startTime;
    arrivalTime = other.arrivalTime;
    transactionTime = other.transactionTime;
    return *this;
}


// ------------------ ACCESSORS ----------------------
int Customer::getStartTime() {
    return startTime;
}

int Customer::getArrivalTime() {
    return arrivalTime;
}

int Customer::getTransactionTime() {
    return transactionTime;
}

// ------------------- MODIFIERS --------------------
void Customer::setStartTime(const int _s) {
    startTime = _s;
}

void Customer::setArrivalTime(const int _a) {
    arrivalTime = _a;
}

void Customer::setTransactionTime(const int _t) {
    transactionTime = _t;
}

 #endif // CUSTOMER_H