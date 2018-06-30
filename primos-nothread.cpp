#include <iostream>

using namespace std;

void encontraPrimo(int, int);

int main(){
	int n = 0, inf = 0;
	cout << "Limite Inferior: " << endl;
	cin >> inf;
	cout << "Limite Superior: " << endl;
	cin >> n;
	encontraPrimo(inf, n);
	return 0;
}

void encontraPrimo (int limInf, int limSup){
	int i = 0, j = 0, cont = 0;
	if(limInf == 0){
		limInf = 1;
	}
	else if(limInf%2 == 0){
		limInf += 1;
	}
	for(i = limInf ; i<=limSup ; i+=2){
		cont = 0;
		for(j = 1; j<=i ; j+=2){
			if(i%j == 0)
			cont++;
		}
		if(cont==2)
		cout << endl << i;
	}
}