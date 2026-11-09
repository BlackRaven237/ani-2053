#include <iostream>
#include <vector>
#include <string>

std::string Trim(const std::string& str) {
    if (str.empty() || str.size() == std::string::npos) return "";

    std::string trim;
    const char* chaine = str.c_str();

    while (*chaine != '\0') {
        if (*chaine == ' ')
            continue;
        else if (*chaine == '/' && *(chaine+1) == '/')
            break;
        else
            trim.push_back(*chaine);
        chaine++;
    }

    return trim;
}

int main() {
    std::string class_name;    // Class name
    std::cin >> class_name;

    std::vector<std::string> members;
    std::string line;

    while(std::getline(std::cin, line)) {
        if (!line.empty()) {
            std::string d = Trim(line);
            members.push_back(d);
        }
    }

    for (auto& m : members) {
        std::cout << m << std::endl;
    }
    
    return 0;
}