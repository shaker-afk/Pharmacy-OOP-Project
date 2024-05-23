#pragma once
#include <string>
#include <iostream>
#include "Date.h"
using namespace std;


class Medication {
public:
	static int id;
	const int Medication_ID;
	string Medication_name;
	string description;
	double price;
	int Quantity_in_stock;
	const string barcode;
	Date Expiry_Date;


public:
	Medication();
	Medication(Date&, string, string, double, int, string);
	Medication(Medication&);
	~Medication();

	bool set_MedicationName(string);
	bool set_Description(string);
	bool set_Price(double);
	bool set_QuantityInStock(int);
	void set_date(const Date&);

	int get_MedicationID()const;
	string get_MedicationName()const;
	string get_Description()const;
	double get_Price()const;
	int get_QuantityInStock()const;
	Date get_date()const;
	string get_Barcode()const;

	virtual void print_MedicationInfo() const;
};