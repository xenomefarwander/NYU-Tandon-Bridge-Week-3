#include <iostream>
#include <string>
using namespace std;

const double POUNDS_TO_KILOS = 0.453592;
const double INCHES_TO_METERS = 0.0254;

int main() {

    double userWeight, userHeight;
    double userBMI;
    string userStatus;

    cout << "Please enter weight (in pounds): ";
    cin >> userWeight;
    cout << "Please enter height (in inches): ";
    cin >> userHeight;

    // Convert height and weight to metric
    userWeight *= POUNDS_TO_KILOS;
    userHeight *= INCHES_TO_METERS;

    userBMI = (userWeight / (userHeight * userHeight));

    if (userBMI < 18.5)
        userStatus = "Underweight";
    else if (userBMI >= 18.5 && userBMI < 25)
        userStatus = "Normal";
    else if (userBMI >= 25 && userBMI < 30)
        userStatus = "Overweight";
    else
        userStatus = "Obese";

    cout << "The weight status is: " << userStatus;

    return 0;
}
