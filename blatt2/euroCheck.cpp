#include "euroCheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <regex>

using std::string;
using std::vector;

bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);

int calculateCheckSum(const std::string& serialNumber, int letterCount);
// template<class UnaryPred>
// bool allCharsAre(string const& vec, UnaryPred predicate);


// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für
//  ungültige Seriennummern. Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
int getEuroSerialNumberVersion(const string& serialNumber) {
	if (std::regex_match(serialNumber, std::regex("[A-Z]{2}[0-9]{10}"))) {
		return VERSION_2013;
	}
	if (std::regex_match(serialNumber, std::regex("[A-Z]{1}[0-9]{11}"))) {
		return VERSION_2002;
	}

	return VERSION_INVALID;
}

// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format: L NNNNNNNNNN N
//  (Leerzeichen im Format werden vom Nutzer nicht mit eingegeben, sondern helfen hier nur beim Zählen)
//  Tipp: `x / 10` liefert die Zehnerstelle und `x % 10` die Einerstelle einer zweistelligen Zahl x.
bool checkEuroSerialNumber2002(const string& serialNumber) {
	int calculatedChecksum = calculateCheckSum(serialNumber, 1);

	if (calculatedChecksum == CHECKSUM_INVALID) {
		return false;
	}

	calculatedChecksum = 8 - (calculatedChecksum % 9);

	if (calculatedChecksum == 0) {
		calculatedChecksum = 9;
	}

	return calculatedChecksum == toNumber(serialNumber.at(serialNumber.length() - 1));
}


// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format: LL NNNNNNNNN N
bool checkEuroSerialNumber2013(const std::string& serialNumber) {
	int calculatedCheckSum = calculateCheckSum(serialNumber, 2);

	if (calculatedCheckSum == CHECKSUM_INVALID) {
		return false;
	}

	calculatedCheckSum = 7 - (calculatedCheckSum % 9);

	if (calculatedCheckSum == 0) {
		calculatedCheckSum = 9;
	}
	if (calculatedCheckSum == -1) {
		calculatedCheckSum = 8;
	}

	return calculatedCheckSum == toNumber(serialNumber.at(serialNumber.length() - 1));
}

// handled by getEuroSerialNumberVersion - no longer needed
// template <class UnaryPred>
// bool allCharsAre(string const& vec, UnaryPred predicate) {
// 	return std::find_if(vec.begin(), vec.end(), predicate) != vec.end();
// }


int calculateCheckSum(const std::string& serialNumber, const int letterCount) {
	string const letters = serialNumber.substr(0, letterCount);
	string const numbers = serialNumber.substr(letterCount, serialNumber.length() - 1 - letterCount);

	/*
	 * handled by getEuroSerialNumberVersion
	if (!allCharsAre(letters, isLetter)) {
		return CHECKSUM_INVALID;
	}

	if (!allCharsAre(numbers, isNumber)) {
		return CHECKSUM_INVALID;
	}
	*/

	vector<int> values;

	std::for_each(letters.begin(), letters.end(), [&values](const char c) {
		const int letterValue = toNumber(c);

		values.push_back(letterValue / 10);
		values.push_back(letterValue % 10);
	});

	std::transform(numbers.begin(), numbers.end(), std::back_inserter(values), toNumber);
	return std::accumulate(values.begin(), values.end(), 0);
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
