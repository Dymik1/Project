#include <iostream>
#include "Auction.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <iomanip>

using namespace std;


bool check(Person expectant,int price)
{
	if (expectant.money()>price)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void renovation(int a, int b)
{
	float expense, x;
	int profit, loss, k;
    int chance_win=(rand() % 99 + 1);
	if(b<500000)
	{
		expense=(rand() % 65 + 35)*700;
	}
	else if(b>=500000)
	{
		expense=(rand() % 165 + 35)*700;
	}
	cout<<endl<<"REMONT:"<<endl;
	cout<<"Koszt remontu: "<< setw(10) <<expense<<endl;
	if(expense<a)
	{
		if(chance_win>7)
		{
			k=(rand() % 75 + 5);
			profit=(b*k*1.7)/1000;
			cout<<"Zysk ze sprzedazy: "<< setw(10) <<profit<<endl;
		}
		else
		{
			k=(rand() % 30 + 5);
			loss=(b*k)/1000;
			cout<<"Strata ze sprzedazy: "<< setw(10) <<loss<<endl;
		}
	}
	else
	{
		cout<<"Dom nie zostal w pelni ukonczony"<<endl;
		if(chance_win>30)
		{
			k=(rand() % 45 + 5);
			profit=(b*k*1.4)/1000;
			cout<<"Zysk ze sprzedazy: "<< setw(10) <<profit<<endl;
		}
		else
		{
			k=(rand() % 30 + 15);
			loss=(b*k)/1000;
			cout<<"Strata ze sprzedazy: "<< setw(10) << loss<<endl;
		}
	}
	cout<<endl;
}

int main()
{
	srand (time(NULL));
    int price_house, new_price_house, original_price;
    int who, convert,the_richest ;
    int i=0, j=0;
    Person people[20];
    Person Win;
    
    original_price = price_house = (rand() % 60 + 10)*10000;
    cout<<"Cena wywolawcza domu: "<< setw(10) << price_house<<endl<<endl;
    
    for (int i = 0; i < 20; ++i)
	{
  	 	 people[i].description();
	}
	the_richest=people[0].money();
	for(int i = 0; i < 20; ++i)
	{
		if(the_richest<people[i].money())
		{
			the_richest==people[i].money()*people[i].bravery();
		}
	}
	if(the_richest<(price_house-150000))
	{
		price_house=price_house/2;
		original_price = price_house;
		cout<<"Cena wywolawcza domu obnizona do: "<<price_house<<endl;
	}
	do
	{
		who=rand() % (20) + 0;
		//cout<<who<<" ";
		//cout<<check(people[who],price_house)<<endl;
		Sleep(1000);
		if(check(people[who],price_house)==1)
		{
			convert=price_house*people[who].bravery();
			new_price_house=price_house+(convert/(13+j));
			if(check(people[who],new_price_house)==1)
			{
				price_house=new_price_house;
				cout<<"Przelicytowal: "<< setw(12) << left << people[who].name()<<" ";
				Win=people[who];
				cout<<"Nowa cena: "<< setw(10) << price_house<<endl;
				j++;
			}
			i=0;
		}
		switch(i)
		{
			case 2:
				cout<<endl<< price_house <<" Po raz pierwszy!"<<endl<<endl;
				break;
			case 3:
				cout<< price_house <<" Po raz drugi!"<<endl<<endl;
				break;
			case 5:
				cout<< price_house <<" Po raz trzeci! SPRZEDANE!!!"<<endl<<endl;
				break;
		}
		if(price_house>=the_richest || i==5 || price_house>2.5*original_price)
		{
			if(i==5)
			{
				break;
			}
			else
			{
			Sleep(1000);
			cout<< price_house <<" Po raz pierwszy!"<<endl<<endl;
			Sleep(1000);
			cout<< price_house <<" Po raz drugi!"<<endl<<endl;
			Sleep(1000);
			cout<< price_house <<" Po raz trzeci! SPRZEDANE!!!"<<endl<<endl;
			break;	
			}
		}
		i++;
		
	}while(1);
	
	if(j==0)
	{
		cout<<"Aukcji nikt nie wygral"<<endl; 
	}
	else
	{
		cout<<endl<<"Aukcje wygral: "<<Win.name()<<endl;
		cout<<"Wydal: "<< setw(10) << price_house<<endl;
		int rest=Win.money()-price_house;
		cout<<"Pozostalo mu/jej: " << setw(10) << rest<<endl;		
	
		renovation(rest, price_house);	
	}

	 
	system("Pause"); 
    return 0;       
}