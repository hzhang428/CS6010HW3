/*
 * queue.h
 *
 *  Created on: Sep 19, 2016
 *      Author: haozhang
 *  Struct of Node and Queue, and the abstract methods of the queue
 */

#ifndef QUEUE_H_
#define QUEUE_H_

/**
 * Definition of the Node
 */
typedef struct Part{
	int nodeNumber;
	struct Part *next;
}Part;

/**
 * Definition of the Queue
 */
typedef struct Queue{
	Part *front;
	Part *back;
	int size;
}Queue;

/**
 * Methods to create and FIFO queue
 */
Queue * createQueue();

/**
 * Methods to add one Node at the back of the queue
 */
void enqueue(Queue *queue, int nodeNumber);

/**
 * Methods to pull a Node from the front of the queue
 */
Part * dequeue(Queue *queue);

/**
 * Print out all the Node in the queue
 */
void printQueue(Queue *queue);

/**
 * Free the memory that is hold by the queue
 */
void freeQueue(Queue *queue);

/**
 * Generate a random number that is in the range of [0,1)
 */
double urand();

/**
 * Generate a random number from an exponential distribution
 * with mean of U
 */
double randexp(double U);

#endif /* QUEUE_H_ */
