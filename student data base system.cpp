#include <iostream>
#include <string>
using namespace std;
#define MAX_STUDENTS 100
struct Student {
    int id;
    string name;
    string address;
    string fatherName;
    string department;
    float fscMarks;
    float matricMarks;
    string fscBoard;
    string matricBoard;
    float percentage;
    float scholarship;
    string province; 
};
Student students[MAX_STUDENTS];
int studentCount = 0;
void calculateScholarshipAndPercentage(Student &student) {
    student.percentage = (student.fscMarks + student.matricMarks) / 2200 * 100;
    if (student.percentage >= 90) {
        student.scholarship = 70.0;
    } else if (student.percentage >= 80) {
        student.scholarship = 50.0;
    } else if (student.percentage >= 70) {
        student.scholarship = 20.0;
    } else {
        student.scholarship = 0.0;
    }
}
void inputStudentData(Student &student) {
    cout << "Enter Student ID: ";
    cin >> student.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Address: ";
    getline(cin, student.address);
    cout << "Enter Father's Name: ";
    getline(cin, student.fatherName);
    cout << "Enter Department: ";
    getline(cin, student.department);
    cout << "Enter FSC Marks (out of 1100): ";
    cin >> student.fscMarks;
    cout << "Enter Matric Marks (out of 1100): ";
    cin >> student.matricMarks;
    cin.ignore();
    cout << "Enter FSC Board: ";
    getline(cin, student.fscBoard);
    cout << "Enter Matric Board: ";
    getline(cin, student.matricBoard);
    cout << "Enter Province: "; 
    getline(cin, student.province);
    calculateScholarshipAndPercentage(student);
}
void displayStudentData(const Student &student) {
    cout << "\nStudent ID: " << student.id
         << "\nName: " << student.name
         << "\nAddress: " << student.address
         << "\nFather's Name: " << student.fatherName
         << "\nDepartment: " << student.department
         << "\nFSC Marks: " << student.fscMarks
         << "\nMatric Marks: " << student.matricMarks
         << "\nFSC Board: " << student.fscBoard
         << "\nMatric Board: " << student.matricBoard
         << "\nProvince: " << student.province
         << "\nPercentage: " << student.percentage << "%"
         << "\nScholarship: " << student.scholarship << "%\n";
}
void updateStudentData(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == id) {
            cout << "Updating data for Student ID: " << id << "\n";
            inputStudentData(students[i]);
            cout << "Student data updated successfully!\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}
void deleteStudentData(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }
            --studentCount;
            cout << "Student with ID " << id << " deleted successfully!\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}
void listAllStudents() {
    if (studentCount == 0) {
        cout << "No students in the database.\n";
        return;
    }

    for (int i = 0; i < studentCount; ++i) {
        displayStudentData(students[i]);
        cout << "-------------------------\n";
    }
}
void initializeStudents() {
    students[0] = {1001, "Hammad", "Wah Cantt", "LatifUllah", "BCCS", 860, 880, "FBR", "FBR", 0, 0, "Punjab"};
    students[1] = {1002, "Ali", "Taxila", "Aftab", "BCCS", 890, 900, "FBR", "FBR", 0, 0, "Punjab"};
    students[2] = {1003, "Ahmed", "Dir", "Naeem", "BCCS", 770, 795, "Malakand", "Malakand", 0, 0, "KPK"};
    students[3] = {1004, "Maaz", "Lahore", "Ibrar", "BSSE", 780, 770, "Lahore", "Lahore", 0, 0, "Punjab"};
    students[4] = {1005, "Fatima", "Pasheen", "Yaseer", "BSSE", 930, 950, "Pasheen", "Pasheen", 0, 0, "Balochistan"};
    students[5] = {1006, "Khadija", "Sukur", "Siddique", "BSSE", 980, 950, "Sukur", "Sukur", 0, 0, "Sindh"};
    students[6] = {1007, "Areesha", "Swat", "Ibrahim", "BSAI", 660, 670, "Malakand", "Malakand", 0, 0, "KPK"};
    students[7] = {1008, "Husna", "Peshawar", "Javeed", "BSAI", 680, 700, "Peshawar", "Peshawar", 0, 0, "KPK"};
    students[8] = {1009, "Bilal", "Mardan", "Khalid", "BSAI", 700, 720, "Mardan", "Mardan", 0, 0, "KPK"};
    students[9] = {1010, "Tehseen", "Taxila", "Imran", "BSAI", 891, 621, "Pindi", "Pindi", 0, 0, "Punjab"};
    studentCount = 10;
    for (int i = 0; i < studentCount; ++i) {
        calculateScholarshipAndPercentage(students[i]);
    }
}
int main() {
    initializeStudents();
    int choice;
    do {
        cout << "\nStudent Database System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. List All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Cannot add more students. Database is full.\n";
                } else {
                    inputStudentData(students[studentCount]);
                    ++studentCount;
                    cout << "Student added successfully!\n";
                }
                break;
            }
            case 2: {
                int id;
                cout << "Enter Student ID to display: ";
                cin >> id;
                cin.ignore();
                bool found = false;
                for (int i = 0; i < studentCount; ++i) {
                    if (students[i].id == id) {
                        displayStudentData(students[i]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student with ID " << id << " not found.\n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter Student ID to update: ";
                cin >> id;
                cin.ignore();
                updateStudentData(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Student ID to delete: ";
                cin >> id;
                cin.ignore();
                deleteStudentData(id);
                break;
            }
            case 5:
                listAllStudents();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}
