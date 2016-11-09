#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include "start.h"
#pragma warning( disable : 4996) 
using namespace std;

//seek the worst case's index
void select_worst(int num1, int num2, Cand* cands)
{
	int i;
	Cand top;
	priority_queue<Cand, vector<Cand>, NodeCmp> pri_cand;
	for (i = 0; i < num1; i++)
	{
		pri_cand.push(cands[i]);
	}
	top = pri_cand.top();
	printf("worst case is £¨%d,%d£©\n", top.n1, top.n2);
	//return top.index;
}

void comparsion(int num1, int num2, Cand* cands)
{
	int i;
	int sum_d = 0, sum_p = 0, sum = 0, sub;
	Cand* ins;
	Cand* all_cand;

	/*Cand* ins = new Cand[num2];
	Cand* all_cand = new Cand[num1];*/

	ins = (Cand*)malloc(num2*sizeof(Cand));
	all_cand = (Cand*)malloc(num1*sizeof(Cand));
	//init first two cands

	for (i = 0; i < num2; i++)
	{
		ins[i].n1 = cands[i].n1;
		ins[i].n2 = cands[i].n2;
		ins[i].index = i;
		sum_d += ins[i].n1;
		sum_p += ins[i].n2;
	}
	sum = sum_d + sum_p;
	sub = abs(sum_d - sum_p);

	for (i = 0; i < num1; i++)
	{
		all_cand[i].n1 = cands[i].n1;
		all_cand[i].n2 = cands[i].n2;
		all_cand[i].index = i;
	}
	select_worst(num1, num2, all_cand);
	/*first two*/
	printf("sum: %d   sub:%d\n", sum, sub);
	//for (i = num2; i < num1; i++)
	{
		//÷êý¨ØüîÜcandidate??ËÛÝï?

		/*1 åýÍýý¨ØüîÜÝï?û¿£¬ö¦?ú¼ôð?*/
		/*2 åýÍýý¨ØüîÜÜôåýõÌ?îÜcaseû¿£¬ö¦÷ênextîÜìé???ËÛÝï?*/
	}
}

int main()
{
	int cand_num;
	int jury_num;
	int num1, num2;
	/*int temp1, temp2;*/
	Cand *cands;
	FILE *fp;

	fp = fopen("candidates.txt", "r");
	if (fp == NULL)
		exit(0);
	else
		printf("there is such a file\n");

	fscanf(fp, "%d %d", &num1, &num2);
	//printf("The first two numbers are %d %d\n", num1, num2);
	cands = (Cand*)malloc(num1*sizeof(Cand));
	for (int i = 0; i < num1; i++)
	{
		fscanf(fp, "%d %d", &cands[i].n1, &cands[i].n2);
	}
	/*for (int i = 0; i < num1; i++)
	{
		printf("%d %d\n", cands[i].n1, cands[i].n2);
	}*/

	/*-----------------------------------*/
	comparsion(num1, num2, cands);
	/*-----------------------------------*/
	fclose(fp);
	getchar();
	getchar();
	
	return 0;
}