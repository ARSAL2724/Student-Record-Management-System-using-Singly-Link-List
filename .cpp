#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Student {
    int rollNo;
    string name;
    float cgpa;
    string department;
    Student* next;
};
class StudentManagementSystem {
private:
    Student* head;
public:
    StudentManagementSystem() {
        head = NULL;
    }
    void addStudent() {
        Student* newStudent = new Student();
        cout << "\n--- Add New Student ---\n";
        cout << "Enter Roll Number: ";
        cin >> newStudent->rollNo;
        if (searchStudent(newStudent->rollNo) != NULL) {
            cout << "Error: Student with Roll No " << newStudent->rollNo << " already exists!\n";
            delete newStudent;
            return;
        }
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newStudent->name);
        cout << "Enter CGPA: ";
        cin >> newStudent->cgpa;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, newStudent->department);
        newStudent->next = NULL;
        if (head == NULL) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "\nStudent added successfully!\n";
    }
    void displayAllStudents() {
        if (head == NULL) {
            cout << "\nNo student records found!\n";
            return;
        }
        cout << "\n--- All Student Records ---\n";
        cout << left << setw(10) << "Roll No" 
             << setw(25) << "Name" 
             << setw(8) << "CGPA" 
             << setw(20) << "Department" << endl;
        cout << string(63, '-') << endl;
        Student* temp = head;
        while (temp != NULL) {
            cout << left << setw(10) << temp->rollNo 
                 << setw(25) << temp->name 
                 << setw(8) << fixed << setprecision(2) << temp->cgpa 
                 << setw(20) << temp->department << endl;
            temp = temp->next;
        }
    }
    Student* searchStudent(int rollNo) {
        Student* temp = head;
        while (temp != NULL) {
            if (temp->rollNo == rollNo) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    void searchAndDisplay() {
        int rollNo;
        cout << "\nEnter Roll Number to search: ";
        cin >> rollNo;
        Student* student = searchStudent(rollNo);
        if (student == NULL) {
            cout << "Student with Roll No " << rollNo << " not found!\n";
        } else {
            cout << "\n--- Student Found ---\n";
            cout << "Roll Number: " << student->rollNo << endl;
            cout << "Name: " << student->name << endl;
            cout << "CGPA: " << fixed << setprecision(2) << student->cgpa << endl;
            cout << "Department: " << student->department << endl;
        }
    }
    void updateStudent() {
        int rollNo;
        cout << "\nEnter Roll Number to update: ";
        cin >> rollNo;
        Student* student = searchStudent(rollNo);
        if (student == NULL) {
            cout << "Student with Roll No " << rollNo << " not found!\n";
            return;
        }
        cout << "\n--- Update Student Record ---\n";
        cout << "Current Details:\n";
        cout << "Name: " << student->name << endl;
        cout << "CGPA: " << student->cgpa << endl;
        cout << "Department: " << student->department << endl;
        cin.ignore();
        cout << "\nEnter New Name: ";
        getline(cin, student->name);
        cout << "Enter New CGPA: ";
        cin >> student->cgpa;
        cin.ignore();
        cout << "Enter New Department: ";
        getline(cin, student->department);
        cout << "\nStudent record updated successfully!\n";
    }
    void deleteStudent() {
        int rollNo;
        cout << "\nEnter Roll Number to delete: ";
        cin >> rollNo;
        if (head == NULL) {
            cout << "No records to delete!\n";
            return;
        }
        if (head->rollNo == rollNo) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student record deleted successfully!\n";
            return;
        }
        Student* temp = head;
        Student* prev = NULL;
        while (temp != NULL && temp->rollNo != rollNo) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Student with Roll No " << rollNo << " not found!\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Student record deleted successfully!\n";
    }
    int countStudents() {
        int count = 0;
        Student* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ~StudentManagementSystem() {
        Student* current = head;
        Student* next = NULL;
        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }
};
int main() {
    StudentManagementSystem sms;
    int choice;
    cout << "===============================================\n";
    cout << "   STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "===============================================\n";
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Total Students\n";
        cout << "7. Exit\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.displayAllStudents();
                break;
            case 3:
                sms.searchAndDisplay();
                break;
            case 4:
                sms.updateStudent();
                break;
            case 5:
                sms.deleteStudent();
                break;
            case 6:
                cout << "\nTotal Students: " << sms.countStudents() << endl;
                break;
            case 7:
                cout << "\nThank you for using Student Management System!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } 
    while (choice != 7);
    return 0;
}
