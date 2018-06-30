#include <cstdio>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <fstream>
#include <cmath>

using namespace std;

mutex mtx;
void printaPrimo(unsigned int limInf, unsigned int limSup);
void manageThreads(unsigned int limInferior, unsigned int limSuperior, unsigned int N);


int main(){
    unsigned int limInf = 0, limSup = 0;
    cout << "Limite Inferior: " << endl;
    cin >> limInf;
    cout << "Limite Superior: " << endl;
    cin >> limSup;
    if(limInf == 0){
        limInf = 1;
    }
    manageThreads(limInf, limSup, 10);
    return 0;
}

void manageThreads(unsigned int limInferior, unsigned int limSuperior, unsigned int N){
    clock_t comecaTimer, paraTimer;
    comecaTimer = clock();
    vector<thread> arr;
    unsigned int each = limSuperior/N;
    unsigned int start = limInferior;
    unsigned int finish = start + each - 1;
    for (unsigned int i = 0; i < N; i++){
        arr.emplace_back(printaPrimo, start, finish);
        start += each;
        finish += each;
    }
    for (auto& thread : arr){
        thread.join();
    }

    paraTimer = clock();
    cout << "Tempo de execucao: " << (double)(paraTimer - comecaTimer) / CLOCKS_PER_SEC << endl;
}

void printaPrimo(unsigned int limInf, unsigned int limSup){
    for (unsigned int i = limInf; i <= limSup; i++){
        for (unsigned int j = 2; j < i; j++){
            if (i % j == 0){
                break;
            }
            else if(j + 1 == i){
                mtx.lock();
                cout << i << endl;
                mtx.unlock();
            }
        }
    }
}