#include <stdio.h>


int pa1_1()
{
#ifndef _OJ_
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	// initializations
	int n, selected;
	scanf("%d", &n);
	int * rateA = new int[n];
	int * rateB = new int[n];
	int * rateC = new int[n];

	// read the rate of students from coach
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &rateA[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &rateB[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &rateC[i]);
	}

	scanf("%d", &selected);

	// indA, indB and indC is used for denoting the current first student to inspect for the three coaches
	// count is the number of already assigned students
	int indA = 0, indB = 0, indC = 0, count = 0;
	// memberStatus is to save the status of students, -1 if they are not assigned to any coach
	int * memberStatus = new int[n];
	for (int i = 0; i < n; ++i)
	{
		memberStatus[i] = -1;
	}

	//loop until every student is assigned
	while(count < n){
		for (int i = indA; i < n; ++i)
		{		
			if(memberStatus[rateA[i]] < 0){			// select the student with highest rate and is also not assigned yet.
				indA = i+1;							// avoid inspecting previous student in the next round
				memberStatus[rateA[i]] = 'A';
				count++;
				if(rateA[i] == selected){			// return if the student is the one being asked
					printf("%c\n", memberStatus[selected]);
					return 0;
				}
				break;
			}
		}
		for (int i = indB; i < n; ++i)
		{
			if(memberStatus[rateB[i]] < 0){
				indB = i+1;
				memberStatus[rateB[i]] = 'B';
				count++;
				if(rateB[i] == selected){
					printf("%c\n", memberStatus[selected]);
					return 0;
				}
				break;
			}
		}
		for (int i = indC; i < n; ++i)
		{
			if(memberStatus[rateC[i]] < 0){
				indC = i+1;
				memberStatus[rateC[i]] = 'C';
				count++;
				if(rateC[i] == selected){
					printf("%c\n", memberStatus[selected]);
					return 0;
				}
				break;
			}
		}
	}
	return 0;
}
