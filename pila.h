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
 *  Classe pila: fornisce l'interfaccia standard per usare una pila 
 *               
 *
 *  Autore: Riccardo Monterisi  
 */


#ifndef _PILA
#define _PILA

#include <iostream>
#include "nodo.h"
#include "eccezione.h"
using namespace std;

// Cella<T>* è da intendersi  come posizione.
// Non è stato possibile usare tale tipo in quanto il
// typedef Cella<tipoelem>* non è possibile fuori dalla
// classe, come sarebbe necessario, in quanto tipoelem
// non è definito (a compile-time).

template <class T>
class pila
{
public:
	typedef T tipoelem;

	//--metodi pubblici
	pila();
	~pila();

	bool pilaVuota(pila<T>*);
	tipoelem leggiPila(pila<T>* ) throw(eccezione);
	void inPila(tipoelem , pila<T>* );
	void fuoriPila(pila<T>* ) throw (eccezione);
	void stampaPila(pila<T>*);

private:	
    void creaPila(); 
	Cella<T>* TESTA;  // puntatore al primo elemento della pila
	nodo<T> gestore; //gestore delle celle
};

//-----------------realizzazione metodi-------------

template <class T>
pila<T>::pila()
/*
 * FUNZIONAMENTO: cotruttore della classe che chiama il metodo
 * 				  creaPila()
 */
{
	creaPila();
}

template <class T>
pila<T>::~pila()
/*
 * FUNZIONAMENTO: distruttore della classe che "elimina" dapprima
 * 				  tutti gli elementi presenti nella pila e poi
 * 				  libera il puntatore TESTA in modo da liberare
 * 				  la memoria e perdere completamente la struttura
 * 				  al termine del suo utilizzo
 */
{
	while (!gestore.vuota(TESTA))
		gestore.sottrai(TESTA);

	free(TESTA);// distruzione del "cursore"
}

template <class T>
void pila<T>::creaPila()
/*
 * SPECIFICA SEMANTICA CREAPILA = P (EMPTY STACK)
 * 			 POST: P = v(LA SEQUENZA VUOTA)
 *
 * FUNZIONAMENTO: viene inizializzato TESTA, puntatore al primo
 * 				  elemento della pila
 */
{
	TESTA = (Cella<T>*) malloc(sizeof(Cella<T>*));
	//TESTA->elemento = 0;
	TESTA->succ = TESTA;
}

template <class T>
bool pila<T>::pilaVuota(pila<T>  *P)
/*
 * SPECIFICA SEMANTICA: PILAVUOTA(P) = b
 * 			 POST: b = VERO SE P== v,ALTRIMENTI b = FALSO
 *
 * PARAMETRO:    P puntatore che si riferisce all'intera pila
 *
* FUNZIONAMENTO: viene invocato il metodo vuota dell'oggetto gestore
* 				 per avere il risultato booleano sullo stato della pila
 */
{
	return  P->gestore.vuota(P->TESTA);
}


template <class T>
T pila<T>::leggiPila(pila<T>  *P) throw (eccezione)
/*
 * SPECIFICA SEMANTICA: LEGGIPILA(P)= a (TOP)
 *  					PRE: P = a1, a2, …, an n>=1
 *  					POST: a = a1
 *
 * PARAMETRO:     P puntatore che si riferisce all'intera pila
 *
 * FUNZIONAMENTO: se la pila non è vuota viene restituito
 * 				  l'elemento di testa
 */
{
	T output;
	if (!(P->pilaVuota(P)))
		output =  P->gestore.leggi(P->TESTA);
	else//lanciare un'eccezione
		throw eccezione("Errore la pila e` vuota!");
	return output;
}


template <class T>
void pila<T>::inPila(tipoelem a, pila<T>* P)
/*
 * SPECIFICA SEMANTICA: INPILA(a, P)= P' (PUSH)
 * 						PRE:  P = a1, a2, …, an n >= 0
 * 						POST: P'= a, a1, a2, …, an
 *
 * PARAMETRI: a  elemento di tipo tipoelem che rappresenta
 * 			     il valore del nuovo elemento della pila
 * 			  P  puntatore che si riferisce all'intera pila
 *
 * FUNZIONAMENTO: viene chiamato il metodo il metodo aggiungi
 * 				  dell'oggetto gestore per aggiungere il nuovo
 * 				  elemento
 */
{

	P->gestore.aggiungi(a, P->TESTA);
}

template <class T>
void pila<T>::fuoriPila(pila<T>* p) throw (eccezione)
/*
 * SPECIFICA SEMANTICA: FUORIPILA(P)= P' (POP)
 * 						PRE:  P = a1, a2, …, an n >= 1
 * 						POST: P'= a2, a3, …, an SE n >= 1, SE n=1 P’= v
 *
 * PARAMETRO:     P puntatore che si riferisce all'intera pila
 *
 * FUNZIONAMENTO: se la pila non è vuota viene chiamato il metodo
 * 				  sottrai dell'oggetto gestore per rimuovere l'elemento
 * 				  di testa
 */
{
	if (!(p->pilaVuota(p)))
		gestore.sottrai(p->TESTA);
	else
     throw eccezione("Errore la pila e` vuota!");
}


template <class T>
void pila<T>::stampaPila(pila<T>* p)
/*
 * PARAMETRO:     P puntatore che si riferisce all'intera pila
 *
 * FUNZIONAMENTO: se la pila non è vuota, viene letto, stampato
 * 				  a video e poi rimosso l'elemento di testa, quindi
 * 				  si richiama ricorsivamente l'intero metodo
 */
{
	T elemento;

	if (!(p->pilaVuota(p))) {
		elemento = p->leggiPila(p);
		p->fuoriPila(p);

		cout << " Elemento: " << elemento;
		cout << "\n";
		stampaPila(p);
		p->inPila(elemento, p);
	}
}

#endif //_PILA
