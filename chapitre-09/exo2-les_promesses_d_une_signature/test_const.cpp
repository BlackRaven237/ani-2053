#include "/home/coderaven/Desktop/Nkentseu/Applications/NkRef/src/NkRef/NkRefView.h"

int main() {
    const nkref::NkRefView vue{};

    vue.PixelToWorld({1.f, 0.f}, {2.f, 4.f});

    vue.GridSpacing(2.0f);

    // vue.PanByPixels(1.0f, 0.0f);

    // ╔══════════════════════════════════════════════════════════════════════════════════════════════╗
    // ║                              Compilation Error: test_const.cpp                               ║
    // ╠══════════════════════════════════════════════════════════════════════════════════════════════╣
    // ║ /home/coderaven/Desktop/ENSPY Notes/L2/Semestre I/ANI-2053 : Coder au service du Concept Art ║
    // ║ d’un Game Director                                                                           ║
    // ║ (Unreal)/ani-2053/chapitre-09/exo2-les_promesses_d_une_signature/test_const.cpp:10:5: error: ║
    // ║ 'this' argument to member function 'PanByPixels' has type 'const nkref::NkRefView', but      ║
    // ║ function is not marked const                                                                 ║
    // ║    10 |     vue.PanByPixels(1.0f, 0.0f);                                                     ║
    // ║       |     ^~~                                                                              ║
    // ║ /home/coderaven/Desktop/Nkentseu/Applications/NkRef/src/NkRef/NkRefView.h:45:9: note:        ║
    // ║ 'PanByPixels' declared here                                                                  ║
    // ║    45 |                         void PanByPixels(float32 dxPixels, float32 dyPixels) {       ║
    // ║       |                              ^                                                       ║
    // ║ 1 error generated.                                                                           ║
    // ╚══════════════════════════════════════════════════════════════════════════════════════════════╝

    
    return 0;
}