#include <iostream>
#include <string>
using namespace std;





string  name;
string last_name;                    //tengo que hacer que el usuario pueda escribir con espacios
string email;
string phone;                        //tengo que hacer que el usuario pueda escribir con espacios
string mat;
string address;                      //tengo que hacer que el usuario pueda escribir con espacios
float cal1=0.0; float cal2 = 0.0; float calf = 0.0;

int x; // para las opciones de cuando se quiere ir de una pestaña

void agregar(); void agregar02();
void view();
void main();
void calific();

void main() {
	system("cls");
	locale::global(locale("spanish"));
	cout << "   § Bienvenido al menú principal para Maestros de la UANL § \n" << endl;

	cout << "     ¿qué desea hacer?" << endl;
	cout << "     1. Agregar datos de un alumno.     \n     2. Ver los datos del alumno   \n     3. Salir de este programa." << endl;
	cin >> x;
	switch (x) {
	case 1:
		agregar(); break;
	case 2:
		view(); break;
	case 3: 
		break;
	default:
		cout << "------------valor fuera de rango----------------"; system("pause>nul");  main();
		break;
	}

	cout << "\nFin de Todo :)"; 
	system("pause>nul");

}

void agregar() {
	system("cls");
	cout << "Estas el la sección de añadir datos.    \n";

	cout << "¿quieres añadir datos?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		agregar02(); break;
	case 2: break;
	default:
		cout << "valor fuera de rango"; main();
		break;
	}


	cout << "\n¿deseas regresar al menu?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		main(); break;
	case 2:
		agregar(); break;
	default:
		cout << "valor fuera de rango"; main();
		break;
	}

}
void agregar02() {
	cout << "Agrega el nombre: ";                  cin >> name;
	cout << "\nAgrega el apellido: ";              cin >> last_name;
	cout << "\nAgrega el correo: ";                cin >> email;
	cout << "\nAgrega el numero de celular: ";     cin >> phone;
	cout << "\nAgrega la matricula: ";             cin >> mat;
	cout << "\nAgrega la direccion : ";            cin >> address;




	cout << "\n¿deseas agregar calificaciones?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		calific(); break;
	case 2:
		break;
	default:
		cout << "valor fuera de rango"; main();
		break;
	}


}
void view() {
	system("cls");
	cout << "estas en la seccion para ver los datos de los alumnos." << endl;

	cout << "-------------nombre: " << name      << endl;
	cout << "-----------apellido: " << last_name << endl;
	cout << "-------------correo: " << email     << endl;
	cout << "------------celular: " << phone     << endl;
	cout << "----------matricula: " << mat       << endl;
	cout << "----------direccion: " << address   << endl;

	cout << "-----calificacion 1: " << cal1      << endl;
	cout << "-----calificacion 2: " << cal2 << endl;
	cout << "-calificacion final: " << calf << endl;




	cout << "\n¿deseas regresar al menu?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		main(); break;
	case 2:
		view(); break;
	default:
		cout << "valor fuera de rango"; main();
		break;
	}


}


void calific() {


	cout << "\nAgrega calificacion 1: "; cin >> cal1;
	cout << "\nAgrega calificacion 2: "; cin >> cal2;
	cout << "\nAgrega calificacion del ultimo examen: "; cin >> calf;




}
