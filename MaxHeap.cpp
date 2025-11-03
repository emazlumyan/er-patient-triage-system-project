// File: MaxHeap.cpp
// Author: Eric Mazlumyan
// Date: October 2025

#include "MaxHeap.h"
#include <iostream>
#include <algorithm>
using namespace std;

void MaxHeap::heapifyUp(int index) {
    while (index > 0) { // Check that the patient is not at the root node
        int parent = (index - 1) / 2; // Define the parent node index
        if (heap[index].getPriority() > heap[parent].getPriority()) { // Check if the child node is of greater value than parent node
            swap(heap[index], heap[parent]); // Swap child and parent node values
            index = parent; // Update index of child node
        }
        else {
            break;
        }

    }
}

void MaxHeap::heapifyDown(int index) {
    int size = heap.size();
    while (true) {
        int left = 2 * index + 1; // Define left child index
        int right = 2 * index + 2; // Define right child index
        int largest = index; // Initialize largest to be current index

        if (left < size && heap[left].getPriority() > heap[largest].getPriority()) { // Validate and check if left child is of greater value than parent node
            largest = left;
        }

        if (right < size && heap[right].getPriority() > heap[largest].getPriority()) { // Validate and check if right child is of greater value than parent node
            largest = right;
        }

        if (largest != index) { // Check that child node value is unequal to parent node value
            swap(heap[index], heap[largest]); // Swap largest child and parent node values
            index = largest; // Update index of parent node
        }
        else {
            break;
        }

    }
}

void MaxHeap::Insert(const Patient& patient) { // Define method for adding new patient to heap
    heap.push_back(patient);
    heapifyUp(heap.size() - 1);
}

Patient MaxHeap::ExtractMax() { // Define method for removing and returning highest priority patient 
    if (heap.empty()) {
        cout << "No patients in queue.\n";
        return Patient();
    }

    Patient maxPatient = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return maxPatient;
}

Patient MaxHeap::Peek() const { // Define method for viewing highest priority patient without removing
    if (heap.empty()) {
        cout << "No patients in queue.\n";
        return Patient();
    }
    return heap[0];
}

bool comparePatientPairs(const pair<Patient, int>& a, const pair<Patient, int>& b) {
    return a.first.getPriority() > b.first.getPriority();
}

void MaxHeap::IncreaseKey(int index) { // Define method for updating patient's priority
    if (index < 0 || index >= heap.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    vector<pair<Patient, int> > displayHeap; // Initialize displayHeap for storing information of patients as viewed by user

    for (int i = 0; i < heap.size(); ++i) { // Store heap contents and associated heap indexes as pairs into displayHeap
        displayHeap.push_back(make_pair(heap[i], i));
    }

    std::sort(displayHeap.begin(), displayHeap.end(), comparePatientPairs); // Sorts patients based on priority from greatest to least

    int heapIndex = displayHeap[index].second; // Define heapIndex accordingly as heap index saved from earlier population of displayHeap
    heap[heapIndex].increasePriority();
    heapifyUp(heapIndex);
}

int MaxHeap::Size() const { // Define method for returning number of patients waiting
    return heap.size();
}

bool comparePatients(const Patient& a, const Patient& b) { // Define helper method for sorting queue display
    return a.getPriority() > b.getPriority();
}

void MaxHeap::DisplayQueue() {
    cout << "=== ER Patient Management System ===" << endl;
    if (heap.empty()) {
        cout << "No patients in queue.\n";
        return;
    }

    cout << "Current Queue:\n";

    vector<Patient> displayHeap = heap; // Define vector displayHeap for displaying information of patients in queue

    std::sort(displayHeap.begin(), displayHeap.end(), comparePatients); // Sorts patients based on priority from greatest to least

    for (size_t i = 0; i < displayHeap.size(); ++i) { // Prints queue display
        cout << i + 1 << ". [Priority: " << displayHeap[i].getPriority() << "] ";
        displayHeap[i].printInfo();
        cout << endl;
    }
    
}
