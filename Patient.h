// File: Patient.h
// Author: Eric Mazlumyan
// Date: October 2025
// Description: Header file for the Patient class

#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
using namespace std;

class Patient {
private:
    // Declare variables
    string name;
    int age;
    int waitTime;
    int triageCategory;
    string symptom;
    int priority;

public:
    // Define default constructor
    Patient() : name(""), age(0), waitTime(0), triageCategory(1), symptom(""), priority(0) {
    }

    // Define parameterized constructor
    Patient(string n, int a, int wT, int tC, string s) : name(n), age(a), waitTime(wT), triageCategory(tC), symptom(s) {
        calculatePriority();
    }

    void calculatePriority() { // Define method to calculate Priority based on triage category, wait time, and age
        int triageValue = 0;
        switch (triageCategory) { // Define triageValue based on triage category
            case 5: 
                triageValue = 60;
                break;
            case 4:
                triageValue = 48;
                break;
            case 3:
                triageValue = 36;
                break;
            case 2:
                triageValue = 24;
                break;
            case 1:
                triageValue = 12;
                break;
        }

        int waitValue = 0;
        if (waitTime >= 60) { // Define waitValue based on wait time
            waitValue = 24;
        }
        else if (waitTime >= 30) {
            waitValue = 16;
        }
        else if (waitTime >= 15) {
            waitValue = 8;
        }

        int ageValue = 0;
        if (age > 64 || age < 18) { // Define ageValue based on age
            ageValue = 5;
        }

        priority = triageValue + waitValue + ageValue; // Compute priority
    }

    // Getter methods
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    int getTriage() const {
        return triageCategory;
    }
    string getSymptom() const {
        return symptom;
    }
    int getPriority() const {
        return priority;
    }

    void increasePriority() { // Define method to increase priority by 5 with cap of 100
        priority += 5;
        if (priority > 100) {
            priority = 100;
        }
    }

    void printInfo() const { // Define method to print patient information in one line
        cout << name << ", Age " << age << ", Triage " << triageCategory << ": " << symptom;
    }
};

#endif
