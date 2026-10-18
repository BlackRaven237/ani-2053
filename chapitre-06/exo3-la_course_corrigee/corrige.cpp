#include "NKThreading/NkThread.h"
#include "NKThreading/NkMutex.h"
#include "NKThreading/NkScopedLock.h"
#include "NKCore/NkAtomic.h"
#include "NKTime/NkChrono.h"

#include <iostream>

using namespace nkentseu;
using namespace nkentseu::threading;

void count_task(long long& compteur) {
    for (int i=0; i<1000000; i++) {
        compteur += 1;
    }
} 

int main() {
    NkChrono chrono;
    long long compteur1 = 0, compteur2 = 0, compteur3 = 0, compteur4 = 0, compteur5 = 0, compteur6 = 0, compteur7 = 0, compteur8 = 0;

    NkThread thread1([&compteur1](void*) {
        count_task(compteur1);
    });

    NkThread thread2([&compteur2](void*) {
        count_task(compteur2);
    });

    NkThread thread3([&compteur3](void*) {
        count_task(compteur3);
    });

    NkThread thread4([&compteur4](void*) {
        count_task(compteur4);
    });

    NkThread thread5([&compteur5](void*) {
        count_task(compteur5);
    });

    NkThread thread6([&compteur6](void*) {
        count_task(compteur6);
    });

    NkThread thread7([&compteur7](void*) {
        count_task(compteur7);
    });

    NkThread thread8([&compteur8](void*) {
        count_task(compteur8);
    });

    thread1.Join();
    thread2.Join();
    thread3.Join();
    thread4.Join();
    thread5.Join();
    thread6.Join();
    thread7.Join();
    thread8.Join();

    long long sum = compteur1 + compteur2 + compteur3 + compteur4 + compteur5 + compteur6 + compteur7 + compteur8;
    float64 elapsedTime = chrono.Elapsed().milliseconds;
    std::cout << "Time: " << elapsedTime << std::endl;
    std::cout << "Total: " << sum << std::endl;

    return 0;
}