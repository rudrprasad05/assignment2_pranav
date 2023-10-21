README

CS112 assignment 2 2023

rudr prasad - s11219309
pranav datt - s11221041

--------------------------------------------------------------------------------------------------------------------------------------

# Assignment2.cpp:

The assignment is visa application processing app. The program reads data about applicants from file named applications.txt, processes it, and provides options to display and filter the applications. Below are the details about the code and instructions on how to run it.

1. Read and Process Applications
The program reads applicant data from the applications.txt file, processes it, and stores it in a linked list.


2. Display Applicants
The program allows you to display different categories of applicants:

Print All Applicants: Displays the full list of applicants.
Print Successful Applicants: Displays applicants who were successful.
Print Failed Applicants: Displays applicants who were unsuccessful.
Print Pending Applicants: Displays applicants with NODecision status.
Create output file named applications_outcome.txt. Contains full list of applicants


3. Manage Applicants
Remove Successful and Failed Applicants: Removes applicants who were successful or failed from the list and displays the updated list with pending applicants.


4. Output to File
The program writes the processed data into the applications_outcome.txt file, categorizing applicants into successful, failed, and pending categories.


5. Error Handling
The program includes error handling for invalid user inputs and file errors.


# Note 
- Please ensure that the applications.txt file is present in the same directory as the executable. The program will read data from this file and create the output file in the same location.
- to run the file, open the A2_s11219309_s11221041.sln file using an IDE such as visual studio. Build and run the programme.


# VisaApplication.h

This program contains a C++ program for managing visa applications. The program utilizes the VisaApplication class to handle individual visa applications. Below are the details about the functionality of the code and instructions on how to run it.

1. VisaApplication Class & Methods

The VisaApplication class represents a visa application and includes the following :

-> visa_type: Type of visa applied for.
-> invoice_no: Invoice number associated with the application.
-> surname: Surname of the applicant.
-> first_name: First name of the applicant.
-> contact: Contact information of the applicant.
-> status: Status of the application.
-> result: Result of the application (success, failure, etc.).

The class includes methods to set and get these attributes and a print() method to display the application details in a formatted manner.

Methods

-> print() - overriden pure virtual function. Will print details to console
-> writeToFile() - will write details to output file
