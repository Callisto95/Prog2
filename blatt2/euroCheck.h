#ifndef BLATT2_EUROCHECK_H
#define BLATT2_EUROCHECK_H

#include <string>

// TODO Aufgabe 2:
//  Deklariert die Funktion `getEuroSerialNumberVersion(serialNumber)`.

const int VERSION_2002 = 2002;
const int VERSION_2013 = 2013;
const int VERSION_INVALID = 0;
const int SERIAL_NUMBER_LENGTH = 12;
int getEuroSerialNumberVersion(std::string & serialNumber);


bool checkEuroSerialNumber2002(std::string & serialNumber);
bool checkEuroSerialNumber2013(std::string & serialNumber);

#endif //BLATT2_EUROCHECK_H
