#pragma once	
#include<vector>
#include<set>
#include<stdio.h>
#include <utility>  
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class No
{
private:

	bool existe_Em_Adj(No* no) {

		bool result = false;
		for each (pair<No*, double> corrente in this->Adj)
		{
			if (corrente.first->nome == no->nome) {
				result = true;
				break;
			}


		}return result;
	}

public:
	vector<pair<No*, double>> Adj;
	int nome;
	set<No*>* conjunto;
	No* pi;
	int chave_para_prim;

	void addAresta(No* no, double peso) {
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
		for each (pair<No*, double> aresta in this->Adj)
		{

			printf("%d-[%.2f]-->", aresta.first->nome, aresta.second);
		}
		printf("null\n");
	}

	void MAKE_SET() {
		this->conjunto = new set<No*>();
		this->conjunto->clear();
		this->conjunto->insert(this);

	}
	set<No*>* FIND_SET() {

		return this->conjunto;

	}


	void UNION(No* v) {

		for each (No* no  in *(v->conjunto))
		{	
			this->conjunto->insert(no);
			no->conjunto = this->conjunto;

		}
	
	
	
	}


	void set_SET(set<No*>* novo) {
		this->conjunto = novo;
	}



	No(int nome);
	~No();

};


struct Comp {

	bool operator() (No* p1, No* p2)
	{
		return p1->chave_para_prim < p2->chave_para_prim;
	}

};