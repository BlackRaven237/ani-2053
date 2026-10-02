#include <iostream>
#include <string>
#include <vector>

enum class unit {
    POINTS = 0,
    SEGMENTS,
    TRIANGLES,
    REFUSE
};

std::string ToString(unit u) {
    switch (u)
    {
        case unit::POINTS: return "POINTS";
        case unit::SEGMENTS: return "SEGMENTS";
        case unit::TRIANGLES: return "TRIANGLES";
        case unit::REFUSE: return "REFUSE";
    }
}

enum class PrimitiveType {
    POINTS = 0,
    LINES,
    LINE_STRIP,
    TRIANGLES,
    TRIANGLE_STRIP,
    TRIANGLE_FAN,
    NONE
};
struct Vertex {
    // Input
    int vertices = 0;
    std::string strType = "";

    // Output
    PrimitiveType pType;
    unit _unit;
    int count = 0;
    int left = 0;

    // Methods
    void SetPrimitiveType() {
        PrimitiveType type;

        if(strType == "POINTS") type = PrimitiveType::POINTS;
        else if (strType == "LINES") type = PrimitiveType::LINES;
        else if (strType == "LINE_STRIP") type = PrimitiveType::LINE_STRIP;
        else if (strType == "TRIANGLES") type = PrimitiveType::TRIANGLES;
        else if (strType == "TRIANGLE_FAN") type = PrimitiveType::TRIANGLE_FAN;
        else if (strType == "TRIANGLE_STRIP") type = PrimitiveType::TRIANGLE_STRIP;
        else type = PrimitiveType::NONE;

        pType = type;
        this->SetUnit(); // Setting current vertex unit
    }

private:
    void SetUnit() {
        switch (pType) {
            case PrimitiveType::LINES : _unit = unit::SEGMENTS; break;
            case PrimitiveType::LINE_STRIP : _unit = unit::SEGMENTS; break;
            case PrimitiveType::POINTS : _unit = unit::POINTS; break;
            case PrimitiveType::TRIANGLES : _unit = unit::TRIANGLES; break;
            case PrimitiveType::TRIANGLE_FAN : _unit = unit::TRIANGLES; break;
            case PrimitiveType::TRIANGLE_STRIP : _unit = unit::TRIANGLES; break;
            case PrimitiveType::NONE : _unit = unit::REFUSE; break;
        }
    }
};

void Output(Vertex& vertex) {
    PrimitiveType type = vertex.pType;
    int count = 0, left = 0;
    int s = vertex.vertices;

    if (type == PrimitiveType::POINTS) {
        count = s;
        left = 0;
    }
    if (type == PrimitiveType::LINES) {
        count = s / 2;
        left = s % 2;
    }
    if (type == PrimitiveType::LINE_STRIP) {
        if (s >= 2) {
            count = s - 1;
            left = 0;
        } else {
            count = 0;
            left = s;
        } 
    }
    if (type == PrimitiveType::TRIANGLES) {
        count = s / 3;
        left = s % 3;
    }
    if (type == PrimitiveType::TRIANGLE_STRIP || type == PrimitiveType::TRIANGLE_FAN) {
        if (s >= 3) {
            count = s - 2;
            left = 0;
        } else {
            count = 0;
            left = s;
        } 
    }

    vertex.count = count;
    vertex.left = left;
}

int main() {
    int number;
    std::vector<Vertex> vertexArray;

    // Read number
    std::cin >> number; 

    for (int i=0; i<number; i++) {
        Vertex vertex;

        std::cin >> vertex.strType >> vertex.vertices;

        vertex.SetPrimitiveType(); // Convert type from str -> primitive

        vertexArray.push_back(vertex);
    }

    // Calculate counts and lefts
    for (int i=0; i<number; i++) {
        Output(vertexArray[i]);
    }

    int points = 0, segments = 0, triangles = 0, refuses = 0;
    for (int i=0; i<number; i++) {
        if(vertexArray[i]._unit == unit::POINTS) points += vertexArray[i].count;
        if(vertexArray[i]._unit == unit::SEGMENTS) segments += vertexArray[i].count;
        if(vertexArray[i]._unit == unit::TRIANGLES) triangles += vertexArray[i].count;
        if(vertexArray[i]._unit == unit::REFUSE) refuses++;
    }

    std::cout << "" << std::endl;

    for (int i=0; i<number; i++) {
        if (vertexArray[i].pType == PrimitiveType::NONE) {
            std::cout << vertexArray[i].strType
                      << " " << vertexArray[i].vertices
                      << " " << ToString(vertexArray[i]._unit) << std::endl;
        } 
        else {
            std::cout << vertexArray[i].strType
                    << " " << vertexArray[i].vertices
                    << " " << vertexArray[i].count
                    << " " << ToString(vertexArray[i]._unit) 
                    << " " << vertexArray[i].left << std::endl;
        }
        
    }

    std::cout << "POINTS: " << points << std::endl;
    std::cout << "SEGMENTS: " << segments << std::endl;
    std::cout << "TRIANGLES: " << triangles << std::endl;
    std::cout << "REFUSES: " << refuses << std::endl;

    return 0;
}