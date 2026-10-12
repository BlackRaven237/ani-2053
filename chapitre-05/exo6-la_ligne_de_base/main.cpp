#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct Character {
    Character(char c, int avance, int x0, int y0, int x1, int y1) : c(c), avance(avance), x0(x0), y0(y0), x1(x1), y1(y1) {}

    char c;
    int avance;
    int x0, y0, x1, y1;
};


struct Pair {
    Pair(std::string ab, int k) : ab(ab), k(k) {}

    std::string ab;
    int k;
};

bool IsCharacterInList(char c, const std::vector<Character>& characters) {
    for (auto& ch : characters) {
        if (ch.c == c) {
            return true;
        }
    }
    return false;
}

void GetStepAndRectangle(const std::vector<Character>& chs, char c, int& avance, int& x0, int& y0, int& x1, int& y1) {
    for (auto& ch : chs) {
        if (ch.c == c) {
            avance = ch.avance;
            x0 = ch.x0;
            y0 = ch.y0;
            x1 = ch.x1;
            y1 = ch.y1;

            return;
        }
    }
}

int GetCorrection(char ch, char next, const std::vector<Pair>& pairs) {
    std::string _pair = "";
    _pair = _pair + ch + next;

    for (auto& pair : pairs) {
        if (pair.ab == _pair) {;
            return pair.k;
        }
    }
    return 0;
}

int main () {
    int G;
    std::cin >> G;

    std::vector<Character> characters;
    for (int i=0; i<G; i++) {
        char c;
        int avance, x0, y0, x1, y1;

        std::cin >> c >> avance >> x0 >> y0 >> x1 >> y1;

        characters.push_back(Character(c, avance, x0, y0, x1, y1));
    }

    int K;
    std::cin >> K;

    std::vector<Pair> pairs;
    for (int i=0; i<K; i++) {
        std::string ab;
        int k;
        std::cin >> ab >> k;

        pairs.push_back(Pair(ab, k));
    }

    std::string texte;
    int ox, oy;
    std::cin >> texte >> ox >> oy;

    int absent = 0, maxx = 0, maxy = 0;

    int minx = characters[0].x0 + ox;
    int miny = characters[0].y0 + oy;

    int x = ox;
    for (size_t i=0; i<texte.size(); i++) {
        if (!IsCharacterInList(texte[i], characters)) {
            std::cout << texte[i] << " ABSENT" << std::endl;
            absent++;
            continue;
        }

        std::cout << texte[i] << " " << x << std::endl;

        int avance = 0, x0 = 0, x1 = 0, y0 = 0, y1 = 0;

        GetStepAndRectangle(characters, texte[i], avance, x0, y0, x1, y1);

        if ((x1 > x0) && (y1 > y0)) {
            x0 = x + x0;
            y0 = oy + y0;

            x1 = x + x1;
            y1 = oy + y1;

            minx = std::min(minx, x0);
            miny = std::min(miny, y0);

            maxx = std::max(maxx, x1);
            maxy = std::max(maxy, y1);
        }

        x = x + avance;

        int k = GetCorrection(texte[i], texte[i+1], pairs);
        
        //std::cout << "\n Correction: " << k << "\n";

        x = x + k;
    }

    int monte = (miny < oy) ? (oy - miny) : 0;
    int descend = (maxy > oy) ? (maxy - oy) : 0;

    const char* ecran = (maxy <= 0) ? "HORS" : ((miny < 0) ? "COUPE" : "VISIBLE");

    if (x != ox) {
        std::cout << "CURSEUR " << x << std::endl;
    }
    
    if (maxx == 0 || maxy == 0) {
        std::cout << "BOITE " << "AUCUNE" << std::endl;
        ecran = "RIEN";
    } else {
        std::cout << "BOITE " << minx << " " << miny << " " << maxx << " " << maxy << std::endl;
    }
    
    std::cout << "MONTE " << monte << std::endl;
    std::cout << "DESCEND " << descend << std::endl;
    std::cout << "ECRAN " << ecran << std::endl;
    std::cout << "ABSENTS " << absent << std::endl;

    return 0;
}
