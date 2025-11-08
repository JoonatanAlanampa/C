#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rectangle.h"
#include "vertailu.h"

int rectAlaVrt(const void *a, const void *b)
{
    Rectangle * const *x = a;
    Rectangle * const *y = b;
    if((*x)->width*(*x)->height==(*y)->width*(*y)->height)
    {
        return 0;
    }
    else
    {
        return ((*x)->width*(*x)->height>(*y)->width*(*y)->height) ? 1 : -1;
    }
}

int rectXyVrt(const void *a, const void *b)
{
    Rectangle * const *x = a;
    Rectangle * const *y = b;
    if((*x)->origin.x==(*y)->origin.x)
    {
        if((*x)->origin.y==(*y)->origin.y)
        {
            return 0;
        }
        else
        {
            return ((*x)->origin.y>(*y)->origin.y) ? 1 : -1;
        }
    }
    else
    {
        return ((*x)->origin.x>(*y)->origin.x) ? 1 : -1;
    }
}

int rectLeveysVrt(const void *a, const void *b)
{
    Rectangle * const *x = a;
    Rectangle * const *y = b;
    if((*x)->width==(*y)->width)
    {
        return 0;
    }
    else
    {
        return ((*x)->width>(*y)->width) ? -1 : 1;
    }
}

int mjPitAakkosVrt(const void *a, const void *b)
{
    char * const *x = a;
    char * const *y = b;
    if(strlen(*x)==strlen(*y))
    {
        return (strcmp(*x, *y));
    }
    else
    {
        return (strlen(*x)>strlen(*y)) ? -1 : 1;
    }
}
