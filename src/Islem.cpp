/**
* @file  			Islem.cpp  
* @description 		Islem sinifi kullanicinin yaptigi islemleri gerceklestirir.
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			06.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/ 

#include "Islem.hpp"

Islem::Islem()
{
	list = new Liste();			//Yeni bir liste olusturulur.	
}

void Islem::dosyaListesiOlustur(string dosyaYolu)
{
	if ((dir = opendir(dosyaYolu.c_str())) == NULL) 
        err_sys("opendir");			//Eger girilen yol yanlissa error verir.

    while ((ent = readdir(dir)) != NULL) 	//Butun dosyalar alinana kadar devam eder.
    {   
		pos = strlen(ent->d_name) - 4;		//Dosyanin uzunlugunu alip 4 cikartir uzantisini bulabilmek icin.

        if (! strcmp(&ent->d_name[pos], ".txt"))	//Eger uzantisi .txt ise islemleri yapar.
        {
			agacListe = new Agac();		//Yeni bir agac olusturur.
            list->dugumEkle(ent->d_name,agacListe);		//Listeye her bir dosya icin dugum ekleyip dosyanin ismini dugumun verisine atar.
			string dosya = dosyaYolu+"\\"+ent->d_name;		//Dizinin icindeki dosyalari alip acabilmek icin dosya yolu ve dosya ismini birlestiriyoruz. 
			agacOlustur(dosya);		//Agac olusturmak icin fonksiyonu cagirir.
		}
	}
    closedir(dir);		//Acilan dizini kapatir.
}

void Islem::err_sys(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void Islem::agacOlustur(string dosyaAdi)
{	
	ifstream read;
	string yazi;			//Dosya islemlerini yapmak icin degiskenler belirlenir.
	read.open(dosyaAdi);	//Verilen parametreye gore dosya acilir.
	if (read.is_open())
	{
		while (read >> yazi)		//Eger dosya acildiysa icini okumaya baslar.
		{
			agacListe->ekle(yazi);		//Txt dosyasi okundukca agaca eleman eklenir.
		}
	}
	else
	{
		cout<<"dosya acilamadi!";		//Eger dosya yolu duzgun degilse dosya acilamadi bilgisi kullaniciya verilir.
	}
	read.close();		//Acilan dosya kapatilir.
}

void Islem::islem()
{
	string dosyaYolu;
	int secim=0;
	cout<<"Klasor: ";
	getline(cin,dosyaYolu);		//Kullanicidan klasoru acmak icin dosya yolu alinir.
	
	dosyaListesiOlustur(dosyaYolu);
	
	while(secim<3)		//Kullanicinin karsisina 3 girilene kadar menu cikartilir.
	{
		cout<<"1.Arama Yap"<<endl<<"2.Listele"<<endl<<"3.Cikis"<<endl;
		cout<<"Seciminiz: ";
		cin>>secim;
		if(secim==1)
		{
			string aranan;
			cout<<"Aramak istediginiz kelime: ";		//Eger secim 1 ise arama yapmak icin kendisinden bir kelime alinir.
			cin>>aranan;
			list->ara(aranan);
		}
		else if(secim==2)
		{
			list->yazdir();		//Eger secim 2 ise liste ve agac ekrana basilir.
		}
		else if(secim==3)
		{
			cout<<"Gorusmek uzere!"<<endl;		//Secim 3 ise programdan cikis yapilir.
		}
		else
		{
			cout<<"Yanlis bir secim yaptiniz."<<endl;		//Farkli bir secim girilirse duzeltmesi icin secim 0'lanir.
			secim=0;
		}
		cout<<endl;
	}
}

Islem::~Islem()
{
	delete list;		//Islem bittiginde liste silinir.
}






























