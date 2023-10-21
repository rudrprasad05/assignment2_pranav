#pragma once
#include "Data.h"
#include <iostream>
#include <iomanip>
#include <ostream>

using namespace std;

class VisaApplication : public Data {

    private:
        string visa_type;
        string invoice_no;
        string surname;
        string first_name;
        string contact;
        string status;
        string result;

public:

    VisaApplication(string visa_type, string invoice_no, string surname, string first_name, string contact, string status, string result)
        : visa_type(visa_type), invoice_no(invoice_no), surname(surname), first_name(first_name), contact(contact), status(status), result(result){}

    void print()
    {
        cout << setw(9) << this->visa_type << setw(4) << " | "
            << setw(8) << this->invoice_no << setw(3) << " | "
            << setw(8) << this->surname << setw(5) << " | "
            << setw(8) << this->first_name << setw(5) << " | "
            << setw(5) << this->contact << setw(5) << " | "
            << setw(5) << this->status << setw(5) << " | "
            << setw(12) << this->result  << " | " << endl ;
            
    }
    void writeFile(ostream& out)
    {
        out << setw(9) << this->visa_type << setw(4) << " | "
            << setw(8) << this->invoice_no << setw(3) << " | "
            << setw(8) << this->surname << setw(5) << " | "
            << setw(8) << this->first_name << setw(5) << " | "
            << setw(5) << this->contact << setw(5) << " | "
            << setw(5) << this->status << setw(5) << " | "
            << setw(12) << this->result  << " | " << endl ;
            
    }

    // getters
    
    string getVisaType(){
        return visa_type;
    }
    string getInvoiceNumber(){
        return invoice_no;
    }
    string getFirstName(){
        return first_name;
    }
    string getSurname() {
        return surname;
    }
    string getContact(){
        return contact;
    }
    string getStatus(){
        return status;
    }
    string getResult(){
        return result;
    }

};