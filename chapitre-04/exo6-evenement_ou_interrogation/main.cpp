#include <iostream>
#include <string>

int main() {
    long long v = 0;
    int n = 0;
    if (!(std::cin >> v >> n)) {
        n = 0;
    }

    bool space = false, left = false, right = false;
    long long xe = 0, xi = 0;
    long long sautsE = 0, sautsI = 0, manques = 0;

    for (int i = 1; i <= n; ++i) {
        int k = 0;
        std::cin >> k;
        int plusSpace = 0;

        for (int j = 0; j < k; ++j) {
            std::string e;
            std::cin >> e;
            if (e.empty()) continue;
            char signe = e[0];
            std::string nom = e.substr(1);
            bool appui = (signe == '+');

            if (nom == "SPACE") {
                space = appui;
                if (appui) {
                    ++sautsE;
                    ++plusSpace;
                }
            } else if (nom == "RIGHT") {
                right = appui;
                if (appui) xe += v;
            } else if (nom == "LEFT") {
                left = appui;
                if (appui) xe -= v;
            }
        }

        // Interrogation : une seule fois, après les événements
        if (space) ++sautsI;
        if (right) xi += v;
        if (left) xi -= v;

        // Appuis manqués : SPACE n'est plus enfoncée à la fin de l'image
        if (!space) manques += plusSpace;

        std::cout << i << ' ' << xe << ' ' << xi << '\n';
    }

    std::cout << "SAUTS EVENEMENTS " << sautsE << '\n';
    std::cout << "SAUTS INTERROGATION " << sautsI << '\n';
    std::cout << "MANQUES " << manques << '\n';
    return 0;
}