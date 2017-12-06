#pragma once
#include "Grafo.h"
#include"No.h"
#include<vector>
#include<set>
#include<stdio.h>
#include <utility>  
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Rede_de_fluxo : public Grafo
{
public:
	void set_fluxo(int no1, int no2, double novo_fluxo) {
		No* origem = this->retorna_no(no1);
		No* destino = this->retorna_no(no2);

		if (origem == NULL || destino == NULL) {
			cout << "impossivel mudar fluxo ";
			return;
		}
		int indice = origem->indice_no_vetor_de_fluxo(destino);
		if (indice == -1) {
			cout << "nao existe essa aresta";
			return;
		}
		origem->fluxo.at(indice) = novo_fluxo;
	}


	void exibe() {

		for each (No* no in this->vetor)
		{
			printf("%d |", no->nome);
				int i = 0;
				for each (pair<No*, double> aresta in no->Adj)
				{
					printf("%d-[%.d/%d]-->", aresta.first->nome, (int)aresta.second, (int)no->fluxo.at(i));
					i++;
				}
				printf("null\n");
			
		}
	
}

	
	Rede_de_fluxo();
	~Rede_de_fluxo();
};

