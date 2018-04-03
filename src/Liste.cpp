/**
* @file  			Liste.cpp  
* @description 		Liste sinifinda yeni bir eleman ekler yazdirir ve arar.
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/

#include "Liste.hpp"

Liste::Liste()
{
	LB = NULL;				//Liste ilk olustugunda hic dugumu olmadigi icin LB pointerina NULL atanir.
}

void Liste::dugumEkle(string item,Agac *agaclistesi)
{
	Dugum *yeniDugum = new Dugum(item, NULL, agaclistesi);       //Olusan yeni dugumun adresi yeniDugum degiskenine atandi.
	Dugum *temp = LB;
	if (temp != NULL)          //Eger ilkDugumAdresi NULL degilse bu if'in icine girer ve bir sonraki dugumun adresini saklar.
	{
		while (temp->getSonraki() != NULL)    //Elemanin sonrakisi NULL olana kadar doner ve her dugum birbirine baglanmis olur.
		{
			temp = temp->getSonraki();
		}
		temp->setSonraki(yeniDugum);
	}
	else
	{
		LB = yeniDugum;   //Eger daha ilk dugum olusuyosa else kismina girer ve ilkDugumAdresi'ne yeniDugum atanir.
	}
}

void Liste::yazdir()
{
	Dugum *temp = LB;				//Uzerinde islem yapacagimiz icin LB pointeri yedek bir pointera atanir Listeyi kaybetmemek adina.
	while(temp->getSonraki()!=NULL)		//Temp'in sonraki dugumu olmayana kadar devam eder.
	{
		cout<<temp->getVeri()<<" : "<<endl;			//Icınde bulundugu dugumun verisini yazdirir.
		Agac *temp1 = temp->agacListesi;			//Icınde bulundugu dugumun kendisine ozel agacinin adresini yedek bir pointera atar.
		temp1->yazdir();							//Her dugumun kendisine ozel agacinin verilerini yazdirir.
		cout<<endl;
		temp = temp->getSonraki();					//Bir sonraki dugume ilerler.
		if(temp->getSonraki()==NULL)
		{
			Agac *temp1 = temp->agacListesi;			//Eger bir sonraki dugum NULL ise son elemanida yazdirmak adina yukaridaki islemler tekrarlanir.
			cout<<temp->getVeri()<<" : "<< endl;
			temp1->yazdir();
		}
	}
}

void Liste::ara(string aranan)
{
	Dugum *temp = LB;					//Uzerinde islem yapacagimiz icin LB pointeri yedek bir pointera atanir Listeyi kaybetmemek adina.
	while(temp->getSonraki()!=NULL)			//Temp'in sonraki dugumu olmayana kadar devam eder.
	{
		Agac *temp1 = temp->agacListesi;		//Icınde bulundugu dugumun kendisine ozel agacinin adresini yedek bir pointera atar.
		if(temp1->ara(aranan)!=NULL)
		{
			cout<<"Aradiginiz kelime "<<temp->getVeri()<<" dosyasinin icinde."<<endl;			//Eger aranan kelime bulunmus ise icinde bulundugumuz dugumun adini yazar.(Dosya adi)
			break;
		}
		temp = temp->getSonraki();					//Bir sonraki dugume ilerler.
		if(temp->getSonraki()==NULL)
		{
			Agac *temp2 = temp->agacListesi;				//Eger bir sonraki dugum NULL ise son elemanida kontrol etmek adina yukaridaki islemler tekrarlanir
			if(temp2->ara(aranan)!=NULL)
			{
				cout<<"Aradiginiz kelime "<<temp->getVeri()<<" dosyasinin icinde."<<endl;
				break;
			}
			else
			{
				cout<<"Aradiginiz kelime bulunamadi."<<endl;			//Hicbir sart karsilanmadiginda kelimenin agac icinde var olmadigi bilgisini kullaniciya verir.
				break;
			}
		}
	}
}

void Liste::temizle()
{
	Dugum *temp = LB;
	while(LB->getSonraki() != NULL)
	{
		LB = LB->getSonraki();				//Islemler bittiginde liste yer kapladigi alani iade eder.
		delete temp;
	}
	delete LB;
}

Liste::~Liste()
{
	temizle();			//Yikici fonksiyonda listeyi temizleyecek olan fonksiyon cagirilir.
}
