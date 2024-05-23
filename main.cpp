#include <iostream>
#include <string>
#include "Customer.h"
#include "Medication.h"
#include "Address.h"
#include "Date.h"
#include "Pharmacy.h"
#include "Pharmacy.h"
#include "Prescription.h"

using namespace std;

Medication *meds;//dynamic array
int numOfMedications = 0;

Customer *customers;//dynamic array
string name = "no name";

Address info;
string Email = "no email";
string city = "no city";
string phone = "no phone number";
string street_name = "no street name";

string *PurchaseMedName;//dynamic array
int *NumberOfMedsPurchased;//dynamic array
int *PurchaseMedIndex;//dynamic array
string itemname = "";
int QuantityOfMedsNeeded = 0;
int custnumb = 0; //number of customers
int itemnumbIndex = 0;

double totalprice = 0;

Pharmacy *pharmacies;
int pharmacyIndex = 0;
int pharmacynumbers = 0;

void AddMedications();
void AddCustomers();
void AddItems();
void Print(int);
void TotalPrice();
void PrintPurchasedMeds();
void RemoveMedication();
void AddOneMed();
void AddOneCustomer();
void Compare2pharmacies();
void ChoosePharmacy();
void ResizePharmacies();


int main() {

	int input = 1;
	
	cout << "Please enter the number of pharmaices you want.\n";
	cin >> pharmacynumbers;
	pharmacies = new Pharmacy[pharmacynumbers];
	while (pharmacyIndex < pharmacynumbers) {
		if (input == 14) {
			delete[] pharmacies;
			delete[] meds;
			delete[]customers;
			delete[] NumberOfMedsPurchased;
			delete[] PurchaseMedIndex;
			delete[] PurchaseMedName;

			return 0;
		}
		string pharName = "No name";
		cout << "Please enter pharmacy number " << pharmacyIndex + 1 << " name : ";
		cin >> pharName; pharmacies[pharmacyIndex].setPharmacyName(pharName);
		cout << endl;
		do {
			cout << "\t\tPharmacy number : " << pharmacyIndex + 1 << endl;

			do {
				if (input < 1 || input>14) cout << "invalid input.\nPlease enter a number again.\n";
				cout << "\nMenu:\n";
				cout << "Enter a number to do the following:\n";
				cout << "1.Add Medications.\n" << "2.Add Customers\n" << "3.Display pharmacy medications\n" << "4.Purchase a medication.\n" << "5.Calculate total price.\n" << "6.Display Customers.\n" << "7.Display purchased Medications.\n";
				cout << "8.Remove a medication from the pharmacy.\n" << "9.Add only one medication to the list of medications in pharmacy.\n" << "10.Add only one customer to the list of customers in pharmacy.\n" << "11.Compare bettwen 2 pharmacies\n" << "12.Choose a different pharmacy.\n" << "13.Resize the number of pharmacies.\n" << "14.Exit.\n";
				cin >> input;
			} while (input < 1 || input > 14);

			if (input == 1) {
				AddMedications();
				pharmacies[pharmacyIndex].addMedications(meds, numOfMedications);
			}
			if (input == 2) {
				AddCustomers();
				pharmacies[pharmacyIndex].addCustomers(customers, custnumb);
			}

			if (input == 3 || input == 6)
				Print(input);

			if (input == 4)
				AddItems();

			if (input == 5)
				TotalPrice();

			if (input == 7)
				PrintPurchasedMeds();

			if (input == 8)
				RemoveMedication();

			if (input == 9)
				AddOneMed();

			if (input == 10)
				AddOneCustomer();

			if (input == 11)
				Compare2pharmacies();

			if (input == 12) {
				ChoosePharmacy();
				if (pharmacies[pharmacyIndex].get_PharName() == "No name")
					break;//to enter the pharmacy name if it is a new pharmacy
			}

			if (input == 13) {
				ResizePharmacies();
				break;
			}

			cout << endl;
		} while (input >= 1 && input <= 13);
	}

	////1 – An object in static memory with attributes in static memory
	//Date d;
	//Prescription p1(1, d, "Panadol", "Pain-killer", 3, 2.5);
	
	////2 – An object in static memory with attributes in dynamic memory
	/*Medication* m = new Medication;
	Customer* c = new Customer;
	Pharmacy P("Twin pharmacy", m, c, 1, 1);
	delete m;
	delete c;*/

	////3 – An object in dynamic memory with attributes in static memory
	//Date d;
	//Prescription *p2=new Prescription(1, d, "Panadol", "Pain-killer", 3, 2.5);
	//delete p2;
	
	////4 – An object in dynamic memory with attributes in dynamic memory
	/*Medication* m = new Medication;
	Customer* c = new Customer;
	Pharmacy *P=new Pharmacy("Twin pharmacy", m, c, 1, 1);
	delete p;
	delete m;
	delete c;*/


	return 0;
}

void AddMedications() {
		cout << "How many medications do you want to add?\n";
		cin >> numOfMedications;
		meds = new Medication[numOfMedications];
		PurchaseMedName = new string[numOfMedications];
		NumberOfMedsPurchased = new int[numOfMedications];
		PurchaseMedIndex = new int[numOfMedications];

		string MedName, MedDescription;
		double MedPrice;
		int MedQuantityInStock;
		Date ExpiryDate;
		int day, month, year;
		bool flag = false;
		for (int i = 0; i < numOfMedications; i++) {
			flag = false;
			while (!flag) {
				cout << "Please enter the name of medication (number " << i + 1 << "):\n";
				cin >> MedName;
				flag = meds[i].set_MedicationName(MedName);
			}
			flag = false;
			while (!flag) {
				cout << "Please enter the medication description:\n";
				cin >> MedDescription;
				flag = meds[i].set_Description(MedDescription);
			}

			flag = false;
			while (!flag) {
				cout << "Please enter the medication price:\n";
				cin >> MedPrice;
				flag = meds[i].set_Price(MedPrice);
			}

			flag = false;
			while (!flag) {
				cout << "Please enter the medication quantity in stock:\n";
				cin >> MedQuantityInStock;
				flag = meds[i].set_QuantityInStock(MedQuantityInStock);
			}

			flag = false;
			cout << "Please enter the medication expiry Date\n";
			while (!flag) {
				cout << "Day: ";
				cin >> day;
				flag = ExpiryDate.setday(day);
			}flag = false;
			while (!flag) {
				cout << "\nMonth : ";
				cin >> month;
				flag = ExpiryDate.setmonth(month);
			}flag = false;
			while (!flag) {
				cout << "\nYear : ";
				cin >> year;
				cout << endl;
				flag = ExpiryDate.setyear(year);
			}
			meds[i].set_date(ExpiryDate);

		}
		flag = false;
}

void AddCustomers() {
	
		cout << "How many customers do you want to add?(maximum 50).\n";
		cin >> custnumb;
		customers = new Customer[custnumb];

	for (int i = 0; i < custnumb; i++) {

		cout << "Enter a customer name (customer " << i + 1 << ")\n";
		cin >> name;
		customers[i].setCustomerName(name);

		cout << "Enter customer email : ";
		cin >> Email;
		info.set_email(Email);

		cout << "\nEnter customer city : ";
		cin >> city;
		info.set_city(city);

		cout << "\nEnter customer mobile number : ";
		cin >> phone;
		info.set_number(phone);

		cout << "\nEnter customer street name : ";
		cin >> street_name;
		info.set_street(street_name);

		customers[i].setCustomerAddress(info);
		cout << endl;

		name = "no name";
		Email = "no email";
		city = "no city";
		phone = "no mobile number";
		street_name = "no street name";
	}
}

void AddItems() {
	if (numOfMedications == 0) cout << "Please enter some medications first.\n";
	else {
		bool foundName = false;
		itemnumbIndex = 0;
		int stop = 1;
		do {
			if (itemnumbIndex < 50) {
				cout << "Enter Medication name you want to purchase. it should be in the shop other wise it won't regester\n";
				cin >> itemname;
				for (int i = 0; i < numOfMedications; i++) {
					if (itemname == meds[i].get_MedicationName()) {
						foundName = true;
						cout << "Enter how many number of medications you want to purchase: \n";
						cin >> QuantityOfMedsNeeded;
						if (meds[i].get_QuantityInStock() >= QuantityOfMedsNeeded)
						{
							PurchaseMedName[itemnumbIndex] = itemname;//array for medication names purchased
							NumberOfMedsPurchased[itemnumbIndex] = QuantityOfMedsNeeded;//array for quantity purchased
							PurchaseMedIndex[itemnumbIndex] = i;//the index of the medication purchased 
							itemnumbIndex++;
							meds[i].set_QuantityInStock(meds[i].get_QuantityInStock() - QuantityOfMedsNeeded);
						}
						else
							cout << "medication is out of stock\n";
					}
				}if (!foundName) cout << "medication name isn't in the shop\n";
			}
			cout << "enter 0 if you finshed adding items and 1 to keep adding (max 50 itmes)\n";
			cin >> stop;
			foundName = false;
		} while (stop);
	}
}

void Print(int input) {

	if (input == 3)
		if (numOfMedications == 0) cout << "Please enter some medications first.\n";
		else
			pharmacies[pharmacyIndex].displayMedications();

	if (input == 6)
		if (custnumb == 0) cout << "Please enter some customers first.\n";
		else
			pharmacies[pharmacyIndex].displayCustomers();
}

void TotalPrice() {
	for (int i = 0; i < itemnumbIndex; i++)
		totalprice += meds[PurchaseMedIndex[i]].get_Price()* NumberOfMedsPurchased[i];
	cout << "Total price is = " << totalprice << endl;
	totalprice = 0;
}

void PrintPurchasedMeds() {
	if (numOfMedications == 0) cout << "Please buy some medications first.\n";
	else
	for (int i = 0; i < numOfMedications; i++) {
		cout << "Medication number ( " << i + 1 << " )\n";
		cout << "Medication name : " << PurchaseMedName[i] << endl;
		cout << "Quantity purcahsed : " << NumberOfMedsPurchased[i] << endl<<endl;
	}
}

void RemoveMedication() {
	if(numOfMedications==0) cout << "Please enter some medications first.\n";
	else {
		string NameOfMedToRemove;
		cout << "Please enter the name of the medication you want to remove from the pharmacy.\n";
		cin >> NameOfMedToRemove;
		if (pharmacies[pharmacyIndex].removeMedication(NameOfMedToRemove)) numOfMedications--;
	}
}

void AddOneMed() {
	Medication m;
	string MedName, MedDescription;
	double MedPrice;
	int MedQuantityInStock;
	Date ExpiryDate;
	int day, month, year;
	bool flag = false;
		flag = false;
		while (!flag) {
			cout << "Please enter the name of medication :\n";
			cin >> MedName;
			flag = m.set_MedicationName(MedName);
		}
		flag = false;
		while (!flag) {
			cout << "Please enter the medication description:\n";
			cin >> MedDescription;
			flag = m.set_Description(MedDescription);
		}

		flag = false;
		while (!flag) {
			cout << "Please enter the medication price:\n";
			cin >> MedPrice;
			flag = m.set_Price(MedPrice);
		}

		flag = false;
		while (!flag) {
			cout << "Please enter the medication quantity in stock:\n";
			cin >> MedQuantityInStock;
			flag = m.set_QuantityInStock(MedQuantityInStock);
		}

		flag = false;
		cout << "Please enter the medication expiry Date\n";
		while (!flag) {
			cout << "Day: ";
			cin >> day;
			flag = ExpiryDate.setday(day);
		}flag = false;
		while (!flag) {
			cout << "\nMonth : ";
			cin >> month;
			flag = ExpiryDate.setmonth(month);
		}flag = false;
		while (!flag) {
			cout << "\nYear : ";
			cin >> year;
			cout << endl;
			flag = ExpiryDate.setyear(year);
		}
		m.set_date(ExpiryDate);

	pharmacies[pharmacyIndex].AddOneMedication(m);//medication added to pharmacy

	meds[numOfMedications].set_MedicationName(MedName);//to add the medication to meds so that we can calculate total price
	meds[numOfMedications].set_Description(MedDescription);
	meds[numOfMedications].set_Price(MedPrice);
	meds[numOfMedications].set_QuantityInStock(MedQuantityInStock);
	meds[numOfMedications].set_date(ExpiryDate);
	numOfMedications++;
}

void AddOneCustomer() {

	Customer c;
	cout << "Enter a customer name: ";
	cin >> name;
	c.setCustomerName(name);
	cout << endl;

	cout << "Enter customer email : ";
	cin >> Email;
	info.set_email(Email);

	cout << "\nEnter customer city : ";
	cin >> city;
	info.set_city(city);

	cout << "\nEnter customer mobile number : ";
	cin >> phone;
	info.set_number(phone);

	cout << "\nEnter customer street name : ";
	cin >> street_name;
	info.set_street(street_name);

	c.setCustomerAddress(info);
	cout << endl;

	name = "no name";
	Email = "no email";
	city = "no city";
	phone = "no mobile number";
	street_name = "no street name";
	pharmacies[pharmacyIndex].AddOneCustomer(c);
	custnumb++;
}

void Compare2pharmacies() {
	int phar1, phar2;
	if (pharmacyIndex == 0) cout << "Add another pharmacy to compare.\n";
	else {
		do {
			cout << "Enter the number of the first pharmcay number you want to compare.\n";
			cin >> phar1;
		} while (phar1 > (pharmacyIndex + 1)||phar1<=0);
		do {
			cout << "Enter the number of the second pharmcay number you want to compare with.\n";
			cin >> phar2;
		} while ((phar2 > (pharmacyIndex + 1) && phar2 != phar1) || phar2 <= 0);
		int compare=1;
		do {
			if (compare != 1) cout << "Incorrect input.Please enter 1 OR 2 only.\n";
			cout << "choose type of comparison :\n" << "\t1.Number of medications in each pharmacy.\n" << "\t2.Number of customers in each pharmacy.\n";
			cin >> compare;
		} while (compare < 1 || compare > 2);
		if (compare == 1) pharmacies[phar1 - 1].medcomp(pharmacies[phar2 - 1]);// (-1) as we want the index
		else pharmacies[phar1 - 1].custcomp(pharmacies[phar2 - 1]);
	}
}

void ChoosePharmacy() {
	int pharmacy_numb;
	do{
		cout << "Enter the number of pharmacy you want to access.\n";
		cin >> pharmacy_numb;
	}while (pharmacy_numb<=0||pharmacy_numb>pharmacynumbers);
	pharmacyIndex = pharmacy_numb-1;
	numOfMedications = pharmacies[pharmacyIndex].get_MedsNumb();
	custnumb = pharmacies[pharmacyIndex].get_CustomersNumb();
}

void ResizePharmacies() {
	int newSize;
	do {
		cout << "Enter the new number of pharmcies you want to add to the current pharmacies.\n";
		cin >> newSize;
	} while (newSize <= 0);
	
	Pharmacy* temp = new Pharmacy[pharmacynumbers+newSize];
	for (int i = 0; i < pharmacynumbers; i++) 
		temp[i].setPharmacy(pharmacies[i]);
	
	pharmacynumbers += newSize;
	pharmacyIndex++;
	delete[] pharmacies;
	pharmacies = temp;
	temp = NULL;
	delete[] temp;

}