//
// Created by Fred on 03/07/2018.
//

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>

using namespace std;

void eh_Primo(int limiteInf, int limiteSup);

int main(){
    int i;
    int pid;
    int lim_inf = 0, lim_sup = 0;

    cout << "Limite Inferior: " << endl;
    cin >> lim_inf;
    cout << "Limite Superior: " << endl;
    cin >> lim_sup;
    // Parent creates the first child.
    pid = fork();

    // Child 1 finds the prime numbers from 1 to 100.
    if(pid == 0)
        eh_Primo(lim_inf, 100);

        // Parent creates child 2.
    else if(pid > 0){
        pid = fork();

        // Child 2 finds prime numbers from 101 to 300
        if(pid == 0)
            eh_Primo(101, 300);
            // Parent creates child 3.
        else if(pid > 0){
            pid = fork();
            // Child 3 finds prime numbers
            // from 301 to 600
            if(pid == 0)
                eh_Primo(301, 600);

                // Parent creates child 4.
            else if(pid > 0){
                pid = fork();
                // Child 4 finds prime numbers
                // from 601 to 1000.
                if(pid == 0)
                    eh_Primo(601, lim_sup);
            }
        }
    }

    return 0;
}

void eh_Primo(int limiteInf, int limiteSup){
    int i, rem = 0, rem0, arraySize = 0;

    for(i = limiteInf; i <= limiteSup; i++){
        rem0 = 0;
        for (int numer = 1; numer <= i; numer++){
            rem = i % numer;
            if (rem == 0 && numer !=1 && numer != i){
                rem0++;
                break;
            }
        }
        if(rem0 == 0){
            cout << i << endl;
        }
    }
}
