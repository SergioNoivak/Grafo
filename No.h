#pragma once	
#include<vector>
#include<stdio.h>
#include <utility>  
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class No
{
private:

	bool existe_Em_Adj(No* no) {

		bool result = false;
		for each (pair<No*,double> corrente in this->Adj)
		{
			if (corrente.first->nome == no->nome) {
				result = true;
				break;
			}

			
		}return result;
	}

public:


	vector<pair<No*,double>> Adj;
	int nome;
	void addAresta(No* no,double peso) {
		if (this->existe_Em_Adj(no)) {

			printf("\n o No %d nao foi adicionado no No %d pois ja foi adicionado anteriormente\n", no->nome, this->nome);
			return;
		}
		pair<No*, double> nova_aresta;
		nova_aresta.first = no;
		nova_aresta.second = peso;
		this->Adj.push_back(nova_aresta);
	}

	void exibe() {
		printf("%d |", this->nome);
		for each (pair<No*,double> aresta in this->Adj)
		{	
			
			printf("%d-[%.2f]-->", aresta.first->nome,aresta.second);
		}
		printf("null\n");
	}
	
	No(int nome);
	~No();

};