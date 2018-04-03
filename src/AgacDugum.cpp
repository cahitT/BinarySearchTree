/**
* @file  			Agac.cpp  
* @description 		AgacDugum sinifindan nesne olusturuldugunda gelen degerleri kendi degerlerine atar.  
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/ 

#include "AgacDugum.hpp"


AgacDugum::AgacDugum(string vr, AgacDugum *sl, AgacDugum *sg)
{
	pSol = sl;
	pSag = sg;			//AgacDugum sinifindan bir nesne olustururken gonderdigimiz parametreleri kurucu fonksiyonda sinifin icindeki degiskenlere atandi.
	veri = vr;
}

AgacDugum::~AgacDugum()
{}		//New ile olusan bir eleman olmadigi icin yikici fonksiyon bos.
