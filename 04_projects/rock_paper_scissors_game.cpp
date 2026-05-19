#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice
{
    Stone = 1,
    Paper = 2,
    Scissors = 3
};
enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};

struct stRoundInfo
{
    short roundNumber = 0;
    enGameChoice playerChoice;
    enGameChoice computerChoice;
    enWinner roundWinner;
    string winnerName;
};
struct stGameResults
{
    short gameRounds = 0;
    short playerWonTimes = 0;
    short computerWonTimes = 0;
    short drawTimes = 0;
    enWinner gameWinner;
    string winnerName;
};

string tabs(short numberOfTabs)
{
    string t = "";
    for (int tabs = 1; tabs <= numberOfTabs; tabs++)
    {
        t += "\t";
    }

    return t;
};
int randomNumber(int from, int to)
{
    int randomNumber = rand() % (to - from + 1) + from;

    return randomNumber;
};
void resetScreen()
{
    system("clear");
    cout << "\033[0m";
};
void setWinnerScreenColor(enWinner winner)
{
    if (winner == enWinner::Draw)
    {
        cout << "\033[43m\033[30m";
    }
    else if (winner == enWinner::Player1)
    {
        cout << "\033[42m\033[97m";
    }
    else
    {
        cout << "\033[41m\033[97m";
    }
};

enGameChoice getComputerChoice()
{
    return (enGameChoice)randomNumber(1, 3);
};

enWinner whoWonTheRound(stRoundInfo roundInfo)
{
    if (roundInfo.computerChoice == roundInfo.playerChoice)
    {
        return enWinner::Draw;
    }
    switch (roundInfo.playerChoice)
    {
    case enGameChoice::Stone:
        if (roundInfo.computerChoice == enGameChoice::Paper)
            return enWinner::Computer;
        break;
    case enGameChoice::Paper:
        if (roundInfo.computerChoice == enGameChoice::Scissors)
            return enWinner::Computer;
        break;
    case enGameChoice::Scissors:
        if (roundInfo.computerChoice == enGameChoice::Stone)
            return enWinner::Computer;
        break;
    }
    return enWinner::Player1;
};
enWinner whoWonTheGame(short player1WinTimes, short computerWinTimes)
{
    if (player1WinTimes == computerWinTimes)
        return enWinner::Draw;
    else if (player1WinTimes > computerWinTimes)
        return enWinner::Player1;
    else
        return enWinner::Computer;
};

string choiceName(enGameChoice choice)
{
    string arrGameChoices[3] = {"Stone", "Paper", "Scissors"};

    return arrGameChoices[choice - 1];
};
string winnerName(enWinner winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "No winner [Draw]"};

    return arrWinnerName[winner - 1];
};

short readHowManyRounds()
{
    short gameRounds = 1;

    do
    {
        cout << "How many rounds 1 to 10? ";
        cin >> gameRounds;
    } while (gameRounds < 1 || gameRounds > 10);

    return gameRounds;
};
enGameChoice readPlayer1Choice()
{
    short choice;

    do
    {
        cout << "Your choice: [1]Stone, [2]Paper, [3]Scissors: ";
        cin >> choice;
    } while (choice < 0 || choice > 3);

    return (enGameChoice)choice;
};
void printRoundResults(stRoundInfo roundInfo)
{
    cout << "____________________Round[" << roundInfo.roundNumber << "]____________________\n\n";
    cout << "Player1 Choice: " << choiceName(roundInfo.playerChoice) << endl;
    cout << "Computer Choice: " << choiceName(roundInfo.computerChoice) << endl;
    cout << "Round Winner: [" << roundInfo.winnerName << "]\n";
    cout << "________________________________________________\n";
};

stGameResults fillGameResults(int gameRounds, short player1Wintimes, short computerWinTimes, short drawTimes)
{
    stGameResults gameResults;

    gameResults.gameRounds = gameRounds;
    gameResults.playerWonTimes = player1Wintimes;
    gameResults.computerWonTimes = computerWinTimes;
    gameResults.drawTimes = drawTimes;
    gameResults.gameWinner = whoWonTheGame(player1Wintimes, computerWinTimes);
    gameResults.winnerName = winnerName(gameResults.gameWinner);

    return gameResults;
};
stGameResults playGame(short howManyRounds)
{
    stRoundInfo roundInfo;
    short player1WinTimes = 0, computerWinTimes = 0, drawTimes = 0;

    for (int gameRound = 1; gameRound <= howManyRounds; gameRound++)
    {
        cout << "\nRound [" << gameRound << "] Begins:\n";
        roundInfo.roundNumber = gameRound;
        roundInfo.playerChoice = readPlayer1Choice();
        roundInfo.computerChoice = getComputerChoice();
        roundInfo.roundWinner = whoWonTheRound(roundInfo);
        roundInfo.winnerName = winnerName(roundInfo.roundWinner);

        if (roundInfo.roundWinner == enWinner::Player1)
        {
            player1WinTimes++;
        }
        else if (roundInfo.roundWinner == enWinner::Computer)
        {
            computerWinTimes++;
        }
        else
        {
            drawTimes++;
        }

        setWinnerScreenColor(roundInfo.roundWinner);

        printRoundResults(roundInfo);
        cout << "\033[0m";
    }

    return fillGameResults(howManyRounds, player1WinTimes, computerWinTimes, drawTimes);
};
void showGameOverScreen()
{
    cout << endl
         << endl
         << tabs(2) << "________________________________________________\n"
         << tabs(2) << "                +++Game Over+++                 \n"
         << tabs(2) << "________________________________________________\n";
};
void showFinalGameResults(stGameResults gameResults)
{
    setWinnerScreenColor(gameResults.gameWinner);
    cout << tabs(2) << "__________________[Game Results]________________\n"
         << tabs(2) << "Game Rounds: " << gameResults.gameRounds << endl
         << tabs(2) << "player1 Won Times: " << gameResults.playerWonTimes << endl
         << tabs(2) << "Computer Won Times: " << gameResults.computerWonTimes << endl
         << tabs(2) << "Draw Times: " << gameResults.drawTimes << endl
         << tabs(2) << "Final Winner: " << gameResults.winnerName << endl
         << "\033[0m";
};

void startGame()
{
    char playAgain = 'Y';
    do
    {
        resetScreen();
        stGameResults gameResults = playGame(readHowManyRounds());
        showGameOverScreen();
        showFinalGameResults(gameResults);

        cout << endl
             << tabs(2)
             << "________________________________________\n"
             << tabs(2)
             << "Do you want to play again? [Y]Yes, [N]No ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
};

int main()
{
    srand(time(unsigned(NULL)));
    startGame();

    return 0;
}