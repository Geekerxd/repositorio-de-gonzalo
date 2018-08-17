#include <iostream>
using namespace std;


void main(){
	locale::global(locale("spanish"));
    cout<< " Número de diagonales Diagonales de un polígono regular de N lados.\n inserte el numero de lados del poligono:   ";
	int n;
	cin >> n;

	int d;
	d = (n*(n - 3)) / 2;

	cout << " El numero de diagonales que tiene su poligono es:           " << d << ".\n";
	cout << " fin\n";




system("pause");
}
