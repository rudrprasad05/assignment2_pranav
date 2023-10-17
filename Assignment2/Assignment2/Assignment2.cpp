#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "List.h"
#include "VisaApplication.h"
#include "Node.h"
#include "Data.h"

using namespace std;

void discard_line(ifstream& in);
void print_success_list(List& myList);
void print_failure_list(List& myList);
void remove_success_failure(List& myList);
void read_file(ifstream& in, List& myList);
void write_file(ofstream& out, List& myList);
void print_header(string props);

int main()
{
    int option;

    ifstream in;
    ofstream out;

    List myList;

    in.open("applications.txt", ios::in);
    out.open("applications_outcome.txt", ios::out);

    // read data from file "applications.txt"
    read_file(in, myList);
    // write data to "applications_outcome.txt"
    write_file(out, myList);

    in.close();
    out.close();

    // show menu options
    cout << "\n <--==[ Welcome to Visa Application App ]==-->" << endl << endl;
    cout << "Choose an option from the menu below" << endl
        << "1. Print All Applicants" << endl
        << "2. Print Successful Applicants" << endl
        << "3. Print Failed Applicants" << endl
        << "4. Print Pending Applicants" << endl << endl
        << "Enter a number [ 1 - 4 ]: ";
    cin >> option;

    // validate option variable 
    while (cin.fail() || option < 1 || option > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid option selected: ";
        cin >> option;
    }

    
    if (option == 1){
        print_header("Full List");
        myList.printList();
    }
    else if (option == 2)
        print_success_list(myList);
    else if (option == 3)
        print_failure_list(myList);
    else if (option == 4)
        remove_success_failure(myList);

    // error validation if option is invalid
    else cout << "Error! Invalid Input" << endl;

    cout << "\n\n";
    cout << "Closing Programme..." << endl;

}

// used to discard the extra line on top of the applications.txt file 
void discard_line(ifstream& in)
{
    char c;

    do
        in.get(c);
    while (c != '\n');
}

// function to remove successful and failed applicants
void remove_success_failure(List& myList) {

    // check if list is empty
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else {
        Node* pHead = myList.getpHead();
        Node* pNode = pHead;
        Node* temp = pNode; // temp node that will hold value of deleted node. used to access next node

        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {

            Data* d = pNode->getData();

            // cast from Data* to VisaApplication*
            VisaApplication *v = (VisaApplication*)d;

            if (v->getResult() == "success" || v->getResult() == "failure") {
                // remove unwanted nodes from list
                myList.removeNode(pNode);
                pNode = temp;

            }
            
        }
    }
    print_header("No Decision");
    myList.printList();

}

// function to print successful applicants to console 
void print_success_list(List& myList) {

    Node* pHead = myList.getpHead();
    Node* pNode = pHead;
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else{
        print_header("Successful Applicants List");
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {

            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            // if visa applicant result is successful then only print
            if (v->getResult() == "success") {
                v->print();
            }
            else {
                continue;
            }
        }
    }
}

void print_failure_list(List& myList){
    Node* pHead = myList.getpHead();
    Node* pNode = pHead;
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else{
        print_header("Failed Applicants List");
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {

            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            // if visa applicant result is failed then only print
            if (v->getResult() == "failure") {
                v->print();
            }
            else {
                continue;
            }
        }
    }
}

void read_file(ifstream& in, List& myList) {

    string temp_string;

    if (in.fail()) {
        cout << "invalid file or pathname" << endl;
        return;
    }

    discard_line(in);

    while (!in.eof()) {

        VisaApplication* visaRecords = new VisaApplication;

        
        in >> temp_string;
        visaRecords->setVisaType(temp_string);

        in >> temp_string;
        visaRecords->setInvoiceNumber(temp_string);

        in >> temp_string;
        visaRecords->setSurname(temp_string);

        in >> temp_string;
        visaRecords->setFirstName(temp_string);

        in >> temp_string;
        visaRecords->setContact(temp_string);

        in >> temp_string;
        visaRecords->setStatus(temp_string);

        in >> temp_string;
        visaRecords->setResult(temp_string);

        if (temp_string == "") {
            break;
        }
       
        myList.appendNode(visaRecords);

        temp_string = "";
    }

}

// function that is used as a template to print data onto the output file 
void write_file_template(ofstream& out, VisaApplication *visaRecords){
    out << setw(9) << visaRecords->getVisaType() << setw(4) << " | "
        << setw(8) << visaRecords->getInvoiceNumber() << setw(3) << " | "
        << setw(8) << visaRecords->getSurname() << setw(5) << " | "
        << setw(8) << visaRecords->getFirstName() << setw(5) << " | "
        << setw(5) << visaRecords->getContact() << setw(5) << " | "
        << setw(5) << visaRecords->getStatus() << setw(5) << " | "
        << setw(12) << visaRecords->getResult()  << " | " << endl ;
}

// function to print all data to the ouput file. 
void write_file(ofstream& out, List& myList){
    Node* pHead = myList.getpHead();
    Node* pNode = pHead;

    out << "Visa Application Out File" << endl;

    if (myList.isEmpty())
        cout << "The list is empty\n";
    else{
        // print full list
        out << "\n--==[ Full List ]==--\n" << endl;
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {
            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            write_file_template(out, v);
            
        }

        // print only Successful Applicants
        out << "\n--==[ Successful Applicants ]==--\n" << endl;
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {
            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            if (v->getResult() == "success") {
                write_file_template(out, v);
            }
        }

        // print only Failed Applicants
        out << "\n--==[ Failed Applicants ]==--\n" << endl;
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {
            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            if (v->getResult() == "failure") {
                write_file_template(out, v);
            }
        }

        // print only Pending Applicants
        out << "\n--==[ Pending Applicants ]==--\n" << endl;
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {
            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            if (v->getResult() == "failure") {
                write_file_template(out, v);
            }
        }
    }
}

void print_header(string props){
    cout << "\n\n Printing... " << props << "\n\n\n";
    cout << setw(8) << "Type" << setw(5) << " | "
        << setw(8) << "Invoice" << setw(3) << " | "
        << setw(8) << "Surname" << setw(5) << " | "
        << setw(8) << "Name" << setw(5) << " | "
        << setw(5) << "Contact" << setw(5) << " | "
        << setw(3) << "status" << setw(4) << " | "
        << setw(12) << "result" << " | " << endl;
    for(int i = 0; i < 85; i++){
        cout << "-";
    }
    cout << endl;
}


