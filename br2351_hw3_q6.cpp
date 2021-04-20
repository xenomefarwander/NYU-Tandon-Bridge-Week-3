#include <iostream>
#include <string>
using namespace std;

const double STD_RATE = 0.40;
const double EVENING_RATE = 0.25;
const double WEEKEND_RATE = 0.15;

int main() {
    int startHours, startMinutes;
    char temp;
    string startDay;
    int callDuration;
    double amountBilled;

    cout << "Please enter call start time in 24-hr format (e.g. 14:30): ";
    cin >> startHours >> temp >> startMinutes;
    cout << "Please enter day of the week (first two letters only, e.g. Mo, Tu, We, Th, Fr, Sa, Su): ";
    cin >> startDay;
    cout << "Please enter call duration in minutes: ";
    cin >> callDuration;

    if (startHours >= 8 && startHours < 18 && startDay != "Sa" && startDay != "Su")
        amountBilled = callDuration * STD_RATE;
    else if ((startHours < 8 || startHours >= 18) && startDay != "Sa" && startDay != "Su")
        amountBilled = callDuration * EVENING_RATE;
    else
        amountBilled = callDuration * WEEKEND_RATE;

    cout << "Total amount billed to customer: $" << amountBilled << endl;


    return 0;
}