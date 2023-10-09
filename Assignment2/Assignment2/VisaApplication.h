#pragma once
#include "Data.h"
#include <iostream>
#include <iomanip>

using namespace std;

class VisaApplication : public Data {

public:


    string visa_type;
    string invoice_no;
    string surname;
    string first_name;
    string contact;
    string status;
    string result;

    void print()
    {
        cout << setw(9) << this->visa_type << setw(4) << " | "
            << setw(8) << this->invoice_no << setw(3) << " | "
            << setw(8) << this->surname << setw(5) << " | "
            << setw(8) << this->first_name << setw(5) << " | "
            << setw(5) << this->contact << setw(5) << " | "
            << setw(5) << this->status << setw(5) << " | "
            << setw(12) << this->result << " | " << endl;
    }

    string getName() {
        return surname;
    }

};