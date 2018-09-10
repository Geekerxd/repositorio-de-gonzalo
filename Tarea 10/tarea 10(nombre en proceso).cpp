
/*
Programa 1:
Programa en C++ que dibuje un rectángulo
relleno de asteriscos con base b y altura a dados
por el usuario
*/
/*1. A partir del programa 1, dibujar sólo el perímetro del rectángulo*/
#include<iostream>
using namespace std;
int main() {
	int a = 0, b = 0;
	cout << "Base: " << endl;
	cin >> b;

	cout << "Altura: " << endl;
	cin >> a;

	int area = b * a;
	int e = 0;
	int contador = 0;
	// Empezando en i = 0
	// Mientras i < area


	for (int i = 0; i < area; i++) {
		if (i % b == 0 && i!=0) {
			cout << endl;
			contador += 1;
		}



		if (contador >= a) {
			cout << "*";
		}
		else if (e = 1) {
			cout << "_";
			if (i + 1 % b == 0) {
				cout << "*";
				e = 0;
			}
		
		}
		else if (i - 1 % b ==0 && i!=1) {
			cout << "_";
			e = 1;
		
		
		
		}
		else cout << "*";


		
	}







	system("pause>nul");
}



/*#include <iostream>
using namespace std;

int main() {
	int base;
	int altura;

	cout << "Base:" << endl;
	cin >> base;

	cout << "Altura:" << endl;
	cin >> altura;

	int area = base * altura;
	int contador=0;

	for (int i = 1; i < area; i++) {
		if (i % base == 0) {
			cout << "\n";
			contador += 1;



		}


		else {
			if (contador != 0 && contador < altura-2) {

				 cout << "_ ";


			}
			if (contador==0 || contador>altura-2 ) {
			cout << "* ";
			  }


		}
	}


	system("pause>nul");
}

*/

