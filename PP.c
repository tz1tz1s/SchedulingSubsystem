//PP code.
void pp(int art[],int cmt[],int prio[], int prcn, int maxt){
	int k,m;
	int temp;
	
//Queue variables.
	int q[prcn];
	for(m=1;m<=prcn;m++){
		q[m-1] = -1;
	}
	int qp[prcn];
	for(m=1;m<=prcn;m++){
		qp[m-1] = 1000;
	}
	int qn[prcn];
	int write,read=0;
	
//Start of simulation.
	printf("\nPP  : ");
	//Simulation clock.		
	for(k=0; k<maxt; k++){
	//Add processes to the queue when they arrive.
		for(m=1; m<=prcn; m++){
			if(art[m-1]==k){
				q[write] = cmt[m-1];
				qn[write] = m;
				qp[write] = prio[m-1];
				write++;
			}
		}
	//Sort processes based on priority.
		for(m=prcn-1;m>0;m--){
			if(qp[m]<qp[m-1]){
				temp = q[m];
				q[m] = q[m-1];
				q[m-1] = temp;
				temp = qn[m];
				qn[m] = qn[m-1];
				qn[m-1] = temp;
				temp = qp[m];
				qp[m] = qp[m-1];
				qp[m-1] = temp;
			}
		}
	//Output based on queue.
		if(q[read]==-1){
			printf("-  ");
		}
		if(q[read]==1){
			printf("P%d ",qn[read]);
			q[read]--;
			qp[read]=-1;
			read++;
		} else if(q[read]>0 && q[read]<3000){
			printf("P%d ",qn[read]);
			q[read]--;
		}
	}
	read = 0; write = 0;
}
