#include <iostream>
using namespace std;





char name[30] ;
char last_name[50] ;
char email[50];
char phone[15];
char mat[15];
char address[20];
 char cal1[5]; char cal2[5]; char calf[5];

int x;

void agregar(); void agregar02();
void view();
void main();
void calific();

void main() {
	system("cls");
	locale::global(locale("spanish"));
	cout << "\t Bienvenido al menú principal para Maestros de la UANL\t" << endl;
	
	cout << "¿qué desea hacer?" << endl;
	cout << "1. Agregar datos de un alumno.     \n2. Ver los datos del alumno   \n3. Salir de este programa."   << endl;
	cin >> x;
	switch (x) {
	case 1:
		agregar(); break;
	case 2:
		view(); break;
	case 3: break;
	default:
		cout << "------------valor fuera de rango----------------"; system("pause>nul");  main();
		break;
	}

	cout << "\nfin de todo"; system("pause>nul");

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
	cout << "1. sí     \n2. No "<< endl;
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
	cout << "\nAgrega la direccion : "; cin >> address;




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

	cout << "nombre: ";               cout << name << endl;
	cout << "apellido: ";           cout << last_name << endl;
	cout << "correo: ";             cout << email << endl;
	cout << "celular: ";  cout << phone << endl;
	cout << "matricula: ";          cout << mat << endl;
	cout << "direccion: "  << address << endl;
cout <<"calificacion 1:"<< cal1 << endl;
cout <<"calificacion 2:"<< cal2 << endl;
cout <<"calificacion final:"<< calf << endl;

	


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