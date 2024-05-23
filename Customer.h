#pragma once
#include<iostream>
#include<string>
#include "Address.h"

using namespace std;


class Customer {

private:
	string CustomerName;
	const int CustomerID;
	Address customer_address;
	static int id;
public:
	Customer();
	Customer(string , Address &);
	Customer(const Customer& );

	bool setCustomerName(string name);
	void setCustomerAddress(const Address&);

	int getCustomerID() const;
	string getCustomerName() const;
	Address getCustomerAddress() const;

	void print_CustomerInfo() const;

};