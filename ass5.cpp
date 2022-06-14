/**
 * TASK:
 * In this assignment, you’ll develop an event driven simulation to simulate the arrival  and 
 * processing of customers at a bank with one teller, and compute some statistics, such as 
 * the average wait time of customers and maximum wait time of a customer.  The bank 
 * can use these statistics to determine whether it makes sense to hire another teller. 
 * 
 * Customers arrive at the bank in some order. For each customer number i, assume that 
 * you know the time when they arrived Ti and the duration  Di it takes the bank teller to 
 * help the customer . The teller helps the customers in the order of their arrival. If the 
 * teller started to help a customer i,  he continues  to help that customer until the 
 * customer’s work finished. The duration for helping customer  i takes exactly Di minutes.
 * 
 * We can assume that if a customer j arrives while the teller is helping customer i, 
 * customer j enters a queue (also called a line). Figure 13.6 ( c)  in your text (shown below) 
 * shows the situation with two customers, one currently being served by a teller and the 
 * other one waiting in line.
 *
 * We can make the simplifying assumption that the queue in the bank can hold 100 
 * customers, and that at no time will there be more than 100 customers at the bank. 
 * Please note that although multiple customers could arrive at the same time, they still 
 * must come through the single queue in a certain order. In this assignment, we assume 
 * the order is already known and specified in the input data. The teller helps the next 
 * available customer from the queue as soon as he finishes helping  the previous one. If 
 * there are no customers in the queue, the teller stays idle.
 */


#include <iostream>
#include <fstream>
#include "Customer.h"
#include "Simulation.h"
#include <vector>

using namespace std;

vector<Customer> readCustomers();

int main()
{
    vector<Customer> customers = readCustomers();
    Simulation s;
    cout << "Processing Customers:" << endl;
    s.processCustomers(customers);
    s.printStatistics();
    return 0;
}

vector<Customer> readCustomers()
{
    // Create an array of Customer objects
    vector<Customer> customerLine;
    // open up data.txt file
    fstream myfile("data.txt", ios_base::in);
    // declare integer variable for the number of customer cases we will handle in the file
    int num;
    // the integer we get from the file we will assign to the num variable
    myfile >> num;

    // declare integer variables for the arrival time and the departure time for each customer case
    int arrive, depart;

    for (int i = 1; i <= num; i++)
    {
        myfile >> arrive >> depart;
        customerLine.push_back(Customer(arrive, depart));
    }

    myfile.close();

    // returns a vector<Customer>
    return customerLine;
}


/* 
 * Sample Input-1:
 * 2 
 * 0 5 
 * 0 5
 * As seen in the sample input given above, the number of customers is 2. The next two 
 * lines gives the time of arrival and duration at the teller for each of two customers. The 
 * first customer arrived at time 0, and the second customer also arrived at time 0. Each 
 * customer requires 5 minutes of the teller’s time. The teller begins processing the first 
 * customer as soon as he arrives, but the second customer needs to wait for 5 minutes. 
 * The maximum wait time is 5 minutes and the average wait time is 2.5 (= (0 + 5)/2) 
 * minutes.
 * Output:   
 * Max Delay = 5
 * Average Delay = 2.5
 * 
 * Sample Input-2:
 * 3
 * 0 10 
 * 0 10
 * 6 10 
 * The first customer was helped at time 0, and the second one was helped at time 10 and 
 * third one was helped at time 20.  The maximum wait time is 14 minutes (since the third 
 * customer arrived at time 6, but was helped at time 20), and the average wait is (0 + 10 + 14)/3  = 8 minutes.
 * Output:   
 * Max Delay = 14
 * Average Delay = 8
 * 
 * Sample Inputs-3 There are no customers, the teller is idle
 * Input: 
 * 0 
 * Output:   
 * Max Delay = -1
 * Average Delay = -1
 * Here, -1 denotes an undefined value.
 * 
 * Sample Input-4: The only customer arrived at time 0, and teller started helping her 
 * immediately.
 * Input: 
 * 1 
 * 0 1 
 * Output:   
 * Max Delay = 0
 * Average Delay = 0
 * 
 * Sample Input-5: The first customer arrived at time 0, the teller started helping him 
 * immediately and finished at time 10. The second customer arrived at time 10, and the 
 * teller started helping her immediately. In this case no customer needed to wait and 
 * hence the average and maximum wait time =  0.
 *  
 * Input: 
 * 2 
 * 0 10
 * 10 20
 * Output:   
 * Max Delay = 0
 * Average Delay = 0
 */