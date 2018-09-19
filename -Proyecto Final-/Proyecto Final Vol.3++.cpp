#include <iostream>
#include <string>
using namespace std;




struct datos {
	string  name;
	string last_name;                    //tengo que hacer que el usuario pueda escribir con espacios
	string email;
	string phone;                        //tengo que hacer que el usuario pueda escribir con espacios
	string mat;
	string address;                      //tengo que hacer que el usuario pueda escribir con espacios
	float cal1 = 0.0; float cal2 = 0.0; float calf = 0.0;
};
/*
int a;
cout << "¿cuantos alumnos  van a existir?"; cin >> a;*/

datos p[12]; //12 alumnos como maximo

int x; // para las opciones de cuando se quiere ir de una pestaña
int c; //contador
int numalums=0;

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
	/*system("pause>nul");*/

}

void agregar() {
	system("cls");
	cout << "Estas el la sección de añadir datos.    \n";

	if (numalums > 0) {
		cout << "Estos son los alumnos que por el momento estan registrados: \n";
		for (c = 0; c < numalums; c++) {
			cout <<"----> "<< p[c].name<<" <----"<<endl;


		}
	}




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
	cout << "-------------------\n"; getline(cin, p[c].name);          //************************** no se porque se salta el primer getline********************************************
	cout << "Agrega el(los) Nombre(s): ";                getline(cin, p[numalums].name);           cout << "OK";
	cout << "\nAgrega el(los) apellido(s): ";            getline(cin, p[numalums].last_name);           cout << "OK";
	cout << "\nAgrega el Correo: ";                      getline(cin, p[numalums].email);  	           cout << "OK";
	cout << "\nAgrega el Número de Celular: ";           getline(cin, p[numalums].phone);		       cout << "OK";
	cout << "\nAgrega la Matrícula: ";                   getline(cin, p[numalums].mat);		           cout << "OK";
	cout << "\nAgrega la Dirección : ";                  getline(cin, p[numalums].address);	           cout << "OK";


	numalums++;

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

	/*cout<<"¿cual es el nombre del alumno que quiere ver?";*/

	for (c = 0; c< numalums; c++) {   //muetra todos
		cout << "----------Nombre(s): " << p[c].name << endl;
		cout << "--------Apellido(s): " << p[c].last_name << endl;
		cout << "-------------correo: " << p[c].email << endl;
		cout << "------------celular: " << p[c].phone << endl;
		cout << "----------matricula: " << p[c].mat << endl;
		cout << "----------direccion: " << p[c].address << endl;

		cout << "-----calificacion 1: " << p[c].cal1 << endl;
		cout << "-----calificacion 2: " << p[c].cal2 << endl;
		cout << "-calificacion final: " << p[c].calf << endl << endl << endl;
	}

	




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


	cout << "\nAgrega calificacion 1: ";                 cin >> p[numalums].cal1;
	cout << "\nAgrega calificacion 2: ";                 cin >> p[numalums].cal2;
	cout << "\nAgrega calificacion del ultimo examen: "; cin >> p[numalums].calf;




}