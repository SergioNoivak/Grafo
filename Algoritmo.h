#pragma once
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<stdlib.h>
#include"Grafo.h"
#include"No.h"
using namespace std;
class Algoritmo
{

public:
	static Grafo* matrizparaGrafo(vector<vector<int>> matriz, int dim) {

		Grafo* g = new Grafo();
		int estado_corrente = -1;

		for (int i = 0; i < dim; i++)
			g->addVetor();
		int i = 0;
		int j = 0;
		for each (vector<int> linha in matriz)
		{
			for each(int value in linha) {
				if (value >= 0) {
					g->addAresta(i, j, value);
				}
				j++;
			}
			j = 0;
			i++;
		}

		return g;

	}

	static void Kruskal(Grafo* g) {

		vector <pair<pair<No*, No*>, double>> resposta;
		for each (No* vertice in g->vetor)
		{
			vertice->MAKE_SET();
			cout << endl;
			exibe_set(vertice->conjunto);
			cout << endl;
		}

		vector <pair<pair<No*, No*>, double>> arestas;
		iniciar_arestas(arestas, g);
		ordenar_arestas(arestas);
		exibir_arestas(arestas);
		cout << endl << endl;

		for each (pair<pair<No*, No*>, double> aresta_fisica in arestas)
		{

			No* u = aresta_fisica.first.first;
			No* v = aresta_fisica.first.second;
			set<No*>* conjunto1 = u->FIND_SET();
			set<No*>* conjunto2 = v->FIND_SET();
			if (conjunto1 != conjunto2) {
				cout << endl;
				cout << "\nconjunto1:(u)\n";
				exibe_set(conjunto1);
				cout << endl;
				cout << "\nconjunto2:(v)\n";
				exibe_set(conjunto2);
				resposta.push_back(aresta_fisica);
				cout << "Resposta:" << endl;
				exibir_arestas(resposta);
				cout << endl;
				u->UNION(v);
				cout << "\n====Conjuntos apos juncao :" << endl;
				cout <<endl<< "u:";
				exibe_set(u->conjunto);
				cout << endl << "v:";
				exibe_set(v->conjunto);
				cout << endl;
			}
			conjunto1=NULL;
			conjunto2=NULL;
		}

		cout << endl << endl;
		exibir_arestas(resposta);

		


	}


	static void exibe_set(set<No*>* conjunto) {
		cout << "{";
		for each (No* var in *conjunto)
		{
			cout << var->nome<<" ";
		}  

		cout << "}";

	}

	
	/**
		retorna por referencia um o conjunto que o no está
		caso não esteja retorna um conjunto vazio
	*/
	








static bool compare(pair<pair<No*, No*>, double>& a, pair<pair<No*, No*>, double>& b) {
	if (a.second < b.second)
		return true;
	return false;
}

static void ordenar_arestas(vector <pair<pair<No*, No*>, double>>& arestas) {
	sort(arestas.begin(), arestas.end(), compare);
}

static void iniciar_arestas(vector <pair<pair<No*, No*>, double>>& arestas,Grafo* g) {

	for each (No* no_vetor in g->vetor)
	{
		for each (pair<No*, double> flexa in no_vetor->Adj)
		{
			pair<No*, No*> aresta_posicional;
			aresta_posicional.first = no_vetor;
			aresta_posicional.second = flexa.first;
			pair<pair<No*, No*>, double> aresta_fisica;
			aresta_fisica.first = aresta_posicional;
			aresta_fisica.second = flexa.second;
			arestas.push_back(aresta_fisica);		}
	}
}

static void exibir_arestas(vector <pair<pair<No*, No*>, double>> arestas) {

	for each (pair<pair<No*, No*>, double> aresta_fisica in arestas)
	{
		cout << "(" << aresta_fisica.first.first->nome << " , " << aresta_fisica.first.second->nome << " , " << aresta_fisica.second << ")" << endl;

	}


}



	Algoritmo();
	~Algoritmo();
};

