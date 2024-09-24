#include <iostream>
#include <sstream>
#include <string>
#include "pipe.h"
using namespace std;

bool is_integer(string const& str) {
    istringstream iss(str);
    int num;
    iss >> num;
    return !iss.fail() && iss.eof();
}

int main() {
    string input;
    while(true) {
        cout << "1. Add a pipe\n2. Add CS\n3. View all objects\n4. Edit the pipe\n5. Edit the CS\n6. Save\n7. Upload\n0. Exit" << endl;
        cin >> input;
        if (is_integer(input)) {
            int choose;
            choose = stoi(input);
            switch (choose) {
                case 0: {
                    return 0;
                }
                case 1: {
                    cout << "Add a pipe" << endl;
                    break;
                }
                case 2: {
                    cout << "Add CS" << endl;
                    break;
                }
                case 3: {
                    cout << "View all objects" << endl;
                    break;
                }
                case 4: {
                    cout << "Edit the pipe" << endl;
                    break;
                }
                case 5: {
                    cout << "Edit the CS" << endl;
                    break;
                }
                case 6: {
                    cout << "Save" << endl;
                    break;
                }
                case 7: {
                    cout << "Load" << endl;
                    break;
                }
                default: {
                    cout << "Enter number from 0 to 7." << endl;
                    break;
                }
            }
        } else {
            cout << "Enter number from 0 to 7." << endl;
        }
        cout << endl;
    }
};
