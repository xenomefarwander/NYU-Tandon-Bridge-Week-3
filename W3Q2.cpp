#include <iostream>
#include <string>

using namespace std;

int main() {

    string userName;
    int gradYear, currentYear;
    int yearsRemaining;

    cout << "Please enter your name: ";
    cin >> userName;
    cout << "Please enter your graduation year: ";
    cin >> gradYear;
    cout << "Please enter current year: ";
    cin >> currentYear;

    yearsRemaining = gradYear - currentYear;

    if (yearsRemaining < 1)
        cout << userName << ", your status is Graduated" << endl;
    else if (yearsRemaining == 1)
        cout << userName << ", you are a Senior" << endl;
    else if (yearsRemaining == 2)
        cout << userName << ", you are a Junior" << endl;
    else if (yearsRemaining == 3)
        cout << userName << ", you are a Sophomore" << endl;
    else if (yearsRemaining == 4)
        cout << userName << ", you are a Freshman" << endl;
    else
        cout << userName << ", you are not in college yet" << endl;

    return 0;
}
