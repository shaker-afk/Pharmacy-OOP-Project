#include<iostream>
#include<string>
#include"Medication.h"
#include"OffTheShelf.h"
using namespace std;

OffTheShelf::OffTheShelf() {
	set_discount(false);
	set_bogof(false);
	set_offerend(Date(), false);
	set_MedicationName("no name");
	set_Description("no Description");
	set_Price(0);
	set_QuantityInStock(0);
	Expiry_Date = Date();
}
OffTheShelf::OffTheShelf(bool bogof = false, bool discount = false, const Date& offend = Date(), string name = "no name", string des = "no Description", int quan = 0, double price_ = 0, const Date& exp_date = Date()) {
	set_offerend(offend, discount);
	set_MedicationName(name);
	set_Description(des);
	set_Price(price_);
	set_QuantityInStock(quan);
	Expiry_Date = exp_date;
	set_discount(bogof);
	set_bogof(discount);
}

void OffTheShelf::set_offerend(const Date& offend, bool discount) {
	if (discount)
		OfferEnds.setyear(offend.get_year() + 2);
	else
	{
		OfferEnds.setmonth(offend.get_month() + 3);
	}
}

void  OffTheShelf::set_bogof(bool bogof) { BOGOF = bogof; }
void  OffTheShelf::set_discount(bool discount) { is_discount = discount; }

bool OffTheShelf::get_bogof() const { return BOGOF; }
bool OffTheShelf::get_discount() const { return is_discount; }
Date OffTheShelf::get_offerend()const { return OfferEnds; }

void OffTheShelf::print_MedicationInfo() const {
	Medication::print_MedicationInfo();
	cout << "offer ends in : ";
	OfferEnds.print();
	if (BOGOF)
		if (is_discount)
			cout << " this medication has buy one get one free and a discount";
		else
		{
			cout << " this medication has buy one get one free and no discount";
		}
	else
	{
		if (is_discount)
			cout << " this medication doesn't have buy one get one free, only a discount";
		else
		{
			cout << " this medication doesn't have buy one get one free nor a discount";
		}
	}
}