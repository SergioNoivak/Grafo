#pragma once
#include"validacao.h"
#include "Grafo.h"
#include"cores.h"
#include"No.h"
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<stdio.h>
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
	 void BFS(No* fonte,No* sorvedouro) {
		 stack<No*> Q;
		 for each (No* no in this->vetor)
		 {
			 no->cor = branco;
			 no->pi = NULL;
		 }
		 fonte->pi = NULL;
		 Q.push(fonte);
		 while (!Q.empty()) {
			 No* u = Q.top();
			 Q.pop();
			 for each (pair<No*,double> flexa in u->Adj)
			 {
				 No* v = flexa.first;
				 if (v->cor == branco) {

					 v->cor = cinzento;
					 v->pi = u;
					 Q.push(v);

				 }

			 }
			 u->cor = preto;
		 }
	}

	

	 int BFS(int fonte, int sorvedouro) {

		 No* no_fonte = this->retorna_no(fonte);
		 No* no_sorvedouro = this->retorna_no(sorvedouro);
		 if (no_fonte == NULL || no_sorvedouro == NULL) {
			 cout << "os nos nao estao no vetor para BFS";
			 return falha ;
		 }		 
		 this->BFS(no_fonte, no_sorvedouro);
		 return sucesso;
}
	 
	 
	 /**
	 
	 
	 */
	 stack<No*> gerar_caminho(int fonte, int sorvedouro) {

		 BFS(fonte, sorvedouro);
		 stack<No*> resposta;
		 No* no_sorvedouro = this->retorna_no(sorvedouro);
		 No* i = no_sorvedouro;
		 while (i != NULL) {
			 resposta.push(i);
			 i = i->pi;
		 }

		 if (resposta.size() <= 1) {
		 
			 return *new stack<No*>;
		 
		 }
		 return resposta;
	 }





	
	Rede_de_fluxo();
	~Rede_de_fluxo();
};

