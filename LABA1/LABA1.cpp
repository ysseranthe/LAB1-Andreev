#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "pipe.h"
#include "LABA1.h"
using namespace std;

bool isInteger(string const& str) {
    istringstream iss(str);
    int num;
    iss >> num;
    return !iss.fail() && iss.eof();
}

pipe createPipe(bool &i,pipe PPipe) {
    if (!i) {
        pipe Pipe;

        int length;
        int diameter;

        bool repair;

        string inputName;
        string inputLength;
        string inputDiameter;
        string inputRepair;

        cout << "Enter the name of the pipe:" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, inputName);

        cout << "Enter the length:" << endl;
        while (true) {
            cin >> inputLength;
            if (isInteger(inputLength) && stoi(inputLength) > 0) {
                length = stoi(inputLength);
                break;
            }
            else {
                cout << "Enter a positive number" << endl;
            }
        }

        cout << "Enter the diameter:" << endl;
        while (true) {
            cin >> inputDiameter;
            if (isInteger(inputDiameter) && stoi(inputDiameter) > 0) {
                diameter = stoi(inputDiameter);
                break;
            }
            else {
                cout << "Enter a positive number" << endl;
            }
        }

        cout << "Is the pipe under repair?(y/n):" << endl;
        while (true) {
            cin >> inputRepair;
            if (inputRepair == "y") {
                repair = true;
                break;
            }
            else if (inputRepair == "n") {
                repair = false;
                break;
            }
            else {
                cout << "(y/n)" << endl;
            }
        }
        Pipe = pipe(inputName, length, diameter, repair);
        i = true;
        return Pipe;
    }
    else {
        return PPipe;
    }
}

void showPipe(pipe Pipe, bool i) {
    if (i) {
        cout << "Pipe name: " << Pipe.getPipeName() << endl;
        cout << "Pipe length: " << Pipe.getPipeLength() << endl;
        cout << "Pipe diameter: " << Pipe.getPipeDiameter() << endl;
        cout << "Is the pipe being repaired?: " << (Pipe.isRepairing() == 1 ? "Yes" : "No") << endl;
    }
}

int main() {
    string input;
    pipe Pipe;
    bool pipeExists = false;

    while (true) {
        cout << "1. Add a pipe\n2. Add CS\n3. View all objects\n4. Edit the pipe\n5. Edit the CS\n6. Save\n7. Upload\n0. Exit" << endl;
        cin >> input;
        if (isInteger(input)) {
            int choose;
            choose = stoi(input);
            switch (choose) {
            case 0: {
                return 0;
            }
            case 1: {
                cout << "Add a pipe" << endl;
                Pipe=createPipe(pipeExists,Pipe);
                break;
            }
            case 2: {
                cout << "Add CS" << endl;
                break;
            }
            case 3: {
                showPipe(Pipe, pipeExists);
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
        }
        else {
            cout << "Enter number from 0 to 7." << endl;
        }
        cout << endl;
    }
}
