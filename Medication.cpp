#include <string>
#include <iostream>
#include "Medication.h"

using namespace std;
int Medication::id = 1;

Medication::Medication() :barcode("1000"), Medication_ID(id++) {
	Expiry_Date = Date();
	set_MedicationName("No name");
	set_Description("no description");
	set_Price(0);
	set_QuantityInStock(0);
}
Medication::Medication(Date& exp_date, string name, string des, double price_, int quan, string barcode_) :barcode(barcode_), Medication_ID(id++) {
	set_MedicationName(name);
	set_Description(des);
	set_Price(price_);
	set_QuantityInStock(quan);
	Expiry_Date = exp_date;

}

Medication::~Medication() {

}
Medication::Medication(Medication& a) : barcode(a.barcode), Medication_ID(a.Medication_ID) {
	Medication_name = a.Medication_name;
	description = a.description;
	price = a.price;
	Quantity_in_stock = a.Quantity_in_stock;
	Expiry_Date = a.Expiry_Date;
}

bool Medication::set_MedicationName(string name) {
	if (name != "") {
		Medication_name = name;
		return true;
	}
	else name = "No name";
	return false;
}
bool Medication::set_Description(string des) {
	if (des != "") {
		description = des;
		return true;
	}
	else description = "No description";
	return false;
}
bool Medication::set_Price(double _price) {
	if (_price > 0) {
		price = _price;
		return true;
	}
	else price = 0;
	return false;
}
bool Medication::set_QuantityInStock(int quan) {
	if (quan > 0) {
		Quantity_in_stock = quan;
		return true;
	}
	else Quantity_in_stock = 0;
	return false;
}
void Medication::set_date(const Date& date_copy) {
	Expiry_Date.setday(date_copy.get_day());
	Expiry_Date.setmonth(date_copy.get_month());
	Expiry_Date.setyear(date_copy.get_year());
}



int Medication::get_MedicationID()const {
	return Medication_ID;
}

string Medication::get_MedicationName() const {
	return Medication_name;
}
string Medication::get_Description() const {
	return description;
}
double Medication::get_Price() const {
	return price;
}
int Medication::get_QuantityInStock() const {
	return Quantity_in_stock;
}

Date Medication::get_date() const {
	return Expiry_Date;
}

string Medication::get_Barcode() const {
	return barcode;
}

void Medication::print_MedicationInfo() const {
	cout << "Medication ID : " << Medication_ID << endl;
	cout << "Medication name: " << Medication_name << endl;
	cout << "Medication description: " << description << endl;
	cout << "Medication price = " << price << endl;
	cout << "Quantity of " << Medication_name << " in stock = " << Quantity_in_stock << endl;
	cout << "Expiry date of " << Medication_name << " : ";
	Expiry_Date.print();
	cout << "Barcode = " << barcode << endl << endl;
}