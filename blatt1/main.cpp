#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cout << "Hello, World!" << endl;

	cout << "Wir sind: " << team[0] << " ... " << team.at(teamSize) << endl;
	vector<string> team = {"Paddy", "Linda"}; // Vektor mit Startwerten
	team.emplace_back("Steve");				  // weiteren Wert zum Vektor hinzufügen
	team.emplace_back("Flo");				  // ...
	int teamSize = team.size();

	return 0;
}
