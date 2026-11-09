#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

static set<string> libere;
static vector<pair<string, string>> deps; // (a, b) dans l'ordre de lecture

// Libère a. Retourne false si le programme meurt (PLANTAGE déjà affiché).
static bool liberer(const string& a, const string& mot) {
    if (libere.count(a)) return true; // déjà libéré : rien à faire
    for (const auto& d : deps) {
        if (d.first == a && libere.count(d.second)) {
            cout << "PLANTAGE " << a << ' ' << d.second << '\n';
            return false;
        }
    }
    libere.insert(a);
    cout << mot << ' ' << a << '\n';
    return true;
}

// Détruit tous les objets d'un bloc, du dernier déclaré au premier.
static bool fermerBloc(const vector<string>& bloc) {
    for (int i = (int)bloc.size() - 1; i >= 0; i--) {
        if (!liberer(bloc[i], "DETRUIT")) return false;
    }
    return true;
}

int main() {
    vector<vector<string>> blocs;
    blocs.push_back({}); // bloc de la fonction

    string ligne;
    while (getline(cin, ligne)) {
        istringstream iss(ligne);
        string cmd;
        if (!(iss >> cmd)) continue; // ligne vide

        if (cmd == "DECL") {
            string x;
            iss >> x;
            blocs.back().push_back(x);
        } else if (cmd == "DEPEND") {
            string a, b;
            iss >> a >> b;
            deps.push_back({a, b});
        } else if (cmd == "FERME") {
            string x;
            iss >> x;
            if (!liberer(x, "FERME")) return 0;
        } else if (cmd == "{") {
            blocs.push_back({});
        } else if (cmd == "}") {
            vector<string> bloc = blocs.back();
            blocs.pop_back();
            if (!fermerBloc(bloc)) return 0;
        }
    }

    // Fin de l'entrée : fermeture du bloc de la fonction
    if (!fermerBloc(blocs.back())) return 0;

    cout << "PROPRE\n";
    return 0;
}