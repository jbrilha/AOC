#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string line;
    ifstream input(argv[1]);

    if (!input.is_open())
        printf("FAILED\n");
    
    int calibration = 0;
    while (getline(input, line)) {
        int first_digit = -1;
        int last_digit = -1;

        for(int i = 0; i < line.length(); i++){
            if(isdigit(line[i]) && first_digit == -1)
                first_digit = line[i] - 0x30;

            if(isdigit(line[line.length() - 1 - i]) && last_digit == -1)
                last_digit = line[line.length() - 1 - i] - 0x30;
        }
        calibration += first_digit * 10 + last_digit;
    }
    printf("%d\n", calibration);

    input.close();

    return 0;
}
