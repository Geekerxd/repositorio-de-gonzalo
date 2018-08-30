# Tarea 05
Preguntas.

1. Error en salida; no tiene el using namespace std

2. Ningun error

3. Sin salida y error; 1 caracter de más

4. error de salida; caracteres de más

5. Ningun error; imprime: a = 8; b = 24

6. -Ningun error; Imprime: 15

7. -Ningun error, Imprime: a = 6 b = 6

8. -Ningun error, Imprime: 1

9. -Ningun error, Imprime: 0

10. -Ningun error, Imprime: mo

# programa/juego: Un Pokemon Tlacuache

_#include <iostream>_
 
_#include<time.h>_
  

using namespace std;

int vidaYo=10;
int vidaTla = 10;

void main() {
	srand(time(NULL));
	locale::global(locale("spanish"));

	cout << "♪♪♪♪♪♪tutututututuutut♪♪♪♪" << endl;
	cout << "oh no, un tlacuache nivel 2 y de vida 10 (como la tuya)" << endl;
	cout << "solo tienes 2 movimiento posibles" << endl;
	int m;

	cout << "preciona 0 para pegar" << endl;
	cout << "preciona 1 para dar patada" << endl;
	 cin >> m; 
	if (m == 0) { vidaTla -= 3;
	
	cout << "oh le has quitao 3. ahora solo le queda: " << vidaTla<<endl;
	
	}
	else if  (m==1) { vidaTla -= 6;
	
	cout << "oh le has quitao 6. ahora solo le queda: " << vidaTla << endl;
	}
	else cout << "insertasre un numero incorrecto\n";





	m = rand() % 2;
	if (m == 0) { vidaYo -= 3;
	cout << "oh me ha quitao 3. ahora solo me queda: " << vidaYo << "\n" << endl;
	}
	else if (m == 1) { vidaYo -= 6; 
	cout << "oh me ha quitao 6. ahora solo me queda: " << vidaYo << "\n" << endl;
	}
	else cout << "insertasre un numero incorrecto\n";








	cout << "preciona 0 para pegar" << endl;
	cout << "preciona 1 para dar patada" << endl;
	cin >> m;
	if (m == 0) {
		vidaTla -= 3;

		cout << "oh le has quitao 3. ahora solo le queda: " << vidaTla << endl;

	}
	else if (m == 1) {
		vidaTla -= 6;

		cout << "oh le has quitao 6. ahora solo le queda: " << vidaTla << endl;
	}
	else cout << "insertasre un numero incorrecto\n";





	m = rand() % 2;
	if (m == 0) {
		vidaYo -= 3;
		cout << "oh me ha quitao 3. ahora solo me queda: " << vidaYo << "\n" << endl;
	}
	else if (m == 1) {
		vidaYo -= 6;
		cout << "oh me ha quitao 6. ahora solo me queda: " << vidaYo << "\n" << endl;
	}
	else cout << "insertasre un numero incorrecto\n";








	cout << "preciona 0 para pegar" << endl;
	cout << "preciona 1 para dar patada" << endl;
	cin >> m;
	if (m == 0) {
		vidaTla -= 3;

		cout << "oh le has quitao 3. ahora solo le queda: " << vidaTla << endl;

	}
	else if (m == 1) {
		vidaTla -= 6;

		cout << "oh le has quitao 6. ahora solo le queda: " << vidaTla << endl;
	}
	else cout << "insertasre un numero incorrecto\n";





	m = rand() % 2;
	if (m == 0) {
		vidaYo -= 3;
		cout << "oh me ha quitao 3. ahora solo me queda: " << vidaYo <<  "\n" << endl;
	}
	else if (m == 1) {
		vidaYo -= 6;
		cout << "oh me ha quitao 6. ahora solo me queda: " << vidaYo << "\n" << endl;
	}
	else cout << "insertasre un numero incorrecto\n";

	if (vidaTla  <= 0 && vidaYo>0) { cout << "FELICIDADES!!!! LE GANASTE AL TLACUACHE\n"; }
	  else if (vidaTla  >0 && vidaYo<=0) { cout << "DEMONIOS! PERDISTE\n"; }
	  else   { cout << "EMPATARON\n"; }

	  cout << "fin\n";

	system("pause>nul");

}


