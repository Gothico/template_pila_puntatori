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
 * 		- devi riconoscere l'autore originario e fornire un link alla 
 * 		  licenza;
 *      - non puoi usare il materiale per scopi commerciali;
 *      - se modifichi, o comunque ti basi su questo materiale devi 
 * 		  distribuire i tuoi elaborati con la stessa licenza.
 * 			
 *
 * Classe eccezione: classe per la gestione delle anomalie
 *
 * Autore: Riccardo Monterisi 
 */
 
#ifndef _eccezione_
#define _eccezione_
#include <iostream>

using namespace std;

class eccezione
 {        
      public:      
             eccezione(char* inp){
                       cerr << inp; 
                       exit(99);
                       };
             ~eccezione(){};
      
    /*
    * ecc(char*):        cotruttore di classe che stampa a video
    *                    una descrizione dell'errore e termina
    *                    l'esecuzione dell'applicazione                                
    * ~ecc():            ditruttore                                        
    */      
}; 
 
 
#endif //_eccezione_
