#ifndef BLATT3_PLAYERSEA_H
#define BLATT3_PLAYERSEA_H


#include <string>
#include <vector>

#include "Ship.h"
#include "Missile.h"


namespace GameObjects {
	inline std::string STYLE_RESET_ALL		  = "\u001B[0m";
	inline std::string STYLE_BLINK			  = "\u001B[5m";
	inline std::string COLOUR_BLUE_BACKGROUND = "\u001B[44m";
	inline std::string COLOUR_RED			  = "\u001B[31m";
	inline std::string COLOUR_PURPLE		  = "\u001B[35m";
	inline std::string COLOUR_CYAN			  = "\u001B[96m";

	inline std::string FIELD_WATER	= COLOUR_BLUE_BACKGROUND + STYLE_BLINK + "~" + STYLE_RESET_ALL;
	inline std::string FIELD_HIT	= COLOUR_BLUE_BACKGROUND + "X" + STYLE_RESET_ALL;
	inline std::string FIELD_NO_HIT = COLOUR_BLUE_BACKGROUND + COLOUR_PURPLE + "*" + STYLE_RESET_ALL;

	enum class AddShipResult {
		SUCCESS,
		OVERLAP,
		OUT_OF_BOUNDS
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
