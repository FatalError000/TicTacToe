#include <iostream>
#include <string>
using namespace std;

string WinTest(char playground[3][3], string numberOfCrossesZeros)
{
    string result = "";
    int crossWin = 0, zeroWin = 0, crossCounter = 0, zeroCounter = 0, rightToLeftJ = 3;

    // vertical win test
    for (int i = 0; i < 3; i++)
    {
        crossCounter = 0;
        zeroCounter = 0;

        for (int j = 0; j < 3; j++)
        {
            if (playground[i][j] == 'X')
            {
                crossCounter++;
            }
            else if (playground[i][j] == 'O')
            {
                zeroCounter++;
            }
        }

        if (crossCounter == 3)
        {
            crossWin++;
        }
        else if (zeroCounter == 3)
        {
            zeroWin++;
        }
    }

    // horizontal win test
    for (int i = 0; i < 3; i++)
    {
        crossCounter = 0;
        zeroCounter = 0;

        for (int j = 0; j < 3; j++)
        {
            if (playground[j][i] == 'X')
            {
                crossCounter++;
            }
            else if (playground[j][i] == 'O')
            {
                zeroCounter++;
            }
        }

        if (crossCounter == 3)
        {
            crossWin++;
        }
        else if (zeroCounter == 3)
        {
            zeroWin++;
        }
    }

    crossCounter = 0;
    zeroCounter = 0;

    // diagonal left to right win test
    for (int i = 0; i < 3; i++)
    {
        if (playground[i][i] == 'X')
        {
            crossCounter++;
        }
        else if (playground[i][i] == 'O')
        {
            zeroCounter++;
        }

        if (crossCounter == 3)
        {
            crossWin++;
        }
        else if (zeroCounter == 3)
        {
            zeroWin++;
        }
    }

    crossCounter = 0;
    zeroCounter = 0;

    // diagonal right to left win test
    for (int i = 0; i < 3; i++)
    {
        rightToLeftJ--;

        if (playground[rightToLeftJ][i] == 'X')
        {
            crossCounter++;
        }
        else if (playground[rightToLeftJ][i] == 'O')
        {
            zeroCounter++;
        }

        if (crossCounter == 3)
        {
            crossWin++;
        }
        else if (zeroCounter == 3)
        {
            zeroWin++;
        }
    }

    if ((crossWin > 0) && (zeroWin > 0))
    {
        return result = "Incorrect! Crosses and zero can't be winners at one time.";
    }
    else if ((crossWin > 1) && (zeroWin == 0))
    {
        return result = "Incorrect! More then one crosses win.";
    }
    else if ((zeroWin > 1) && (crossWin == 0))
    {
        return result = "Incorrect! More then one zeros win.";
    }
    else if ((crossWin > 0) && (numberOfCrossesZeros[1] >= numberOfCrossesZeros[0]))
    {
        return result = "Incorrect! Crosses win, but number of zeros more or equal then number of crosses!";
    }
    else if ((zeroWin > 0) && (numberOfCrossesZeros[0] > numberOfCrossesZeros[1]))
    {
        return result = "Incorrect! Zeros win, but number of crosses more then number of zeros!";
    }
    else if ((crossWin == 1) && (zeroWin == 0))
    {
        return result = "Crosses win.";
    }
    else if ((zeroWin == 1) && (crossWin == 0))
    {
        return result = "Zeros win.";
    }
    else if ((zeroWin == 0) && (crossWin == 0))
    {
        return result = "Nobody wins.";
    }
}

string PlaygroundVerification(char playground[3][3]) // char playground[3][3]
{
    string result = "";
    int zerosCounter = 0, crossesCounter = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((playground[i][j] != 'X') && (playground[i][j] != 'O') && (playground[i][j] != '#'))
            {
                return result = "Incorrect symbol detected!";
            }
            else if (playground[i][j] == 'X')
            {
                crossesCounter++;
            }
            else if (playground[i][j] == 'O')
            {
                zerosCounter++;
            }
        }
    }

    if (zerosCounter > crossesCounter)
    {
        return result = "Incorrect! Number of zeros more then number of crosses!";
    }

    return result = to_string(crossesCounter) + to_string(zerosCounter);
}

void InputInPlayground(string firstLine, string secondLine, string thirdLine, char playground[][3])
{
    for (int i = 0; i < 3; i++)
    {
        playground[0][i] = firstLine[i];
        playground[1][i] = secondLine[i];
        playground[2][i] = thirdLine[i];
    }
}

void mainTest(string firstLine, string secondLine, string thirdLine, string answer)
{
    char playground[3][3];
    string playgroundVerificationResult;

    cout << firstLine << endl << secondLine << endl << thirdLine << endl << answer << endl;

    InputInPlayground(firstLine, secondLine, thirdLine, playground);

    playgroundVerificationResult = PlaygroundVerification(playground);

    if (playgroundVerificationResult[0] == 'I')
    {
        cout << playgroundVerificationResult;
    }
    else
    {
        cout << WinTest(playground, playgroundVerificationResult);
    }
    cout << endl << endl;
}

void Tests()
{
    char playground[3][3];
    string playgroundVerificationResult;

    cout << "Examples : " << endl;

    //-----------------------------------------1----------------------------------------
    mainTest("X##", "OXO", "OOO", "Answer: Incorrect.");
    //--------------------------------------------2--------------------------------------------
    mainTest("X##", "#X#", "OO#", "Answer: Nobody.");
    //--------------------------------------------3--------------------------------------------
    mainTest("XXO", "OOX", "XOX", "Answer: Nobody.");
    //----------------------------------------------4------------------------------------------
    mainTest("XO#", "XO#", "X#O", "Answer: Incorrect.");
    //----------------------------------------------5------------------------------------------
    mainTest("OX#", "XOX", "X#O", "Answer: Incorrect.");
    //----------------------------------------------6------------------------------------------
    mainTest("##X", "OX#", "X#O", "Answer: Petya won.");
    //----------------------------------------------END ------------------------------------------
}

int main()
{
    char playground[3][3];
    string firstLine, secondLine, thirdLine, playgroundVerificationResult;

    Tests();

    cout << endl << "Acceptable symbols : X - for cross, O (not number) for zero, # for empty." << endl;

    do {
        cout << "Enter first line, then second line, then third line. Length of line must be 3 symbols. Neither more, nor less." << endl;
        cin >> firstLine >> secondLine >> thirdLine;
    } while ((firstLine.length() != 3) || (secondLine.length() != 3) || (thirdLine.length() != 3));

    InputInPlayground(firstLine, secondLine, thirdLine, playground);

    playgroundVerificationResult = PlaygroundVerification(playground);

    if (playgroundVerificationResult[0] == 'I')
    {
        cout << playgroundVerificationResult;
        return 0;
    }
    else
    {
        cout << WinTest(playground, playgroundVerificationResult);
        return 0;
    }

}
