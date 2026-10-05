#include <iostream>
#include <algorithm>
#include <vector>

enum class PolicyType 
{
    FOLLOW_WINDOW = 0,
    STRETCH,
    FIT_LETTERBOX,
    INTEGER_SCALE,
    FIT_CROP,
    MANUAL
};

const char* ToString(PolicyType type) {
    switch (type)
    {
    case PolicyType::FOLLOW_WINDOW:
        return "FOLLOW_WINDOW";

    case PolicyType::STRETCH:
        return "STRETCH";

    case PolicyType::FIT_LETTERBOX:
        return "FIT_LETTERBOX";

    case PolicyType::INTEGER_SCALE:
        return "INTEGER_SCALE";

    case PolicyType::FIT_CROP:
        return "FIT_CROP";

    case PolicyType::MANUAL:
        return "MANUAL";
    }
}
struct Policy
{
    Policy(int _vx, int _vy, int _vw, int _vh,
           int _mw, int _mh,
           PolicyType _type) 
    {
        this->vx = _vx;
        this->vy = _vy;
        this->vw = _vw;
        this->vh = _vh;
        this->mw = _mw;
        this->mh = _mh;
        this->type = _type;
    }

    PolicyType type;

    int vx, vy, vw, vh;
    int mw, mh;
};
struct Window 
{
    int RW = 0, RH = 0;     // reference size
    int AW = 1, AH = 1;     // last size
    int W = 1, H = 1;       // current size
};

void Read(Window& window) {
    std::cin >> window.RW >> window.RH >> window.AW
             >> window.AH >> window.W >> window.H;
};

int Round(int a, int b) {
    if (b == 0) return 0;

    return (2 * a + b) / (2 * b);
}

Policy FOLLOW_WINDOW(const Window& window, PolicyType type = PolicyType::FOLLOW_WINDOW) {
    int vx = 0, vy = 0;
    int vw = window.W, vh = window.H;
    int mw = window.W, mh = window.H;

    return Policy(vx, vy, vw, vh, mw, mh, type);
}

Policy STRETCH(const Window& window) {
    if (window.RW == 0 || window.RH == 0) {
        return FOLLOW_WINDOW(window, PolicyType::STRETCH);
    }
    
    int vx = 0, vy = 0;
    int vw = window.W, vh = window.H;
    int mw = window.RW, mh = window.RH;

    return Policy(vx, vy, vw, vh, mw, mh, PolicyType::STRETCH);
}

Policy FIT_LETTERBOX(const Window& window) {
    if (window.RW == 0 || window.RH == 0) {
        return FOLLOW_WINDOW(window, PolicyType::FIT_LETTERBOX);
    }

    int vx = 0, vy = 0, vw = 0, vh = 0;
    int mw = 0, mh = 0;

    if ((window.W * window.RH) <= (window.H * window.RW)) {
        vw = window.W;
        vh = Round(window.RH * window.W, window.RW);
    } else {
        vh = window.H;
        vh = Round(window.RW * window.H, window.RH);
    }

    vx = (window.W - vw) / 2;
    vy = (window.H - vh) / 2;

    mw = window.RW, mh = window.RH;

    return Policy(vx, vy, vw, vh, mw, mh, PolicyType::FIT_LETTERBOX);
}

Policy INTEGER_SCALE(const Window& window) {
    if (window.RW == 0 || window.RH == 0) {
        return FOLLOW_WINDOW(window, PolicyType::INTEGER_SCALE);
    }

    int vx = 0, vy = 0, vw = 0, vh = 0;
    int mw = 0, mh = 0;

    if (window.W >= window.RW && window.H >= window.RH) {
        int k = std::min(window.W / window.RW, window.H / window.RH);

        vw = window.RW * k;
        vh = window.RH * k;
    } else {
        if (window.W * window.RH <= window.H * window.RW) {
            vw = window.W;
            vh = Round(window.RH * window.W, window.RW);
        } else {
            vh = window.H;
            vh = Round(window.RW * window.H, window.RH);
        }
    }

    vx = (window.W - vw) / 2;
    vy = (window.H - vh) / 2;

    mw = window.RW, mh = window.RH;

    return Policy(vx, vy, vw, vh, mw, mh, PolicyType::INTEGER_SCALE);
}

Policy FIT_CROP(const Window& window) {
    if (window.RW == 0 || window.RH == 0) {
        return FOLLOW_WINDOW(window, PolicyType::FIT_CROP);
    }

    int vx = 0, vy = 0;
    int vw = window.W, vh = window.H;
    int mw = 0, mh = 0;

    if (window.W * window.RH > window.H * window.RW) {
        mw = window.RW; 
        mh = Round(window.RW * window.H, window.W);
    } else {
        mh = window.RH; 
        mw = Round(window.RH * window.W, window.H);
    }

    return Policy(vx, vy, vw, vh, mw, mh, PolicyType::FIT_CROP);
}

Policy MANUAL(const Window& window) {
    int vx = 0, vy = 0;
    int vw = window.AW, vh = window.AH;
    int mw = window.AW, mh = window.AH;

    return Policy(vx, vy, vw, vh, mw, mh, PolicyType::MANUAL);
}

std::vector<Policy> CalculatePolicyValues(const Window& window) {

    return { FOLLOW_WINDOW(window), STRETCH(window), 
             FIT_LETTERBOX(window), INTEGER_SCALE(window),
             FIT_CROP(window), MANUAL(window)
           };
}

int main() {
    /// Input
    Window window;
    Read(window);

    /// Computation
    auto policies = CalculatePolicyValues(window);

    int bandes = 0;
    for (auto& policy : policies) {
        if (policy.vy < window.W && policy.vh < window.H) {
            bandes++;
        }
    }

    const char* deformation = "NON";
    if ((window.RW != 0 || window.RW != 0) && (window.W * window.RH != window.H * window.RW)) {
        deformation = "OUI";
    }

    /// Output
    for (auto& policy : policies) {
        std::cout << ToString(policy.type) << " " << policy.vx << " "
                  << policy.vy << " " << policy.vw << " "
                  << policy.vh << " " << policy.mw << " "
                  << policy.mh << "\n";
    }

    std::cout << "BANDES " << bandes << std::endl;
    std::cout << "DEFORMATION " << deformation << std::endl;

    return 0;
}
