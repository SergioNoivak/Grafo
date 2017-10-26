#pragma once
#include"No.h"
#include <utility>  
class Conjunto_Disjunto
{
public:
	
	No* Head;
	No* tail;
	
	void Make_set(No* no_do_grafo) {

		this->Head = no_do_grafo;
	}

	Conjunto_Disjunto();

	Conjunto_Disjunto* Union(Conjunto_Disjunto* outro){

		Conjunto_Disjunto* resultado = new Conjunto_Disjunto();
		resultado->Head = this->Head;
		No* ponto_de_juncao = this->tail;
		ponto_de_juncao->conjunto->proximo = outro->Head;
		for (No* i = resultado->Head; i->conjunto->proximo != NULL; i = i->conjunto->proximo) {

			i->conjunto->Conj = this;

		}

		return resultado;

	}
	void Insert(No* no_do_grafo) {

		if (no_do_grafo->conjunto->Conj != this) {
			no_do_grafo->conjunto->proximo = NULL;
			this->tail->conjunto->proximo = no_do_grafo;
			this->tail = this->tail->conjunto->proximo;
		}
	}
	

	Conjunto_Disjunto(No* elemento);
	~Conjunto_Disjunto();
};

