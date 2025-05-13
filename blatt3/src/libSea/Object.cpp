#include "Object.h"

#include <algorithm>
#include <vector>

using Sea::Coordinates;
using Sea::Object;
using Sea::Orientation;
using std::vector;

vector<Coordinates> getAllCoordinates(Coordinates const& anchor, const unsigned int size,
									  Orientation const orientation) {

	std::vector<Coordinates> coordinates;

	for (unsigned int offset = 0; offset < size; offset++) {
		if (orientation == Orientation::X) {
			coordinates.emplace_back(anchor.getX() + offset, anchor.getY());
		} else {
			coordinates.emplace_back(anchor.getX(), anchor.getY() + offset);
		}
	}

	return coordinates;
}

namespace Sea {

	Object::Object(Coordinates const& newCoordinates, const unsigned int newSize, const Orientation newOrientation) :
		Coordinates(newCoordinates),
		size(newSize),
		orientation(newOrientation) {}

	bool Object::atCoordinates(Coordinates const& coordinates) const {
		// TODO Aufgabe 2:
		//  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen
		//  Koordinaten (`coordinates`) liegt.

		vector<Coordinates> points = getAllCoordinates(*this, size, orientation);
		return std::any_of(points.begin(), points.end(),
						   [&coordinates](Coordinates const& point) { return coordinates.samePositionAs(point); });
	}

	bool Object::intersectsWith(Object const& otherObject) const {
		// TODO Aufgabe 2:
		//  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt
		//  (`otherObject`) überschneiden.

		vector<Coordinates> points = getAllCoordinates(otherObject, otherObject.size, otherObject.orientation);
		return std::any_of(points.begin(), points.end(),atCoordinates);
	}

} // namespace Sea
