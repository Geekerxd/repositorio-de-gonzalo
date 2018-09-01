#include <iostream>
#include <time.h>
using namespace std;

void juego();
void main();

void main() {

	locale::global(locale("spanish"));
	juego();
	system("pause>nul");
	cout << "\n\n\n\nFIN DE TODO EL JUEGO.";
		
}

void juego() {


	system("cls");
	int opcion=0;
	int compu=0;
	srand(time(NULL));
	cout << "bienvenido al Piedra Papel O Tijera[el juego]" << endl;
	system("pause");
	cout << "\nElije 1 para piedra\nElije 2 para papel\nElije 3 para tijera"<<endl;
	cin >> opcion;

	compu = rand() % 3+1;





	if(opcion==1) {
		cout << "TU[PIEDRA] VS ";
		if (compu == 1) { cout << "COMPU[PIEDRA]" << endl;   cout << "empate"<<endl; }
		if (compu == 2) { cout << "COMPU[PAPEL]"  << endl; cout << "Perdiste" << endl; }
		if (compu == 3) { cout << "COMPU[TIJERA]" << endl; cout << "Ganaste" << endl; }
	
	}
	else if (opcion == 2) {
		cout << "TU[PAPEL] VS ";
		if (compu == 1) { cout << "COMPU[PIEDRA]" << endl; cout << "Ganaste" << endl; }
		if (compu == 2) { cout << "COMPU[PAPEL]" << endl;  cout << "empate" << endl; }
		if (compu == 3) { cout << "COMPU[TIJERA]" << endl; cout << "Perdiste" << endl; }

	}
	else if (opcion == 3) {
		cout << "TU[TIJERA] VS ";
		if (compu == 1) { cout << "COMPU[PIEDRA]" << endl; cout << "Perdiste" << endl; }
		if (compu == 2) { cout << "COMPU[PAPEL]" << endl;  cout << "Ganaste" << endl; }
		if (compu == 3) { cout << "COMPU[TIJERA]" << endl; cout << "empate" << endl; }

	}
	else cout << "---------Introdusiste un valor fuera de rango--------";

	opcion == 0;
	cout << "¿quieres jugar otra vez?\n1 Sí\n2 no\n";
	cin >> opcion;
	if (opcion == 1) { main(); }
	else if(opcion==2){ cout << "\nadiós"; }
	else cout << "---------Introdusiste un valor fuera de rango--------";

}