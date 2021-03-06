//
// Created by Fred on 03/07/2018.
//

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void eh_Primo(int limiteInf, int limiteSup);
void forkExe();

int main(){
    forkExe();
    return 0;
}

void eh_Primo(int limiteInf, int limiteSup){
    int i, rem = 0, rem0;
    clock_t comecaTimer, paraTimer;
    comecaTimer = clock();
 
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
    paraTimer = clock();
    cout << "Tempo de execucao: " << (double)(paraTimer - comecaTimer) / CLOCKS_PER_SEC << endl;
}


void forkExe(){
    int pid;
    
    pid = fork();

    if(pid == 0){
        eh_Primo(1, 100);
        waitpid(pid,NULL,0);
    }
    
    else if(pid > 0){
        pid = fork();

        if(pid == 0){
            eh_Primo(101, 300);
            waitpid(pid,NULL,0);
        }
        else if(pid > 0){
            pid = fork();
            
            if(pid == 0){
                eh_Primo(301, 600);
                waitpid(pid,NULL,0);
            }
            else if(pid > 0){
                pid = fork();
                
                if(pid == 0){
                    eh_Primo(601, 1000);
                    waitpid(pid,NULL,0);
                }
            }
        }
    }
}
