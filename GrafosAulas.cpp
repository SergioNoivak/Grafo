// GrafosAulas.cppQ'32AA!3cde41aqw2sde4'1	'2qwsxfsxssxde4tfgr6v5b 5taqsw2xsftgr56 da3e41	'2qswcde4ttf51	'AQSW2XTVFGUBNHYYUAQSW2XAX3CDE4TT5A1Q : define o ponto de entrada para o aplicativo do console.
//
#include<Windows.h>
#include "stdafx.h"
#include<iostream>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#include"Persistencia.h"
using namespace std;
int main()
{


	Grafo* g = new Grafo();
	for (int i = 0; i < 9; i++)
		g->addVetor();
	g->addAresta(0, 1, 4);
	g->addAresta(1, 2, 8);
	g->addAresta(2, 3, 7);
	g->addAresta(3, 4, 9);
	g->addAresta(4, 5, 10);
	g->addAresta(5, 6, 2);
	g->addAresta(6, 7, 1);
	g->addAresta(7, 0, 8);
	g->addAresta(7, 1, 11);
	g->addAresta(7, 8, 7);
	g->addAresta(8, 2, 2);
	g->addAresta(8, 6, 6);
	g->addAresta(2, 5, 4);
	g->addAresta(5, 3, 14);
	g->exibe();


	Algoritmo::Prim(g, 0);
	//Algoritmo::Kruskal(g);
	



	/*for (int i = 0; i < 7; i++)
		g->addVetor();
	g->addAresta(0, 1, 7);
	g->addAresta(1, 2, 8);
	g->addAresta(2, 3, 5);
	g->addAresta(3, 4, 9);
	g->addAresta(4, 5, 11);
	g->addAresta(5, 6, 6);
	g->addAresta(6, 1, 9);
	g->addAresta(6, 3, 15);
	g->addAresta(5, 3, 8);
	g->addAresta(3, 1, 7);
	
	*/
	
		/*Grafo * g =Persistencia::retorna_grafo_do_arquivo();
*/


		//Algoritmo::Kruskal(g);
	



	system("Pause");
}

