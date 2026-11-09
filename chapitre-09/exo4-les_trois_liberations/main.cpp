#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<bool> libere; // libere[t] vaut true si la texture t a déjà été libérée

// Libère `fois` fois la texture t. Retourne false si le programme meurt.
static bool liberer(int t, int fois) {
    for (int j = 0; j < fois; j++) {
        if (libere[t]) return false;
        libere[t] = true;
    }
    return true;
}

static void plantage(const string& k, int t) {
    cout << "PLANTAGE " << k << " TEXTURE " << t << '\n';
}

int main() {
    int S, V, F, n;
    cin >> S >> V >> F >> n;

    vector<int> tableau;
    libere.assign(1, false); // l'indice 0 est inutilisé
    int creees = 0;

    for (int op = 1; op <= n; op++) {
        string cmd;
        cin >> cmd;
        if (cmd == "AJOUTE") {
            creees++;
            libere.push_back(false);
            tableau.push_back(creees);
        } else if (cmd == "SUPPRIME") {
            int i;
            cin >> i;
            int t = tableau[i];
            if (!liberer(t, S)) {
                plantage(to_string(op), t);
                return 0;
            }
            tableau.erase(tableau.begin() + i);
        } else if (cmd == "VIDE") {
            for (int t : tableau) {
                if (!liberer(t, V)) {
                    plantage(to_string(op), t);
                    return 0;
                }
            }
            tableau.clear();
        }
    }

    for (int t : tableau) {
        if (!liberer(t, F)) {
            plantage("FIN", t);
            return 0;
        }
    }

    vector<int> perdues;
    for (int t = 1; t <= creees; t++)
        if (!libere[t]) perdues.push_back(t);

    cout << "CREEES " << creees << '\n';
    cout << "FUITES " << perdues.size() << '\n';
    cout << "PERDUES";
    if (perdues.empty()) {
        cout << " AUCUN";
    } else {
        for (int t : perdues) cout << ' ' << t;
    }
    cout << '\n';
    return 0;
}