#include <iostream>
#include <string>
#include <vector>

using int64 = long long;

struct Audio
{
    Audio(std::string name, int64 frequence, int canaux, int64 bits, int duree, int64 fichier) : 
            name(name), frequence(frequence), canaux(canaux), 
            bits(bits), duree(duree), fichier(fichier) {}

    std::string name;
    int canaux, duree;
    int64 frequence, bits, fichier; 
};

int64 CalculateBrut(const Audio& audio);

int main() {
    int64 S;
    std::cin >> S;

    int N;
    std::cin >> N;

    std::vector<Audio> audios;
    for (int i=0; i<N; i++) {
        std::string name;
        int canaux, duree;
        int64 frequence, bits, fichier; 

        std::cin >> name >> frequence >> canaux >> bits >> duree >> fichier;

        audios.push_back(Audio(name, frequence, canaux, bits, duree, fichier));
    }

    int refuses = 0, flux;
    int64 memoire = 0;

    for(auto& audio : audios) {
        if ((audio.bits % 8 != 0) || audio.bits > 32) {
            std::cout << audio.name << " REFUSE" << std::endl;
            refuses++;
            continue;
        }

        int64 brut = CalculateBrut(audio);
        int pourcent = (audio.fichier * 100) / brut;

        const char* lecture = ""; 
        if (brut <= S) {
            lecture = "MEMOIRE";
            memoire = memoire + brut;
        } else {
            lecture = "FLUX";
            flux++;
        }

        std::cout << audio.name << " " << brut << " " 
                  << pourcent << " " << lecture << std::endl;
    }

    std::cout << "MEMOIRE " << memoire << std::endl;
    std::cout << "FLUX " << flux << std::endl;
    std::cout << "REFUSES " << refuses << std::endl;

    return 0;
}

int64 CalculateBrut(const Audio& audio) {
    int64 result = audio.frequence * audio.canaux * (audio.bits / 8) * audio.duree;
    return result / 1000;
}