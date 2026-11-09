#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Methode {
    string nom;
    bool declaree;
    bool modifie;
    vector<int> appels;
};

static vector<Methode> m;
static vector<int> etat; // 0 = inconnu, 1 = oui, 2 = non

static bool pourraitEtreConst(int i) {
    if (etat[i] != 0) return etat[i] == 1;
    bool ok;
    if (m[i].declaree) {
        ok = true;
    } else if (m[i].modifie) {
        ok = false;
    } else {
        ok = true;
        for (int a : m[i].appels) {
            if (!pourraitEtreConst(a)) { ok = false; break; }
        }
    }
    etat[i] = ok ? 1 : 2;
    return ok;
}

static void afficher(const string& titre, const vector<int>& liste) {
    cout << titre;
    if (liste.empty()) {
        cout << " AUCUN";
    } else {
        for (int i : liste) cout << ' ' << m[i].nom;
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    m.resize(n);
    map<string, int> index;
    vector<vector<string>> noms(n);

    for (int i = 0; i < n; i++) {
        string decl;
        int modif, k;
        cin >> m[i].nom >> decl >> modif >> k;
        m[i].declaree = (decl == "const");
        m[i].modifie = (modif == 1);
        noms[i].resize(k);
        for (int j = 0; j < k; j++) cin >> noms[i][j];
        index[m[i].nom] = i;
    }
    for (int i = 0; i < n; i++)
        for (const string& s : noms[i]) m[i].appels.push_back(index[s]);

    etat.assign(n, 0);

    vector<int> pourrait;
    for (int i = 0; i < n; i++)
        if (!m[i].declaree && pourraitEtreConst(i)) pourrait.push_back(i);

    vector<bool> const_(n);
    for (int i = 0; i < n; i++) const_[i] = m[i].declaree;

    vector<int> racines;
    for (int i : pourrait) {
        bool racine = true;
        for (int a : m[i].appels)
            if (!const_[a]) { racine = false; break; }
        if (racine) racines.push_back(i);
    }

    // Passes simultanées
    int passes = 0;
    size_t restantes = pourrait.size();
    while (restantes > 0) {
        vector<int> cetEtage;
        for (int i : pourrait) {
            if (const_[i]) continue;
            bool pret = true;
            for (int a : m[i].appels)
                if (!const_[a]) { pret = false; break; }
            if (pret) cetEtage.push_back(i);
        }
        if (cetEtage.empty()) break; // sécurité, ne devrait pas arriver
        for (int i : cetEtage) const_[i] = true;
        restantes -= cetEtage.size();
        passes++;
    }

    afficher("POURRAIT", pourrait);
    afficher("RACINES", racines);
    cout << "PASSES " << passes << '\n';
    return 0;
}