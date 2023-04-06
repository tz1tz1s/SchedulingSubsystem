#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"
#include "PP.h"
#include "SRTF.h"

//Fanction that creates the simulation time. 
int Time(int art[],int cmt[], int prcn){
	
	int maxa,maxc,maxt = 0;
	int min = 1000;
	int m;
	int p;
	
	for(m=0; m<=prcn-1; m++){
		if(art[m]>=maxa){
			maxa = art[m];
			p=m;
		}
	}
	for(m=0; m<=prcn-1; m++){
		if(art[m]<min){
			min = art[m];
		}
	}
	for(m=0; m<=prcn-1; m++){
		maxc = maxc+cmt[m]-1;
	}
	if(maxc >= maxa+cmt[p]){
		maxt = maxc+min;
	}else {
		maxt = maxa+cmt[p];
	}
	return (maxt); 
}
//Fanction that creatrs the time table for the Gantt chart.
void TimeTable(int maxt){
	int m;
	printf("Time:");
	if(maxt>10){
		for(m=1; m<10 ;m++){
			printf(" %d ",m);
		}
		printf(" ");
		for(m=10; m<=maxt; m++){
			printf("%d ",m);
		}
	}
	else{
		for(m=1; m<=maxt ;m++){
			printf(" %d ",m);
		}
	} 
}

int main(int argc, char *argv[]){
    int i,t;
    int prcn;
    int tmqm;
    int select=10;

 //Set processes.
    printf("Select the number of processes: ");
    scanf("%d", &prcn);
    int art[prcn];
    int cmt[prcn]; 
    int prio[prcn];
    for(i=1; i<=prcn; i++){
    		printf("Process %d:\n",i);
            printf("Arrival time: "); 
            scanf("%d", &art[i-1]);
            printf("Complition time: ");
            scanf("%d", &cmt[i-1]);
			printf("Priority: ");  
            scanf("%d", &prio[i-1]);
			printf("\n");                                      
    }
    int time = Time(art,cmt,prcn);
	while (select != 0){
		printf("\n\nSelect a method.\n1) First come first served.\n2) Priority based Preemptive.\n3) Shortest Remaining Time First.\n4) All of the above.\n0) Close program.\n");
		scanf("%d",&select);
		switch (select) {
			case 1:
				TimeTable(time);
				fcfs(art,cmt,prcn,time);
				break;
			case 2:
				TimeTable(time);
				pp(art,cmt,prio,prcn,time);
				break;
			case 3:
				TimeTable(time);
				srtf(art,cmt,prcn,time);
				break;
			case 4:
				TimeTable(time);
				fcfs(art,cmt,prcn,time);
				pp(art,cmt,prio,prcn,time);
				srtf(art,cmt,prcn,time);
				break;
			case 0:
				printf("Good bye!!!");
				break;
			default:
				printf("---!!Select one the numbers please!!---");
		}
	}
	return 0;
}
