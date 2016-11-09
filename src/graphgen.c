#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "queueNew.h"
#define N 100

int addNode(Queue array[N],int nodeIndex){
	//decide connectIndex
	double randomNumber = (rand()%100)/100.0;
	double p[nodeIndex];
	double lastP = 0;
	int connectIndex = 0;
	for(int i = 0; i < nodeIndex; i ++){
		double size = (&(array[i]))->size;
		p[i] = size/(nodeIndex*2) + lastP;
		if(randomNumber <= p[i]){
			connectIndex = i;
			break;}
		lastP = p[i];
	}
	//connect nodes & update QueueArray
	Queue *newQ = createQueue();
	enqueue(newQ, connectIndex);
	array[nodeIndex] = *newQ;
	enqueue(&(array[connectIndex]), nodeIndex);
	return connectIndex;
}

int main(){
//	initial parameter
//	time_t t;
//	srand((unsigned) time(&t));
	Queue array[N];

	//fully connected topology
	Queue *q0 = createQueue();
	enqueue(q0,1);
	enqueue(q0,2);
	array[0] = *q0;
	Queue *q1 = createQueue();
	enqueue(q1,0);
	enqueue(q1,2);
	array[1] = *q1;
	Queue *q2 = createQueue();
	enqueue(q2,0);
	enqueue(q2,1);
	array[2] = *q2;

	//add new nodes
	FILE *f=fopen("output.txt","w");
	fprintf(f,"%d,%d\n",0, 1);
	fprintf(f,"%d,%d\n",1, 2);
	fprintf(f,"%d,%d\n",2, 0);
	for(int i = 3; i < N; i ++){
		int temp = addNode(array, i);
		fprintf(f,"%d,%d\n",i, temp);
	}
	fclose(f);

	//find max degree
	int maxDegree = 0;
	for(int i = 0; i < N; i ++){
		int tempSize = (&(array[i]))->size;
		if( tempSize > maxDegree){
			maxDegree = tempSize;
		}
	}
	//make degree array
	int degreeArray[maxDegree];
	for(int i = 0; i < maxDegree; i ++){
		degreeArray[i] = 0;
	}
	for(int i = 1; i < N; i ++){
		int tempSize = (&(array[i]))->size;
		degreeArray[tempSize] += 1;
	}
	printf("maxDegree: %d\n",maxDegree);

	//print for check
	//for(int i = 0; i < N; i ++){
	//	printf("第%d个点\n",i);
	//	printQueue(&(array[i]));
	//}

	//for(int i = 0; i < maxDegree; i ++){
	//	printf("%d\n",degreeArray[i]);
	//}
	return 0;
}


