# Project: Emergency Room Patient Triage System
## Author: Eric Mazlumyan

**Project Context**
The Emergency Room Patient Triage System project was part of the curriculum of the course CS/IS 212 (Advanced Data Structures) at Glendale Community College.

**Project Overview**
The program is a simulation of an Emergency Room patient management system in which patients receive care by order of priority dependent on multiple parameters. The system is based on a max-heap data structure that allows for efficient updating and organizing of patient priority as related developments occur.

**Compilation Instructions**
- While in the directory in which the program is saved, run the following terminal command: "g++ -std=c++17 MaxHeap.cpp main.cpp -o er_system".
- In order to run the program, run the following terminal command: "./er_system".

**Program Instructions for User**
- After the main menu appears automatically, select an option by entering a number between 1 through 7.
- Follow along with the instructions that follow based on selection.

**Description of Priority Algorithm**
Patient priority is calculated based on three factors: triage category, wait time, and age. 1 triage category unit is equal to 12 priority units. Wait times of 60 minutes or more, 30 minutes or more but less than 60 minutes, and 15 minutes or more but less than 30 minutes are equivalent to 24 priority units, 16 priority units, and 8 priority units, respectively. Age of greater than 64 years and age of lower than 18 years are both equivalent to 5 priority units. Priority is capped at 100 priority units. Priority units are summed to determine the priority value result for a given patient.
