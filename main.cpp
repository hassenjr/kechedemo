#include <iostream>
#include <string>
#include "student.h"
#include "teacher.h"
#include "course.h"
#include "attendance.h"
#include "grade.h"
#include "operations.h"

using namespace std;

void studentMenu() {
    int choice;
    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student\n";
        cout << "3. Search Student\n";
        cout << "4. List All Students\n";
        cout << "5. Promote Student\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: searchStudent(); break;
            case 4: listStudents(); break;
            case 5: promoteStudentByID(); break;
        }
    } while (choice != 0);
}

void teacherMenu() {
    int choice;
    do {
        cout << "\n--- Teacher Management ---\n";
        cout << "1. Add Teacher\n";
        cout << "2. Edit Teacher\n";
        cout << "3. Search Teacher\n";
        cout << "4. List All Teachers\n";
        cout << "5. Assign Class Teacher\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addTeacher(); break;
            case 2: editTeacher(); break;
            case 3: searchTeacher(); break;
            case 4: listTeachers(); break;
            case 5: assignClassTeacher(); break;
        }
    } while (choice != 0);
}

void courseMenu() {
    int choice;
    do {
        cout << "\n--- Course Management ---\n";
        cout << "1. Add Course\n";
        cout << "2. Edit Course\n";
        cout << "3. Search Course\n";
        cout << "4. List All Courses\n";
        cout << "5. Assign Teacher to Course\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addCourse(); break;
            case 2: editCourse(); break;
            case 3: searchCourse(); break;
            case 4: listCourses(); break;
            case 5: assignTeacherToCourse(); break;
        }
    } while (choice != 0);
}

void attendanceMenu() {
    int choice;
    do {
        cout << "\n--- Attendance Module ---\n";
        cout << "1. Mark Attendance\n";
        cout << "2. Edit Attendance\n";
        cout << "3. View Attendance\n";
        cout << "4. Attendance Reports\n";
        cout << "5. Attendance Stats\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: markAttendance(); break;
            case 2: editAttendance(); break;
            case 3: viewAttendance(); break;
            case 4: generateMonthlyReport(); break;
            case 5: calculateAttendanceStats(); break;
        }
    } while (choice != 0);
}

void gradeMenu() {
    int choice;
    do {
        cout << "\n--- Grade Management ---\n";
        cout << "1. Record Grades\n";
        cout << "2. Edit Grades\n";
        cout << "3. Calculate GPA\n";
        cout << "4. Grade Reports\n";
        cout << "5. Honor Roll\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: recordGrade(); break;
            case 2: editGrade(); break;
            case 3: calculateGPA(); break;
            case 4: generateTranscript(); break;
            case 5: showHonorRoll(); break;
        }
    } while (choice != 0);
}

void operationsMenu() {
    int choice;
    do {
        cout << "\n--- School Operations ---\n";
        cout << "1. Assign Classroom\n";
        cout << "2. View Classroom Assignments\n";
        cout << "3. Add Calendar Entry\n";
        cout << "4. View School Calendar\n";
        cout << "5. Add School Event\n";
        cout << "6. View Events\n";
        cout << "7. Record Fee Payment\n";
        cout << "8. View Fee Payments\n";
        cout << "9. Backup Data\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: assignClassroom(); break;
            case 2: viewClassroomAssignments(); break;
            case 3: addCalendarEntry(); break;
            case 4: viewCalendar(); break;
            case 5: addEvent(); break;
            case 6: viewEvents(); break;
            case 7: recordFee(); break;
            case 8: viewFees(); break;
            case 9: backupData(); break;
        }
    } while (choice != 0);
}

int main() {


    int mainChoice;
    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Student Management\n";
        cout << "2. Teacher Management\n";
        cout << "3. Course Management\n";
        cout << "4. Attendance Module\n";
        cout << "5. Grade Management\n";
        cout << "6. School Operations\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;
        cin.ignore();

        switch (mainChoice) {
            case 1: studentMenu(); break;
            case 2: teacherMenu(); break;
            case 3: courseMenu(); break;
            case 4: attendanceMenu(); break;
            case 5: gradeMenu(); break;
            case 6: operationsMenu(); break;
        }

    } while (mainChoice != 0);

    cout << "Thank you for using the system!\n";
    return 0;
}
