#pragma once
#include<vector>
#include<stdarg.h>
#include<utility>
#include"No.h"
using namespace std;

class Grafo
{
public:
	vector<No*> vetor;
	int numero_estados;
	bool esta_no_vetor(int nome) {
		bool result = false;

		for each (No* no in this->vetor)
		{
			if (no->nome == nome) {
				result = true;
				break;
			}
		}
		return result;
	}

	void addVetor() {
		
			No* novo_no = new No(this->numero_estados);
			this->vetor.push_back(novo_no);
			this->numero_estados++;
	}

	void exibe() {

		for each (No* no in this->vetor)
		{
			no->exibe();
		}
	}
	void Add_aresta_direcionada(int no1,int no2,double peso) {
	
		No* origem = retorna_no(no1);
		No* fim = retorna_no(no2);

		if (origem == NULL || retorna_no(no2) == NULL) {

			printf("\n Impossivel adicionar aresta (%d,%d) \n", no1, no2);
			return;
		}
		origem->addAresta(fim, peso);
	}






















	
	void Add_aresta_nao_direcionada(int no1, int no2, double peso) {
		this->Add_aresta_direcionada(no1, no2, peso);
		this->Add_aresta_direcionada(no2, no1, peso);
	}


	double get_custo_aresta(No* no1, No* no2) {

		for each (pair<No*,double> flexa in no1->Adj)
		{
			if (flexa.first == no2) {
				return flexa.second;
			}
		}
		return -1;
	}




	

	Grafo();
	~Grafo();



	No* retorna_no(int nome) {

		for each (No* corrente in this->vetor)
		{
			if (corrente->nome == nome)
				return corrente;
		}
		return NULL;
	}
};

