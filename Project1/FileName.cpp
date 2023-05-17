#include <iostream>
#include <string>

using namespace std;

int dscount(string str, char s1, char s2) {
    int count = 0;
    bool foundS1 = false;

    for (int i = 0; i < str.length() - 1; i++) {
        char currentChar = tolower(str[i]); // drop all registers from upper to lower
        char nextChar = tolower(str[i + 1]);

        if (currentChar == s1) {
            if (nextChar == s2 && !foundS1) { // add +1 to the score if you find a match in the string s1s2
                count++;
                foundS1 = true;
            }
        }
        else {
            foundS1 = false;
        }
    }

    return count;
}

int main() {
    // Tests
    string input = "ab___ab__";
    char s1 = 'a';
    char s2 = 'b';

    // Answer: 4
    cout << dscount(input, s1, s2) << std::endl;

    input = "___cd____";
    s1 = 'c';
    s2 = 'd';

    // Answer: 3
    cout << dscount(input, s1, s2) << std::endl;

    input = "de_______";
    s1 = 'd';
    s2 = 'e';

    // Answer: 2
    cout << dscount(input, s1, s2) << std::endl;

    input = "_ba______";
    s1 = 'a';
    s2 = 'd';

    // Answer: 0
    std::cout << dscount(input, s1, s2) << std::endl;

    input = "aAa";
    s1 = 'a';
    s2 = 'a';

    // Answer: 2
    std::cout << dscount(input, s1, s2) << std::endl;

    input = "-ab-àb-ab";
    s1 = 'a';
    s2 = 'b';

    // Answer: 2
    std::cout << dscount(input, s1, s2) << std::endl;

    input = "12_12__12";
    s1 = '1';
    s2 = '2';

    // Answer: 3
    std::cout << dscount(input, s1, s2) << std::endl;

    input = "_a__b____";
    s1 = 'a';
    s2 = 'b';

    // Answer: 0
    std::cout << dscount(input, s1, s2) << std::endl;

    return 0;
}
