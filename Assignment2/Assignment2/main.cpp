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
bool check_white_space(string input1);
void print_success_failure(string type, List& myList);
void remove_success_failure(List& myList);
void read_file(ifstream& in, List& myList);
void print_header(){
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

int main()
{
    int option;

    ifstream in;
    ofstream out;

    List myList;

    in.open("applications.txt", ios::in);
    // out.open("applications_outcome.txt", ios::out);

    read_file(in, myList);

    in.close();


    cout << "Welcome to Visa Application App" << endl;
    cout << "Choose an option from the menu below" << endl
        << "1. Print All Applicants" << endl
        << "2. Print Successful Applicants" << endl
        << "3. Print Failed Applicants" << endl
        << "4. Print Pending Applicants" << endl
        << "Enter a number [ 1 - 4 ]: ";
    cin >> option;

    while (cin.fail() || option < 1 || option > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid option selected: ";
        cin >> option;
    }

    cout << "\n\n";

    if (option == 1)
        myList.printList();
    else if (option == 2)
        print_success_failure("success", myList);
    else if (option == 3)
        print_success_failure("failure", myList);
    else if (option == 4)
        remove_success_failure(myList);
    else
        cout << "Error! Invalid Input" << endl;

    cout << "\n\n";
    

    // out.close();

}

void discard_line(ifstream& in)
{
    char c;

    do
        in.get(c);
    while (c != '\n');
}

void remove_success_failure(List& myList) {


    if (myList.isEmpty())
        cout << "The list is empty\n";
    else {
        Node* pHead = myList.getpHead();
        Node* pNode = pHead;
        Node* temp = pNode;

        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {

            Data* d = pNode->getData();

            VisaApplication* v = dynamic_cast<VisaApplication*>(d);

            if (v->result == "success" || v->result == "failure") {
                myList.removeNode(pNode);
                pNode = temp;

            }
            else {
                continue;
            }
        }
    }
    myList.printList();

}

void print_success_failure(string type, List& myList) {

    Node* pHead = myList.getpHead();
    Node* pNode = pHead;
    if (myList.isEmpty())
        cout << "The list is empty\n";
    else{
        print_header();
        for (pNode = pHead; pNode != NULL; pNode = myList.nextNode(pNode)) {

            Data* d = pNode->getData();
            VisaApplication* v = dynamic_cast<VisaApplication*>(d);


            if (v->result == type) {
                v->print();
            }
            else {
                continue;
            }
        }
    }
}

void read_file(ifstream& in, List& myList) {

    if (in.fail()) {
        cout << "invalid file or pathname" << endl;
        return;
    }

    discard_line(in);

    while (!in.eof()) {

        VisaApplication* v = new VisaApplication;

        in >> v->visa_type;
        in >> v->invoice_no;
        in >> v->surname;
        in >> v->first_name;
        in >> v->contact;
        in >> v->status;
        in >> v->result;

        if (check_white_space(v->visa_type)) {
            break;
        }

        myList.appendNode(v);


    }

}

bool check_white_space(string input1) {
    if (input1 == "") {
        return true;
    }
    else return false;
}


