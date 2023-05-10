#include<stdio.h>
#include<stdlib.h>



typedef struct dui{
	int data;
	struct dui *next;
}ddui,*DDUI

typedef struct duicon{
	int size;
	struct dui *front;
	struct dui *last;
	
}cdui,*CDUI

