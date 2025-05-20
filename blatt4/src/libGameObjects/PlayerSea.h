#ifndef BLATT4_PLAYERSEA_H
#define BLATT4_PLAYERSEA_H


#include <string>
#include <vector>
#include <memory>
#include <exception>

#include "Ship.h"
#include "Missile.h"
#include "Constants.h"


namespace GameObjects {

    class PlayerSea {
    private:
        std::string playerName;
        std::vector<Ship> ships;

        // TODO Aufgabe 1:
        //  Die Listen `missilesSent` und `missilesReceived` sollen nicht direkt Missile-Instanzen (Kopien) speichern, sondern Smart Pointer (`shared_ptr`) nutzen, um auf existierende Instanzen zu verweisen.
        std::vector<Missile> missilesSent, missilesReceived;

        // TODO Aufgabe 1:
        bool receiveMissile(Missile & missile);

        OutputGrid gridOwnSea = OutputGrid(Constants::seaSizeY, std::vector<OutputGridCell>(Constants::seaSizeX));
        OutputGrid gridOtherSea = gridOwnSea;

    public:
        PlayerSea(std::string const & newPlayerName);

        std::string const & getPlayerName() const;

        static std::string getSeaBounds();

        static bool isInsideSeaBounds(Sea::Coordinates const & coordinates);

        bool overlapWithExistingShips(Ship const & otherShip) const;

        // TODO Aufgabe 2:
        //  Deklariert hier (mindestens) eine eigene Exception-Klasse, die von `std::exception` erbt.
        //  Entfernt `AddShipResult` und passt die Funktion `addShip(..)` entsprechend an.
        enum class AddShipResult {
            added,
            outsideSeaBounds,
            overlapOtherShip
        };
        AddShipResult addShip(Ship const & ship);

        // TODO Aufgabe 1:
        bool sendMissileTo(PlayerSea & otherSea, Missile missile);

        bool allShipsDestroyed() const;


        void print(std::string const & otherPlayerName) const;

    private:
        void printHeader(std::string const & otherPlayerName) const;
        void printLine(unsigned int y) const;
        static void printHorizontalBorder();
    };

}


#endif //BLATT4_PLAYERSEA_H
