#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <time.h>
#include <windows.h>
using namespace std;




struct datos {
	string  name;
	string last_name;
	string semail;  char email[100];
	string sphone; char phone[50];
	string mat;
	string address;
	string scal1;  char chcal1[6];  float cal1 = 0.0;
	string scal2; char chcal2[6];  float cal2 = 0.0;
	string scalf; char chcalf[6];  float calf = 0.0;
	
    float prom = 0.0;

};
datos p[100]; 

int x; // para las opciones de cuando se quiere ir de una pestaña
int c; //contador
int numalums = 0; // ----------------------------------------------numero de alumnos
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

int countAt, countDot;
int countNum = 0;
int countFail = 0;
bool t = false;


void main() {
	/*
	p[0].name = { "Gonzalo Geeker" };
	p[0].last_name = { "Aguilar Galeana" };
	p[0].email= "gag_g249A@hotmail.com";
	p[0].phone = { "81 86 846 392" };
	p[0].mat = { "1827045" };
	p[0].address = { "paseo del carmen #207" };
	
	//p[0].email =  "gag_g249A@hotmail.com" ;
	
	 
	p[0].cal1 = 89;
	p[0].cal2 = 90;
	p[0].calf = 91;
	*/
	
	string l;
	ifstream archivoLec;
	archivoLec.open("ejemploGon.txt",ios::binary);
	if (archivoLec.is_open()) {
		int i = 0;
		while (getline(archivoLec, l)) {
			if (i % 9 == 0) {
				p[i / 9].name = l;
				numalums++;
			}
			else if (i%9==1) {
				p[i / 9].last_name = l;
			}
			else if (i % 9 == 2) {
				p[i / 9].semail = l;

				strcpy_s(p[i / 9].email, p[i / 9].semail.c_str());

			}
			else if (i % 9 == 3) {
				p[i / 9].sphone = l;
				strcpy_s(p[i / 9].phone, p[i / 9].sphone.c_str());
			}
			else if (i % 9 == 4) {
				p[i / 9].mat = l;
			}
			else if (i % 9 == 5) {
				p[i / 9].address = l;
			}
			else if (i % 9 == 6) {
				p[i / 9].scal1 = l;
				p[i / 9].cal1 = stof(p[i / 9].scal1);
				
			}
			else if (i % 9 == 7) {
				p[i / 9].scal2 = l;
				p[i / 9].cal2 = stof(p[i / 9].scal2);
			}
			else if (i % 9 == 8) {
				p[i / 9].scalf = l;
				p[i / 9].calf = stof(p[i / 9].scalf);
			}

			
			i++;
		}

		
	}
	else { // Si no se pudo abrir
		cout << "No se pudo abrir el archivo.";
	}

	
	archivoLec.close();// Cerrar el archivo

	for (c = 0; c < numalums; c++) {
		cout << "----> " << p[c].name << endl;
	}
	cout << "numero de alumnos: " << numalums;

	system("pause>nul");
	system("cls");
	menu();

}
void menu() {
	if (q==true) { system("cls"); }

	locale::global(locale("spanish"));
	cout << "   § Bienvenido al menú principal para Maestros de la UANL § \n" << endl;


	cout << "    ¿qué desea hacer?" << endl;
	cout << "     1. Agregar datos de un alumno.     \n     2. Ver los datos del alumno.   \n     3. buscar alumno por matricula.\n     4. Modificar datos de un alumno.\n     5. Eliminar un alumno.\n     6. Guardar datos en el archivo.\n     0. Salir de este programa." << endl;
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
	
	for (c = 0; c < numalums; c++) {
		cout << "----> " << p[c].name << endl;
	}

	



	cout << "¿quieres añadir datos?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		agregar02(); break;
	case 2: break;

	case 0:

		cout << "\nIngresaste algo incorrecto :'(";
		
		break;
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
	cout << "\nAgrega el Correo: "; 
correo:
	countAt = 0; countDot = 0;
		
		cin>> p[numalums].email;
		for (int i = 0; p[numalums].email[i] != NULL; i++) {

			if (p[numalums].email[i] == 64) {
				countAt++;
			}
			if (countAt == 1 && p[numalums].email[i] == '.') {
				countDot++;
			}
		}
		if (countAt == 0) {
			cout << "Falta un @ " << endl; countDot = 0; goto correo;
		}
		else if (countAt > 1) {
			cout << "Hay mas de 1 @" << endl; countAt = 0; countDot = 0; goto correo;
		}
		else if (countDot == 0) {
			cout << "Falta el punto " << endl; countAt = 0; goto correo;
		}
		else if (countDot > 1) {
			cout << "Hay mas de un punto" << endl; countAt = 0; countDot = 0; goto correo;
		}
		else {
			cout << "ok" ;
		}

		cin.ignore();
		cout << "\nAgrega el Número de Celular: ";     
	phone:
		countNum = 0;
		countFail = 0;
		cin >> p[numalums].phone;

		for (int j = 0; p[numalums].phone[j] != NULL; j++) {

			if (p[numalums].phone[j] >= 48 && p[numalums].phone[j] <= 57) {
				countNum++;
			}
			else { countFail++; }

		}
		if (countNum < 8) {cout << "***su numero debe ser almenos 8 y maximo 12***\n"; goto phone;}
		else if (countNum > 12) { cout << "***su numero debe de maximo 12 y minimo 8***\n"; goto phone; }
		else { cout << "OK"; }
	
mat:
	cout << "\n¿Quiere agregar una matricula o que se auto-genere?\n   1.Agregar matricula.\n   2.Que se autogenere.\n";     
	int y = 0;
	cin >> y;
	if (y==1) {
	
		cout << "escribe la matricula: ";
		cin.ignore();
		getline(cin, p[numalums].mat);
		
		x = 0;
		t = false;
		while (x < numalums) {
			if (strcmp(p[numalums].mat.c_str(), p[x].mat.c_str()) == 0 && x!= numalums) {
				t = true;

			}
			x++;
		}
		if (t) { cout << "\n***Esta matricula ya existe. intentalo de nuevo***\n"; goto mat; }
		else cout << "OK";
	}

		
      
	else if (y==2) {
		
		srand(time(NULL));
		int o= rand() % 10000+ 1800000;

		char str[15];
		sprintf_s(str, "%d", o);
		p[numalums].mat = str;
		cout <<"esta es su matricula: "<< p[numalums].mat<<endl;
		x = 0;
		 t = false;
		while (x < numalums) {
			if (strcmp(p[numalums].mat.c_str(), p[x].mat.c_str()) == 0 && x != numalums) {
				t = true;

			}
			x++;
		}
		if (t == true) { cout << "***Esta matricula ya existe. intentalo de nuevo***"; goto mat; }
		else cout << "OK";
		
	}
	
		
	
	
		         
	cin.ignore();
	cout << "\nAgrega la Dirección (calle y numero, colonia):\n";
	getline(cin, p[numalums].address);	         
	cout << "OK";


		

	cout << "\n¿deseas agregar calificaciones?" << endl;
	cout << "1. sí     \n2. No " << endl;
	cin >> x;
	switch (x) {
	case 1:
		calific(); break;
	case 2:
		numalums++;
		break;
	default:
		cout << "valor fuera de rango"; agregar02();
		break;
	}


}

float truncar(float nro) {
	long x = 100 * nro;
	float y = (float)x / (float)100;
	return y;
}


void calific() {
	cout << "******************************************************************\n ";
	cout << "Si no se quiere registrar una calificacion \n ingrese 0 en la calificacion\n";
	cout << "******************************************************************\n ";
cali1:
	int countNum = 0;
	int countFail = 0;
	cout << "\nAgrega calificacion 1: ";                cin >> p[numalums].cal1;

	
	p[numalums].cal1 = truncar(p[numalums].cal1); // lo trunquea para que quede 2 dedimales
	int ret = snprintf(p[numalums].chcal1, sizeof p[numalums].chcal1, "%f", p[numalums].cal1);


	



	if (p[numalums].cal1 < 0) { cout << "****La calificacion debe de ser mayor o igual a cero****\n "; goto cali1; }
	if (p[numalums].cal1 > 100) { cout << "****La calificacion debe de ser menor o igual a cien****\n "; goto cali1; }

	for (int i = 0; p[numalums].chcal1[i] != NULL; i++) {// Este for revista si todos son numeros

		if (p[numalums].chcal1[i] >= 48 && p[numalums].chcal1[i] <= 57) {
			countNum++;
		}
		else if (p[numalums].chcal1[i] == 44) {} //detecta el , en el numero para que lo acepte
		else { countFail++; }  // si alguno no es numero lo cuenta

	}
	if (countFail >= 1) {
		cout << "\nIngresaste algo que no es un número. Intentalo de nuevo. \n"; goto cali1;
	}


	if (p[numalums].cal1 >= 0 && p[numalums].cal1 <= 100) {
		cout << "Ok";

	}


cali2:
	countNum = 0;
	countFail = 0;
	cout << "\nAgrega calificacion 2: ";                 cin >> p[numalums].cal2;
	
	p[numalums].cal2 = truncar(p[numalums].cal2); // lo trunquea para que quede 2 dedimales
	 ret = snprintf(p[numalums].chcal2, sizeof p[numalums].chcal2, "%f", p[numalums].cal2);


	

	if (p[numalums].cal2 < 0) { cout << "****La calificacion debe de ser mayor o igual a cero****\n "; goto cali2; }
	if (p[numalums].cal2 > 100) { cout << "****La calificacion debe de ser menor o igual a cien****\n "; goto cali2; }

	for (int i = 0; p[numalums].chcal2[i] != NULL; i++) {// revista si todos son numeros

		if (p[numalums].chcal2[i] >= 48 && p[numalums].chcal2[i] <= 57) {
			countNum++;
		}
		else if (p[numalums].chcal2[i] == 44) {}
		else { countFail++; }

	}
	if (countFail >= 1) {
		cout << "\nIngresaste algo que no es un número. Intentalo de nuevo. \n"; goto cali2;
	}



	if (p[numalums].cal2 >= 0 && p[numalums].cal2 <= 100) { cout << "Ok"; }

calif:
	countNum = 0;
	countFail = 0;
	cout << "\nAgrega calificacion del ultimo examen: "; cin >> p[numalums].calf;

	p[numalums].calf = truncar(p[numalums].calf); // se trunquea el flotante para que quede 2 dedimales
	 ret = snprintf(p[numalums].chcalf, sizeof p[numalums].chcalf, "%f", p[numalums].calf);


	


	if (p[numalums].calf < 0) { cout << "****La calificacion debe de ser mayor o igual a cero****\n "; goto calif; }
	if (p[numalums].calf > 100) { cout << "****La calificacion debe de ser menor o igual a cien****\n "; goto calif; }

	for (int i = 0; p[numalums].chcalf[i] != NULL; i++) {// revista si todos son numeros

		if (p[numalums].chcalf[i] >= 48 && p[numalums].chcalf[i] <= 57) {
			countNum++;
		}
		else if (p[numalums].chcalf[i] == 44) {}
		else { countFail++; }

	}
	if (countFail >= 1) {
		cout << "\nIngresaste algo que no es un número. Intentalo de nuevo. \n"; goto calif;
	}


	if (p[numalums].calf >= 0 && p[numalums].cal2 <= 100) { cout << "Ok\n"; }

	cout << "calificacion 1"<< "     ---- " << p[numalums].cal1 << endl;
	cout << "calificacion 2"<< "     ---- " << p[numalums].cal2 << endl;
	cout << "calificacion Final"<< " ---- " << p[numalums].calf << endl;

	if (p[numalums].cal1 == 0 || p[numalums].cal2 == 0 || p[numalums].calf == 0) {p[numalums].prom = 0;}
	else {p[numalums].prom = (p[numalums].cal1*0.30) + (p[numalums].cal2*0.45) + (p[numalums].calf*0.25);}
	
	cout <<"Promedio Final: "<< p[numalums].prom << endl;
	cout << "numalums: " << numalums << endl;



	numalums++;
}

void view() {
	system("cls");
	cout << "estas en la seccion para ver los datos de los alumnos." << endl;

	/*cout<<"¿cual es el nombre del alumno que quiere ver?";*/

	for (c = 0; c < numalums; c++) {   //muetra todos

		if (p[c].cal1 == 0 || p[c].cal2 == 0 || p[c].calf == 0) { p[c].prom = 0; }
		else { p[c].prom = (p[c].cal1*0.30) + (p[c].cal2*0.45) + (p[c].calf*0.25);
		p[c].prom = truncar(p[c].prom); // lo trunquea para que quede 2 dedimales
		}

		
		cout << "----------Nombre(s): " << p[c].name << endl;
		cout << "--------Apellido(s): " << p[c].last_name << endl;
		cout << "-------------correo: " << p[c].email << endl;
		cout << "------------celular: " << p[c].phone << endl;
		cout << "----------matricula: " << p[c].mat << endl;
		cout << "----------direccion: " << p[c].address << endl;

		cout << "-----calificacion 1: " << p[c].cal1 << endl;
		cout << "-----calificacion 2: " << p[c].cal2 << endl;
		cout << "-calificacion final: " << p[c].calf << endl;
		cout << "-----------Promedio: " << p[c].prom << endl << endl << endl;
		cout << "numalums: " << c << endl;
	}
	
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

	int y = 0;
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
					cout << "¿que quieres modificar?\n 1.- Nombre\n 2.- Apellidos\n 3.- Correo\n 4.- Número de Celular\n 5.- Matrícula\n 6.- Dirección \n 7.- Calificacion 1\n 8.- Calificacion 2\n 9.- Calificacion Final\n 0.- Nada. ";
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
						cout << "Agrega el Correo: ";
					correo2:
						countAt = 0; countDot = 0;
						cin >> p[l].email;
						for (int i = 0; p[l].email[i] != NULL; i++) {

							if (p[l].email[i] == 64) {
								countAt++;
							}
							if (countAt == 1 && p[l].email[i] == '.') {
								countDot++;
							}
						}
						if (countAt == 0) {
							cout << "Falta un @ " << endl; countDot = 0; goto correo2;
						}
						else if (countAt > 1) {
							cout << "Hay mas de 1 @" << endl; countAt = 0; countDot = 0; goto correo2;
						}
						else if (countDot == 0) {
							cout << "Falta el punto " << endl; countAt = 0; goto correo2;
						}
						else if (countDot > 1) {
							cout << "Hay mas de un punto" << endl; countAt = 0; countDot = 0; goto correo2;
						}
						else {
							cout << "ok";
						}
						break;
					case 4:
						cin.ignore();
						cout << "Agrega el Número de Celular: ";  
					phone2:
						countNum = 0;
						countFail = 0;
						cin >> p[l].phone;

						for (int j = 0; p[l].phone[j] != NULL; j++) {

							if (p[l].phone[j] >= 48 && p[l].phone[j] <= 57) {
								countNum++;
							}
							else { countFail++; }

						}
						if (countNum < 8) { cout << "***su numero debe ser almenos 8 y maximo 12***\n"; goto phone2; }
						else if (countNum > 12) { cout << "***su numero debe de maximo 12 y minimo 8***\n"; goto phone2; }
						else { cout << "OK"; }

						break;
					case 5:
						
					mat2:
						
							cout << "Escribe la matricula: ";
							cin.ignore();
							getline(cin, p[l].mat);

							x = 0;
							t = false;
							while (x < numalums) {
								if (strcmp(p[l].mat.c_str(), p[x].mat.c_str()) == 0 && x != l) {
									t = true;

								}
								x++;
							}
							if (t) { cout << "\n***Esta matricula ya existe. intentalo de nuevo***\n"; goto mat2; }
							else cout << "OK";
						
						break;
					case 6:
						cin.ignore();
						cout << "Agrega la Dirección : ";                  getline(cin, p[l].address);	           cout << "OK";
						break;
					case 7:
						cin.ignore();
						cout << "Agrega calificacion 1: ";   cali01:  
						cin >> p[l].cal1; 
						p[l].cal1 = truncar(p[l].cal1); // lo trunquea para que quede 2 dedimales
						if (p[l].cal1 < 0) { cout << "****La calificacion debe de ser mayor o igual a cero****\n "; goto cali01; }
						if (p[l].cal1 > 100) { cout << "****La calificacion debe de ser menor o igual a cien****\n "; goto cali01; }
						if (p[l].cal1 >= 0 && p[l].cal1 <= 100) {
							cout << "Ok";

						}
						if (p[l].cal1 == 0 ) { p[l].prom = 0; }
						else { p[l].prom = (p[l].cal1*0.30) + (p[l].cal2*0.45) + (p[l].calf*0.25);
						p[l].prom = truncar(p[l].prom); // lo trunquea para que quede 2 dedimales
						}

						break;
					case 8:
						cin.ignore();  
						cout << "Agrega calificacion 2: ";   cali02:        
						cin >> p[l].cal2;
						p[l].cal2 = truncar(p[l].cal2); // lo trunquea para que quede 2 dedimales
						if (p[l].cal2 < 0) { cout << "****La calificacion debe de ser mayor o igual a cero****\n "; goto cali02; }
						if (p[l].cal2 > 100) { cout << "****La calificacion debe de ser menor o igual a cien****\n "; goto cali02; }
						if (p[l].cal2 >= 0 && p[l].cal2 <= 100) {
							cout << "Ok";

						}
						if ( p[l].cal2 == 0 ) { p[l].prom = 0; }
						else { p[l].prom = (p[l].cal1*0.30) + (p[l].cal2*0.45) + (p[l].calf*0.25);
						p[l].prom = truncar(p[l].prom); // lo trunquea para que quede 2 dedimales
						}
						break;
					case 9:
						cin.ignore();
						cout << "Agrega calificacion del ultimo examen: ";
					cali0f:
						cin >> p[l].calf; 
						p[l].calf = truncar(p[l].calf); // lo trunquea para que quede 2 dedimales
						if (p[l].calf < 0) { cout << "****La calificacion debe de ser mayor o igual a cero****\n "; goto cali0f; }
						if (p[l].calf > 100) { cout << "****La calificacion debe de ser menor o igual a cien****\n "; goto cali0f; }
						if (p[l].calf >= 0 && p[l].calf <= 100) {
							cout << "Ok";

						}
						if ( p[l].calf == 0) { p[l].prom = 0; }
						else { p[l].prom = (p[l].cal1*0.30) + (p[l].cal2*0.45) + (p[l].calf*0.25);
						p[l].prom = truncar(p[l].prom); // lo trunquea para que quede 2 dedimales
						}
						break;
					case 0:break;
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
	archivo.open("ejemploGon.txt", ios::binary);

	for (c = 0; c < numalums; c++) {
		archivo << p[c].name << endl;
		archivo << p[c].last_name << endl;
		archivo << p[c].email << endl;
		archivo << p[c].phone << endl;
		archivo << p[c].mat << endl;
		archivo << p[c].address << endl;

		archivo << p[c].cal1 << endl;
		archivo << p[c].cal2 << endl;
		archivo << p[c].calf << endl;
		
	}
	



	
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

	

