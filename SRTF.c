//SRTF code
void srtf(int art[],int cmt[], int prcn, int maxt){
	int k,m;
	int temp;
	
//Queue variables.
	int q[prcn];
	for(m=1;m<=prcn;m++){
		q[m-1] = 1000;
	}
	int qn[prcn];
	int write,read=0;
	
//Start of simulation.
	printf("\nSRTF: ");
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
	//Sort processes based on time remaining.
		for(m=prcn-1;m>0;m--){
			if(q[m]<q[m-1]){
				temp = q[m];
				q[m] = q[m-1];
				q[m-1] = temp;
				temp = qn[m];
				qn[m] = qn[m-1];
				qn[m-1] = temp;
			}
		}
	//Output based on queue.
		if(q[read]==1000){
			printf("-  ");
		}
		if(q[read]==1){
			printf("P%d ",qn[read]);
			q[read]--;
			q[read]=-1;
			read++;
		} else if(q[read]>0 && qn[read]<3000){
			printf("P%d ",qn[read]);
			q[read]--;
		}
	}
	read = 0; write =0 ;
}
