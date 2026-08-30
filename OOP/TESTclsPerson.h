#pragma once
#include <iostream>
using namespace std;

class TESTclsPerson
{
private:
    int _ID;
    string _firstName;
    string _lastName;
    string _email;
    string _phone;

public:
    TESTclsPerson(int ID, string firstName, string lastName, string email, string phone)
    {
        _ID = ID;
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }
    int ID()
    {
        return _ID;
    }
    string firstName()
    {
        return _firstName;
    }
    string lastName()
    {
        return _lastName;
    }
    string fullName()
    {
        return _firstName + " " + _lastName;
    }

    string email()
    {
        return _email;
    }
    string phone()
    {
        return _phone;
    }

    virtual void print()
    {
        cout << "Info:\n";
        cout << "\n__________________________________\n";
        cout << "ID        : " << _ID << endl;
        cout << "First Name: " << _firstName << endl;
        cout << "Last Name : " << _lastName << endl;
        cout << "Full Name : " << fullName() << endl;
        cout << "Email     : " << _email << endl;
        cout << "Phone     : " << _phone << endl;
        cout << "__________________________________\n";
    }
    void setFirstName(string firstName)
    {
        _firstName = firstName;
    }
    void setLastName(string lastName)
    {
        _lastName = lastName;
    }

    void setEmail(string email)
    {
        _email = email;
    }
    void setPhone(string phone)
    {
        _phone = phone;
    }

    void sendEmail(string subject, string body)
    {
        cout << "The following message sent successfully to email: " << _email << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl
             << endl;
    }
    void sendSMS(string SMS)
    {
        cout << "The following SMS sent successfully to phone: " << _phone << endl;
        cout << SMS << endl;
    }

    friend class clsDeveloper;
    friend string friendFunc(TESTclsPerson person1);
};