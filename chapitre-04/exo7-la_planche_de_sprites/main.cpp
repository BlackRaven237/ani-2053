#include <iostream>

int main() {
    long long C, R, W, H, F, D, P;
    if (!(std::cin >> C >> R >> W >> H >> F >> D >> P)) return 0;

    long long N = 0;
    std::cin >> N;

    long long cur = 0;      // case courante
    long long acc = 0;      // temps accumulé
    long long avances = 0;
    long long plafonnes = 0;

    for (long long i = 0; i < N; ++i) {
        long long dt;
        std::cin >> dt;

        if (dt > P) {
            dt = P;
            ++plafonnes;
        }

        acc += dt;

        while (acc >= D) {
            acc -= D;
            cur = (cur + 1) % F;
            ++avances;
        }

        long long x = (cur % C) * W;
        long long y = (cur / C) * H;
        std::cout << cur << " " << x << " " << y << " " << W << " " << H << "\n";
    }

    std::cout << "AVANCES " << avances << "\n";
    std::cout << "PLAFONNES " << plafonnes << "\n";
    return 0;
}