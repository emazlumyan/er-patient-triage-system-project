// File: main.cpp
// Author: Eric Mazlumyan
// Date: October 2025
// Description: Entry point for Emergency Room Patient Triage System providing menu-driven interface for user interaction

#include <iostream>
#include "MaxHeap.h"
using namespace std;

int main() {
    // Declare variables
    MaxHeap queue;
    int choice;

    while (true) { // Check that the user has not exited program
        cout << "=== ER Patient Management Menu ===\n";
        cout << "1. Add new patient\n";
        cout << "2. Display current queue\n";
        cout << "3. Process next patient\n";
        cout << "4. View highest priority patient\n";
        cout << "5. Update a patient's priority (condition worsening)\n";
        cout << "6. Show number of patients waiting\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // Declare variables
            string name;
            int age;
            int waitTime;
            int triageCategory;
            string symptom;

            // Prompt the user and accept input from user
            cout << "Enter patient first and last name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter patient age: ";
            cin >> age;
            cout << "Enter the number of minutes since the patient arrived: ";
            cin >> waitTime;
            cout << "Enter triage category (1-5): ";
            cin >> triageCategory;
            cin.ignore();
            cout << "Enter symptom: ";
            getline(cin, symptom);

            // Add new patient
            Patient newPatient(name, age, waitTime, triageCategory, symptom);
            cout << "New patient arrived!\n";
            cout << "Adding: ";
            newPatient.printInfo();
            cout << endl;
            queue.Insert(newPatient); 
        }
        else if (choice == 2) {
            queue.DisplayQueue();
        }
        else if (choice == 3) {
            cout << "Processing next patient...\n";
            Patient nextPatient = queue.ExtractMax();
            cout << "TREATING: ";
            nextPatient.printInfo();
            cout << endl;
        }
        else if (choice == 4) {
            cout << "Viewing highest priority patient...\n";
            Patient priorityPatient = queue.Peek();
            cout << "[Priority: " << priorityPatient.getPriority() << "] ";
            priorityPatient.printInfo();
            cout << endl;
        }
        else if (choice == 5) {
            // Prompt the user and accept input from user for determining patient of interest
            cout << "Select which patient's priority to increase:\n";
            queue.DisplayQueue();
            cout << "Enter patient number (1-" << queue.Size() << "): ";
            int patientNumber;
            cin >> patientNumber;

            if (patientNumber < 1 || patientNumber > queue.Size()) { // Validate input
                cout << "Invalid selection.\n";
            }
            else { // Increase the priority of patient of interest by 5 with cap of 100
                queue.IncreaseKey(patientNumber - 1);
                cout << "Patient's priority updated.\n";
            }
        }
        else if (choice == 6) {
            cout << "The number of patients currently waiting is: " << queue.Size() << ".\n";
        }
        else if (choice == 7) {
            cout << "Exiting system.\n";
            break;
        }
        else {
            cout << "Invalid selection. Try again.\n";
        }

    }

    return 0;
}
