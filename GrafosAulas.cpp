// GrafosAulas.cppQ'32AA!3cde41aqw2sde4'1	'2qwsxfsxssxde4tfgr6v5b 5taqsw2xsftgr56 da3e41	'2qswcde4ttf51	'AQSW2XTVFGUBNHYYUAQSW2XAX3CDE4TT5A1Q : define o ponto de entrada para o aplicativo do console.
//
#include "stdafx.h"
#include<iostream>
#include"Grafo.h"
#include"Persistencia.h"
#include<Windows.h>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int main()
{

	Grafo* g = new Grafo();
	for (int i = 0; i < 7; i++)
		g->addVetor();

/*	g->addAresta(0, 1, 7.0);
	g->addAresta(0, 3, 5.0);
	g->addAresta(1, 0, 7.0);
	g->addAresta(1, 2, 8.0);
	g->addAresta(1, 3, 9.0);
	g->addAresta(1, 4, 7.0);
	g->addAresta(2, 1, 8.0);
	g->addAresta(2, 4, 5.0);
	g->addAresta(3, 0, 5.0);
	g->addAresta(3, 1, 9.0);
	g->addAresta(3, 4, 15.0);
	g->addAresta(3, 5, 6.0);
	g->addAresta(4, 1, 7.0);
	g->addAresta(4, 2, 5.0);
	g->addAresta(4, 3, 15.0);
	g->addAresta(4, 5, 8.0);
	g->addAresta(4, 6, 9.0);
	g->addAresta(5, 3, 6.0);
	g->addAresta(5, 4, 8.0);
	g->addAresta(5, 6, 11.0);
	g->addAresta(6, 4, 9.0);
	g->addAresta(6, 5, 11.0);
	g->exibe();*/



	//Persistencia::gravar_em_arquivo("dados.txt", g);

	Persistencia::retorna_grafo("dados.txt");

	system("Pause");
	return 0;
}
