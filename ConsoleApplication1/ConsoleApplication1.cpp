/*
Estimarea lui pi este bazata de numere aleatoare si probabilitati. Estimarea lui pi spune:
Avand un cerc de raza r pe care il vom incadra intr-un patrat de raza 2r(lungimea diametrului
patratului), vom genera numere aleatoare care se afla in interiorul patratului.
Evident, unele puncte generate se vor afla atat in interiorul patratului,
cat si in interiorul cercului. Pentru fiecare punct generat din patrat, vom verifica si 
numara si punctele care se afla si in interiorul cercului. La sfarsit, impartind 
de 4*numarul de puncte din cerc supra tuturor numerelor din patrat(inclusiv pe cele din cerc)
ne va da un rezultat care este foarte aproape de numarul pi=3,14159. 
Cu cat sunt mai multe puncte generate, cu atat acuratetea rezultatului va fi mai mare.
*/

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int min = -1, max = 1; //luam un cerc de raza 1 si centru 0.
void init(double &a, double &b)
{
	double f1 = (double)rand() / RAND_MAX;
	double f2 = (double)rand() / RAND_MAX;
	a = min + f1 * (max - min); 
	b = min + f2 * (max - min); //generam elementele a si b, care sunt coordonatele 
	//punctului actual, asigurandu-ne ca se afla cu siguranta in interiorul patratului
}
int main()
{
	double x, y;
	int raza = 1, cerc=0, patrat=0,limita=9999999; //luam raza cercului 1
	//variabila cerc reprezinta numarul de puncte din cerc, iar variabila patrat
	//reprezinta numarul de puncte din patrat.
	//limita reprezinta numarul de puncte generate, luam un numar foarte mare
	//pentru ca acuratetea sa fie cat mai buna.
	srand(time(NULL));
	for (int i = 0; i <= limita; i++)
	{
		init(x, y); //initializam punctul actual cu coordonate aflate in interiorul patratului
		patrat++; //numaram punctul deoarece se aflain patrat
		if (x*x + y * y <= raza * raza) //verificam daca punctul se afla si in interiorul cercului
			cerc++; //in caz afirmativ, il numaram
	}
	double pi = (double)(4 * cerc) / patrat; //ii dam lui pi valoarea formulei 
	//4* numarul de puncte din cerc supra numarului de puncte din patrat. Rezultatul va fi 
	//aproximativ pi=3,14.. .
	cout << "pi="<<pi; //afisam rezultatul.
}

