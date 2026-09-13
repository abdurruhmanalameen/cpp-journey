#include <iostream>
#include "clsPerson.h"
#include "clsEmployee.h"
using namespace std;

// abstract class / interface / contract
class clsPeople
{
public:
    virtual void speak(string language) = 0;
};

class clsDeveloper : public clsEmployee
{
private:
    string _mainProgrammingLanguage;

public:
    clsDeveloper(int ID, string firstName, string lastName, string email, string phone, string title, string department, float salary, string mainProgrammingLanguage) : clsEmployee(ID, firstName, lastName, email, phone, title, department, salary)
    {
        _mainProgrammingLanguage = mainProgrammingLanguage;
    }
    string mainProgrammingLanguage()
    {
        return _mainProgrammingLanguage;
    }
    void setMainProgrammingLanguage(string mainProgrammingLanguage)
    {
        _mainProgrammingLanguage = mainProgrammingLanguage;
    }
    void print()
    {
        cout << "Info:\n";
        cout << "\n__________________________________\n";
        cout << "ID        : " << ID() << endl;
        cout << "First Name: " << firstName() << endl;
        cout << "Last Name : " << lastName() << endl;
        cout << "Full Name : " << fullName() << endl;
        cout << "Email     : " << email() << endl;
        cout << "Phone     : " << phone() << endl;
        cout << "Title     : " << title() << endl;
        cout << "Department: " << department() << endl;
        cout << "Salary    : " << salary() << endl;
        cout << "PLanguage : " << _mainProgrammingLanguage << endl;
        cout << "__________________________________\n";
    }

    void goodMan(clsPerson Friend)
    {
        Friend._firstName;
        // can access private or protected info
    }
};

string friendFunc(clsPerson person1)
{
    return person1._firstName + person1._lastName;
}
int main()
{
    // clsPerson person1("A100", "Abdurruhman", "Alameen", "abdurruhmanalameen@gmail.com", "0795512753");
    // person1.print();

    // person1.sendEmail("Assignment 1", "I tried to solve it but it was so hard I'm sorry!");
    // person1.sendSMS("Hi, how are you doing?");

    clsEmployee employee1(200, "Ahmed", "Khalid", "hammod@gmail.com", "0912234344", "CEO", "Cambridge", 2100);
    // employee1.print();

    clsDeveloper developer1(300, "Fatima", "Devid", "fatima123@gmail.com", "0933332323", "Employee", "Frontend", 10000, "C++");
    // developer1.print();

    clsPerson *person1 = &employee1;

    person1->print();

    return 0;
}