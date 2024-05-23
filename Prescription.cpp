#include<iostream>
#include<string>
#include"Medication.h"
#include "Prescription.h"
using namespace std;


Prescription::Prescription() {
	set_FDANumber(0);
	set_date(Date());
	set_MedicationName("no name");
	set_Description("no Description");
	set_Price(0);
	set_QuantityInStock(0);
}
Prescription::Prescription(int FDA = 0, const Date& appdate = Date(), string name = "no name", string des = "no Description", int quan = 0, double price_ = 0) {
	set_FDANumber(FDA);
	set_date(appdate);
	set_MedicationName(name);
	set_Description(des);
	set_Price(price_);
	set_QuantityInStock(quan);
}

void Prescription::set_approvaldate(const Date& date_copy) {
	ApprovalDate.setday(date_copy.get_day());
	ApprovalDate.setmonth(date_copy.get_month());
	ApprovalDate.setyear(date_copy.get_year());
}

void Prescription::set_FDANumber(int FDA) {
	FDANumber = FDA;
}

int Prescription::get_FDANumber() const { return FDANumber; }
Date Prescription::getapprovaldate() const { return ApprovalDate; }

void Prescription::print_MedicationInfo()const {
	Medication::print_MedicationInfo();
	cout << "Approval date is : ";
	ApprovalDate.print();
	cout << "FDA number is : " << FDANumber << endl;

}