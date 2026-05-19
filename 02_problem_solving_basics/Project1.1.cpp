#include <iostream>
#include <cstdlib>
using namespace std;

//========================= STONE & PAPER & SCISSOR ==============================
enum enChoices
{
    Stone = 1,
    Paper,
    Scissors
};
int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
short howManyRounds()
{
    short rounds;
    cout << "How many rounds 1 to 10? ";
    cin >> rounds;

    return rounds;
}
enChoices getPlayerChoice()
{
    short choice;

    cin >> choice;

    return (enChoices)choice;
}
enChoices getComputerChoice()
{
    return (enChoices)randomNumber(1, 3);
}
void roundWinner(enChoices playerChoice, enChoices ComputerChoice, short &playerPoints, short &computerPoints, short &drawTimes)
{

    cout << "Round Winner: ";
    if (playerChoice == ComputerChoice)
    {
        cout << "\033[43m\033[30m";
        cout << "No Winner!";
        drawTimes++;
    }
    else if (playerChoice == enChoices::Stone && ComputerChoice == enChoices::Scissors ||
             playerChoice == enChoices::Paper && ComputerChoice == enChoices::Stone ||
             playerChoice == enChoices::Scissors && ComputerChoice == enChoices::Paper)
    {
        cout << "\033[42m\033[97m";
        playerPoints++;
        cout << "Player1";
    }
    else
    {
        cout << "\033[41m\033[97m";
        computerPoints++;
        cout << "Computer";
    }
    cout << "\033[0m";
}
void gameResults(short playerPoints, short computerPoints, short rounds, short drawTimes)
{
    cout << "                +++Game Over+++                 \n"
         << "________________________________________________\n"
         << "__________________[Game Results]________________\n"
         << "Game Rounds: " << rounds << endl
         << "player1 Won Times: " << playerPoints << endl
         << "Computer Won Times: " << computerPoints << endl
         << "Draw Times: " << drawTimes << endl
         << "Final Winner: ";
    if (playerPoints > computerPoints)
    {
        cout << "Player1 is the WINNER!\n";
    }
    else if (computerPoints > playerPoints)
    {
        cout << "Computer is the WINNER!\n";
    }
    else
    {
        cout << "No Winner!\n";
    }
    cout << "________________________________________________\n";
}
void roundStructure()
{
    short rounds = howManyRounds();
    short playerPoints = 0, computerPoints = 0, drawTimes = 0;

    for (int i = 1; i <= rounds; i++)
    {
        cout << "Round [" << i << "] begins: \n";

        cout << "Your choice: [1]Stone, [2]Paper, [3]Scissors: ";
        enChoices playerChoice = getPlayerChoice();
        enChoices ComputerChoice = getComputerChoice();

        cout << "____________________Round[" << i << "]____________________\n\n";

        cout << "Player1 Choice: ";
        switch (playerChoice)
        {
        case enChoices::Paper:
            cout << "Paper\n";
            break;
        case enChoices::Scissors:
            cout << "Scissors\n";
            break;
        case enChoices::Stone:
            cout << "Stone\n";
            break;
        default:
            cout << "Wrong Choice!\n";
        }

        cout << "Computer Choice: ";
        switch (ComputerChoice)
        {
        case enChoices::Paper:
            cout << "Paper\n";
            break;
        case enChoices::Scissors:
            cout << "Scissors\n";
            break;
        case enChoices::Stone:
            cout << "Stone\n";
            break;
        default:
            cout << "Wrong Choice!\n";
        }
        roundWinner(playerChoice, ComputerChoice, playerPoints, computerPoints, drawTimes);
        cout << "\n________________________________________________\n";
    }
    gameResults(playerPoints, computerPoints, rounds, drawTimes);
}
void playAgain()
{
    bool choice = true;

    while (choice)
    {
        cout << "Do you want to play again? [1]YES, [0]NO ";
        cin >> choice;

        if (choice)
        {
            system("clear");
            roundStructure();
        }
        else
        {
            system("clear");
        }
    }
}

int main()
{
    srand(time(unsigned(NULL)));

    roundStructure();
    playAgain();

    return 0;
}