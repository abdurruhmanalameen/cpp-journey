#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
private:
    string _firstName;
    string _lastName;
    string _email;
    string _phone;

public:
    clsPerson(string firstName, string lastName, string email, string phone)
    {
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
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
};