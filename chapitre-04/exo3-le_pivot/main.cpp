#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Rectangle {
    std::string name = "";

    // position, scale, origin and size
    int w = 0, h = 0;
    int px = 0, py = 0;
    int ox = 0, oy = 0;
    int sx = 0, sy = 0;

    // angle
    int angle = 0;
    int c, s;

    int coins_locaux[8];
    int coins_global[8];
    int boites[4];

    void init() {
        DetermineUnitRotationVec();

        coins_locaux[0] = 0;
        coins_locaux[1] = 0;

        coins_locaux[2] = w;
        coins_locaux[3] = 0;

        coins_locaux[4] = w;
        coins_locaux[5] = h;

        coins_locaux[6] = 0;
        coins_locaux[7] = h;
    }

    void FindBoxCoord() {
        int min_x, min_y;
        int max_x, max_y;
        
        min_x = coins_global[0];
        min_y = coins_global[1];
        max_x = coins_global[0];
        max_y = coins_global[1];

        for(int i=2; i<8; i+=2) {
            min_x = std::min(min_x, coins_global[i]);
            min_y = std::min(min_y, coins_global[i+1]);

            max_x = std::max(max_x, coins_global[i]);
            max_y = std::max(max_y, coins_global[i+1]);
        }

        boites[0] = min_x;
        boites[1] = min_y;
        boites[2] = max_x;
        boites[3] = max_y;
    }

private:
    void DetermineUnitRotationVec() {
        int alpha;

        if (angle > 360) {
            alpha = angle - 360;
        } else if (angle < 0) {
            alpha = 360 + angle;
        } else {
            alpha = angle;
        }

        switch (alpha) {
        case 0: 
            c = 1, s = 0;
            break; 
        case 90:
            c = 0, s = 1;
            break;
        case 180:
            c = -1, s = 0;
            break;
        case 270:
            c = 0, s = -1;
            break;
        }
    }
};

void ScaleAndRotate(Rectangle& rect) {
    for (int i=0; i<8; i+=2) {
        int ax = (rect.coins_locaux[i] - rect.ox) * rect.sx;     // x-coordinates
        int ay = (rect.coins_locaux[i+1] - rect.oy) * rect.sy;   // y-coordinates

        int rx = ax * rect.c - ay * rect.s;
        int ry = ax * rect.s + ay * rect.c;

        rect.coins_global[i] = rect.px + rx;
        rect.coins_global[i+1] = rect.py + ry;
    }
}

void print_coins_global(const Rectangle& rect) {
    for (int i=0; i<8; i++) {
        std::cout << rect.coins_global[i] << " ";
    }
    std::cout << std::endl;
}

void print_boites(const Rectangle& rect) {
    for (int i=0; i<4; i++) {
        std::cout << rect.boites[i] << " ";
    }
    std::cout << std::endl;
}

int main () {
    int number;
    std::cin >> number;

    std::vector<Rectangle> rectangles;
    for (int i=0; i<number; i++) {
        Rectangle rectangle;
        std::cin >> rectangle.name >> rectangle.w >> rectangle.h
                 >> rectangle.px >> rectangle.py
                 >> rectangle.ox >> rectangle.oy
                 >> rectangle.sx >> rectangle.sy
                 >> rectangle.angle;

        rectangle.init();
        ScaleAndRotate(rectangle);
        rectangle.FindBoxCoord();

        rectangles.push_back(rectangle);
    }

    int refuses = 0;
    for (auto rectangle : rectangles) {
        if (rectangle.angle % 90 != 0) {
            std::cout << rectangle.name << " " << "ANGLE REFUSE" << std::endl;
            refuses++;
        } else { 
            std::cout << rectangle.name << " COINS ";
            print_coins_global(rectangle);

            std::cout << rectangle.name << " BOITE ";
            print_boites(rectangle);
        }
    }

    std::cout << "REFUSES " << refuses << std::endl;
    return 0;
}
