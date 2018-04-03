/**
* @file  			Islem.hpp  
* @description 		Islem sinifinin baslik dosyasi.  
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			06.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/ 

#ifndef ISLEM_HPP
#define ISLEM_HPP
#include "Agac.hpp"
#include "AgacDugum.hpp"
#include "Dugum.hpp"
#include "Liste.hpp"
#include<string>
#include<string.h>
#include<fstream>
#include<dirent.h>
using namespace std;

class Islem
{
public:
	DIR *dir;			//Girilen dizin yolunu acmamiza saglayan eleman.
	fstream deneme;			//Dosya islemlerini yapmamiza saglayan eleman.
    struct dirent *ent;		//uzerinde islem yapilan eleman.
	int pos;				//dosyanin uzatisini kontrol etmek icin kullandigimiz degisken.
	Liste *list;			//Liste uzerinde islem yapmak icin kullandigimiz eleman.
	Agac *agacListe;		//Agac uzerinde islem yapmak icin kullandigimiz eleman.	
	Islem();				//Islem sinifinin kurucu fonksiyonu.
	void dosyaListesiOlustur(string);	//Liste olusturan fonksiyon.
	void err_sys(const char *);			//Eger girilen yol yanlissa error veren fonksiyon.
	void agacOlustur(string);			//Agac olusturan fonksiyon.
	void islem();						//Butun islemlerin yapildigi icinde fonksiyonlarin cagirildigi fonksiyon.
	~Islem();							//Islem sinifinin yikici fonksiyonu.
};

#endif