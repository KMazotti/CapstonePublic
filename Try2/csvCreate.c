/*
 * csvCreate.c
 *
 *  Created on: Feb 14, 2019
 *      Author: Kaitlin Mazotti
 */

#include<stdio.h>

#include<string.h>

void createCSV(char *filename,int a[][3],int n,int m){

    printf("\n Creating %s.csv file",filename);

    FILE *fp;

    int i,j;

    filename=strcat(filename,".csv");

    fp=fopen(filename,"w+");

    fprintf(fp,"Student Id, Physics, Chemistry, Maths");

    for(i=0;i<m;i++){

        fprintf(fp,"\n%d",i+1);

        for(j=0;j<n;j++)

            fprintf(fp,",%d ",a[i][j]);

        }

    fclose(fp);

    printf("\n %sfile created",filename);

}
