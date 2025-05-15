#include "Missile.h"

// TODO Aufgabe 3:
//  Definiert die Funktionen der Klasse `Missile`.
namespace GameObjects {
	Missile::Missile(Coordinates const& coordinates) : Coordinates(coordinates) {}

	void Missile::hitSomething() {
		isHit = true;
	}

	bool Missile::hasHitSomething() const {
		return isHit;
	}


} // namespace GameObjects
