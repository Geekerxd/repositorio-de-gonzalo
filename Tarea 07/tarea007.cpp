#include <iostream>
using namespace std;

// Declaración de variables globales

int opcion;

// 1. Declarar funciones
void patioTra();
void patioFue();
void sala();
void stairs();
void toilet();
void toilet2();
void cuarto1();void cuarto2();void cuarto3();

void main() {
	locale::global(locale("spanish"));
	patioFue(); // 3. Se mandan llamar

	cout << "\n¡¡¡SE ACABÓ EL RECORRIDO!!" << endl;

	system("pause");
}

// 2. Definir funciones
void patioFue() {
	cout << "Estás en el patio de afuera." << endl;

	cout << "¿a donde quieres entar?" << endl;

	cout << "1. Sala \n2. Patio trasero" << endl;

	cin >> opcion;

	switch(opcion ) {
	case 1:
		sala();
		break;

	case 2:
		patioTra();
		break;
	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;

	}
}
void sala() {
	cout << "Estás en la sala." << endl;

	cout << "ahora a donde quieres ir?" << endl;

	cout << "1. patio de afuera \n2. patio trasero\n3. al baño\n4. o a las escaleras." << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		patioFue();
		break;

	case 2:
		patioTra();
		break;
	case 3:
		toilet();
		break;
	case 4:
		stairs();
		break;

	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;
	}
}
void patioTra() {

	cout << "Estás en el patio trasero." << endl;
	cout << "¿a donde quieres entar?" << endl;

	cout << "1. patio de afuera \n2. sala" << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		patioFue();
		break;

	case 2:
		sala();
		break;
	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;
	}


}

void toilet() {

	cout << "Estás en el baño." << endl;
	cout << "¿a donde quieres entar?" << endl;

	cout << "1. sala " << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		sala();
		break;

	
	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;
	}




}
void stairs() {

	cout << "Estás en las escaleras." << endl;
	cout << "¿a donde quieres entar?" << endl;

	cout << "1. el segundo baño  \n2. sala\n3. cuarto 1\n4. cuarto 2\n5. cuarto 3" << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		toilet2();
		break;

	case 2:
		sala();
		break;

	case 3:
		cuarto1();
		break;
	case 4:
		cuarto2();
		break;
	case 5:
		cuarto3();
		break;
	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;
	}



}

void toilet2() {

	cout << "Estás en el segundo baño." << endl;
	cout << "¿a donde quieres entar?" << endl;

	cout << "1. a las escaleras   " << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		stairs();
		break;

	
	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;
	}


}
void cuarto1() {


	cout << "Estás en el cuarto1." << endl;
	cout << "¿a donde quieres entar?" << endl;

	cout << "1. a las escaleras   " << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		stairs();
		break;


	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;
	}
}
void cuarto2() {


	cout << "Estás en el cuarto2." << endl;
	cout << "¿a donde quieres entar?" << endl;

	cout << "1. a las escaleras   " << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		stairs();
		break;


	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;
	}
}
void cuarto3() {


	cout << "Estás en el cuarto3." << endl;
	cout << "¿a donde quieres entar?" << endl;

	cout << "1. a las escaleras   " << endl;

	cin >> opcion;

	switch (opcion) {
	case 1:
		stairs();
		break;


	default:
		cout << "hmmm.... escribiste algo fuera de rango";
		break;
	}
}
