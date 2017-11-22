#pragma once
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
				cout << endl << "u:";
				exibe_set(u->conjunto);
				cout << endl << "v:";
				exibe_set(v->conjunto);
				cout << endl;
			}
			conjunto1 = NULL;
			conjunto2 = NULL;
		}

		cout << endl << endl;
		exibir_arestas(resposta);




	}





	
	static void Prim(Grafo* g, int comeco) {
		
		
		multiset<No*, Comp> Q;
		
		No* r = g->retorna_no(comeco);
		r->chave_para_prim = 0;

		for each (No* u in g->vetor)
		{
			if(u!=r)   
				u->chave_para_prim = INT_MAX;
			u->pi = NULL;
			Q.insert(u);

		}

		
		cout << "\n PRIM============\n";
		while (!Q.empty()) {
			No* u = EXTRACT_MIN(Q);
			cout <<" "<< u->nome;
			for each (pair<No*,double> flexa in u->Adj)
			{
				if (pertence(flexa.first, Q)&&flexa.second<flexa.first->chave_para_prim ) {
					/*cout << endl << "{";
					for each (No* var in Q)
					{
						cout << var->chave_para_prim << " ,";
					}
					cout << "}" << endl;*/
					EXTRACT(Q, flexa.first);
					flexa.first->pi = u;
					flexa.first->chave_para_prim = flexa.second;
					Q.insert(flexa.first);
				}
			}
}
		cout << endl;
		for each (No* var in g->vetor)
		{
			cout << " ";
			cout << var->nome<<"["<<var->chave_para_prim<<"] "<< "->";
			var->pi == NULL ? cout << "null" : cout << var->pi->nome;
			cout << endl;
			
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
			if (no == v)
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

		for each (pair<pair<No*, No*>, double> aresta_fisica in arestas)
		{
			cout << "(" << aresta_fisica.first.first->nome << " , " << aresta_fisica.first.second->nome << " , " << aresta_fisica.second << ")" << endl;
		}
	}

	Algoritmo();
	~Algoritmo();
};

