#pragma once

#include<stdio.h>	
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include "Grafo.h"
#include"Algoritmo.h"
using namespace std;

class Persistencia
{

public:
	 static void gravar_em_arquivo(char* nome_arquivo, Grafo* g) {

		FILE* arquivo_gravacao = fopen(nome_arquivo, "w");
		fprintf(arquivo_gravacao, "%d\n", g->numero_estados);
		for each ( No* corrente in g->vetor)
		{

			for each (pair<No*,double> atual in corrente->Adj)
			{
				fprintf(arquivo_gravacao, "%d %.1f ", atual.first->nome, atual.second);
			}

			fprintf(arquivo_gravacao, "\n");
		}

		fclose(arquivo_gravacao);
	
	 }

	 ///Todo LEITURA

	 static Grafo* retorna_grafo_do_arquivo() {
		 fstream arquivo;
		 arquivo.open("ExemploGrafo.txt");
		 Grafo* g = new Grafo();
		 if (arquivo.is_open()) {
			 int x;
			 int tamanho_matriz;
			 arquivo >> tamanho_matriz;
			 vector<vector<int>> matriz;
	
			 	for (int i = 0; i < tamanho_matriz; i++) {
					vector<int> linha;
				 for (int j = 0; j < tamanho_matriz; j++) {
					 arquivo >> x;
					 linha.push_back(x);
				 }
				 matriz.push_back(linha);
			 }

			
				return Algoritmo::matrizparaGrafo(matriz, tamanho_matriz);

			 arquivo.close();
}
		 else {
			 printf("Arquivo nulo");
			 return NULL;
			 
		 }
	 }


	 

	Persistencia();
	~Persistencia();
};

