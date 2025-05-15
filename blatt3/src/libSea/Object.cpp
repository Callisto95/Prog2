#include "Object.h"

#include <algorithm>
#include <vector>

using Sea::Coordinates;
using Sea::Object;
using Sea::Orientation;
using std::vector;

namespace Sea {

	Object::Object(Coordinates const& newCoordinates, const unsigned int newSize, const Orientation newOrientation) :
		Coordinates(newCoordinates),
		size(newSize),
		orientation(newOrientation) {}

	bool Object::atCoordinates(Coordinates const& coordinates) const {
		// TODO Aufgabe 2:
		//  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen
		//  Koordinaten (`coordinates`) liegt.

		vector<Coordinates> points = getAllCoordinates();
		return std::any_of(points.begin(), points.end(),
						   [&coordinates](Coordinates const& point) { return coordinates.samePositionAs(point); });
	}

	bool Object::intersectsWith(Object const& otherObject) const {
		// TODO Aufgabe 2:
		//  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt
		//  (`otherObject`) überschneiden.

		vector<Coordinates> points = otherObject.getAllCoordinates();
		return std::any_of(points.begin(), points.end(),
						   [this](Coordinates const& coordinates) { return atCoordinates(coordinates); });
	}

	vector<Coordinates> Object::getAllCoordinates() const {
		std::vector<Coordinates> coordinates;

		for (unsigned int offset = 0; offset < size; offset++) {
			if (orientation == Orientation::X) {
				coordinates.emplace_back(getX() + offset, getY());
			} else {
				coordinates.emplace_back(getX(), getY() + offset);
			}
		}

		return coordinates;
	}

} // namespace Sea
