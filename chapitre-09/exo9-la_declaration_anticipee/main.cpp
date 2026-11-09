#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int u;
    cin >> u;

    vector<string> ordre;          // types dans l'ordre de première apparition
    map<string, bool> inclure;     // true si au moins un emploi exige la définition

    for (int i = 0; i < u; i++) {
        string type, emploi;
        cin >> type >> emploi;
        if (inclure.find(type) == inclure.end()) {
            inclure[type] = false;
            ordre.push_back(type);
        }
        if (emploi == "VALEUR" || emploi == "BASE" ||
            emploi == "CORPS" || emploi == "TAILLE") {
            inclure[type] = true;
        }
    }

    int a;
    cin >> a;
    set<string> inclus;
    for (int i = 0; i < a; i++) {
        string t;
        cin >> t;
        inclus.insert(t);
    }

    int nbInclure = 0, nbAnticiper = 0, retirees = 0;
    for (const string& t : ordre) {
        if (inclure[t]) {
            cout << t << " INCLURE\n";
            nbInclure++;
        } else {
            cout << t << " ANTICIPER\n";
            nbAnticiper++;
            if (inclus.count(t)) retirees++;
        }
    }

    cout << "INCLURE " << nbInclure << '\n';
    cout << "ANTICIPER " << nbAnticiper << '\n';
    cout << "INCLUSIONS_RETIREES " << retirees << '\n';
    return 0;
}