#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameLevel
{
    Easy = 1,
    Medium = 2,
    Hard = 3,
    Mixed = 4
};
enum enOperators
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    Mix = 5
};
enum enResults
{
    Pass = 1,
    Fail = 2
};

struct stGameInfo
{
    short numberOfQuestions = 0;
    short rightAnswers = 0;
    short wrongAnswers = 0;
    enResults finalResult;
    enOperators opType;
};

short randomNumber(short from, short to)
{
    short randomNumber = rand() % (to - from + 1) + from;

    return randomNumber;
}
void resetScreen()
{
    system("clear");
    cout << "\033[0m";
};
void setWinnerScreenColor(enResults result)
{
    if (result == enResults::Pass)
    {
        cout << "\033[42m\033[97m";
    }
    else
    {
        cout << "\033[41m\033[97m";
        cout << "\a";
    }
};
string separators(short howManyLine)
{
    string l = "";

    for (short lines = 1; lines <= howManyLine; lines++)
    {
        l += "_";
    }

    return l;
}

short readHowManyQuestions()
{
    short numOfQuestions = 0;

    do
    {
        cout << "How many question do you want? ";
        cin >> numOfQuestions;
    } while (numOfQuestions <= 0);

    return numOfQuestions;
}
enGameLevel readGameLevel()
{
    short gameLevel;

    do
    {
        cout << "Choose the level [1]Easy [2]Medium [3]Hard [4]Mix:  ";
        cin >> gameLevel;

    } while (gameLevel < 1 || gameLevel > 4);

    return (enGameLevel)gameLevel;
}
enOperators readOperationType()
{
    short operatorType;

    do
    {
        cout << "Enter operation type [1]Add [2]Sub [3]Mul [4]Div [5]Mix? ";
        cin >> operatorType;
    } while (operatorType < 1 || operatorType > 5);

    return (enOperators)operatorType;
}

short getTheElement(enGameLevel gameLevel)
{
    if (gameLevel == enGameLevel::Mixed)
    {
        gameLevel = (enGameLevel)randomNumber(1, 3);
    }

    switch (gameLevel)
    {
    case enGameLevel::Easy:
        return randomNumber(1, 9);
    case enGameLevel::Medium:
        return randomNumber(10, 19);
    default:
        return randomNumber(19, 99);
    }
}
string getGameLevelName(enGameLevel gameLevel)
{
    string arrGameLevel[4] = {"Easy", "Medium", "Hard", "Mix"};

    return arrGameLevel[gameLevel - 1];
}
string getOperatorName(enOperators TheOperator)
{
    string arrOperators[4] = {"+", "-", "*", "/"};

    return arrOperators[TheOperator - 1];
}

string resultName(enResults result)
{
    string arrResults[2] = {"Pass :-)", "Fail :-("};

    return arrResults[result - 1];
}

short rightAnswer(short firstElement, short secondElement, enOperators operatorType)
{
    switch (operatorType)
    {
    case enOperators::Add:
        return firstElement + secondElement;
    case enOperators::Sub:
        return firstElement - secondElement;
    case enOperators::Mul:
        return firstElement * secondElement;
    default:
        return firstElement / secondElement;
    }
}
bool checkFinalResult(short rightAnswers, short wrongAnswers)
{
    return rightAnswers >= wrongAnswers;
}
stGameInfo fillGameResult(short numberOfQuestions, short rightAnswers, short wrongAnswers, enOperators opType)
{
    stGameInfo gameInfo;
    gameInfo.numberOfQuestions = numberOfQuestions;
    gameInfo.rightAnswers = rightAnswers;
    gameInfo.wrongAnswers = wrongAnswers;
    gameInfo.opType = opType;
    if (checkFinalResult(rightAnswers, wrongAnswers))
    {
        gameInfo.finalResult = enResults::Pass;
    }
    else
    {
        gameInfo.finalResult = enResults::Fail;
    }

    return gameInfo;
}
stGameInfo playGame()
{
    stGameInfo gameInfo;
    short numberOfQuestions = readHowManyQuestions();
    enGameLevel gameLevel = readGameLevel();
    enOperators operatorType = readOperationType();
    short answer = 0;
    short rightAnswers = 0;
    short wrongAnswers = 0;

    for (short Q = 1; Q <= numberOfQuestions; Q++)
    {
        cout << "\033[0m";

        short firstElement = getTheElement(gameLevel);
        short secondElement = getTheElement(gameLevel);
        enOperators currentOpType = operatorType;
        if (operatorType == enOperators::Mix)
        {
            currentOpType = (enOperators)randomNumber(1, 4);
        }
        short theRightAnswer = rightAnswer(firstElement, secondElement, currentOpType);

        cout << "\nQuestion [" << Q << "/" << numberOfQuestions << "]";
        cout << "\n\n";
        cout << firstElement << endl;
        cout << secondElement << "\t" << getOperatorName(currentOpType) << endl;
        cout << "_________________\n";
        cin >> answer;
        if (theRightAnswer == answer)
        {
            setWinnerScreenColor(enResults::Pass);
            cout << "Right Answer :-)";
            rightAnswers++;
        }
        else
        {
            setWinnerScreenColor(enResults::Fail);
            cout << "Wrong Answer! :-(" << endl;
            cout << "\a";
            cout << "The Right Answer is: " << theRightAnswer;
            wrongAnswers++;
        }
    }

    return fillGameResult(numberOfQuestions, rightAnswers, wrongAnswers, operatorType);
}

void showFinalGameResults(stGameInfo gameInfo)
{
    setWinnerScreenColor(gameInfo.finalResult);
    cout << "\n"
         << separators(33) << "\n";
    cout << "Final Result Is    : " << resultName(gameInfo.finalResult) << endl;
    cout << separators(33) << "\n";
    cout << "Number Of Questions: " << gameInfo.numberOfQuestions << endl;
    cout << "Op Type            : ";
    if (gameInfo.opType == enOperators::Mix)
    {
        cout << "Mix" << endl;
    }
    else
    {
        cout << getOperatorName(gameInfo.opType) << endl;
    }
    cout << "Number Of Right Answers: " << gameInfo.rightAnswers << endl;
    cout << "Number Of Wrong Answers: " << gameInfo.wrongAnswers << endl;
    cout << separators(33) << "\n";
}

void startGame()
{
    char playAgain = 'Y';
    do
    {
        resetScreen();
        stGameInfo play = playGame();
        showFinalGameResults(play);
        cout << "\033[0m";
        cout << "\nDo You Want To Play Again? Y/N ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
}

int main()
{
    srand(time(unsigned(NULL)));

    startGame();
    return 0;
}