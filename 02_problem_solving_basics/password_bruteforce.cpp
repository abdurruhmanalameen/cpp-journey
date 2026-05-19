#include <iostream>
using namespace std;

string readText(string message)
{
    string text;

    cout << message << endl;
    getline(cin, text);

    return text;
}
bool guessPassword(string password)
{
    int trial = 0;

    for (int i = 65; i <= 90; i++)
    {

        for (int j = 65; j <= 90; j++)
        {

            for (int k = 65; k <= 90; k++)
            {
                trial++;
                string word = "";

                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << "Trial [" << trial << "]: " << word << endl;

                if (word == password)
                {
                    cout << "Password is: " << word << " found after " << trial << " trials" << endl;
                    //k = 100, j = 100, i = 100;
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    guessPassword(readText("Enter the password: "));
    return 0;
}