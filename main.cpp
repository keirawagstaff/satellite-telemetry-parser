#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string inputFile = "telemetry_data.csv";
    string logFile = "telemetry_log.csv";

    ifstream inFile(inputFile);
    ofstream outLog(logFile);

    if(!inFile.is_open()){
        cout << "Could not open input file" << endl;
    }

    string line;
    getline(inFile, line);
    outLog << line << endl;

    while(getline(inFile, line)){
        if(line.empty())continue;

        outLog << line << endl;
    }

    return 0;
}