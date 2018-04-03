/**
* @file  			Dugum.cpp  
* @description 		Dugum sinifindan nesne olusturuldugunda gelen degerleri kendi degiskenlerine atar.
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/
 
#include "Dugum.hpp"



Dugum::Dugum(string eleman,Dugum *snrk,Agac *agc)
{
	sonraki = snrk;
	m_veri = eleman;				//Dugum sinifindan bir nesne olustururken gonderilen parametreleri dugum sinifinin icindeki degerlere atar.
	agacListesi = agc;
}

void Dugum::setSonraki(Dugum *ileri)
{
	sonraki = ileri;			//Gelen degeri sinifin icindeki ilgili degiskene atar.
}

void Dugum::setVeri(string item)
{
	m_veri = item;				//Gelen degeri sinifin icindeki ilgili degiskene atar.
}

Dugum * Dugum::getSonraki()
{
	return sonraki;				//Sinifin icindeki private alanda olan degiskeni dondurur.
}


string Dugum::getVeri()
{
	return m_veri;				//Sinifin icindeki private alanda olan degiskeni dondurur.
}

Dugum::~Dugum()
{}
