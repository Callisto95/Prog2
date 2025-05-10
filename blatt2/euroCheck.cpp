#include "euroCheck.h"
#include <vector>
#include <iostream>

using std::string;
using std::vector;

bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);

bool isVersion2013 (string const & serialNumber) {
	if (!(isLetter(serialNumber.at(0)) && isLetter(serialNumber.at(1)))) {
		return false;
	}
	for (int i = 2; i <= serialNumber.length() - 1; i++) {
		const char currentChar = serialNumber.at(i);
		if (!isNumber(currentChar)) {
			return false;
		}
	}
	return true;
}
bool isVersion2002 (string const & serialNumber) {

	if (!isLetter(serialNumber.at(0))) {
		return false;
	}
	for (int i = 1; i <= serialNumber.length() - 1; i++) {
		const char currentChar = serialNumber.at(i);
		if (!isNumber(currentChar)) {
			return false;
		}
	}
	return true;
}

	// TODO Aufgabe 7:
int getEuroSerialNumberVersion(string & serialNumber) {
	if (serialNumber.length() != SERIAL_NUMBER_LENGTH) {
		return VERSION_INVALID;
	}

	if (isVersion2013(serialNumber)) {
		return VERSION_2013;
	}

	if (isVersion2002(serialNumber)){
		return VERSION_2002;
	}

	return VERSION_INVALID;

	// TODO Aufgabe 2:
	//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
	//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
	//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
	/*
	 OLD FORMAT CHECKER (AUFGABE 2)

    if (isLetter(serialNumber.at(0)) && isLetter(serialNumber.at(1)) ) {
		return VERSION_2013;
    } else if (isLetter(serialNumber.at(0)) ) {
		return VERSION_2002;
    }
	*/
}

// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format: L NNNNNNNNNN N
//  (Leerzeichen im Format werden vom Nutzer nicht mit eingegeben, sondern helfen hier nur beim Zählen)
//  Tipp: `x / 10` liefert die Zehnerstelle und `x % 10` die Einerstelle einer zweistelligen Zahl x.
bool checkEuroSerialNumber2002 (std::string & serialNumber) {
	// Format Checker
	/*
	if (serialNumber.length() != SERIAL_NUMBER_LENGTH) {
		return false;
	}

	if (!isLetter(serialNumber.at(0))) {
		return false;
	}

	for (int i = 1; i <= serialNumber.length() - 1; i++) {
		const char currentChar = serialNumber.at(i);
		if (!isNumber(currentChar)) {
			return false;
		}
	}
	// Format Checker END
	*/

	// pruefZiffer Ersteller
	int quersumme = 0;
	for (int i = 0; i < serialNumber.length() - 1; i++) {
		const char currentChar = serialNumber.at(i);

		if (isNumber(currentChar)) {
			quersumme += toNumber(currentChar);
		}
		if (isLetter(currentChar)) {
			const int number = toNumber(currentChar);
			quersumme += number / 10;
			quersumme += number % 10;
		}

	}
	int pruefZiffer = 8 - (quersumme % 9);

	if (pruefZiffer == 0) {
		pruefZiffer = 9;
	}

	// Überprüfen
	return toNumber(serialNumber.at(serialNumber.length() - 1)) == pruefZiffer;

}

// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format: LL NNNNNNNNN N
bool checkEuroSerialNumber2013(std::string & serialNumber) {
	// Format Checker
	/*
	if (serialNumber.length() != SERIAL_NUMBER_LENGTH) {
		return false;
	}

	if (! (isLetter(serialNumber.at(0)) && isLetter(serialNumber.at(1))) ) {
		return false;
	}

	for (int i = 2; i <= serialNumber.length() - 1; i++) {
		const char currentChar = serialNumber.at(i);
		if (!isNumber(currentChar)) {
			return false;
		}
	}
	// Format Checker END
	*/

	// pruefZiffer Ersteller
	int quersumme = 0;
	for (int i = 0; i < serialNumber.length() - 1; i++) {
		const char currentChar = serialNumber.at(i);

		if (isNumber(currentChar)) {
			quersumme += toNumber(currentChar);
		}
		if (isLetter(currentChar)) {
			const int number = toNumber(currentChar);
			quersumme += number / 10;
			quersumme += number % 10;
		}

	}
	int pruefZiffer = 7 - (quersumme % 9);

	switch (pruefZiffer) {
	case 0:
		pruefZiffer = 9;
		break;
	case -1:
		pruefZiffer = 8;
		break;
	}

	// Überprüfen
	return toNumber(serialNumber.at(serialNumber.length() - 1)) == pruefZiffer;
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
