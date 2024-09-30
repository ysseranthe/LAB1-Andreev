#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
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

void editPipe(pipe& Pipe, bool i) {
    string inputStatus;
    if (i) {
        cout << "Change the repair status of the pipe?(y/n): " << endl;
        while (true) {
            getline(cin, inputStatus);
            if (inputStatus == "y") {
                Pipe.setIsRepairing(!Pipe.isRepairing());
                break;
            }
            else if (inputStatus == "n") {
                break;
            }
            else {
                cout << "(y/n)" << endl;
            }
        }
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
            if (isInteger(inputEfficiency)/* && stoi(inputEfficiency) > 0*/ && stoi(inputEfficiency) < 101) {
                efficiency = stoi(inputEfficiency);
                break;
            }
            else {
                cout << "Enter a number from 0 to 100" << endl;
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

void editCs(cs& Cs, bool i) {
    if (i) {
        string inputNum;
        cout << "Enter a number of working workshops to change (- if you reduce it): " << endl;

        while (true) {
            getline(cin, inputNum);
            if (isInteger(inputNum) && stoi(inputNum) > -Cs.getWorkshopsInOperation() && stoi(inputNum) + Cs.getWorkshopsInOperation() <= Cs.getNumberOfWorkshops()) {
                Cs.changeOperatingWorkshops(stoi(inputNum));
                break;
            }
            else {
                cout << "Try another number" << endl;
            }
        }
    }
}

void save(pipe Pipe, cs Cs, bool pi, bool csi) {
    if (pi && csi) {
        ofstream out;
        out.open("main.txt");
        if (out.is_open())
        {
            out << Pipe.getPipeName() << endl << Pipe.getPipeLength() << endl << Pipe.getPipeDiameter() << endl << Pipe.isRepairing() << endl << Cs.getName() << endl << Cs.getNumberOfWorkshops() << endl << Cs.getWorkshopsInOperation() << endl << Cs.getEfficiency() << endl;
        }
        out.close();
        cout << "File has been written" << endl;
    }
    else if (pi) {
        ofstream out;
        out.open("main.txt");
        if (out.is_open())
        {
            out << Pipe.getPipeName() << endl << Pipe.getPipeLength() << endl << Pipe.getPipeDiameter() << endl << Pipe.isRepairing() << endl;
        }
        out.close();
        cout << "File has been written" << endl;
    }
    else if (csi) {
        ofstream out;
        out.open("main.txt");
        if (out.is_open())
        {
            out << Cs.getName() << endl << Cs.getNumberOfWorkshops() << endl << Cs.getWorkshopsInOperation() << endl << Cs.getEfficiency() << endl;
        }
        out.close();
        cout << "File has been written" << endl;
    }
    else {
        cout << "No data to save" << endl;
    }
}

void load(pipe& Pipe, cs& Cs, bool& pipeExists, bool& csExists) {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "Could not open file for reading." << endl;
        return;
    }

    string line;

    if (getline(in, line)) {
        string pipeName = line;
        int pipeLength, pipeDiameter;
        bool pipeRepair;

        if (getline(in, line)) {
            pipeLength = stoi(line);
        }
        else {
            cout << "Error reading pipe length." << endl;
            return;
        }

        if (getline(in, line)) {
            pipeDiameter = stoi(line);
        }
        else {
            cout << "Error reading pipe diameter." << endl;
            return;
        }

        if (getline(in, line)) {
            pipeRepair = (line == "1");
        }
        else {
            cout << "Error reading pipe repair status." << endl;
            return;
        }

        Pipe = pipe(pipeName, pipeLength, pipeDiameter, pipeRepair);
        pipeExists = true;
    }


    if (getline(in, line)) {
        string csName = line;
        int numberOfWorkshops, workshopsInOperation, efficiency;

        if (getline(in, line)) {
            numberOfWorkshops = stoi(line);
        }
        else {
            cout << "Error reading number of workshops." << endl;
            return;
        }

        if (getline(in, line)) {
            workshopsInOperation = stoi(line);
        }
        else {
            cout << "Error reading workshops in operation." << endl;
            return;
        }

        if (getline(in, line)) {
            efficiency = stoi(line);
        }
        else {
            cout << "Error reading efficiency." << endl;
            return;
        }

        Cs = cs(csName, numberOfWorkshops, workshopsInOperation, efficiency);
        csExists = true;
    }

    in.close();
    cout << "Data successfully loaded from file." << endl;
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
                    //cout << "Edit the pipe" << endl;
                    editPipe(Pipe, pipeExists);
                    break;
                }
                case 5: {
                    //cout << "Edit the compressor station" << endl;
                    editCs(Cs, csExists);
                    break;
                }
                case 6: {
                    //cout << "Save" << endl;
                    save(Pipe, Cs, pipeExists, csExists);
                    break;
                }
                case 7: {
                    //cout << "Load" << endl;
                    load(Pipe, Cs, pipeExists, csExists);
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
