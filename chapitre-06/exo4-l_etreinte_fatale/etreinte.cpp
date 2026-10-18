#include "NKThreading/NkThread.h"
#include "NKThreading/NkMutex.h"
#include "NKThreading/NkScopedLock.h"
#include "NKTime/NkChrono.h"

#include <iostream>

using namespace nkentseu;
using namespace nkentseu::threading;

NkMutex m1, m2;
void task(int& compteur) {
    for (int i=0; i<1000; i++) {
        compteur += 1;
    }
} 

int main() {
    int compteur = 0;

    NkThread a([&compteur](void*) {
        NkLockGuard lock1(m2);
        // NkLockGuard lock1(m1);
        
        NkChrono::SleepMilliseconds(100);

        NkLockGuard lock2(m1);
        // NkLockGuard lock1(m2);

        task(compteur);
    });

    NkThread b([&compteur](void*) {
        NkLockGuard lock1(m2);
        NkChrono::SleepMilliseconds(100);
        NkLockGuard lock2(m1);
        
        task(compteur);
    });

    a.Join();
    b.Join();

    std::cout << "Total: " << compteur << std::endl;

    return 0;
}