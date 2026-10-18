#include "NKThreading/NkThread.h"
#include <iostream>

using namespace nkentseu::threading;

void count_task(long long& compteur) {
    for (int i=0; i<1000000; i++) {
        compteur += 1;
    }
} 

int main() {
    long long compteur = 0;

    NkThread thread1([&compteur](void*) {
        count_task(compteur);
    });

    NkThread thread2([&compteur](void*) {
        count_task(compteur);
    });

    NkThread thread3([&compteur](void*) {
        count_task(compteur);
    });

    NkThread thread4([&compteur](void*) {
        count_task(compteur);
    });

    NkThread thread5([&compteur](void*) {
        count_task(compteur);
    });

    NkThread thread6([&compteur](void*) {
        count_task(compteur);
    });

    NkThread thread7([&compteur](void*) {
        count_task(compteur);
    });

    NkThread thread8([&compteur](void*) {
        count_task(compteur);
    });

    thread1.Join();
    thread2.Join();
    thread3.Join();
    thread4.Join();
    thread5.Join();
    thread6.Join();
    thread7.Join();
    thread8.Join();

    std::cout << "Total: " << compteur << std::endl;
    std::cout << "Expected Total: " << (8 * 1000000) << std::endl;

    return 0;
}