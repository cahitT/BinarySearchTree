/**
* @file  			AgacDugum.hpp  
* @description 		AgacDugum sinifinin baslik dosyasi.  
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/ 

#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP

#include <iostream>
#include <string>
using namespace std;

class AgacDugum
{	
public:
	AgacDugum *pSol;    //Sol cocugu gosteren pointer.
	AgacDugum *pSag;	//Sag cocugu gosteren pointer.
	string veri;		//Dugumun verisini gosteren degisken.
	AgacDugum(string, AgacDugum *, AgacDugum *);	//AgacDugum sinifinin kurucu fonksiyonu.
	~AgacDugum();	//AgacDugum sinifinin yikici fonksiyonu.
};

#endif // !AGACDUGUM_HPP