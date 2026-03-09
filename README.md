# Satellite Telemetry Parser

A C++ command-line tool that reads simulated satellite telemetry data, validates sensor readings against safe operating ranges, 
flags anomalies, and logs all records to an output file.

Built as a personal project to explore concepts relevant to aerospace software engineering.

---

## Features

- Parses CSV-formatted telemtry data into structured records
- Validates four sensor fields against defined safe operating ranges
- Prints console alerts for any out-of-range readings
- Logs all telemetry records to an output CSV file regardless of status

---

## Getting Started

### Build & Run
```bash
g++ -std=c++17 -o telemetry main.cpp
./telemetry
```


### Input Format

The program reads from 'telemtry_data.csv' in the following format:
```
timestamp,temperature_C,battery_pct,altitude_km,signal_strength
1,22.4,95.1,408.2,-87.3
```

### Output
- **Console** - prints any alerts for out-of-range values
- **telemetry_log.csv** - full log of all parsed records

---

## Utilized Validation Ranges

| Field | Safe Range |
|---|---|
| Temperature | -20°C to 50.0°C |
| Battery | > 20.0% |
| Altitude | 300.0 km to 2000.0 km |
| Signal Strength | > -120.0 dBm |

---

## Example Output
```
  [ALERT] T = 3 | Temperature out of range: 51.7°C
  [ALERT] T = 3 | Battery critically low: 19.5%
```

---

## Project Structure
```
satellite-telemetry-parser/
├── main.cpp
├── telemetry.h
└── telemetry_data.csv
```

---

## Planned Improvementes

- Live data simulation using random number generation
- Multithreaded architecture (producer/consumer pattern)
- Terminal dashboard using ncurses

---

## Author

Keira Wagstaff - Computer Science @ CU Boulder
