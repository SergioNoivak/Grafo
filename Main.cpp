// GrafosAulas.cppQ'32AA!3cde41aqw2sde4'1	'2qwsxfsxssxde4tfgr6v5b 5taqsw2xsftgr56 da3e41	'2qswcde4ttf51	'AQSW2XTVFGUBNHYYUAQSW2XAX3CDE4TT5A1Q : define o ponto de entrada para o aplicativo do console.
//
#include<queue>
#include<Windows.h>
#include "stdafx.h"
#include"Rede_de_fluxo.h"
#include<iostream>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#include"Persistencia.h"
using namespace std;
int main()
{
		Rede_de_fluxo* rede = new Rede_de_fluxo();
		

			for (int i = 0; i < 9; i++)
				rede->addVetor();

			rede->Add_aresta_direcionada(0, 1, 4);
			rede->Add_aresta_direcionada(1, 2, 8);
			rede->Add_aresta_direcionada(2, 3, 7);
			rede->Add_aresta_direcionada(4, 3, 9);
			rede->Add_aresta_direcionada(4, 5, 10);
			rede->Add_aresta_direcionada(6, 7, 1);
			rede->Add_aresta_direcionada(5, 6, 2);
			rede->Add_aresta_direcionada(7, 0, 8);
			rede->Add_aresta_direcionada(7, 1, 11);
			rede->Add_aresta_direcionada(7, 8, 7);
			rede->Add_aresta_direcionada(8, 2, 2);
			rede->Add_aresta_direcionada(8, 6, 6);
			rede->Add_aresta_direcionada(2, 5, 4);
			rede->Add_aresta_direcionada(5, 3, 14);
			
			rede->exibe();
			rede->BFS(0, 4);
			cout << endl;

			stack<No*> caminho = rede->gerar_caminho(0, 4);
			cout << endl << "CAMINHO"<<endl;
				while(!caminho.empty())
				{
					No* var = caminho.top();
					cout << var->nome << " ";
					caminho.pop();
				}
			
		system("Pause");
}


/*
for (int i = 0; i < 9; i++)
rede->addVetor();

rede->Add_aresta_direcionada(0, 1, 4);
rede->Add_aresta_direcionada(2, 3, 7);
rede->Add_aresta_direcionada(3, 4, 9);
rede->Add_aresta_direcionada(4, 5, 10);
rede->Add_aresta_direcionada(6, 7, 1);
rede->Add_aresta_direcionada(5, 6, 2);
rede->Add_aresta_direcionada(1, 2, 8);
rede->Add_aresta_direcionada(7, 0, 8);
rede->Add_aresta_direcionada(7, 1, 11);
rede->Add_aresta_direcionada(7, 8, 7);
rede->Add_aresta_direcionada(8, 2, 2);
rede->Add_aresta_direcionada(8, 6, 6);
rede->Add_aresta_direcionada(2, 5, 4);
rede->Add_aresta_direcionada(5, 3, 14);
rede->exibe();
cout << endl;
rede->set_fluxo(0, 1, 11);
rede->set_fluxo(8, 6, 77);
rede->exibe();
cout << endl;*/

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