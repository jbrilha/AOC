#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
    string line;
    ifstream input(argv[1]);

    unordered_map<string, char> numbers {
        {"one", '1'},   {"two", '2'},   {"three", '3'},
        {"four", '4'},  {"five", '5'},  {"six", '6'},
        {"seven", '7'}, {"eight", '8'}, {"nine", '9'},
    };

    if (!input.is_open())
        cout << "FAILED" << endl;

    int calibration = 0;
    while (getline(input, line)) {
        int first_digit, last_digit;

        uintmax_t first_digit_pos = string::npos; // using unsigned so I can just compare using <
        uint32_t last_digit_pos = 0;

        for (const auto &number : numbers) {
            size_t found_first_number = line.find(number.first); // uintmax_t same as size_t which is unsigned long
            size_t found_first_digit = line.find(number.second);
            size_t found_last_number = line.rfind(number.first);
            size_t found_last_digit = line.rfind(number.second);

            if (found_first_number < first_digit_pos) {
                first_digit_pos = found_first_number;
                first_digit = numbers[number.first] - 0x30;
            }
            if (found_first_digit < first_digit_pos) {
                first_digit_pos = found_first_digit;
                first_digit = number.second - 0x30;
            }
            
            if (found_last_digit != string::npos) 
                if (found_last_digit >= last_digit_pos) {
                    last_digit_pos = found_last_digit;
                    last_digit = number.second - 0x30;
                }
            if (found_last_number != string::npos) 
                if (found_last_number >= last_digit_pos) {
                    last_digit_pos = found_last_number;
                    last_digit = numbers[number.first] - 0x30;
                }
        }
        calibration += first_digit * 10 + last_digit;
    }
    cout << calibration << endl;

    input.close();

    return 0;
}
