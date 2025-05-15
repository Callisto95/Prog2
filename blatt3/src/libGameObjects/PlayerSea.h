#ifndef BLATT3_PLAYERSEA_H
#define BLATT3_PLAYERSEA_H


#include <string>
#include <vector>

#include "Ship.h"
#include "Missile.h"


namespace GameObjects {
	inline std::string FIELD_WATER = "\u001B[96m~\u001B[0m";
	inline std::string FIELD_HIT = "\u001B[31mX\u001B[0m";
	inline std::string FIELD_NO_HIT = "\u001B[35m*\u001B[0m";

	enum class AddShipResult {
		OUT_OF_BOUNDS,
		OVERLAP,
		ADDED_SUCCESSFULLY
	};

    class PlayerSea {
    private:
        std::string playerName;
        std::vector<Ship> ships;
#ifdef CLASS_MISSILE_COMPLETE
        std::vector<Missile> missilesSent;

        bool receiveMissile(Missile & missile);
#endif

    public:
        PlayerSea(std::string const & newPlayerName);

        std::string const & getPlayerName() const;

        static std::string printSeaArea();

        bool overlapWithExistingShips(Ship const & otherShip) const;

        // TODO Aufgabe 6:
        //  Erweitert `addShip(..)` so, dass nicht nur ein `bool`, sondern ein Statuswert (`enum class`) zurückgegeben wird.
        //  Dieser soll nicht nur angeben ob, sondern auch warum ein Schiff nicht hinzugefügt werden konnte.
        AddShipResult addShip(Ship const & ship);

        bool sendMissileTo(PlayerSea & otherSea, Sea::Coordinates const & targetCoordinates);
        bool missileAlreadySentTo(Sea::Coordinates const & targetCoordinates) const;

        bool allShipsDestroyed() const;

    	void printSea() const;
    };

}


#endif //BLATT3_PLAYERSEA_H
