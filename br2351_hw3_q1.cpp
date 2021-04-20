#include <iostream>
using namespace std;

const float CLUB_DISCOUNT = 0.90;

int main() {
    float firstItem, secondItem;
    char hasCard;
    float taxRate;
    float totalPrice;

    cout << "Enter price of first item: ";
    cin >> firstItem;
    cout << "Enter price of second item: ";
    cin >> secondItem;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> hasCard;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;
    cout << "Base price: " << firstItem + secondItem << endl;

    // Applies 50% discount to lower priced item
    if (firstItem <= secondItem)
        firstItem *= 0.5;
    else
        secondItem *= 0.5;

    // Applies the 10% Club Member discount
    if (hasCard == 'Y' || hasCard == 'y')
        totalPrice = (firstItem + secondItem) * CLUB_DISCOUNT;
    else
        totalPrice = (firstItem + secondItem);

    // Prints pre-tax price with discounts
    cout << "Price after discounts: " << totalPrice << endl;

    // Prints total price after applying tax
    taxRate /= 100; // Moves tax rate decimal point two places to the left
    totalPrice *= (1 + taxRate);
    cout << "Total price: " << totalPrice;

    return 0;
}
