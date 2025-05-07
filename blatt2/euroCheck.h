#ifndef BLATT2_EUROCHECK_H
#define BLATT2_EUROCHECK_H

#include <string>

constexpr int VERSION_2013 = 2023;
constexpr int VERSION_2002 = 2002;
constexpr int VERSION_INVALID = 0;

// TODO Aufgabe 2:
//  Deklariert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
int getEuroSerialNumberVersion(const std::string& serialNumber);

bool checkEuroSerialNumber2002(const std::string& serialNumber);
bool checkEuroSerialNumber2013(std::string & serialNumber);

#endif //BLATT2_EUROCHECK_H
