#ifndef BLATT3_MISSILE_H
#define BLATT3_MISSILE_H


#include "Coordinates.h"


// TODO Aufgabe 3:
//  Implementiert die Klasse `Missile` als Erweiterung (Vererbung) der Klasse `Coordinates`, im Namensraum
//  `GameObjects`.
namespace GameObjects {

	class Missile : public Sea::Coordinates {
	protected:
		bool hit;

	public:
		// TODO Aufgabe 3:
		//  Deklariert einen Konstruktor, sodass Missiles mit `Coordinates` erstellt werden müssen.
		Missile(Coordinates const& coordinates);

		// TODO Aufgabe 3:
		//  Deklariert eine Funktion `void hitSomething()`, die diese Instanz als Treffer markiert.
		//  (Dazu ist eine zusätzliche Membervariable nötig)
		void hitSomething();

		// TODO Aufgabe 3:
		//  Deklariert eine Funktion `bool hasHitSomething() const`, die prüft, ob diese Instanz ein Treffer war.
		bool hasHitSomething() const;
	};
} // namespace GameObjects
// TODO Aufgabe 3:
//  Entfernt die Kommentar-Zeichen (//) vor `#define CLASS_MISSILE_COMPLETE` wenn Aufgabe 3 erledigt ist:
#define CLASS_MISSILE_COMPLETE


#endif // BLATT3_MISSILE_H
