// GrafosAulas.cppQ'32AA!3cde41aqw2sde4'1	'2qwsxfsxssxde4tfgr6v5b 5taqsw2xsftgr56 da3e41	'2qswcde4ttf51	'AQSW2XTVFGUBNHYYUAQSW2XAX3CDE4TT5A1Q : define o ponto de entrada para o aplicativo do console.
//
#include<Windows.h>
#include"Grafo_nao_direcionado.h"
#include "stdafx.h"
#include<iostream>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#include"Persistencia.h"
using namespace std;
int main()
{

		Grafo * g =Persistencia::retorna_grafo_do_arquivo();
		Algoritmo::Prim(g,0);
		Algoritmo::Kruskal(g);

	system("Pause");
}

//	//EXEMPLO LIVRO
//	//Grafo* g = new Grafo();
//	//for (int i = 0; i < 9; i++)
//	//	g->addVetor();
//	//g->Add_aresta_nao_direcionada(0, 1, 4);
//	//g->Add_aresta_nao_direcionada(1, 2, 8);
//	//g->Add_aresta_nao_direcionada(2, 3, 7);
//	//g->Add_aresta_nao_direcionada(3, 4, 9);
//	//g->Add_aresta_nao_direcionada(4, 5, 10);
//	//g->Add_aresta_nao_direcionada(6, 7, 1);
//	//g->Add_aresta_nao_direcionada(5, 6, 2);
//	//g->Add_aresta_nao_direcionada(7, 0, 8);
//	//g->Add_aresta_nao_direcionada(7, 1, 11);
//	//g->Add_aresta_nao_direcionada(7, 8, 7);
//	//g->Add_aresta_nao_direcionada(8, 2, 2);
//	//g->Add_aresta_nao_direcionada(8, 6, 6);
//	//g->Add_aresta_nao_direcionada(2, 5, 4);
//	//g->Add_aresta_nao_direcionada(5, 3, 14);
//	////g->exibe();
//
//
//
////EXEMPLO WIKIPEDIA
//	/*for (int i = 0; i < 7; i++)
//		g->addVetor();
//
//	g->Add_aresta_nao_direcionada(0, 1, 7);
//	g->Add_aresta_nao_direcionada(1, 2, 8);
//	g->Add_aresta_nao_direcionada(2, 3, 5);
//
//	g->Add_aresta_nao_direcionada(3, 1, 7);	
//	g->Add_aresta_nao_direcionada(3, 4, 9);	
//	g->Add_aresta_nao_direcionada(3, 5, 8);
//	g->Add_aresta_nao_direcionada(3, 6, 15);
//	g->Add_aresta_nao_direcionada(0, 6, 5);
//
//	g->Add_aresta_nao_direcionada(1, 6, 9);
//	g->Add_aresta_nao_direcionada(5, 4, 11);
//	g->Add_aresta_nao_direcionada(5, 6, 6);
//	*/
//
//
//	/*for (int i = 0; i < 7; i++)
//		g->addVetor();
//
//	g->Add_aresta_nao_direcionada(0, 1, 1);
//	g->Add_aresta_nao_direcionada(1, 2, 2);
//	g->Add_aresta_nao_direcionada(2, 3, 6);
//
//	g->Add_aresta_nao_direcionada(3, 4, 3);
//	g->Add_aresta_nao_direcionada(4, 5, 4);
//	g->Add_aresta_nao_direcionada(5, 0, 4);
//	g->Add_aresta_nao_direcionada(5, 1, 6);
//	g->Add_aresta_nao_direcionada(1, 6, 4);
//
//	g->Add_aresta_nao_direcionada(6, 2, 5);
//	g->Add_aresta_nao_direcionada(3, 6, 8);
//	g->Add_aresta_nao_direcionada(5, 6, 3);
//	g->Add_aresta_nao_direcionada(6, 4, 7);
//	
//	Algoritmo::Prim(g, 0);
//*/
//	//Algoritmo::Kruskal(g);
//	
//
//
//	/*for (int i = 0; i < 7; i++)
//
//		g->addVetor();
//	g->addAresta(0, 1, 7);
//	g->addAresta(1, 2, 8);
//	g->addAresta(2, 3, 5);
//	g->addAresta(3, 4, 9);
//	g->addAresta(4, 5, 11);
//	g->addAresta(5, 6, 6);
//	g->addAresta(6, 1, 9);
//	g->addAresta(6, 3, 15);
//	g->addAresta(5, 3, 8);
//	g->addAresta(3, 1, 7);
//	
//	*/
//	/*
//	for (int i = 0; i < 6; i++)
//		g->addVetor();
//	g->Add_aresta_nao_direcionada(0, 1, 6);
//	g->Add_aresta_nao_direcionada(0, 3, 5);
//	g->Add_aresta_nao_direcionada(0, 2, 1);
//	g->Add_aresta_nao_direcionada(1, 2, 2);
//	g->Add_aresta_nao_direcionada(1, 4, 5);
//	g->Add_aresta_nao_direcionada(4, 2, 6);
//	g->Add_aresta_nao_direcionada(4, 5, 3);
//	g->Add_aresta_nao_direcionada(3, 5, 4);
//	g->Add_aresta_nao_direcionada(2, 5, 4);
//	g->Add_aresta_nao_direcionada(3, 2, 2);
//
//
//	Algoritmo::Prim(g, 0);
//
//*/