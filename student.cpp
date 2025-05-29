
// student.cpp
#include "student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Utility to split CSV line into Student object
Student parseStudent(const string& line) {
    stringstream ss(line);
    string item;
    Student s;
    getline(ss, s.id, ',');
    getline(ss, s.name, ',');
    getline(ss, s.grade, ',');
    getline(ss, s.contact, ',');
    return s;
}

// Utility to convert Student object to CSV string
string toCSV(const Student& s) {
    return s.id + "," + s.name + "," + s.grade + "," + s.contact;
}

void addStudent() {
    Student s;
    cout << "Enter Student ID: ";
    getline(cin, s.id);
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Grade: ";
    getline(cin, s.grade);
    cout << "Enter Contact: ";
    getline(cin, s.contact);

    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << toCSV(s) << '\n';
        file.close();
        cout << "Student added successfully.\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

void editStudent() {
    string searchId;
    cout << "Enter Student ID to edit: ";
    getline(cin, searchId);

    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");
    bool found = false;

    string line;
    while (getline(inFile, line)) {
        Student s = parseStudent(line);
        if (s.id == searchId) {
            found = true;
            cout << "Editing Student: " << s.name << endl;
            cout << "Enter new name (current: " << s.name << "): ";
            getline(cin, s.name);
            cout << "Enter new grade (current: " << s.grade << "): ";
            getline(cin, s.grade);
            cout << "Enter new contact (current: " << s.contact << "): ";
            getline(cin, s.contact);
            // Keep ID unchanged to avoid duplicate issues
        }
        outFile << toCSV(s) << '\n';
    }

    inFile.close();
    outFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student record updated.\n";
    else
        cout << "Student ID not found.\n";
}


void searchStudent() {
    string keyword;
    cout << "Enter Student ID or Name to search: ";
    getline(cin, keyword);

    ifstream file("students.txt");
    bool found = false;
    string line;
    while (getline(file, line)) {
        Student s = parseStudent(line);
        if (s.id == keyword || s.name == keyword) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << s.id << "\nName: " << s.name << "\nGrade: " << s.grade << "\nContact: " << s.contact << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
        cout << "Student not found.\n";
}

void listStudents() {
    string filterGrade;
    cout << "Enter grade to filter (leave empty to list all): ";
    getline(cin, filterGrade);

    ifstream file("students.txt");
    string line;
    cout << "\nList of Students:\n";
    while (getline(file, line)) {
        Student s = parseStudent(line);
        if (filterGrade.empty() || s.grade == filterGrade) {
            cout << "ID: " << s.id << ", Name: " << s.name << ", Grade: " << s.grade << ", Contact: " << s.contact << endl;
        }
    }
    file.close();
}

void promoteStudentByID() {
    string targetID;
    cout << "Enter Student ID to promote: ";
    cin >> targetID;
    cin.ignore(); // to clear newline left by cin

    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        Student s = parseStudent(line);
        if (s.id == targetID) {
            try {
                int g = stoi(s.grade);
                if (g >= 12) {
                    cout << "Student " << s.name << " is already in the maximum grade (12).\n";
                } else {
                    s.grade = to_string(g + 1);
                    cout << "Student " << s.name << " promoted to grade " << s.grade << ".\n";
                }
                found = true;
            } catch (...) {
                cout << "Cannot promote student with non-numeric grade.\n";
            }
        }
        outFile << toCSV(s) << '\n';
    }

    inFile.close();
    outFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (!found) {
        cout << "Student ID not found.\n";
    }
}

