#pragma once
#include <iostream>
#include "clsPerson.h"
using namespace std;

class clsEmployee : public clsPerson
{
private:
    float _salary;
    string _department;
    string _title;

public:
    clsEmployee(string firstName, string lastName, string email, string phone, string title, string department, float salary) : clsPerson(firstName, lastName, email, phone)
    {
        _title = title;
        _department = department;
        _salary = salary;
    }
    void setDepartment(string department)
    {
        _department = department;
    }
    string department()
    {
        return _department;
    }
    void setTitle(string title)
    {
        _title = title;
    }
    string title()
    {
        return _title;
    }
    float salary()
    {
        return _salary;
    }
    void setSalary(float salary)
    {
        _salary = salary;
    }
    void print()
    {
        // clsPerson::print();

        cout << "Info:\n";
        cout << "\n__________________________________\n";
        cout << "First Name: " << firstName() << endl;
        cout << "Last Name : " << lastName() << endl;
        cout << "Full Name : " << fullName() << endl;
        cout << "Email     : " << email() << endl;
        cout << "Phone     : " << phone() << endl;
        cout << "Title     : " << _title << endl;
        cout << "Department: " << _department << endl;
        cout << "Salary    : " << _salary << endl;
        cout << "__________________________________\n";
    }
};
