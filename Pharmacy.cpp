#include <iostream>
#include <string>
#include "Customer.h"
#include "Medication.h"
#include "Pharmacy.h"
using namespace std;

int Pharmacy::nextPharmacyID = 1;

Pharmacy::Pharmacy() :pharmacyID(nextPharmacyID++) {
	pharmacyName = "No name";
	medicationCount = 0;
	customerCount = 0;
	med = NULL;
	cust = NULL;
}

Pharmacy::Pharmacy(string name,Medication m[], Customer c[],int mednumber,int custnumber) :pharmacyID(nextPharmacyID++), pharmacyName(name), medicationCount(mednumber), customerCount(custnumber) {
	med = new Medication[medicationCount];
	cust = new Customer[customerCount];
	for (int i = 0; i < medicationCount; i++) {
		med[i].set_MedicationName(m[i].get_MedicationName());
		med[i].set_Description(m[i].get_Description());
		med[i].set_Price(m[i].get_Price());
		med[i].set_QuantityInStock(m[i].get_QuantityInStock());
		med[i].set_date(m[i].get_date());
	}
	for (int i = 0; i < customerCount; i++) {
		cust[i].setCustomerName(c[i].getCustomerName());
		cust[i].setCustomerAddress(c[i].getCustomerAddress());
	}
}

Pharmacy ::~Pharmacy() {
	if (med != NULL)
		delete[] med;
	if (cust != NULL)
		delete[] cust;
}


void Pharmacy::setPharmacyName(string name) {
	pharmacyName = name;
}

void Pharmacy::setPharmacy(Pharmacy p) {
	pharmacyName = p.pharmacyName;
	medicationCount = p.medicationCount;
	customerCount = p.customerCount;
	med = new Medication[medicationCount];
	cust = new Customer[customerCount];
	for (int i = 0; i < medicationCount; i++) {
		med[i].set_MedicationName(p.med[i].get_MedicationName());
		med[i].set_Description(p.med[i].get_Description());
		med[i].set_Price(p.med[i].get_Price());
		med[i].set_QuantityInStock(p.med[i].get_QuantityInStock());
		med[i].set_date(p.med[i].get_date());
	}
	for (int i = 0; i < customerCount; i++) {
		cust[i].setCustomerName(p.cust[i].getCustomerName());
		cust[i].setCustomerAddress(p.cust[i].getCustomerAddress());
	}
}

void Pharmacy::AddOneMedication(const Medication& medication)
{
	//resizing the med array
	//temp array to keep the data
	Medication* temp = new Medication[medicationCount+1];
	//copy the data
	for (int i = 0; i < medicationCount; i++) {
		temp[i].set_MedicationName(med[i].get_MedicationName());
		temp[i].set_Description(med[i].get_Description());
		temp[i].set_Price(med[i].get_Price());
		temp[i].set_QuantityInStock(med[i].get_QuantityInStock());
		temp[i].set_date(med[i].get_date());
	}

	delete[] med;//old med
	med = temp;//new med 
	temp = NULL;
	delete[] temp;//emptying the heap
	
		med[medicationCount].set_MedicationName(medication.get_MedicationName());
		med[medicationCount].set_Description(medication.get_Description());
		med[medicationCount].set_Price(medication.get_Price());
		med[medicationCount].set_QuantityInStock(medication.get_QuantityInStock());
		med[medicationCount].set_date(medication.get_date());
		medicationCount++;
}



void Pharmacy::addMedications(const Medication m[],int medsnumber)
{	
	if (med != NULL)
		delete[] med;
	medicationCount = medsnumber;
	med = new Medication[medicationCount];
		for (int i = 0; i < medicationCount; i++) {
			med[i].set_MedicationName(m[i].get_MedicationName());
			med[i].set_Description(m[i].get_Description());
			med[i].set_Price(m[i].get_Price());
			med[i].set_QuantityInStock(m[i].get_QuantityInStock());
			med[i].set_date(m[i].get_date());
		}

	
}

bool Pharmacy::removeMedication(const string medicationName)
{
	bool flag = false;
	for (int i = 0; i < medicationCount; i++)
	{
		if (med[i].get_MedicationName() == medicationName)
		{
			flag = true;
			for (int j = i; j < medicationCount-1 ; j++)
			{
				med[j].set_MedicationName(med[j+1].get_MedicationName());
				med[j].set_Description(med[j + 1].get_Description());
				med[j].set_Price(med[j + 1].get_Price());
				med[j].set_QuantityInStock(med[j + 1].get_QuantityInStock());
				med[j].set_date(med[j + 1].get_date());
			}
			medicationCount--;//as we removed one medication
		}
	}
	if (flag == false) {
		cout << "there is no medication of this name (" << medicationName << ")\n";
		return false;
	}
	else {
		cout << '(' << medicationName << ") is removed.\n";
		//resizing the med array
		//temp array to keep the data
		Medication* temp = new Medication[medicationCount];
		//copy the data
		for (int i = 0; i < medicationCount; i++) {
			temp[i].set_MedicationName(med[i].get_MedicationName());
			temp[i].set_Description(med[i].get_Description());
			temp[i].set_Price(med[i].get_Price());
			temp[i].set_QuantityInStock(med[i].get_QuantityInStock());
			temp[i].set_date(med[i].get_date());
		}

		delete[] med;

		med = temp;
		temp = NULL;
		delete[] temp;

		return true;
	}
	
}

void Pharmacy::addCustomers(const Customer c[],int custnumber)
{
	if (cust != NULL)
		delete[] cust;
	customerCount = custnumber;
	cust = new Customer[customerCount];
		for (int i = 0; i < customerCount; i++) {
			cust[i].setCustomerName(c[i].getCustomerName());
			cust[i].setCustomerAddress(c[i].getCustomerAddress());
		}
	
}

void Pharmacy::AddOneCustomer(const Customer& customer)
{
	Customer* temp = new Customer[customerCount + 1];
	for (int i = 0; i < customerCount; i++) {
		temp[i].setCustomerName(cust[i].getCustomerName());
		temp[i].setCustomerAddress(cust[i].getCustomerAddress());
	}
	delete[] cust;

	cust = temp;
	temp = NULL;
	delete[] temp;

	cust[customerCount].setCustomerName(customer.getCustomerName());
	cust[customerCount].setCustomerAddress(customer.getCustomerAddress());
	customerCount++;
	
}

void Pharmacy::displayMedications() const
{
	cout << "Available Medications:\n";
	for (int i = 0; i < medicationCount; i++)
	{
		med[i].print_MedicationInfo();

	}
}

void Pharmacy::displayCustomers() const
{
	cout << "Customers list:\n";
	for (int i = 0; i < customerCount; i++)
	{
		cust[i].print_CustomerInfo();
	}
}

void Pharmacy::medcomp(Pharmacy& ob)const{
		if (medicationCount == ob.medicationCount) {
			cout << "Both phramacies have " << medicationCount << " medications" << endl;
		}
		else if (medicationCount > ob.medicationCount) {
			cout << "pharmacy " << pharmacyName << " has more medications(" << medicationCount << ") than " << ob.pharmacyName << " (" << ob.medicationCount << ")" << endl;
		}
		else
			cout << "pharmacy " << ob.pharmacyName << "has more medications(" << ob.medicationCount << ") than " << pharmacyName << " (" << medicationCount << ")" << endl;
	}

void Pharmacy::custcomp(Pharmacy& ob)const{
	if (customerCount == ob.customerCount) {
		cout << "Both phramacies have " << customerCount << " Customers" << endl;
	}
	else if (customerCount > ob.customerCount) {
		cout << "pharmacy " << pharmacyName << " has more Customers(" << customerCount << ") than " << ob.pharmacyName << " (" << ob.customerCount << ")" << endl;
	}
	else
		cout << "pharmacy " << ob.pharmacyName << " has more Customers(" << ob.customerCount << ") than " << pharmacyName << " (" << customerCount << ")" << endl;
}

int Pharmacy::get_MedsNumb() {
	return medicationCount;
}
int Pharmacy::get_CustomersNumb() {
	return customerCount;
}
string Pharmacy::get_PharName() {
	return pharmacyName;
}