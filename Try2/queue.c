/*
 * queue.c
 *
 *  Created on: Feb 12, 2019
 *      Author: Kaitlin Mazotti
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <setup.h>
#include "queue.h"




int items[SIZE], front = -1, rear = -1;
volatile uint32_t i;

////*****************************************************************************
//// Circular buffer
////*****************************************************************************

void enQueue(int value){
    if(rear == SIZE-1){
        blinkLEDBlue(); // Queue is Full
        for(i=20; i>0; i--);
    }
    else {
        if(front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d", value);
    }
}

void deQueue(){
    if(front == -1){
        blinkLEDRed(); // Queue is Empty
        for(i=20; i>0; i--);
    }
    else{
        printf("\nDeleted : %d", items[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void display(){
    if(rear == -1){
        blinkLEDRed(); // Queue is Empty
        for(i=20; i>0; i--);
    }
    else{
        int i;
        printf("\nQueue elements are:\n");
        for(i=front; i<=rear; i++)
            printf("%d\t",items[i]);
            blinkLEDGreen(); // Queue is Empty
            for(i=20; i>0; i--);
    }
}

