#include <stdio.h>
#include "print.h"

void printString( void *data )
{
    char *str = (char *)data;
    printf("%s ", str);
}

void printInteger( void *data )
{
    int *iNum = (int *)data;
    printf("%d ", *iNum);
}

void printFloat( void *data )
{
    float *fNum = (float *)data;
    printf("%f ", *fNum);
}

void printDouble( void *data )
{
    double *dNum = (double *)data;
    printf("%f ", *dNum);
}

void printCharacter( void *data )
{
    char *ch = (char *)data;
    printf("%c ", *ch);
}
