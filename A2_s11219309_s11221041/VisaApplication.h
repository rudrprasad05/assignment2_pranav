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

    // setters

    void setVisaType(string visa_type){
        this->visa_type = visa_type;
    }
    void setInvoiceNumber(string invoice_no){
        this->invoice_no = invoice_no;
    }
    void setFirstName(string first_name){
        this->first_name = first_name;
    }
    void setSurname(string surname){
        this->surname = surname;
    }
    void setContact(string contact){
        this->contact = contact;
    }
    void setStatus(string status){
        this->status = status;
    }
    void setResult(string result){
        this->result = result;
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