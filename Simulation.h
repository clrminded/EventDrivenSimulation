/* Author: Christopher Liudahl-Rackley
 * Date: 12/3/2021
 * Class: CS300
 * Assignment 5
 * Description: A simulation of a customer as they enter and exit a time. This is a 
 * simulation that could be described in many different ways. The intent was a customer
 * enters a bank line, makes a transaction. As transactions are made, the line gets updated 
 * though each interaction.
 */
#ifndef SIMULATION
#define SIMULATION

#include <iostream>
#include <vector>
#include <fstream>
#include "Customer.h"
#include "Queue.h"

using namespace std;

class Simulation {
private:
    Queue<Customer> *q;
    int currentTime;
    int maxDelay;
    double avgDelay;

public:
    Simulation();
    ~Simulation();

    friend ostream& operator<<(ostream& os, Simulation& _simulation) {
        os << _simulation.getMaxDelay() << _simulation.getAvgDelay();
        return os;
    }

    void processCustomers(vector<Customer>);
    void printStatistics();
    int getMaxDelay();
    double getAvgDelay();
};

Simulation::Simulation():currentTime(0), maxDelay(0), avgDelay(0) {
    q = new Queue<Customer>();
}

Simulation::~Simulation() {
    delete q;
    q = nullptr;
}

void Simulation::processCustomers(vector<Customer> customers) {
    int numberOfCustomers = customers.size();
    if(customers.size() == 0) {
        maxDelay = -1;
        avgDelay = -1;
    }
    /* since the customers are organized by their arrival time we can enqueue do the calculations then dequeue */
    for(int i = 0; i < customers.size(); i++) {
        // for every customer that comes in we put them in line
        q->enqueue(customers[i]);
        // use a Customer variable for the front customer in the line
        Customer currCustomer = q->qfront();
        /* when we pull the customer from the line we have 2 pieces of information given to us, their arrival time and their transaction time. This is where we are going to update the customers start time with the current time. */
        currCustomer.setStartTime(currentTime);
        /* the max delay gets updated, so this information stays current as the transactions occur */
        maxDelay = currCustomer.getStartTime() - currCustomer.getArrivalTime();
        // avgDelay = (avgdelay + maxdelay) / numberOfCustomers
        avgDelay += double(maxDelay) / double(numberOfCustomers);
        /* before the customer leaves as they finish their transaction, we update the current time with the time that occured durring the transaction and then the customer leaves the line. */
        currentTime += currCustomer.getTransactionTime();
        q->dequeue();
    }
}

void Simulation::printStatistics() {
    cout << "Output:" << endl;
    cout << "Max Delay = " << maxDelay << endl;
    cout << "Average Delay = " << avgDelay << endl;
}

int Simulation::getMaxDelay() {
    return maxDelay;
}

double Simulation::getAvgDelay() {
    return avgDelay;
}

#endif // SIMULATION