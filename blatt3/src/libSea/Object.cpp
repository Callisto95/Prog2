#include "Object.h"

#include <vector>

namespace Sea {

	std::vector<Coordinates> getPositions(Coordinates const& startPosition, const unsigned int size,
										  const Sea::Orientation orientation) {

		std::vector<Coordinates> positions;
		unsigned int			 x0 = startPosition.getX();
		unsigned int			 y0 = startPosition.getY();

		for (unsigned int i = 0; i < size; i++) {

			if (orientation == Sea::Orientation::X) {
				positions.emplace_back(x0 + i, y0);
			} else {
				positions.emplace_back(x0, y0 + i);
			}
		}

		return positions;
	}

	Object::Object(Coordinates const& newCoordinates, unsigned int newSize, Sea::Orientation newOrientation) :
		Coordinates(newCoordinates),
		size(newSize),
		orientation(newOrientation) {}

	bool Object::atCoordinates(Coordinates const& coordinates) const {
		// TODO Aufgabe 2:
		//  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen
		//  Koordinaten (`coordinates`) liegt.

		std::vector<Coordinates> vec = getPositions(*this, size, orientation);

		for (Coordinates a : vec) {
			if (a.samePositionAs(coordinates)) {
				return true;
			}
		}
		return false;

		/*
		 ???
		 */
	}

	bool Object::intersectsWith(Object const& otherObject) const {
		// TODO Aufgabe 2:
		//  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt
		//  (`otherObject`) überschneiden.

		std::vector<Coordinates> otherVec = getPositions(otherObject, otherObject.size, otherObject.orientation);

		for (Coordinates c : otherVec) {
			if (atCoordinates(c)) {
				return true;
			}
		}
		return false;
		/*
		 ???
		 */
	}

} // namespace Sea
