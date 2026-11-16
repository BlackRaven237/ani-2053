#include <iostream>
#include <string>
#include <vector>

struct Image {
    int id;
    float x, y, echelle, rotation, opacite;
    bool miroirX, miroirY, selectionne;
    size_t largeur, hauteur;
    std::string chemin;
    size_t octets;

};

int main() {
    int n;

    std::cin >> n;

    std::vector<Image> images;
    images.reserve(n);

    for (int i = 0; i < n; i++) {
        Image img;
        std::cin >> img.id
                 >> img.x >> img.y >> img.echelle >> img.rotation >> img.opacite
                 >> img.miroirX >> img.miroirY
                 >> img.largeur >> img.hauteur
                 >> img.selectionne
                 >> img.chemin
                 >> img.octets;
        images.push_back(img);
    }

    size_t restent = 0, changes = 0;
    int place = 0;
    for (size_t k = 0; k < images.size(); ++k) {
        const Image& img = images[k];
        if (img.octets == 0) {
            std::cout << "ITEM " << (k + 1) << " SAUTE\n";
            continue;
        }
        ++place;
        ++restent;

        std::cout << "ITEM " << place << " " << place << " ";
        bool premier = true;
        auto champ = [&](const char* nom) {
            if (!premier) std::cout << ' ';
            std::cout << nom;
            premier = false;
            ++changes;
        };

        if (img.id != 0) champ("id");
        if (img.selectionne) champ("selected");
        if (img.chemin != "-") champ("sourcePath");

        if (premier) std::cout << "AUCUN";
        std::cout << '\n';
    }

    std::cout << "RESTENT " << restent << '\n';
    std::cout << "CHANGES " << changes << '\n';

    return 0;
}