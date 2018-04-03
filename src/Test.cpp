/**
* @file  			Test.cpp  
* @description 		Main fonksiyonu bu dosyanin icinde bulunur. 
* @course  			1.Ogretim A - Grubu  
* @assignment  		3.Odev   
* @date    			04.12.2017
* @author  			Cahit Tulum <cahit.tulum@ogr.sakarya.edu.tr>   
*/

#include "Islem.hpp"
using namespace std;

int main()
{
	Islem *program = new Islem();		//Programin baslamasi icin islem sinifindan bir nesne olusturulur.
	program->islem();
	return 0;
}