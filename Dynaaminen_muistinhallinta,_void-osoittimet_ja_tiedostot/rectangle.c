#include <stdlib.h>

struct Point
{
  int x;
  int y;
};

typedef struct Point Point;

struct Rectangle
{
  int width;
  int height;
  Point origin;
};

typedef struct Rectangle Rectangle;

Rectangle * createRectangle(void)
{
    Rectangle *rect = malloc(sizeof(Rectangle));

    rect->width=0;
    rect->height=0;
    rect->origin.x=0;
    rect->origin.y=0;

    return rect;
}

Rectangle * createRectangle2(Point p)
{
    Rectangle *rect = malloc(sizeof(Rectangle));

    rect->width=0;
    rect->height=0;
    rect->origin=p;

    return rect;
}

Rectangle * createRectangle3(int w, int h)
{
    Rectangle *rect = malloc(sizeof(Rectangle));

    rect->width=w;
    rect->height=h;
    rect->origin.x=0;
    rect->origin.y=0;

    return rect;
}

Rectangle * createRectangle4(Point p, int w, int h)
{
    Rectangle *rect = malloc(sizeof(Rectangle));

    rect->width=w;
    rect->height=h;
    rect->origin=p;

    return rect;
}

void move(Rectangle *r, int x, int y)
{
    r->origin.x=x;
    r->origin.y=y;
}

int getArea(const Rectangle *r)
{
    int area;

    area = r->width*r->height;

    return area;
}
