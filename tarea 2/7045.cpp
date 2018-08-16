


#include <iostream>

using namespace std;

int main() {

	locale::global(locale("spanish"));
	cout << "Dame tu nombre: ";
	char nombre[20];
	cin>> nombre;

	cout << "ahora tu apellido: ";
	char apellido[20];
	cin >> apellido;

	cout << "ahora tu edad: ";
	int edad;
	cin >> edad;

	cout << "estoy por finalizar. dame tu telefono falso: ";
	char telefono[20];
	cin >> telefono;

	cout << "------------------------------------------------ \n";
	cout << "Nombre: " << apellido << ", " << nombre<<"."<<endl;
	cout << "---"<<endl;
	cout << "Edad: " << edad << " años."<< endl;
	cout << "Telefono: +52" << telefono<< endl ;



	cout << "------------------------------------------------ \n";

	system("pause");
	return 0;
}