#pragma once
#include <map>
#include<limits>
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
					g->Add_aresta_direcionada(i, j, value);
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
		}

		vector <pair<pair<No*, No*>, double>> arestas;
		iniciar_arestas(arestas, g);
		ordenar_arestas(arestas);


		for each (pair<pair<No*, No*>, double> aresta_fisica in arestas)
		{

			No* u = aresta_fisica.first.first;
			No* v = aresta_fisica.first.second;
			set<No*>* conjunto1 = u->FIND_SET();
			set<No*>* conjunto2 = v->FIND_SET();
			if (conjunto1 != conjunto2) {
				resposta.push_back(aresta_fisica);
				u->UNION(v);
			}
			conjunto1 = NULL;
			conjunto2 = NULL;
		}
		cout << "Solucao do Algoritmo de KRUSKAL:";
		cout << "\n Arvore Geradora Minima =";


		exibir_arestas(resposta);

	}


	static void Prim(Grafo* g, int comeco) {


		vector<pair<No*, No*>> solucao;
		No* r = g->retorna_no(comeco);
		if (r != NULL) {
			r->chave_para_prim = 0;
			map<No*, bool> B;
			map<No*, bool> A;
			for each (No* var in g->vetor)
			{
				if (var != r) {
					B.insert(make_pair(var, true));

				}
			}
			A.insert(make_pair(r, true));
			

			while (!B.empty()) {
				pair<No*, No*> aresta_minima = MINIMUM_PAIR(A, B, g);
				B.erase(aresta_minima.second);
				A.insert(make_pair(aresta_minima.second, true));
				solucao.push_back(aresta_minima);
			}
			cout << "Solucao do Algoritmo de PRIM:";
			cout << "\n Arvore Geradora Minima = {";
			int soma_de_pesos = 0;
			for each (pair<No*, No*> var in solucao)
			{
				soma_de_pesos += g->get_custo_aresta(var.first, var.second);
				cout << " (" << var.first->nome << " ; " << var.second->nome << ")   ";
			}
			cout << "} CUSTO : "<<soma_de_pesos<<"\n";
		}
		else {
			cout << "\n O grafo nao possui esse vertice inicial para prim" << endl;;
		}
	}

	static No* EXTRACT_MIN(multiset<No*, Comp>& Q) {
		No* u = *Q.begin();
		Q.erase(Q.begin());
		return u;
	}
	static void EXTRACT(multiset<No*, Comp>& Q,No* no) {
		
		for (multiset<No*, Comp>::iterator it = Q.begin(); it != Q.end(); ++it)
		{
			if ((*it)->nome == no->nome) {
				Q.erase(it);
				break;
		}
	}

		
	}


	static pair<No*, No*> MINIMUM_PAIR(map<No*,bool> A, map<No*, bool> B, Grafo* g) {
		
		pair<No*, No*> aresta;
		double minimo = INT_MAX;
		for each (pair<No*,bool> n_a in A)
		{
			for each (pair<No*, bool> n_b in B)
			{
				
				int value = g->get_custo_aresta(n_a.first, n_b.first);
				if (minimo > value && value > 0) {
					minimo = value;
					aresta.first = n_a.first;
					aresta.second = n_b.first;
				}
			}
		}
		return aresta;
	}


	static void exibe_set(set<No*>* conjunto) {
		cout << "{";
		for each (No* var in *conjunto)
		{
			cout << var->nome << " ";
		}

		cout << "}";

	}



	static bool pertence(No* v, multiset<No*,Comp> Q) {

		for each (No* no in Q)
		{
			if (no->nome == v->nome)
				return true;
		}
		return false;
	}




	/**
		retorna por referencia um o conjunto que o no está
		caso não esteja retorna um conjunto vazio
	*/
	static bool compare_No(No* a, No* b) {
		if (a->chave_para_prim < b->chave_para_prim)
			return false;
		return true;
	}


	static bool compare_aresta(pair<pair<No*, No*>, double>& a, pair<pair<No*, No*>, double>& b) {
		if (a.second < b.second)
			return true;
		return false;
	}

	static void ordenar_arestas(vector <pair<pair<No*, No*>, double>>& arestas) {
		sort(arestas.begin(), arestas.end(), compare_aresta);
	}

	static void iniciar_arestas(vector <pair<pair<No*, No*>, double>>& arestas, Grafo* g) {

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
				arestas.push_back(aresta_fisica);
			}
		}
	}

	static void exibir_arestas(vector <pair<pair<No*, No*>, double>> arestas) {

		cout << "{ ";
		int soma_dos_pesos=0;
		for each (pair<pair<No*, No*>, double> aresta_fisica in arestas)
		{
			cout << "(" << aresta_fisica.first.first->nome << " ; " << aresta_fisica.first.second->nome << ")"<<"   ";
			soma_dos_pesos += aresta_fisica.second;
		}

		cout << "} ";

		cout << "CUSTO : " << soma_dos_pesos<<endl;
	}

	Algoritmo();
	~Algoritmo();
};

