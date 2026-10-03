#include <iostream>
#include <math.h>
#include <vector>

#define pi 3.141592653589793

enum class Verdict {
    VISIBLE = 0,
    INVISIBLE,
    JAMAIS,
    REFUSE
};

const char* to_string(Verdict verdict) {
    switch (verdict) {
        case Verdict::VISIBLE : return "VISIBLE";
        case Verdict::INVISIBLE : return "INVISIBLE";
        case Verdict::REFUSE : return "REFUSE";
        case Verdict::JAMAIS : return "JAMAIS";
    }
}

struct Circle {
    int radius = 1;
    int segments = 1;

    Verdict verdict;
    int gap = 0;
    int zoom = 0;

    void calculate() {
        if (segments <= 2) {
            verdict = Verdict::REFUSE;
            return;
        }

        float g = radius * (1 - cos(pi / segments));
        gap = g * 1000;

        if (g == 0) {
            verdict = Verdict::JAMAIS;
            return;
        }

        zoom = (100 / g) + 1;

        if (zoom <= 100) {
            verdict = Verdict::VISIBLE;
        } else {
            verdict = Verdict::INVISIBLE;
        }
    }
};

int main() {
    int number;
    std::vector<Circle> circles;

    std::cin >> number; 

    for (int i=0; i<number; i++) {
        Circle circle;

        std::cin >> circle.radius >> circle.segments;

        circle.calculate();

        circles.push_back(circle);
    }

    int visibles = 0, refuses = 0;

    for (auto circle : circles) {
        if (circle.verdict == Verdict::JAMAIS) {
            std::cout << circle.radius << " " << circle.segments << " "
                      << circle.gap << " " << to_string(circle.verdict) << std::endl;

        } else if (circle.verdict == Verdict::REFUSE) {
            refuses++;

            std::cout << circle.radius << " " << circle.segments << " "
                      << to_string(circle.verdict) << std::endl;
        } else {
            if (circle.verdict == Verdict::VISIBLE) visibles++;

            std::cout << circle.radius << " " << circle.segments << " "
                      << circle.gap << " " << circle.zoom << " "
                      << to_string(circle.verdict) << std::endl;
        }
    }

    std::cout << "VISIBLES " << visibles << std::endl;
    std::cout << "REFUSES " << refuses << std::endl;

    return 0;
}
