// ConsoleApplication27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Student 
{
	char fio[64]; 
	char date[16]; 
	char city[32]; 
	double bal; 
};

struct List 
{
	Student Student; 
	List *pNext; 
};


void addFirst(List *& pF, 
	List* p) /
{
	p->pNext = pF;
	pF = p;
}

List * delFirst(List *&pF) 
{
	if (pF == 0) return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;

}

bool add(List *&pF, List * pZad, List *p)
{

	if (pZad == pF) 
	{
		p->pNext = pF;
		pF = p;
		return true;
	}

	List *pPred = pF; 
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false; 
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}

List * del(List*& pF, List *p) 
{
	if (pF == 0) return 0;
	if (pF == p) 
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF; 
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0) return 0; 
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF)); 
}

int main(int argc, char* argv[])
{
	List *pF = 0; 
	List *p;
	
	char Ch; 
	do
	{
		p = (List *)malloc(sizeof(List)); 
		printf("\nFIO: ");
		fflush(stdin); gets_s(p->Student.fio, 63);
		printf("Date: ");
		fflush(stdin); gets_s(p->Student.date, 15);
		printf("city: ");
		fflush(stdin); gets_s(p->Student.city, 31);
		printf("bal=");
		fflush(stdin); scanf_s("%lf", &p->Student.bal);
		addFirst(pF, p); 
		printf("For continue press Y or y else any key! ");
		Ch = _getche(); 
	} while (Ch == 'Y' || Ch == 'y');
	
	for (List *pi = pF; pi; pi = pi->pNext) 
		printf("\n%s %s %s oklad=%.2f", pi->Student.fio, pi->Student.date,
			pi->Student.city, pi->Student.bal);

	for (List *pi = pF; pi->pNext;)
	{
		
		double min = pi->Student.bal;
		List *pmin = pi;
		for (List *pj = pi->pNext; pj; pj = pj->pNext)
			if (pj->Student.bal<min)
			{
				min = pj->Student.bal;
				pmin = pj;
			}
		if (pi != pmin) 
		{
			del(pF, pmin);
			add(pF, pi, pmin);
		}
		else pi = pi->pNext;
	}
	
	printf("\nSrting:");
	for (List *pi = pF; pi; pi = pi->pNext) 
		printf("\n%s %s %s bal=%.2f", pi->Student.fio, pi->Student.date,
			pi->Student.city, pi->Student.bal);
	printf("\nFor exit press any key ");
	system("pause"); 
	return 0;
}
