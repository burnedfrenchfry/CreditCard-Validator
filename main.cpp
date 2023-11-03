#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool is_valid(const string& card_number) {
    int total = 0;
    bool is_second_digit = false;
    //Starting the Luhn Algorithm
    for (int i = card_number.length() - 1; i >= 0; --i) {
        int digit = card_number[i] - '0';
        if (is_second_digit){
            digit *= 2;
            if (digit > 9){
                digit -= 9;
            }
        }
        total += digit;
        is_second_digit = !is_second_digit;
    }
    return total % 10 == 0;
}

string security_cc(const string& card_number) {
    string censored_number = card_number;

    //Keep Last 4 Digits
    for (size_t i = 0; i < censored_number.length() - 4; ++i) {
        if (isdigit(censored_number[i])) {
            censored_number[i] = '*';
        }
    }
    return censored_number;
}

int main(){
    string user_input;
    cout << "Enter your credit card number: ";
    cin >> user_input;

    string censored_input = security_cc(user_input);
    cout << "Censored: " << censored_input << endl;

    if (is_valid(user_input)) {
        cout << "This Card Number Is Valid!" << endl;
    } else {
        cout << "Invalid!!" << endl;
    }
    return 0;
}