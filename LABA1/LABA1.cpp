#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "pipe.h"
#include "cs.h"
#include "LABA1.h"
using namespace std;

bool isInteger(string const& str) {
    istringstream iss(str);
    int num;
    return (iss >> num) && iss.eof();
}

pipe createPipe(bool &i,pipe newPipe) {
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
        getline(cin, inputName);

        cout << "Enter the length:" << endl;
        while (true) {
            getline(cin, inputLength);
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
            getline(cin, inputDiameter);
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
            getline(cin, inputRepair);
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
        return newPipe;
    }
}

void showPipe(pipe Pipe, bool i) {
    if (i) {
        cout << "Pipe name: " << Pipe.getPipeName() << endl;
        cout << "Pipe length: " << Pipe.getPipeLength() << endl;
        cout << "Pipe diameter: " << Pipe.getPipeDiameter() << endl;
        cout << "Is the pipe being repaired?: " << (Pipe.isRepairing() == 1 ? "Yes" : "No") << "\n" << endl;
    }
}

cs createCs(bool& i, cs newCs) {
    if (!i) {
        cs Cs;

        int numberOfWorkshops;
        int workshopsInOperation;
        int efficiency;

        string inputName;
        string inputNumberOfWorkshops;
        string inputWorkshopsInOperation;
        string inputEfficiency;

        cout << "Enter the name of the compressor station:" << endl;
        getline(cin, inputName);

        cout << "Enter the number of workshops:" << endl;
        while (true) {
            getline(cin, inputNumberOfWorkshops);
            if (isInteger(inputNumberOfWorkshops) && stoi(inputNumberOfWorkshops) > 0) {
                numberOfWorkshops = stoi(inputNumberOfWorkshops);
                break;
            }
            else {
                cout << "Enter a positive number greater than 0" << endl;
            }
        }

        cout << "Enter the number of workshops in operation:" << endl;
        while (true) {
            getline(cin, inputWorkshopsInOperation);
            if (isInteger(inputWorkshopsInOperation) && stoi(inputWorkshopsInOperation) > 0 && numberOfWorkshops >= stoi(inputWorkshopsInOperation)) {
                workshopsInOperation = stoi(inputWorkshopsInOperation);
                break;
            }
            else {
                cout << "Enter a positive number <= than number of workshops" << endl;
            }
        }

        cout << "Enter the efficiency:" << endl;
        while (true) {
            getline(cin, inputEfficiency);
            if (isInteger(inputEfficiency) && stoi(inputEfficiency) > 0 && stoi(inputEfficiency) < 101) {
                efficiency = stoi(inputEfficiency);
                break;
            }
            else {
                cout << "Enter a number greater than 0 and less than 101" << endl;
            }
        }

        Cs = cs(inputName, numberOfWorkshops, workshopsInOperation, efficiency);
        i = true;
        return Cs;
    }
    else {
        return newCs;
    }
}

void showCs(cs Cs, bool i) {
    if (i) {
        cout << "Compressor station name: " << Cs.getName() << endl;
        cout << "The number of workshops: " << Cs.getNumberOfWorkshops() << endl;
        cout << "The number of workshops in operation: " << Cs.getWorkshopsInOperation() << endl;
        cout << "The efficiency: " << Cs.getEfficiency() << endl;
    }
}

int main() {
    string input;
    pipe Pipe;
    cs Cs;
    bool pipeExists = false;
    bool csExists = false;

    while (true) {
        cout << "1. Add a pipe\n2. Add CS\n3. View all objects\n4. Edit the pipe\n5. Edit the CS\n6. Save\n7. Upload\n0. Exit\n" << endl;
        getline(cin, input);
        if (isInteger(input)) {
            int choose;
            choose = stoi(input);
            switch (choose) {
                case 0: {
                    return 0;
                }
                case 1: {
                    //cout << "Add a pipe" << endl;
                    Pipe = createPipe(pipeExists, Pipe);
                    break;
                }
                case 2: {
                    //cout << "Add a CS" << endl;
                    Cs = createCs(csExists, Cs);
                    break;
                }
                case 3: {
                    showPipe(Pipe, pipeExists);
                    showCs(Cs, csExists);
                    break;
                }
                case 4: {
                    cout << "Edit the pipe" << endl;
                    break;
                }
                case 5: {
                    cout << "Edit the compressor station" << endl;
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
