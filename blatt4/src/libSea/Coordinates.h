#ifndef BLATT4_COORDINATES_H
#define BLATT4_COORDINATES_H


#include <string>
#include <iostream>


namespace Sea {

    class Coordinates {
    protected:
        unsigned int x, y;

    public:
        Coordinates(unsigned int newX, unsigned int newY);

        bool samePositionAs(unsigned int otherX, unsigned int otherY) const;

        // TODO Aufgabe 4:
        //  Ersetzt die Funktion `samePositionAs(..)` durch den `operator==(..)`.
        //  Rückgabetyp, Parameter und Inhalt bleiben identisch.
        bool samePositionAs(Coordinates const & otherCoordinates) const;

        virtual unsigned int getX() const;
        virtual unsigned int getY() const;

        virtual std::string toString() const;
    };

}

// TODO Aufgabe 4:
//  Deklariert einen `operator<<(..)`.
//  Dieser bekommt eine `std::ostream`- und eine `Sea::Coordinates`-Referenz übergeben und liefert eine `std::ostream`-Referenz zurück.
/*
 ???
 */


#endif //BLATT4_COORDINATES_H
