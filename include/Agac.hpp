/**
* @file  			Agac.hpp  
* @description 		Agac sinifinin alt alanlarinin tanimlamalari burada yer alir.  
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/ 
 
#ifndef AGAC_HPP
#define AGAC_HPP

#include "AgacDugum.hpp"

class Agac
{
private:
	AgacDugum *kok;			//Agaci kontrol etmek icin bas dugumunu gosteren pointer.
	void Ekle(AgacDugum*&, string);		//Agaca eleman eklemek icin cagirilan fonksiyon.
	AgacDugum* Ara(AgacDugum*, string);		//Agac icinde arama yapmak icin cagirdigimiz fonksiyon.
	void Yazdir(AgacDugum *);			//Agacin icindeki degerleri yazdirmak istedigimizde cagirdigimiz fonksiyon.
public:
	Agac();		//agac sinifinin kurucu fonksiyonu.
	void ekle(string);	
	AgacDugum* ara(string);
	void yazdir();					//Private alanda olan fonksiyonlara sinifin disindan ulasabilmek icin yazdigimiz fonksiyonlar.
	bool Bosmu();				//agacin icinde eleman var mi yok mu onu kontrol eden fonksiyon.
	bool DugumSil(AgacDugum*&);		//agactan eleman cikartmak istedigimizde ya da program sonlandiginda agaci temizlemek icin cagirdigimiz fonksiyon.
	void temizle();
	~Agac();
	
};
#endif // !AGAC_HPP