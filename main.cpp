#include <iostream>

using namespace std;

struct Student
{
    string fName;
    string lName;
    string id;
    Student * next;

    Student()
    {
        cout << "First Name: ";
        cin >> fName;
        cout << "Last Name: ";
        cin >> lName;
        cout << "ID: ";
        cin >> id;
        next= 0;
    }
    void print()
    {
        cout << "\n\nI will now display the information.\nFirst Name: " << fName << " \nLast Name: " << lName <<" \nID: " << id<< endl<< endl;
    }
};

int main()
{
//    cout << "Create the first and print" << endl;
//    Student aStudent;
//    aStudent.print();
//
//    cout << "Create the pointer and print the first student" << endl;
//    Student * ptrStudent = &aStudent;
//    ptrStudent->print();

    cout << "Point the pointer to a new student and print" << endl;
    Student * head;
    head = new Student;
    head->print();


    cout<< "Create a new student and add him next in line\n";
    Student *two;
    two= new Student;
    two-> next= two;

    if (two->next== two)
    {
        cout<< "Success\n";
    }

    two-> print();

    return 0;
}
