#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;



struct uczen
{
        string imie,nazwisko;
        int wiek;
        
        
        
        


};

class klasa
{
                vector <struct uczen> spis;
       
        public:
        		void wczytajZPliku(const char *);  
                void wypisz();
                void zapiszDoPliku(const char *);
                void sort();
                              
};

int func(const void * a, const void * b)
{
	       
   return ( *(int*)a - *(int*)b );
}

void klasa::wczytajZPliku(const char *nazwa)
{
        struct uczen dane;
ifstream plik1;
plik1.open(nazwa);  

   if(plik1.good())  
            while(!plik1.eof())  
                 {
                 plik1  >> dane.wiek;
                  plik1  >> dane.imie;
                   plik1  >> dane.nazwisko;

                         spis.push_back(dane); 
                 }
                   plik1.close();  
               }



void klasa::sort()
{
		
	qsort(&spis[0],spis.size(), sizeof(struct uczen), func); 
	
	for (int i=0; i<spis.size(); i++)
	{
		for(int i=0;i<spis.size();++i)
		
 			cout<<spis[i];
	}
	

}


void klasa::wypisz()
{
		string napis;
		ifstream plik;
		    plik.open("a.txt");
		    if(plik.good())
		     while(!plik.eof())
		
		    {
		        plik>>napis;
		    }
		    plik.close();
}




void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                  plik <<"["<<"{"<<it->wiek<<":"<<it->imie<<":"<<it->nazwisko<<"]"<< "\n";
              	  cout <<"["<<"{"<<it->wiek<<":"<<it->imie<<":"<<it->nazwisko<<"]"<< "\n";
        }
        plik.close();  
}




int main(int argc, char** argv) {
        klasa TI;
        TI.wczytajZPliku("b.txt");
        TI.sort();
        TI.wypisz();
        TI.zapiszDoPliku("a.txt");

    
        return 0;
}
