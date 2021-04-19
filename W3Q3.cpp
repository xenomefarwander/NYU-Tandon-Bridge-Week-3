/* This program calculates solutions for quadratic equations ax^2 + bx + c = 0. It determines the number of
 * solutions and assigns a code based on the type and number of solutions. The code assignment drives the switch
 * operator, which applies the appropriate calculations and output.
*/

#include <iostream>
#include <cmath>
using namespace std;

const int INFINITE_SOLUTIONS = 0;
const int ZERO_SOLUTIONS = 1;
const int LINEAR_EQUATION = 2;
const int TWO_REAL_SOLUTIONS = 3;
const int ONE_SOLUTION = 4;
const int NO_REAL_SOLUTIONS = 5;

int main() {

    double a, b, c;
    char outputCode;
    double discriminantVal;
    double firstSolution;
    double secondSolution;

    // Assign values to variables
    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    // Evaluate inputs for three cases where a = 0 first
    if (a == 0 && b == 0 && c == 0)
        outputCode = INFINITE_SOLUTIONS;
    else if (a == 0 && b == 0 && c != 0)
        outputCode = ZERO_SOLUTIONS;
    else if (a == 0 && b != 0)
        outputCode = LINEAR_EQUATION; 
    else {
        //Calculate number of solutions using discriminant (b^2 - 4ac) of quadratic formula
        discriminantVal = (b * b) - (4 * a * c);
        if (discriminantVal > 0)
            outputCode = TWO_REAL_SOLUTIONS;
        else if (discriminantVal < 0)
            outputCode = NO_REAL_SOLUTIONS;
        else
            outputCode = ONE_SOLUTION; // i.e. discriminant = 0
    }

    switch (outputCode){
        case INFINITE_SOLUTIONS:
            // case 0 = 0
            cout << "This equation has an infinite number of solutions" << endl;
            break;
        case ZERO_SOLUTIONS:
            // case of "any non-zero number = 0"
            cout << "This equation has no solution" << endl;
            break;
        case LINEAR_EQUATION:
            // case for equation of form bx + c (i.e. b = line slope, - c / b = y-intercept)
            cout << "This equation is linear and has one real solution x=" << -c / b << endl;
            break;
        case TWO_REAL_SOLUTIONS:
            // case for discriminantVal > 0
            firstSolution = (-b + sqrt(discriminantVal)) / (2 * a); // quadratic formula
            secondSolution = (-b - sqrt(discriminantVal)) / (2 * a);
            cout << "This equation has two solutions x=" << firstSolution << " and x="
                 << secondSolution << endl;
            break;
        case ONE_SOLUTION:
            // case for discriminantVal = 0
            firstSolution = (-b + 0) / (2 * a); // + 0 added to avoid output x = -0
            cout << "This equation has one repeated real number solution x="
                 << firstSolution << endl;
            break;
        case NO_REAL_SOLUTIONS:
            // case for discriminantVal < 0
            cout << "This equation has no real solutions" << endl;
            break;
        default:
            cout << "Error: Invalid input" << endl;
            break;
    }

    return 0;
}
