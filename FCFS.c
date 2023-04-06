//FCFS code.
void fcfs(int art[],int cmt[], int prcn, int maxt){
	int k,m;
	
//Queue variables.
	int q[prcn];
	for(m=1;m<=prcn;m++){
		q[m-1] = -1;
	}
	int qn[prcn];
	int write,read=0;
	
//Start of simulation.
	printf("\nFCFS: ");
	//Simulation clock.	
	for(k=0; k<=maxt; k++){
	//Add processes to the queue when they arrive.
		for(m=1; m<=prcn; m++){
			if(art[m-1]==k){
				q[write] = cmt[m-1];
				qn[write] = m;
				write++;
			}
		}
	//Output based on queue.
		if(q[read]==-1){
			printf("-  ");
		}
		if(q[read]==1){
			printf("P%d ",qn[read]);
			q[read]--;
			read++;
		} else if(q[read]>1 && q[read]<3000){
			printf("P%d ",qn[read]);
			q[read]--;
		}
	}
	read=0; write=0;
}
