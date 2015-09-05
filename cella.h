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
 *
 * Classe cella: contiene il template che rappresenta l'unità
 *		 della pila con puntatori
 *
 *  Autore: Riccardo Monterisi  
 */

#ifndef CELLA_H_
#define CELLA_H_

template <class T> class Cella
{
	public:
		T elemento;
		Cella<T>* succ;
};


#endif /* CELLA_H_ */
