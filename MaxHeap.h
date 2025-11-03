// File: MaxHeap.h
// Author: Eric Mazlumyan
// Date: October 2025

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "Patient.h"
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<Patient> heap; // Declare vector heap

    // Declare private functions
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Declare public functions
    void Insert(const Patient& patient);
    Patient ExtractMax();
    Patient Peek() const;
    void IncreaseKey(int index);
    int Size() const;
    void DisplayQueue();
};

#endif
