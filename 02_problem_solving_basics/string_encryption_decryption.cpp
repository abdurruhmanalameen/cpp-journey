#include <iostream>
#include <string>

using namespace std;

string readMessage()
{
    string message;

    cout << "Enter the message: ";
    getline(cin, message);

    return message;
}
string encryption(string message, short encryptionKey)
{
    for (int i = 0; i <= message.length(); i++)
    {
        message[i] = char(int(message[i]) + encryptionKey);
    }

    return message;
}
string decryption(string encryptedMessage, short encryptionKey)
{
    for (int i = 0; i <= encryptedMessage.length(); i++)
    {
        encryptedMessage[i] = char(int(encryptedMessage[i]) - encryptionKey);
    }

    return encryptedMessage;
}

int main()
{
    const short encryptionKey = 2;

    string message = readMessage();
    string afterEnc = encryption(message, encryptionKey);
    string afterDec = decryption(afterEnc, encryptionKey);

    cout << "Text before encryption: " << message << endl;
    cout << "Text after encryption: " << afterEnc << endl;
    cout << "Text after decryption: " << afterDec << endl;

    return 0;
}