#pragma once
#include<vector>

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
	void addAresta(int no1,int no2,double peso) {
	
		No* origem = retorna_no(no1);
		No* fim = retorna_no(no2);

		if (origem == NULL || retorna_no(no2) == NULL) {

			printf("\n Impossivel adicionar aresta (%d,%d) \n", no1, no2);
			return;
		}
		origem->addAresta(fim, peso);
	}
	





	void Kruskal() {
		

		//vector<pair<No*, No*>> arestas_ordenadas;
		//vector<vector<No*>> set;
		//for each (No* no in this->vetor)
		//{
		//	set.push_back(Algoritmos::MAKE_SET(no));
		//}



	}


	Grafo();
	~Grafo();

private:

	No* retorna_no(int nome) {

		for each (No* corrente in this->vetor)
		{
			if (corrente->nome == nome)
				return corrente;
		}
		return NULL;
	}
};

