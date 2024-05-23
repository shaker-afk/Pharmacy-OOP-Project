#pragma once
#include<iostream>
#include<string>
using namespace std;

class Address
{
	string Email;
	string city;
	string mobile_number;
	string street_name;
public:
	Address();
	Address(string, string, string, string);
	Address(const Address&);

	bool set_email(string);
	bool set_city(string);
	bool set_number(string);
	bool set_street(string);

	string get_email()const;
	string get_number()const;
	string get_street()const;
	string get_city()const;

	void print()const;

};