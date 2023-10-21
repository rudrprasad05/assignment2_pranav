#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ostream>

#include "List.h"
#include "VisaApplication.h"

using namespace std;

void discard_line(ifstream& in);

void print_success_list(List& myList, ofstream &out);
void print_failure_list(List& myList, ofstream &out);
void remove_success_failure(List& myList, ofstream &out);
void deleteList(List &myList);

void read_file(ifstream& in, List& myList);
void writeFile(ofstream& out, List& myList);
void print_header(string props, ostream& outputType);


int main()
{
    // Variable to store the user's menu option
    int option;
    bool running = true;

    // input file
    ifstream in;
    // output file
    ofstream out;

    List myList;

    // read data from file "applications.txt"
    // show menu options
    cout << "\n <--==[ Welcome to Visa Application App ]==-->" << endl;


    while(running){
        cout << "\nChoose an option from the menu below" << endl
            << "1. Print All Applicants" << endl
            << "2. Print Successful Applicants" << endl
            << "3. Print Failed Applicants" << endl
            << "4. Print Pending Applicants" << endl
            << "5. Write to File" << endl
            << "6. Quit";

        
        read_file(in, myList); 
        cout << "\n\nEnter a number [ 1 - 6 ]: ";
        cin >> option;

        // validate option variable 
        while (cin.fail() || option < 1 || option > 6) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option selected: ";
            cin >> option;
        }

        if (option == 1) {
            print_header("Full List", cout);
            // print full list of applicants stored in linked list
            myList.printList();
        }
        else if (option == 2)
            // print only applicants who were successful
            print_success_list(myList, out);

        else if (option == 3)
            // print only applicants who were unsuccessful
            print_failure_list(myList, out);

        else if (option == 4) {
            // remove unsuccessful and failed applicants. print list
            remove_success_failure(myList, out);
            
        }
        else if ( option == 5){
            writeFile(out, myList);
        }
            
        else if (option == 6) {
            cout << "Closing Programme..." << endl;
            running = false;
            break;
        }

        else cout << "Error! Invalid Input" << endl;
        deleteList(myList);


    }
  
    system("pause");
    return 0;
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
void remove_success_failure(List& myList, ofstream &out) {

    // check if list is empty
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else {
        // point to head of list
        Node* pHead = myList.getpHead();
        Node* pNode = pHead;
        // temp node that will hold value of deleted node. used to access next node
        Node* temp = pNode; 

        for (pNode = pHead; pNode != nullptr; pNode = myList.nextNode(pNode)) {

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
    print_header("No Decision", cout);
    myList.printList();

}

// function to print successful applicants to console 
void print_success_list(List& myList, ofstream &out) {

    Node* pHead = myList.getpHead();
    Node* pNode = pHead;
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else{
        print_header("Successful Applicants List", cout);

        for (pNode = pHead; pNode != nullptr; pNode = myList.nextNode(pNode)) {

            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            // if visa applicant result is successful then only print
            if (v->getResult() == "success") {
                // print to console
                v->print();
                // write same data to file
                v->writeFile(out);
            }
        }
    }

}

void print_failure_list(List& myList, ofstream &out){

    Node* pHead = myList.getpHead();
    Node* pNode = pHead;
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else{
        print_header("Failed Applicants List", cout);

        for (pNode = pHead; pNode != nullptr; pNode = myList.nextNode(pNode)) {

            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            // if visa applicant result is failed then only print
            if (v->getResult() == "failure") {
                // print to console
                v->print();
                // write same data to file
                v->writeFile(out);
            }
            
        }
    }

}

void read_file(ifstream& in, List& myList) {
    in.open("applications.txt", ios::in);

    // temporary string  to hold data read from the file.
    string visa_type,
        invoice_no,
        surname,
        first_name,
        contact,
        status,
        result;

    // check if errors encounted
    if (in.fail()) {
        cout << "invalid file or pathname" << endl;
        return;
    }

    // discard unwanted lines
    discard_line(in);

    // loop through until end of file reached
    while (in >> visa_type) {

        in >> invoice_no;
        in >> surname;
        in >> first_name;
        in >> contact;
        in >> status;
        in >> result;

        VisaApplication* visaRecords = new VisaApplication(visa_type, invoice_no, surname, first_name, contact, status, result);

        // append to linked list
        myList.appendNode(visaRecords);
    }
    in.close();

}
void writeFile(ofstream& out, List& myList){
    out.open("applications_outcome.txt", ios::out);

    Node* pHead = myList.getpHead();
    Node* pNode = pHead;
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else{
        print_header("Visa Applicants List", out);

        for (pNode = pHead; pNode != nullptr; pNode = myList.nextNode(pNode)) {

            Data* d = pNode->getData();
            VisaApplication *v = (VisaApplication*)d;

            v->writeFile(out);
        }

        cout << "File written" << endl;
    }
    out.close();

}

// function that is used as a template to print data onto the output file 
void print_header(string props, ostream& outputType){
    outputType << "\n\n Printing... " << props << "\n\n\n";
    outputType << setw(8) << "Type" << setw(5) << " | "
        << setw(8) << "Invoice" << setw(3) << " | "
        << setw(8) << "Surname" << setw(5) << " | "
        << setw(8) << "Name" << setw(5) << " | "
        << setw(5) << "Contact" << setw(5) << " | "
        << setw(3) << "status" << setw(4) << " | "
        << setw(12) << "result" << " | " << endl;
    for(int i = 0; i < 85; i++){
        outputType << "-";
    }
    outputType << endl;
}

void deleteList(List &myList){
    while (!myList.isEmpty())   //keep on removing until the
        //head points to NULL
        myList.removeNode(myList.getpHead());
    cout << "List deleted\n";
}
