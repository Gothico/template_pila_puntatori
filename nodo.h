/*
 * Tale sorgente è distribuito secondo licenza CC BY-NC-SA 4.0: 
 * 			http://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 * 
 * Tu sei libero di:
 *    - condividere — riprodurre, distribuire, comunicare al pubblico, 
 * 		esporre in pubblico, rappresentare, eseguire e recitare 
 * 		questo materiale con qualsiasi mezzo e formato; 
 *    - modificare — remixare, trasformare il materiale e basarti su di 
 * 		esso per le tue opere.
 * 	
 * Il licenziante non può revocare questi diritti fintanto che tu 
 * rispetti i termini della licenza alle seguenti condizioni:
 * 	- devi riconoscere l'autore originario e fornire un link alla licenza;
 *      - non puoi usare il materiale per scopi commerciali;
 *      - se modifichi, o comunque ti basi su questo materiale devi 
 * 	  distribuire i tuoi elaborati con la stessa licenza.
 * 			
 * Classe nodo: rappresenta il gestore delle celle
 *
 * Autore: Riccardo Monterisi 
 */

#ifndef NODO_H_
#define NODO_H_

#include"cella.h"

template <class T>
class nodo {
public:
	nodo() {};
	~nodo(){};
	bool vuota(Cella<T>*);
	T leggi(Cella<T>*);
	void aggiungi(T a, Cella<T>*);
	void sottrai(Cella<T>*);
};


//---implementazioni

template <class T>
bool nodo<T>::vuota(Cella<T>* t)
/*
 * PARAMETRO:     t puntatore di tipo Cella<T>* indicante
 * 			      la testa della pila
 *
 * FUNZIONAMENTO: si verifica che la testa non punti ad un elemento
 */
{
	bool out = false;
	if (t->succ == t)
		out = true;

	return out;
}

template <class T>
T nodo<T>::leggi(Cella<T>* t)
/*
 * PARAMETRO:     t puntatore di tipo Cella<T>* indicante
 * 			      la testa della pila
 *
 * FUNZIONAMENTO: si restituisce il campo elemento dell'elemento
 * 				  puntato da t
 */
{
	T out = t->succ->elemento;
	return out;
}

template <class T>
void nodo<T>::aggiungi(T a, Cella<T>* t)
/*
 * PARAMETRO:     t puntatore di tipo Cella<T>* indicante
 * 			      la testa della pila
 *
 * FUNZIONAMENTO: si inserisce una nuova cella che viene puntato
 * 				  da t (testa della pila) e il cui successivo è il
 * 				  precedente elemento puntato da t
 */
{
	Cella<T>* temp;

	temp = (Cella<T>*) malloc(sizeof(Cella<T>*));
	temp->elemento = a;
	if (vuota(t)) {
		temp->succ = NULL;
		t->succ = temp;
	}
	else {
		Cella<T>* prov;
		prov = (Cella<T>*) malloc(sizeof(Cella<T>*));

		prov = t->succ;
		//prov->succ = NULL;
		temp->succ = prov;
		t->succ = temp;
	}
}

template <class T>
void nodo<T>::sottrai(Cella<T>* t)
/*
 * PARAMETRO:     t puntatore di tipo Cella<T>* indicante
 * 			      la testa della pila
 *
 * FUNZIONAMENTO: si collega t con l'elemento successivo alla testa
 * 				  della pila che così ha un elemento in meno
 */
{
	Cella<T>* temp;

	temp = t->succ;
    if (temp->succ == NULL)
    	t->succ = t;
    else
    	t->succ = temp->succ;
	free(temp);
}



#endif /* NODO_H_ */
