/**
* @file  			Agac.cpp  
* @description 		Agac sinifinda arama yazma ekleme islemi yapar.
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/

#include "Agac.hpp"

Agac::Agac()
{
	kok = NULL;			//Agac olustugunda basta hic eleman olmadigi icin kok'e NULL degeri atandi.
}

void Agac::ekle(string yeni)
{
	Ekle(kok,yeni);			//Private alandaki Ekle() fonksiyonu cagirildi parametre olarakta kok'u ve eklemek istedigimiz degeri gonderdik.
}

AgacDugum* Agac::ara(string aranan)
{
	return Ara(kok,aranan);			//Private alandaki Ara() fonksiyonu cagirildi bu fonksiyon bize kelimenin bulundugu dugumu gonderiyor.
}

void Agac::yazdir()
{
	Yazdir(kok);			//Yine Private alandaki Yazdir() fonksiyonu cagirildi kokten itibaren baslayip sona kadar icindeki degerleri yazdiriyor. 
}

void Agac::Ekle(AgacDugum *&alt,string item)
{
	if (alt == NULL)
	{
		alt = new AgacDugum(item,NULL,NULL);		//Rekürsif fonksiyonlar sonucunda artik parametreyle gelen alt degiskeni NULL ise yeni bir dugum olusturuluyor. Ya da agacta daha once hic eleman yok ise.
	}
	else if(alt->veri > item)
	{
		Ekle(alt->pSol, item);			//Eklerken parametreyle gonderdigimiz deger icinde bulundugumuz dugumun verisinden kucuk ise dugumun sol tarafina eklenmesi icin Ekle() fonksiyonu cagiriliyor.
	}
	else if (alt->veri < item)
	{
		Ekle(alt->pSag, item);			//Eklerken parametreyle gelen deger icinde bulundugumuz dugumun verisinden buyuk ise dugumun sag tarafina eklenmesi icin tekrar Ekle() fonksiyonu cagiriliyor.
	}
	else return;						//Eger gelen deger dugumdeki degere esit ise agaca eklenmeden hicbir islem yapmadan return ediliyor.
}

AgacDugum* Agac::Ara(AgacDugum *alt,string item)
{
    if (alt == NULL || alt->veri == item)		//alt degiskeni NULL ise veya gonderilen deger dugumdeki degere esit ise alt degiskeni donduruluyor.
       return alt;
    if (alt->veri < item)					//Gelen degisken dugumdeki degiskenden buyuk ise artik o dugumun sag tarafinda arama yapiliyor.
       return Ara(alt->pSag, item);
    return Ara(alt->pSol, item);			//Gelen degisken dugumdeki degiskenden kucuk ise artik o dugumun sol tarafinda arama yapiliyor.
}

void Agac::Yazdir(AgacDugum* alt) 
{
	if (alt != NULL) 
	{
		Yazdir(alt->pSol);
		cout << alt->veri << " ";				//Yazdirirken inorder yontemi kullandigimiz icin once agacin en soluna gidip en kucuk degerden itibaren yazdirmaya basliyor.
		Yazdir(alt->pSag);
	}
}

bool Agac::Bosmu()
{
	return kok == NULL;					//Eger kok NULL'a esitse true donduruluyor.
}

bool Agac::DugumSil(AgacDugum *&alt)
{
	AgacDugum *silinecekDugum = alt;			//Uzerinde islem yapacagimiz icin kok degeri silinecekDugum degiskenine ataniyor. Eger direk kok uzerinden islem yapilirsa agaci kaybederiz.
			
	if(alt->pSag == NULL) alt = alt->pSol;		//Eger sag cocuk yoksa sol cocuga gider.
	else if(alt->pSol == NULL) alt = alt->pSag;		//Eger sol cocuk yoksa sag cocuga gider.
	else
	{
		silinecekDugum = alt->pSol;				//Eger yapraga geldiysek yani iki cocukta NULL ise silme islemine baslanir.
		AgacDugum *ebeveynDugum = alt;
		while(silinecekDugum->pSag != NULL)
		{
			ebeveynDugum = silinecekDugum;				
			silinecekDugum = silinecekDugum->pSag;
		}
		alt->veri = silinecekDugum->veri;
		if(ebeveynDugum == alt)
			alt->pSol = silinecekDugum->pSol;
		else
			ebeveynDugum->pSag = silinecekDugum->pSol;
	}
	delete silinecekDugum;
	return true;
}

void Agac::temizle()
{
	while(!Bosmu())
	{
		DugumSil(kok);			//Agac bos olana kadar devam eder yani kok NULL olana kadar ve agac temizlenir.
	}
}

Agac::~Agac()
{
	temizle();			//Islem bittiginde yikici fonksiyonda agaci temizleyecek olan temizle() fonksiyonu cagirilir.
}


