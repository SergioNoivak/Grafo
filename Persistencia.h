#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#include "Grafo.h"
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
/*
	 static void retorna_grafo(char* nome_arquivo) {
		 FILE* arquivo_leitura = fopen(nome_arquivo, "r");
		 int numero_de_nos = -1;
		 fscanf(arquivo_leitura, "%d", &numero_de_nos);
		 printf("%d", numero_de_nos);
		 char buffer[10000];
		 char *tokenize;
		 int i = 0;
		 while (!feof(arquivo_leitura)) {
			 cout << endl << i << endl;
			 fgets(buffer, 10000, arquivo_leitura);
			 tokenize = strtok(buffer, " ");
			 while (tokenize != NULL) {
				 cout << "*" << tokenize << endl;
				 tokenize = strtok(NULL, " ");
			 }
			 i++;
		 }
	 }
*/


	Persistencia();
	~Persistencia();
};

