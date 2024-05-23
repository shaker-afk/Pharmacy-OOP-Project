#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
#include "Medication.h"
using namespace std;
class Pharmacy {
private:
	const int pharmacyID;
	static int nextPharmacyID;
	string pharmacyName;
	Medication *med;
	Customer *cust;
	int medicationCount;
	int customerCount;
public:
	Pharmacy();
	Pharmacy(string , Medication [], Customer [], int, int);
	~Pharmacy();

	void setPharmacyName(string);
	void setPharmacy(Pharmacy);

	void AddOneMedication(const Medication&);
	void addMedications(const Medication [], int);
    bool removeMedication(const string);
	void addCustomers(const Customer [],int);
	void AddOneCustomer(const Customer&);
	void displayMedications() const;
	void displayCustomers() const;
	void medcomp(Pharmacy& ob)const;
	void custcomp(Pharmacy& ob)const;

	int get_MedsNumb();
	int get_CustomersNumb();
	string get_PharName();
};