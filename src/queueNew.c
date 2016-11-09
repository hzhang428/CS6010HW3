/*
 * queue.c
 *
 *  Created on: Sep 19, 2016
 *      Author: haozhang
 *	Implementation of the queue
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "queueNew.h"

Queue* createQueue() {
	Queue *queue =(Queue*) malloc(sizeof(struct Queue));
	if (queue == NULL) {
		printf("Fatal Error: Out of memory when creating queue\n");
		exit(1);
	}
	queue->front = NULL;
	queue->back = NULL;
	queue->size = 0;
	return queue;
}

void enqueue(Queue *queue, int nodeNumber) {
	Part *newNode = (Part*) malloc(sizeof(struct Part));
	if (newNode == NULL) {
		printf("Fatal Error: Out of memory\n");
		exit(1);
	}
	newNode->nodeNumber = nodeNumber;
	newNode->next = NULL;
	if (queue->size == 0) {
		queue->front = newNode;
		queue->back = newNode;
	} else {
		queue->back->next = newNode;
		queue->back = newNode;
	}
	queue->size++;
}

Part* dequeue(Queue *queue) {
	if (queue->size == 0) {
		return NULL;
	}
	Part *top = (Part*) malloc(sizeof(struct Part));
	top = queue->front;
	if (queue->size == 1) {
		queue->front = NULL;
		queue->back = NULL;
	} else {
		queue->front = queue->front->next;
	}
	queue->size--;
	return top;
}

void printQueue(Queue *queue) {
	Part *current = queue->front;
	while(current != NULL) {
		printf("nodeNumber: %d\n", current->nodeNumber);
		current = current->next;
	}
	free(current);
}

void freeQueue(Queue *queue) {
	Part *current;
	while(queue->front != NULL) {
		current = queue->front;
		queue->front = queue->front->next;
		free(current);
	}
	free(queue);
}

double urand() {
	return (double) rand() / ((unsigned) RAND_MAX + 1);
}

double randexp(double U) {
	return - (U * log(1.0 - urand()));
}
