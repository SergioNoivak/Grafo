#include "stdafx.h"
#include "Conjunto_Disjunto.h"
#include <utility>  





Conjunto_Disjunto::Conjunto_Disjunto(No* elemento)
{
	Make_set(elemento);
	this->Head->conjunto->proximo = NULL;
	this->tail = this->Head;
}
Conjunto_Disjunto::Conjunto_Disjunto() {




}



Conjunto_Disjunto::~Conjunto_Disjunto()
{
}
