// teacher.cpp
#include "teacher.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

// Parse CSV line to Teacher struct
Teacher parseTeacher(const string& line) {
    stringstream ss(line);
    string item;
    Teacher t;
    getline(ss, t.id, ',');
    getline(ss, t.name, ',');
    getline(ss, t.subject, ',');
    getline(ss, t.contact, ',');
    getline(ss, t.classAssigned, ',');
    return t;
}

// Convert Teacher struct to CSV string
string toCSV(const Teacher& t) {
    return t.id + "," + t.name + "," + t.subject + "," + t.contact + "," + t.classAssigned;
}

void addTeacher() {
    Teacher t;
    cout << "Enter Teacher ID: ";
    getline(cin, t.id);
    cout << "Enter Name: ";
    getline(cin, t.name);
    cout << "Enter Subject: ";
    getline(cin, t.subject);
    cout << "Enter Contact: ";
    getline(cin, t.contact);
    t.classAssigned = "None";

    ofstream file("teachers.txt", ios::app);
    if (file.is_open()) {
        file << toCSV(t) << '\n';
        file.close();
        cout << "Teacher added successfully.\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

void editTeacher() {
    string searchId;
    cout << "Enter Teacher ID to edit: ";
    getline(cin, searchId);

    ifstream inFile("teachers.txt");
    ofstream outFile("temp.txt");
    bool found = false;
    string line;

    while (getline(inFile, line)) {
        Teacher t = parseTeacher(line);
        if (t.id == searchId) {
            found = true;
            cout << "Editing Teacher: " << t.name << endl;
            cout << "Enter new name (current: " << t.name << "): ";
            getline(cin, t.name);
            cout << "Enter new subject (current: " << t.subject << "): ";
            getline(cin, t.subject);
            cout << "Enter new contact (current: " << t.contact << "): ";
            getline(cin, t.contact);
        }
        outFile << toCSV(t) << '\n';
    }

    inFile.close();
    outFile.close();
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");

    if (found)
        cout << "Teacher record updated.\n";
    else
        cout << "Teacher ID not found.\n";
}

void searchTeacher() {
    string keyword;
    cout << "Enter Teacher ID or Subject to search: ";
    getline(cin, keyword);

    ifstream file("teachers.txt");
    bool found = false;
    string line;
    while (getline(file, line)) {
        Teacher t = parseTeacher(line);
        if (t.id == keyword || t.subject == keyword) {
            cout << "\nTeacher Found:\n";
            cout << "ID: " << t.id << "\nName: " << t.name << "\nSubject: " << t.subject
                 << "\nContact: " << t.contact << "\nClass Assigned: " << t.classAssigned << endl;
            found = true;
        }
    }
    file.close();

    if (!found)
        cout << "No matching teacher found.\n";
}

void listTeachers() {
    ifstream file("teachers.txt");
    string line;
    cout << "\nList of All Teachers:\n";
    while (getline(file, line)) {
        Teacher t = parseTeacher(line);
        cout << "ID: " << t.id << ", Name: " << t.name << ", Subject: " << t.subject
             << ", Contact: " << t.contact << ", Class Assigned: " << t.classAssigned << endl;
    }
    file.close();
}

void assignClassTeacher() {
    string teacherId, className;
    cout << "Enter Teacher ID to assign as class teacher: ";
    getline(cin, teacherId);

    // Input and validate class name
    while (true) {
        cout << "Enter class to assign (e.g., 5A, 12E): ";
        getline(cin, className);

        // Allow only classes 1-12 with section A-E
        if (regex_match(className, regex("^(1[0-2]|[1-9])[A-E]$"))) {
            break;
        } else {
            cout << "Invalid class format. Please enter class as 1_12 followed by section A_E (e.g., 3A, 12E).\n";
        }
    }

    ifstream inFile("teachers.txt");
    ofstream outFile("temp.txt");
    bool found = false;
    string line;

    while (getline(inFile, line)) {
        Teacher t = parseTeacher(line);
        if (t.id == teacherId) {
            t.classAssigned = className;
            found = true;
        }
        outFile << toCSV(t) << '\n';
    }

    inFile.close();
    outFile.close();
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");

    if (found)
        cout << "Class " << className << " assigned to teacher.\n";
    else
        cout << "Teacher ID not found.\n";
}

