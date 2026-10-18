#include "NKThreading/NkThread.h"
#include "NKThreading/NkThreadPool.h"
#include "NKTime/NkChrono.h"

#include <iostream>

using namespace nkentseu;
using namespace nkentseu::threading;

void sum_task(int a) {
    int sum = 0;
    for (int i=0; i < (1000*100); ++i) {
        sum += i;
    }

    sum = sum * a;
}

void DoWorkUsingPool() {
    NkThreadPool pool(4);

    for (int i=0; i < 200; ++i) {
        pool.Enqueue([i](){
            sum_task(i);
        }); 
    }

    pool.Join();
}

void DoWorkUsingThreads() {
    for (int i=0; i<200; ++i) {
        NkThread worker([i](void*) {
            sum_task(i);
        });

        worker.Join();
    } 
}

int main() {
    NkChrono chrono;

    DoWorkUsingPool();

    float64 elapsedTime = chrono.Elapsed().milliseconds;

    std::cout << "Time: " << elapsedTime << std::endl;

    return 0;
}