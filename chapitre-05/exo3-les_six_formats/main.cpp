#include <iostream>
#include <string>
#include <vector>

struct Format {
    Format (std::string name, int bpp, bool c, bool t, bool f) : name(name), bpp(bpp), couleur(c), transparence(t), flottants(f){}
    
    std::string name;
    int bpp;
    bool couleur, transparence, flottants;

    long long CalculateMemory(int w, int h) {
        return w * h * bpp;
    }

    bool IsValid() {
        if (name != "GRAY8" && name != "GRAY_A16" && name != "RGB24" && name != "RGBA32" && name != "RGB96F" && name != "RGBA128F")  {
            return false;
        }

        return true;
    }

    static Format GRAY8()       { return Format("GRAY8",    1, false, false, false); };
    static Format GRAY_A16()    { return Format("GRAY_A16", 2, false, true, false); };
    static Format RGB24()       { return Format("RGB24",    3, true, false, false); };
    static Format RGBA32()      { return Format("RGBA32",   4, true, true, false); };
    static Format RGB96F()      { return Format("RGB96F",   12, true, false, true); };
    static Format RGBA128F()    { return Format("RGBA128F", 16, true, true, true); };
};

std::string ToUpper(const char* str) {
    if (!str) return "";

    std::string result(str);

    for (char& c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }

    return result;
}

Format GetFormatFromName(const std::string& fmt) {
    if (fmt == "GRAY8") {
        return Format::GRAY8();
    }
    else if (fmt == "GRAY_A16") {
        return Format::GRAY_A16();
    }
    else if (fmt == "RGB24") {
        return Format::RGB24();
    }
    else if (fmt == "RGBA32") {
        return Format::RGBA32();
    }
    else if (fmt == "RGB96F") {
        return Format::RGB96F();
    }
    else if (fmt == "RGBA128F") {
        return Format::RGBA128F();
    }
    else {
        return Format(fmt, 0, 0, 0, 0);
    }
}

std::string GetLosts(const Format& source, const Format& target) {
    std::string result = "AUCUNE";

    if (source.transparence && !target.transparence) {
        result = "TRANSPARENCE";
    } 

    if (source.couleur && !target.couleur) {
        if (result == "AUCUNE") { 
            result = "COULEUR";
        } else {
            result = result + "+COULEUR"; 
        }
    }
    
    if (source.flottants && !target.flottants) {
        if (result == "AUCUNE") { 
            result = "ETENDU"; 
        } else {
            result = result + "+ETENDU";
        }
    }

    return result;
}

int main () {
    int w, h, N;

    std::cin >> w >> h; 
    if (w < 1 || h < 1) return -1;

    std::cin >> N;

    std::vector<Format> sources, targets;
    for (int i=0; i<N; i++) {
        std::string source, target;
        std::cin >> source >> target;

        source = ToUpper(source.c_str());
        target = ToUpper(target.c_str());

        sources.push_back(GetFormatFromName(source));
        targets.push_back(GetFormatFromName(target));
    }

    long long total = 0; 
    int sans_pertes = 0, refuses = 0;
    for (int i=0; i<N; i++) {
        if (!sources[i].IsValid() || !targets[i].IsValid()) {
            std::cout << sources[i].name << " " << targets[i].name << " REFUSE" << std::endl;
            refuses++;
            continue;
        }

        long long source_memory = sources[i].CalculateMemory(w, h);
        long long target_memory = targets[i].CalculateMemory(w, h);

        std::string pertes = GetLosts(sources[i], targets[i]);
 
        if (pertes == "AUCUNE") {
            sans_pertes++;
        }
        total = total + target_memory;

        std::cout << sources[i].name << " " << targets[i].name
                  << " " << source_memory << " " << target_memory 
                  << " " << pertes << std::endl;
    }

    std::cout << "TOTAL " << total << std::endl;
    std::cout << "SANS_PERTE " << sans_pertes << std::endl;
    std::cout << "REFUSES " << refuses << std::endl;

    return 0;
}