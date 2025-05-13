#include "Object.h"


namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }

    bool Object::atCoordinates(Coordinates const & coordinates) const
    {
        // TODO Aufgabe 2:
        //  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen Koordinaten (`coordinates`) liegt.
        return false;
        /*
         ???
         */
    }

    bool Object::intersectsWith(Object const & otherObject) const
    {
        // TODO Aufgabe 2:
        //  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt (`otherObject`) überschneiden.
        return false;
        /*
         ???
         */
    }

}
