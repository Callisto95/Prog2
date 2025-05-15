#include "PlayerSea.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

#include "Coordinates.h"
using Sea::Coordinates;

#include "Constants.h"


namespace GameObjects {

    PlayerSea::PlayerSea(string const & newPlayerName)
    : playerName(newPlayerName)
    {
    }

    string const & PlayerSea::getPlayerName() const
    {
        return playerName;
    }

    string PlayerSea::printSeaArea()
    {
        return "Spielfeld: 0-" + to_string(Constants::seaSizeX - 1) +
                       " x 0-" + to_string(Constants::seaSizeY - 1);
    }

    bool PlayerSea::overlapWithExistingShips(Ship const & otherShip) const
    {
        for (unsigned int shipIdx = 0; shipIdx < ships.size(); ++shipIdx) {
            Ship const & ship = ships[shipIdx];
            if (ship.intersectsWith(otherShip)) {
                return true;
            }
        }
        return false;
    }

    // TODO Aufgabe 6:
    //  Erweitert `addShip` so, dass der Rückgabewert angibt, welches tatsächliche Problem aufgetreten ist:
    //  Außerhalb des Spielfelds (Seegrenzen) oder Überlappung mit einem anderen Schiff.
    AddShipResult PlayerSea::addShip(Ship const & ship)
    {
		if (!ship.isInsideSeaBounds()) {
			return AddShipResult::OUT_OF_BOUNDS;
		}

    	if (overlapWithExistingShips(ship)) {
    		return AddShipResult::OVERLAP;
    	}

        ships.push_back(ship);
        return AddShipResult::SUCCESS;
    }

    bool PlayerSea::sendMissileTo(PlayerSea & otherSea, Coordinates const & targetCoordinates)
    {
#ifdef CLASS_MISSILE_COMPLETE
        Missile missile(targetCoordinates);
        bool hit = otherSea.receiveMissile(missile);
        missilesSent.push_back(missile);
        return hit;
#else
        return false;
#endif
    }

    bool PlayerSea::missileAlreadySentTo(Coordinates const & targetCoordinates) const
    {
#ifdef CLASS_MISSILE_COMPLETE
        for (unsigned int missileIdx = 0; missileIdx < missilesSent.size(); ++missileIdx) {
            Missile const & missile = missilesSent[missileIdx];
            if (missile.samePositionAs(targetCoordinates)) {
                return true;
            }
        }
#endif
        return false;
    }

#ifdef CLASS_MISSILE_COMPLETE
    bool PlayerSea::receiveMissile(Missile & missile)
    {
        bool hit = false;
#ifdef CLASS_SHIP_COMPLETE
        for (unsigned int shipIdx = 0; shipIdx < ships.size(); ++shipIdx) {
            Ship & ship = ships[shipIdx];
            if (ship.checkAndUpdateIncomingMissile(missile)) {
                hit = true;
            }
        }
#endif
        return hit;
    }
#endif

    bool PlayerSea::allShipsDestroyed() const
    {
        for (unsigned int shipIdx = 0; shipIdx < ships.size(); ++shipIdx) {
            Ship const & ship = ships[shipIdx];
            if (!ship.isDestroyed()) {
                return false;
            }
        }
        return true;
    }

	void PlayerSea::printSea() const {
    	string sea[Constants::seaSizeX][Constants::seaSizeY];

		for (unsigned int x = 0; x < Constants::seaSizeX; x++) {
			for (unsigned int y = 0; y < Constants::seaSizeY; y++) {
				sea[x][y] = FIELD_WATER;
			}
		}

    	for (Missile const& missile : missilesSent) {
    		sea[missile.getX()][missile.getY()] = missile.hasHitSomething() ? FIELD_HIT : FIELD_NO_HIT;
    	}

    	for (unsigned int y = 0; y < Constants::seaSizeY; y++) {
    		for (unsigned int x = 0; x < Constants::seaSizeX; x++) {
    			cout << sea[x][y];
    		}
    		cout << endl;
    	}
	}
}
