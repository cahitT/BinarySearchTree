/**
* @file  			Liste.hpp  
* @description 		Liste sinifinin baslik dosyasi.  
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>
*/

#ifndef LISTE_HPP
#define LISTE_HPP

#include "Dugum.hpp"

class Liste
{
private:
	Dugum *LB;				//Dugumlerden olusan listenin bas dugumunu gosteren pointer.
public:
	Liste();				//Liste sinifinin kurucu fonksiyonu.
	void dugumEkle(string,Agac *);		//Dugum eklemek istersek cagirilan fonksiyon.
	void yazdir();						//Dugumlerden olusan listenin verilerini yazdirmak istersek cagirilan fonksiyon.
	void ara(string);					//Bir veriyi aramak istedigimizde cagirlan fonksiyon.
	void temizle();						//Listeyi temizleyen ve cop birakmayan fonksiyon.
	~Liste();							//Liste sinifinin yikici fonksiyonu.
};

#endif // !LISTE_HPP