#include "init.h"

// TODO Aufgabe 7:
//  Bringe die `include`- und `using`-Anweisungen in eine sinnvolle Ordnung.
#include <climits>
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::getline;
using std::cin;
using std::endl;
using std::cout;
using std::vector;

#include "Coordinates.h"
#include "Ship.h"
#include "Constants.h"
#include "Object.h"
#include "PlayerSea.h"
using Sea::Coordinates;
using Sea::Orientation;
using GameObjects::Ship;
using GameObjects::PlayerSea;
using GameObjects::Constants;


unsigned int const Constants::seaSizeX = 3;
unsigned int const Constants::seaSizeY = 3;
vector<unsigned int> const Constants::shipSizes = { 2, 1 };


void initializePlayerSeasWithShips(vector<PlayerSea> & playerSeas)
{
    for (unsigned int playerIdx = 0; playerIdx < 2; ++playerIdx) {
        string playerName = inputPlayerName();
        playerSeas.emplace_back(playerName);
        initializeShips(playerSeas[playerIdx]);
    }
}

string inputPlayerName() {
	// TODO Aufgabe 5:
	//  Es soll ein Spielername eingegeben werden.
	//  In der Ausgabe soll eine Spielernummer durchgezählt werden (Spieler 1, Spieler 2).
	//  Dazu soll eine `static` Variable verwendet werden.
	static int playerCount = 0;
	cout << endl << "Name von Spieler " << playerCount << ":";
	playerCount++;

	string playerName;
	getline(cin, playerName);
	return playerName;
}

void initializeShips(PlayerSea & playerSea)
{
    cout << "Setze deine Schiffe ins Wasser (" << PlayerSea::printSeaArea() << ")." << endl;

    for (unsigned int shipIdx = 0; shipIdx < Constants::shipSizes.size(); ++shipIdx) {
        auto size = Constants::shipSizes[shipIdx];

        while (!initializeShip(playerSea, size));
    }
    for (unsigned int i = 0; i < 20; ++i) {
        cout << endl;
    }
}

bool initializeShip(PlayerSea & playerSea, unsigned int size)
{
    Ship ship = inputShip(size);
    auto addResult = playerSea.addShip(ship);
    // TODO Aufgabe 6:
    //  Erweitert die Auswertung, und gebt entsprechend des Status-Rückgabewerts von `addShip(..)` eine spezifische Meldung aus.
    switch (addResult) {
    case GameObjects::AddShipResult::OUT_OF_BOUNDS: {
    	cout << "Das Schiff´muss innerhalb der Grenzen liegen!" << endl;
    	break;
    }
    case GameObjects::AddShipResult::OVERLAP: {
    	cout << "Das Schiff darf nicht auf einem anderem Schiff liegen!" << endl;
    	break;
    }
    case GameObjects::AddShipResult::ADDED_SUCCESSFULLY: {}
    }

    return addResult == GameObjects::AddShipResult::ADDED_SUCCESSFULLY;
}

Ship inputShip(unsigned int size)
{
    cout << endl << "Neues Schiff der Groesse " << size << endl;
    Coordinates coordinates = inputCoordinates();
    Orientation orientation = inputOrientation();

    return Ship(coordinates, size, orientation);
}

Coordinates inputCoordinates()
{
    unsigned int x, y;
    do {
        cout << "  x y:";
        cin >> x >> y;
    } while (checkForInputError());
    return Coordinates(x, y);
}

Orientation inputOrientation()
{
    string orientation;
    do {
        cout << "  Ausrichtung nach (r/rechts oder u/unten):";
        cin >> orientation;
    } while (checkForInputError() || (orientation[0] != 'r' && orientation[0] != 'u'));
    return orientation[0] == 'r' ? Orientation::X : Orientation::Y;
}

bool checkForInputError()
{
    bool error = cin.fail();
    if (error) {
        cout << "Eingabe fehlerhaft." << endl;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return error;
}
