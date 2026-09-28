#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventDispatcher.h"

using namespace nkentseu;

void ReverseRGBA(NkVector<uint8>& pixel);
void Reverse(NkVector<uint8>& pixels);

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;

    cfg.title  = "My window";
    cfg.width  = 800;
    cfg.height = 640;

    cfg.resizable     = true;
    cfg.movable       = true;
    cfg.closable      = true;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[app] window creation failed");
        return -1;
    }

    while (window.IsOpen()) { 
        /* events come here */

        while (NkEvent* ev = NkEvents().PollEvent()) {
            // ev points to current event
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) window.Close();

                // Ctrl + v
                else if (kp->HasCtrl() && kp->GetKey() == NkKey::NK_V) {
                    // // Get text from clipboard
                    // NkString text = window.GetClipboardText();

                    // // Set text to upper
                    // text.ToUpper();

                    // // Set text to clipboard
                    // window.SetClipboardText(text);

                    // // Log Text
                    // logger.Info("text : {0}", text);

                    NkClipboardImage image;

                    if (!window.GetClipboardImage(image)) {
                        logger.Error("No image copied from clipboard");
                    } 
                    else {
                        Reverse(image.pixels);

                        window.SetClipboardImage(image);

                        logger.Info("Image : width {0}, height {1} \n", 
                                                    image.width, 
                                                    image.height, 
                                                    "Pixels - r: {2}, g: {3}, b: {4}, a: {5}", 
                                                    image.pixels[0], image.pixels[1],
                                                    image.pixels[2], image.pixels[3]
                        );
                    }
                }
            }
        }
    }

    return 0;
}

void Reverse(NkVector<uint8>& pixels) {
    size_t size = pixels.Size();
    
    for (size_t i = 0; i < size; i += 4) {
        NkVector<uint8> pixel;

        for (int j=0; j < 4; j++) {
            pixel.PushBack(pixels[i + j]);
        }

        ReverseRGBA(pixel);
    }
}

void ReverseRGBA(NkVector<uint8>& pixel) {
    // We don't need to reverse `alpha`
    size_t size = pixel.Size() - 1;

    for (size_t i=0; i < size / 2; ++i) {
        uint8 temp = pixel[i];
        pixel[i] = pixel[size - 1 - i];
        pixel[size - 1 - i] = temp;
    };
}