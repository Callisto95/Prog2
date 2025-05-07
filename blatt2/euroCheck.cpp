#include "euroCheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::string;

bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);

// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
int getEuroSerialNumberVersion(const string& serialNumber) {
	bool isValidSerialNumber = isLetter(serialNumber.at(0));

	if (!isValidSerialNumber) {
		return VERSION_INVALID;
	}

	if (isLetter(serialNumber.at(1))) {
		return VERSION_2013;
	}

	return VERSION_2002;
}

// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format: L NNNNNNNNNN N
//  (Leerzeichen im Format werden vom Nutzer nicht mit eingegeben, sondern helfen hier nur beim Zählen)
//  Tipp: `x / 10` liefert die Zehnerstelle und `x % 10` die Einerstelle einer zweistelligen Zahl x.
bool checkEuroSerialNumber2002(const string& serialNumber) {
	string const rawNumbers = serialNumber.substr(1, serialNumber.length() - 2);
	const int rawLetterValue = toNumber(serialNumber.at(0));

	std::vector<int> numbers;
	int initialShift = 1;
	if (rawLetterValue > 10) {
		numbers	   = std::vector<int>(rawNumbers.length() + 2);
		numbers[0] = rawLetterValue / 10;
		numbers[1] = rawLetterValue % 10;
		initialShift = 2;
	} else {
		numbers	   = std::vector<int>(rawNumbers.length() + 1);
		numbers[0] = rawLetterValue;
	}
	const auto begin = std::next(numbers.begin(), initialShift);

	std::transform(rawNumbers.begin(), rawNumbers.end(), begin, [](const char n){return toNumber(n);});
	const int sum = std::reduce(numbers.begin(), numbers.end(), 0, [](const int n1, const int n2){return n1 + n2;});

	int calculatedChecksum = 8 - (sum % 9);

	if (calculatedChecksum == 0) {
		calculatedChecksum = 9;
	}

	return calculatedChecksum == toNumber(serialNumber.at(serialNumber.length() - 1));
}


// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format: LL NNNNNNNNN N
bool checkEuroSerialNumber2013(std::string& serialNumber) {
	return true;
}


// L
bool isLetter(char c) {
    return 'A' <= c && c <= 'Z';
}
// N
bool isNumber(char c) {
    return '0' <= c && c <= '9';
}
int toNumber(char c) {
    if (isNumber(c)) {
        return c - '0';
    }
    if (isLetter(c)) {
        return c - 'A' + 1;
    }
    std::cout << "Error: toNumber(char): " << c << std::endl;
    return 0;
}
