/**
* @file  			Dugum.hpp  
* @description 		Dugum sinifinin baslik dosyasi.  
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/ 

#ifndef DUGUM_HPP
#define DUGUM_HPP
#include "Agac.hpp"
#include <iostream>
using namespace std;
class Dugum
{
private:
	Dugum *sonraki;			//Kendinden bir sonraki dugumu gosterek olan pointer.
	string m_veri;			//Listenin icindeki dugumu gosterecek olan degisken yani dosya adlarini.
public:
	Agac *agacListesi;			//Her dugumun kendine ozel bir agaci olacagindan dugumlerin icinde Agac turunden bir degisken.
	Dugum(string,Dugum*,Agac*);		//Dugum sinifinin kurucu fonksiyonu.
	void setSonraki(Dugum*);		//Sonraki pointerina degisken atayan fonksiyon.
	void setVeri(string);			//Dugumun verisine degisken atayan fonksiyon.
	Dugum* getSonraki();			//Sonraki dugumunu donduren fonksiyon.
	string getVeri();				//Dugumun verisini donduren fonksiyon.
	~Dugum();						//Dugum sinifinin yikici fonksiyonu.
};

#endif // !DUGUM_HPP