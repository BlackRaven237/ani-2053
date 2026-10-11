#include <iostream>
#include <cctype>
#include <string>
#include <vector>

enum class Format {
    PNG, JPEG, BMP,
    QOI, GIF, ICO,
    HDR, EXR, PBM, 
    PGM, PPM, TGA, 
    SVG, REFUSE
};

struct Image {
    Image(std::string _name, std::string _bytes, size_t _size) : name(_name), bytes(_bytes), size(_size) {}

    std::string name;
    std::string bytes;
    size_t size;
};

const char* ToString(const Format& fmt);
std::string ToUpper(const char* str);
std::string ToLower(const char* str);

std::string GetImageExtension(const std::string& name);
Format GetFormatFromExtension(const std::string& ext);
Format GetFormatFromBytes(const std::string& bytes, size_t size);

int main() {
    int N;
    std::cin >> N;

    std::vector<Image> images;
    for (int i=0; i<N; i++) {
        std::string name, bytes;
        size_t size;

        std::cin >> name >> size >> bytes;

        images.push_back(Image(name, bytes, size));
    }

    int lus = 0, mesonges = 0, refuses = 0;
    for (auto& image : images) {
        Format fmt, real;

        std::string ext = GetImageExtension(image.name);
        fmt = GetFormatFromExtension(ext);
        real = GetFormatFromBytes(ToUpper(image.bytes.c_str()), image.size);

        if (real == Format::REFUSE) {
            refuses++;
            std::cout << image.name << " " << ToString(real) << std::endl;
        }
        else {
            lus++;
            if (fmt != real) {
                mesonges++;
            }

            const char* verdict = (fmt == real) ? "OK" : "MENT";

            std::cout << image.name << " " << ToString(real) << " " << verdict << std::endl;
        }
    }

    std::cout << "LUS " << lus << std::endl;
    std::cout << "MENSONGES " << mesonges << std::endl;
    std::cout << "REFUSES " << refuses << std::endl;
    
    return 0;
}

std::string ToUpper(const char* str) {
    if (!str) return "";

    std::string result(str);

    for (char& c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }

    return result;
}

std::string ToLower(const char* str) {
    if (!str) return "";

    std::string result(str);

    for (char& c : result) {
        c = std::tolower(static_cast<unsigned char>(c));
    }

    return result;
}

const char* ToString(const Format& fmt) {
    switch (fmt) {
        case Format::PNG: return "PNG";
        case Format::JPEG: return "JPEG";
        case Format::BMP: return "BMP";
        case Format::QOI: return "QOI";
        case Format::GIF: return "GIF";
        case Format::ICO: return "ICO";
        case Format::HDR: return "HDR";
        case Format::EXR: return "EXR";
        case Format::PBM: return "PBM";
        case Format::PGM: return "PGM";
        case Format::PPM: return "PPM";
        case Format::TGA: return "TGA";
        case Format::SVG: return "SVG";
        case Format::REFUSE: return "REFUSE";
    }
}

std::string GetImageExtension(const std::string& name) {
    if (name == "-") {
        return "";
    }

    size_t begin = name.find_last_of('.');
    size_t end = name.size();

    std::string ext = name.substr(begin, end);

    return ToLower(ext.c_str());
}

Format GetFormatFromExtension(const std::string& ext) {
    if (ext == ".jpg" || ext == ".jpeg")
        return Format::JPEG;
    else if (ext == ".png")
        return Format::PNG;
    else if (ext == ".bmp")
        return Format::BMP;
    else if (ext == ".qoi")
        return Format::QOI;
    else if (ext == ".gif")
        return Format::GIF;
    else if (ext == ".ico" || ext == ".cur")
        return Format::ICO;
    else if (ext == ".hdr")
        return Format::HDR;
    else if (ext == ".exr")
        return Format::EXR;
    else if (ext == ".pbm") 
        return Format::PBM;
    else if (ext == ".pgm")
        return Format::PGM;
    else if (ext == ".ppm")
        return Format::PPM;
    else if (ext == ".tga")
        return Format::TGA;
    else if (ext == ".svg")
        return Format::SVG;
    else
        return Format::REFUSE;
}

Format GetFormatFromBytes(const std::string& bytes, size_t size) {
    if (size < 4) {
        return Format::REFUSE;
    }

    int sz = bytes.size();

    std::vector<std::string> b;
    for (size_t i=0; i<sz; i+=2) {
        std::string substr = bytes.substr(i, 2);
        b.push_back(substr);
    }

    if (size >= 8 && b[0] == "89" && b[1] == "50" && b[2] == "4E" && b[3] == "47") {
        return Format::PNG;
    }
    else if (b[0] == "FF" && b[1] == "D8" && b[2] == "FF") {
        return Format::JPEG;
    }
    else if (b[0] == "42" && b[1] == "4D") {
        return Format::BMP;
    }
    else if (b[0] == "89" && b[1] == "50" && b[2] == "4E" && b[3] == "47") {
        return Format::QOI;
    }
    else if (b[0] == "47" && b[1] == "49" && b[2] == "46" && b[3] == "38") {
        return Format::GIF;
    }
    else if (b[0] == "00" && b[1] == "00" && (b[2] == "01" || b[2] == "02") && b[3] == "00") {
        return Format::ICO;
    }
    else if (size >= 10 && b[0] == "23" && b[1] == "3F") {
        return Format::HDR;
    }
    else if (b[0] == "76" && b[1] == "2F" && b[2] == "31" && b[3] == "01") {
        return Format::EXR;
    }
    else if (size >= 18 && (b[2] == "00" || b[2] == "01" || b[2] == "02" || b[2] == "03" || b[2] == "09" || b[2] == "0A" || b[2] == "0B")) {
        return Format::TGA;
    }
    else if (b[0] == "50" && (b[1] == "31" || b[1] == "32" || b[1] == "33" || b[1] == "34" || b[1] == "35" || b[1] == "36")) {
        if (b[1] == "31" || b[1] == "34") {
            return Format::PBM;
        }
        else if (b[1] == "32" || b[1] == "35") {
            return Format::PGM;
        }
        else {
            return Format::PPM;
        }
    }

    else if ((b[0] == "3C" && b[1] == "3F" && b[2] == "78" && b[3] == "6D" && b[4] == "6C") || (b[0] == "3C" && b[1] == "73" && b[2] == "76" && b[3] == "67")) {
        return Format::SVG;
    }

    else {
        std::vector<std::string> str;
        for (size_t i=0; i < b.size(); i++) {
            if (b[0] == "EF" && b[1] == "BB" && b[2] == "BF") {
                continue;
            } 
            if (b[i] == "20" || b[i] == "09" || b[i] == "0A" || b[i] == "0D") {
                continue;
            }

            str.push_back(b[i]);
        }

        // if ((str[0] == "3C" && str[1] == "3F" && str[2] == "78" && str[3] == "6D" && str[4] == "6C") || (str[0] == "3C" && str[1] == "73" && str[2] == "76" && str[3] == "67")) {
        //     return Format::SVG;
        // }
        
        return Format::REFUSE;
    }

}
