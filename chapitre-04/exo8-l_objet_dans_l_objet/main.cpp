#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Object {
public:
    Object() {}

    Object(std::string name, std::string parent_name, int tx, int ty, int angle, int scale) {
        this->name = name;
        this->parent_name = parent_name;
        this->tx = tx;
        this->ty = ty;
        this->angle = angle;
        this->scale = scale;
    }

    std::string GetName() {
        return name;
    }

    std::string GetParentName() {
        return parent_name;
    }

    void PlaceInWorld(const Object& parent) {
        int ax = tx * parent.scale;
        int ay = ty * parent.scale;

        DetermineUnitRotationVec(parent.angle);

        int rx = ax * c - ay * s;
        int ry = ax * s + ay * c;

        tx = parent.tx + rx;
        ty = parent.ty + ry;

        angle = angle + parent.angle;
        
        if (angle < 0) {
            angle = 0;
        }
        if (angle >= 270) {
            angle = 270;
        }

        scale = scale * parent.scale;
        level = parent.level + 1;
    }

private:
    std::string name;
    std::string parent_name;

    int c = 0, s = 0;
    void DetermineUnitRotationVec(int _angle) {
        int alpha;

        if (_angle > 360) {
            alpha = _angle - 360;
        } else if (angle < 0) {
            alpha = 360 + _angle;
        } else {
            alpha = _angle;
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
public:
    int tx, ty;
    int angle;
    int scale;
    int level;
};

Object SearchParent(std::string name, std::vector<Object>& objs) {
    for (auto& obj : objs) {
        if (name == obj.GetName()) {
            return obj; 
        }
    }
    return Object();
}

int main () {
    int number = 0;

    std::cin >> number;

    std::vector<Object> objects;

    /// Input
    for (int i=0; i<number; i++) {
        std::string name, parent_name;
        int tx, ty, angle, scale;

        std::cin >> name >> parent_name >> tx >> ty >> angle >> scale;

        objects.push_back(Object(name, parent_name, tx, ty, angle, scale));
    }

    /// Computation
    for(auto& obj : objects) {
        std::string parent_name = obj.GetParentName();

        if (parent_name == "-") {
            continue;
        } else {
            Object parent = SearchParent(parent_name, objects);

            obj.PlaceInWorld(parent);
        }
    }

    /// Output
    for (auto& obj : objects) {
        std::cout << obj.GetName() << " " << obj.tx << " "
                  << obj.ty << " " << obj.angle << " "
                  << obj.scale << std::endl;
    }

    int level = objects[0].level;
    for (int i=1; i<number; i++) {
        level = std::max(level, objects[i].level);
    }

    std::cout << "PROFONDEUR " << level + 1 << std::endl;
    return 0;
}
