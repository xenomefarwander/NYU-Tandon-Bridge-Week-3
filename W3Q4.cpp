#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    double inputReal;
    int menuChoice;
    int inputInteger;
    bool isNegative;
    int outputVal;

    cout << "Please enter a Real number:" << endl;
    cin >> inputReal;
    cout << "Choose your rounding method:\n"
         << "1. Floor round\n"
         << "2. Ceiling round\n"
         << "3. Round to the nearest whole number" << endl;
    cin >> menuChoice;

    //Check for negative input
    if (inputReal < 0)
        isNegative = true;
    else
        isNegative = false;

    //Obtain integer value of user's input
    inputInteger = int(inputReal);

    //Round according to user's menu choice
    switch (menuChoice){
        case FLOOR_ROUND:
            // Either number is positive (prints int value as is), or number is negative and already rounded
            if (!isNegative || (isNegative && (inputReal - inputInteger == 0)))
                outputVal = inputInteger;
            // Else number is negative and not rounded
            else
                outputVal = inputInteger - 1;
            break;
        case CEILING_ROUND:
            // Either number is negative, or number is positive and already rounded
            if (isNegative || (!isNegative && (inputReal - inputInteger == 0)))
                outputVal = inputInteger;
            // Else number is positive and not rounded
            else
                outputVal = inputInteger + 1;
            break;
        case ROUND:
            // When number is positive and fractional part greater than or equal to 0.5, round up
            if (!isNegative && (inputReal - inputInteger >= 0.5))
                outputVal = inputInteger + 1;
            // When number is negative and fractional part is less than -0.5, then subtract 1 from int
            else if (isNegative && (inputReal - inputInteger <= -0.5))
                outputVal = inputInteger -1;
            /* When number is already rounded OR when number is negative and fractional part is greater
             * than to -0.5 (round up negative, i.e to right on number line) OR when number is positive and
             * fractional part is less than 0.5 (round down) */
            else
                outputVal = inputInteger;
            break;
        default:
            cout << "Invalid input" << endl;
            outputVal = 07734;
    }

    cout << outputVal << endl;

    return 0;
}
