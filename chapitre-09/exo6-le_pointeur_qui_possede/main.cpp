#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Ligne {
    string cmd;
    string a;
    string b;
};

static map<string, int> tient;   // variable -> numéro d'objet (0 = nul)
static vector<string> ordre;     // variables dans l'ordre de première apparition

static void vue(const string& v) {
    if (tient.find(v) == tient.end()) {
        tient[v] = 0;
        ordre.push_back(v);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Ligne> prog(n);
    vector<int> copies;

    for (int i = 0; i < n; i++) {
        cin >> prog[i].cmd >> prog[i].a;
        if (prog[i].cmd == "MOVE" || prog[i].cmd == "COPY") cin >> prog[i].b;
        if (prog[i].cmd == "COPY") copies.push_back(i + 1);
    }

    // Une copie empêche la compilation : on ne rejoue rien
    if (!copies.empty()) {
        for (int k : copies) cout << "REFUSE " << k << '\n';
        return 0;
    }

    int crees = 0, detruits = 0, nuls = 0;

    for (int i = 0; i < n; i++) {
        const Ligne& l = prog[i];
        int k = i + 1;

        if (l.cmd == "NEW") {
            vue(l.a);
            int nouveau = ++crees;
            int ancien = tient[l.a];
            if (ancien != 0) {
                cout << "DETRUIT " << ancien << '\n';
                detruits++;
            }
            tient[l.a] = nouveau;
        } else if (l.cmd == "MOVE") {
            vue(l.a);
            vue(l.b);
            int obj = tient[l.a];
            tient[l.a] = 0;
            int ancien = tient[l.b];
            if (ancien != 0) {
                cout << "DETRUIT " << ancien << '\n';
                detruits++;
            }
            tient[l.b] = obj;
        } else if (l.cmd == "RESET") {
            vue(l.a);
            int ancien = tient[l.a];
            if (ancien != 0) {
                cout << "DETRUIT " << ancien << '\n';
                detruits++;
            }
            tient[l.a] = 0;
        } else if (l.cmd == "USE") {
            vue(l.a);
            if (tient[l.a] == 0) {
                cout << "NUL " << k << ' ' << l.a << '\n';
                nuls++;
            }
        }
    }

    // Fin : les variables meurent dans l'ordre inverse de leur première apparition
    for (int i = (int)ordre.size() - 1; i >= 0; i--) {
        int obj = tient[ordre[i]];
        if (obj != 0) {
            cout << "DETRUIT " << obj << '\n';
            detruits++;
            tient[ordre[i]] = 0;
        }
    }

    cout << "CREES " << crees << '\n';
    cout << "DETRUITS " << detruits << '\n';
    cout << "NULS " << nuls << '\n';
    return 0;
}