//Converting Roman Numerals to Decimal
#include <iostream>
using namespace std;

// this function returns value of a Roman symbol
int value(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}

// returns decimal value of roman numeral
int romanToDecimal(string& s) {
    int res = 0; 

    for (int i = 0; i < s.length(); i++) {
        
        // get value of current symbol
        int s1 = value(s[i]);

        // Compare with the next symbol if it exists
        if (i + 1 < s.length()) {
            int s2 = value(s[i + 1]);

            // if current value is greater or equal, 
            // add it to result
            if (s1 >= s2) {
                res += s1;
            }
            else {
                // else, add the difference and skip 
                // next symbol
                res += (s2 - s1);
                i++;
            }
        }
        else {
            res += s1;
        }
    }

    return res;
}

int main() {
    string s = "IX";
    cout << romanToDecimal(s) << endl;
    return 0;
}