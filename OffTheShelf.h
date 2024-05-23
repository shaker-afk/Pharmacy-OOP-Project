#pragma once
#include<iostream>
#include<string>
#include"Medication.h"
using namespace std;

class OffTheShelf : public Medication {
	bool BOGOF;
	Date OfferEnds;
	bool is_discount;
public:
	OffTheShelf();
	OffTheShelf(bool, bool, const Date&, string, string, int, double, const Date&);

	void set_offerend(const Date&, bool);
	void set_bogof(bool);
	void set_discount(bool);

	bool get_bogof()const;
	bool get_discount()const;
	Date get_offerend()const;

	void print_MedicationInfo()const;
};