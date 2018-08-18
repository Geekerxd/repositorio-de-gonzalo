/*Hacer un programa que calcule las coordenadas (x, y)
de un punto dados el radio y su ángulo sexagesimal.*/

#include <math.h>
#include <iostream>

using namespace std;

void main() {
	locale::global(locale("spanish"));

	float radio;
	cout << "hola humano. insterte el radio de su punto: \n";
	cin >> radio;
	float angx;
	cout << "ahora el ángulo sexagesimal:    \n";
	cin >> angx;

	float pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174f;
	float rd;

	rd = angx * (pi / 180);

	float x;
	 float  y;
	x = radio * cos(rd);
	y = radio * sin(rd);


	cout << "sus cordenadas son exactas son :\n(" << x << ", " << y << ")\nFIN.\n";
	cout << "y sus cordenadas son redondeadas son:\n(" << round(x) << ", " << round(y) << ")\nFIN.\n";


	system("pause");
}
