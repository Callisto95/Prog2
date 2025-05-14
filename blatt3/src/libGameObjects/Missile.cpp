#include "Missile.h"

// TODO Aufgabe 3:
//  Definiert die Funktionen der Klasse `Missile`.
namespace GameObjects {
	Missile::Missile(Coordinates const& coordinates) : Coordinates(coordinates), hit(false) {}

	void Missile::hitSomething() {
		hit = true;
	}

	bool Missile::hasHitSomething() const {
		return hit;
	}

} // namespace GameObjects
