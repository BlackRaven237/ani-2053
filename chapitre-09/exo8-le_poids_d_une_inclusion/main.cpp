#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

static bool finitPar(const string& s, const string& suf) {
    return s.size() >= suf.size() &&
           s.compare(s.size() - suf.size(), suf.size(), suf) == 0;
}

int main() {
    int n;
    cin >> n;
    vector<string> noms(n);
    vector<vector<string>> incs(n);
    map<string, int> index;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> noms[i] >> k;
        incs[i].resize(k);
        for (int j = 0; j < k; j++) cin >> incs[i][j];
        index[noms[i]] = i;
    }

    // inclusion inversée : includeurs[f] = fichiers qui incluent directement f
    vector<vector<int>> includeurs(n);
    for (int i = 0; i < n; i++) {
        for (const string& s : incs[i]) {
            auto it = index.find(s);
            if (it != index.end()) includeurs[it->second].push_back(i);
        }
    }

    vector<bool> estCpp(n), estH(n);
    for (int i = 0; i < n; i++) {
        estCpp[i] = finitPar(noms[i], ".cpp");
        estH[i] = finitPar(noms[i], ".h");
    }

    // nombre de .cpp à recompiler si le fichier f change
    auto compter = [&](int f) {
        vector<bool> vu(n, false);
        vector<int> pile;
        vu[f] = true;
        pile.push_back(f);
        int total = 0;
        while (!pile.empty()) {
            int x = pile.back();
            pile.pop_back();
            if (estCpp[x]) total++;
            for (int y : includeurs[x]) {
                if (!vu[y]) {
                    vu[y] = true;
                    pile.push_back(y);
                }
            }
        }
        return total;
    };

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string f;
        cin >> f;
        cout << f << ' ' << compter(index[f]) << '\n';
    }

    int meilleur = -1, meilleurR = -1;
    for (int i = 0; i < n; i++) {
        if (!estH[i]) continue;
        int r = compter(i);
        if (r > meilleurR) {
            meilleurR = r;
            meilleur = i;
        }
    }

    if (meilleur < 0) cout << "PLUS_LOURD AUCUN\n";
    else cout << "PLUS_LOURD " << noms[meilleur] << ' ' << meilleurR << '\n';
    return 0;
}