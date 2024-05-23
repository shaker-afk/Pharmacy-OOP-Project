#include<iostream>
#include<string>
#include"Customer.h"

using namespace std;

int Customer:: id = 1;
Customer::Customer() :CustomerID(id++)
{
	CustomerName = "No name";
	customer_address = Address();
}
Customer::Customer(string name, Address& address) : CustomerID(id++) {
	setCustomerName(name);
	setCustomerAddress(address);
}
Customer::Customer(const Customer& copy_customer) :CustomerID(copy_customer.CustomerID)
{
	CustomerName = copy_customer.CustomerName;
	customer_address = copy_customer.customer_address;
}


bool Customer::setCustomerName(string name) {
	if (name != "") {
		CustomerName = name;
		return true;
	}
	else name = "No name";
	return false;

}
void Customer::setCustomerAddress(const Address&addr_copy){
		customer_address.set_city(addr_copy.get_city());
		customer_address.set_email(addr_copy.get_email());
		customer_address.set_number(addr_copy.get_number());
		customer_address.set_street(addr_copy.get_street());
}


int Customer::getCustomerID() const {
	return CustomerID;
}
string Customer::getCustomerName() const {
	return CustomerName;
}
Address Customer::getCustomerAddress() const {
	return customer_address;
}



void Customer::print_CustomerInfo() const {
	cout << "Customer ID: " << getCustomerID() << endl;
	cout << "Customer Name: " << getCustomerName() << endl;
	customer_address.print();
	cout << endl;
}