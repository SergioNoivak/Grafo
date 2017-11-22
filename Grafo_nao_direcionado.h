#pragma once
#include "Grafo.h"
class Grafo_nao_direcionado : public Grafo
{
public:
	void addAresta(int no1, int no2, double peso) {
		Grafo::Add_aresta_direcionada(no1, no2, peso);
		Grafo::Add_aresta_direcionada(no2, no1, peso);
	}


	Grafo_nao_direcionado();
	~Grafo_nao_direcionado();
};

