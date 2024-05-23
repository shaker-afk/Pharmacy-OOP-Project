#pragma once
#include<iostream>
#include<string>
#include"Medication.h"
using namespace std;

class Prescription : public Medication {
	int FDANumber;
	Date ApprovalDate;

public:
	Prescription();
	Prescription(int, const Date&, string, string, int, double);

	void set_approvaldate(const Date&);
	void set_FDANumber(int);

	int get_FDANumber()const;
	Date getapprovaldate()const;

	void print_MedicationInfo()const;
};