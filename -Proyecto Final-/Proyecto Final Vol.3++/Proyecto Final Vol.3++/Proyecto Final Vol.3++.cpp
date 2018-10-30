#include <iostream>
#include <string>
#include <fstream>
using namespace std;




struct datos {
	string  name;
	string last_name;
	string email;
	string phone;
	string mat;
	string address;
	float cal1 = 0.0; float cal2 = 0.0; float calf = 0.0; float prom = 0.0;

};
/*
int a;
cout << "¿cuantos alumnos  van a existir?"; cin >> a;*/

datos p[20]; //20 alumnos como maximo

int x; // para las opciones de cuando se quiere ir de una pestaña
int c; //contador
int numalums = 1; //numero de alumnos
bool q=false; //solo freseo

void menu();

void agregar(); void agregar02();
void view();
void main();
void calific();
void search();
void modificar(); 
void eliminate();
void save();

string k; //para que el usuario me ingrese lo que quiere buscar.



void main() {
	p[0].name = { "Gonzalo Geeker" };
	p[0].last_name = { "Aguilar Galeana" };
	p[0].email = { "gag_g249A@hotmail.com" };
	p[0].phone = { "81 86 846 392" };
	p[0].mat = { "1827045" };
	p[0].address = { "paseo del carmen #207" };

	p[0].cal1 = 89;
	p[0].cal2 = 90;
	p[0].calf = 91;

	string l;

	ifstream archivoLec("ejemploGon.txt");
	if (archivoLec.is_open()) {
		int i = 0;
		while (getline(archivoLec, l)) {
			if (i % 6 == 0) {
				p[i / 6].name = l;
			}
			else if(i % 6== 1) {
				p[i / 6].last_name = l;
			}
			else if (i % 6 == 2) {
				p[i / 6].email = l;
			}
			else if (i % 6 == 3) {
				p[i / 6].phone = l;
			}
			else if (i % 6 == 4) {
				p[i / 6].mat = l;
			}
			else if (i % 6 == 5) {
				p[i / 6].address = l;
			}
			i++;
		}
		archivoLec.close();

		for (int i = 0; i < 5; i++)
		{
			cout << p[i].name << " " << p[i].last_name << endl;
		}

		system("pause>nul");
		system("cls");
	}
	else { // Si no se pudo abrir
		cout << "No se pudo abrir el archivo.";
	}

	// Cerrar el archivo
	archivoLec.close();

	menu();

}
void menu() {
	if (q==true) { system("cls"); }

	locale::global(locale("spanish"));
	cout << "   § Bienvenido al menú principal para Maestros de la UANL § \n" << endl;


	cout << "    ¿qué desea hacer?" << endl;
	cout << "     1. Agregar datos de un alumno.     \n     2. Ver los datos del alumno   \n     3. buscar alumno por matricula.\n     4. Modificar datos de un alumno.\n     5. Eliminar un alumno.\n     6. Guardar datos en el archivo.\n     0. Salir de este programa." << endl;
	cin >> x;
	switch (x) {
		
	case 1:
		q = true;
		agregar();  break;
	case 2:
		q = true;
		view();  break;

	case 3:
		q = true;
		search();  break;
	case 4:
		q = true;
		modificar(); break;
	case 5:
		q = true;
		eliminate(); break;
	case 6:
		q = true;
       save(); break;
	case 0:

		cout << "\nFin de Todo :)";
		system("pause>nul");
		break;

	default:
		q = true;
		cout << "------------valor fuera de rango----------------"; system("pause>nul");
		menu();
		break;
	}


	


}

void agregar() {
	system("cls");
	cout << "Estas el la sección de añadir datos.    \n";



	cout << "Estos son los alumnos que por el momento estan registrados: \n";
	cout << "----> " << p[0].name << " <----" << endl;
	for (c = 1; c < numalums; c++) {
		cout << "----> " << p[c].name << " <----" << endl;


	}





	cout << "¿quieres añadir datos?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		agregar02(); break;
	case 2: break;
	default:
		cout << "valor fuera de rango"; agregar();
		break;
	}


	cout << "\n¿deseas regresar al menu?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		menu(); break;
	case 2:
		agregar(); break;
	default:
		cout << "valor fuera de rango"; agregar();
		break;
	}

}
void agregar02() {
	cin.ignore();
	cout << "---------------------------------------------------------------------------\n";
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
		cout << "valor fuera de rango"; agregar02();
		break;
	}


}
void calific() {


	cout << "\nAgrega calificacion 1: ";                 cin >> p[numalums].cal1;
	cout << "\nAgrega calificacion 2: ";                 cin >> p[numalums].cal2;
	cout << "\nAgrega calificacion del ultimo examen: "; cin >> p[numalums].calf;




}

void view() {
	system("cls");
	cout << "estas en la seccion para ver los datos de los alumnos." << endl;

	/*cout<<"¿cual es el nombre del alumno que quiere ver?";*/

	for (c = 0; c < numalums; c++) {   //muetra todos
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
	/*
	for (c = 0; c < 20; c++) {   //tarea 12
		cout << "----------Nombre(s): " << p[c].name << endl;
		cout << "--------Apellido(s): " << p[c].last_name << endl;
		cout << "-------------correo: " << p[c].email << endl;
		cout << "------------celular: " << p[c].phone << endl;
		cout << "----------matricula: " << p[c].mat << endl;
		cout << "----------direccion: " << p[c].address << endl;
		cout << "-----calificacion 1: " << p[c].cal1 << endl;
		cout << "-----calificacion 2: " << p[c].cal2 << endl;
		cout << "-calificacion final: " << p[c].calf << endl << endl << endl;
		if (c == numalums - 1) { break; }
	}
	*/




	cout << "\n¿deseas regresar al menu?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		menu(); break;
	case 2:
		view(); break;
	default:
		cout << "valor fuera de rango"; view();
		break;
	}


}

void search() {

	//tarea 13
	cin.ignore();
	system("cls");
	cout << "estas en la seccion para Buscar alumnos por matricula." << endl;

	cout << "¿cual es la Matricula del alumno que Busca?\n";

	

	getline(cin, k);

	bool encontrado = false;
	

	int l = -1;
	while (l < numalums)
	{
		// c_str() convierte de string a cadena de caracteres
		// strcmp sólo funciona con cadenas de caracteres

		if (strcmp(k.c_str(), p[l].mat.c_str()) == 0) { // Si el matricula es igual que el especificado
			cout << "Lo encontré: " << endl;

			cout << "----------Nombre(s): " << p[l].name << endl;
			cout << "--------Apellido(s): " << p[l].last_name << endl;
			cout << "-------------correo: " << p[l].email << endl;
			cout << "------------celular: " << p[l].phone << endl;
			cout << "----------matricula: " << p[l].mat << endl;
			cout << "----------direccion: " << p[l].address << endl;

			cout << "-----calificacion 1: " << p[l].cal1 << endl;
			cout << "-----calificacion 2: " << p[l].cal2 << endl;
			cout << "-calificacion final: " << p[l].calf << endl << endl << endl;
			
				encontrado = true;
				break; // Salir del ciclo de for
			}

		
		

		
		l++;
	}

	if (!encontrado) {
		cout << "No había registros con ese nombre" << endl;
	}

	system("pause > nul");

	


	cout << "\n¿deseas regresar al menu?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		menu(); break;
	case 2:
		search(); break;
	default:
		cout << "valor fuera de rango";
		search();
		break;
	}

}

void modificar() {
	//tarea 14
	
	cin.ignore();
	system("cls");
	cout << "estas en la seccion para MODIFICAR alumnos por matricula." << endl;

	cout << "¿cual es la Matricula del alumno que Busca?\n";
	

	getline(cin, k);


	bool encontrado = false;


	int l = -1;
	while (l < numalums)
	{
		// c_str() convierte de string a cadena de caracteres
		// strcmp sólo funciona con cadenas de caracteres

		if (strcmp(k.c_str(), p[l].mat.c_str()) == 0) { // Si el matricula es igual que el especificado
			cout << "Lo encontré: " << endl;

			cout << "----------Nombre(s): " << p[l].name << endl;
			cout << "--------Apellido(s): " << p[l].last_name << endl;
			cout << "-------------correo: " << p[l].email << endl;
			cout << "------------celular: " << p[l].phone << endl;
			cout << "----------matricula: " << p[l].mat << endl;
			cout << "----------direccion: " << p[l].address << endl;

			cout << "-----calificacion 1: " << p[l].cal1 << endl;
			cout << "-----calificacion 2: " << p[l].cal2 << endl;
			cout << "-calificacion final: " << p[l].calf << endl << endl << endl;

			

			encontrado = true;
			break; // Salir del ciclo de for
		}





		l++;
	}

	if (!encontrado) {
		cout << "No había registros con ese nombre" << endl;
	}

	if (encontrado) {

		 cout << "Haga otro click...\n";
		 system("pause > nul");
					cout << "¿que quieres modificar?\n 1.- Nombre\n 2.- Apellidos\n 3.- Correo\n 4.- Número de Celular\n 5.- Matrícula\n 6.- Dirección \n 7.- Calificacion 1\n 8.- Calificacion 2\n 9.- Calificacion Final\n";
					cin >> x;
					switch (x) {
						
					case 1:
						cin.ignore();
						cout << "Agrega el(los) Nombre(s): ";                getline(cin, p[l].name);           cout << "OK";
						break;
					case 2:
						cin.ignore();
						cout << "Agrega el(los) apellido(s): ";            getline(cin, p[l].last_name);           cout << "OK";
						break;
					case 3:
						cin.ignore();
						cout << "Agrega el Correo: ";                      getline(cin, p[l].email);  	           cout << "OK";
						break;
					case 4:
						cin.ignore();
						cout << "Agrega el Número de Celular: ";           getline(cin, p[l].phone);		       cout << "OK";
						break;
					case 5:
						cin.ignore();
						cout << "Agrega la Matrícula: ";                   getline(cin, p[l].mat);		           cout << "OK";
						break;
					case 6:
						cin.ignore();
						cout << "Agrega la Dirección : ";                  getline(cin, p[l].address);	           cout << "OK";
						break;
					case 7:
						cin.ignore();
						cout << "Agrega calificacion 1: ";                 cin >> p[l].cal1; cout << "OK";
						break;
					case 8:
						cin.ignore();
						cout << "Agrega calificacion 2: ";                 cin >> p[l].cal2; cout << "OK";
						break;
					case 9:
						cin.ignore();
						cout << "Agrega calificacion del ultimo examen: "; cin >> p[l].calf; cout << "OK";
						break;
					default: break;

					

					

					

				
			}




	}



		system("pause > nul");

		cout << "\n¿deseas regresar al menu?" << endl;
		cout << "1. sí     \n2. No " << endl;
		cin >> x;
		switch (x) {
		case 1:
			menu(); break;
		case 2:
			modificar();
			 break;
		default:
			cout << "valor fuera de rango";
			modificar();
			
			break;
		}





	}
void eliminate() {
	//tarea 16
	system("cls");
	cin.ignore();
	cout << "Estas el la seccion para ELIMINAR A UN ALUMNO." << endl ;
	cout << "Para eliminar a un alumno debe escribir la matricula: " << endl;



	getline(cin, k);


	bool encontrado = false;


	int l = -1;
	while (l < numalums)
	{
		// c_str() convierte de string a cadena de caracteres
		// strcmp sólo funciona con cadenas de caracteres

		if (strcmp(k.c_str(), p[l].mat.c_str()) == 0) { // Si el matricula es igual que el especificado
			cout << "Lo encontré: " << endl;

			cout << "----------Nombre(s): " << p[l].name << endl;
			cout << "--------Apellido(s): " << p[l].last_name << endl;
			cout << "-------------correo: " << p[l].email << endl;
			cout << "------------celular: " << p[l].phone << endl;
			cout << "----------matricula: " << p[l].mat << endl;
			cout << "----------direccion: " << p[l].address << endl;

			cout << "-----calificacion 1: " << p[l].cal1 << endl;
			cout << "-----calificacion 2: " << p[l].cal2 << endl;
			cout << "-calificacion final: " << p[l].calf << endl << endl << endl;



			encontrado = true;
			break; // Salir del ciclo de for
		}
		l++;
	}

	if (!encontrado) {
		cout << "No había registros con ese nombre" << endl;
	}

	if (encontrado) {

		cout << "Haga otro click...\n";
		system("pause > nul");
		cout << "¿que quieres Eliminarlo?\n 1.- Sí\n 2.- No\n";
		cin >> x;
		switch (x) {

		case 1:
			for (int i = l; i < numalums;i++) {
				p[i] = p[i + 1];
			}
			numalums--;
			cout << "OK";
			break;
		case 2: break;
		default: break;
		}
	}



	system("pause > nul");

	cout << "\n¿deseas regresar al menu?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		menu(); break;
	case 2:
		eliminate();
		break;
	default:
		cout << "valor fuera de rango";
		menu();

		break;
	}
}
void save() {
	system("cls");
	cout << "hemm, que hay de nuevo viejo";
	system("pause>nul");



	// Se crea objeto de escritura
	ofstream archivo;

	// Se guarda como binario
	archivo.open("ejemplo.data", ios::binary);

	// Se escribe el arreglo entero en el archivo
	archivo.write((char*)&p, sizeof(p));

	// Al terminar se cierra el archivo
	archivo.close();



	cout << "\n¿deseas regresar al menu?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		menu(); break;
	case 2:
		save();
		break;
	default:
		cout << "valor fuera de rango";
		menu();

		break;
	}

}

	

