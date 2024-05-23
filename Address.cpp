#pragma once
#include<iostream>
#include<string>
#include"Address.h"
using namespace std;

Address::Address() {
	Email = "no email";
	city = "no city";
	mobile_number = "no number";
	street_name = "no name";
}
Address::Address(string email_, string city_, string street, string number) {
	set_city(city_);
	set_email(email_);
	set_number(number);
	set_street(street);
}
Address::Address(const Address&address_copy) {
	Email = address_copy.Email;
	city = address_copy.city;
	mobile_number = address_copy.mobile_number;
	street_name = address_copy.street_name;
}

bool Address::set_email(string email_) {
	if (email_ != "") {
		Email = email_;
		return true;
	}
	else
	{
		Email = "no email";
		return false;
	}
}
bool Address::set_city(string city_) {
	if (city!= "") {
		city = city_;
		return true;
	}
	else
	{
		city = "no city";
		return false;
	}
}
bool Address::set_number(string number) {
	if (number!= "") {
		mobile_number = number;
		return true;
	}
	else
	{
		mobile_number = "no number";
		return false;
	}
}
bool Address::set_street(string street) {
	if (street!= "") {
		street_name = street;
		return true;
	}
	else
	{
		street_name = "no name";
		return false;
	}
}

string Address::get_email() const{
	return Email;
}
string Address::get_number() const{
	return mobile_number;
}
string Address::get_street() const{
	return street_name;
}
string Address::get_city() const{
	return city;
}

void Address::print()const {
	cout << "Email : " << Email <<endl<< "mobile number : " << mobile_number << endl << "city : " << city << endl << "street name : " << street_name << endl;
}
