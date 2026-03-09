#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "telemetry.h"

using namespace std;

void verifyData(TelemetryRecord& info){
    if(info.temperature_C < -20 || info.temperature_C > 50){
        cout << " [ALERT] T = " << info.time_stamp
            << " | Temperature out of range: " << info.temperature_C << " C" << endl;
    }
    if(info.battery_pct < 20.0){
        cout << " [ALERT] T = " << info.time_stamp 
            << " | Battery critically low: " << info.battery_pct << "%" << endl;
    }
    if(info.altitude_km < 300.0 || info.altitude_km > 2000.0){
        cout << " [ALERT] T = " << info.time_stamp
            << " | Altitude out of range: " << info.altitude_km << " km" << endl;
    }
    if(info.signal_strength < -120.0){
        cout << " [ALERT] T = " << info.time_stamp
            << " | Signal too weak: " << info.signal_strength << " dBm" << endl;
    }
}

void logsData(ofstream& outLog, TelemetryRecord& info){
    outLog << info.time_stamp << ", "
        << info.temperature_C << ", "
        << info.battery_pct << ", "
        << info.altitude_km << ", "
        << info.signal_strength << endl;
}

int main(){
    string inputFile = "telemetry_data.csv"; // data input
    string logFile = "telemetry_log.csv"; // writing out for our log
    ifstream inFile(inputFile);
    ofstream outLog(logFile);

    if(!inFile.is_open()){ // make sure file is open
        cout << "Could not open input file" << endl;
        return -1;
    }

    string line; 
    getline(inFile, line); // takes in the headers of our data so we don't parse through that below
    outLog << line << endl; // writes it out so we have a header; plan to make this pretty later

    while(getline(inFile, line)){ // while there's still lines to read in from the file
        if(line.empty())continue; // move on

        stringstream ss(line); // put line to ss
        vector<string> fields;
        string token;
        TelemetryRecord currentLine;

        while(getline(ss, token, ',')){ // while loop that puts our values into a vector (so we can put them into struct)
            fields.push_back(token);
        }
        
        currentLine.time_stamp = stoi(fields[0]);
        currentLine.temperature_C = stod(fields[1]);
        currentLine.battery_pct = stod(fields[2]);
        currentLine.altitude_km = stod(fields[3]);
        currentLine.signal_strength = stod(fields[4]);

        verifyData(currentLine);
        logsData(outLog, currentLine);
    }

    return 0;
}