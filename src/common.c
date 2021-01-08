#include <common.h>

Size NewSize(float width, float height)
{
    Size win = *(Size*)calloc(1, sizeof(Size));
    win.Width = width;
    win.Height = height;
    return win;
}

Point NewPoint(float x, float y)
{
    Point point = *(Point*)calloc(1, sizeof(Point));
    point.x = x;
    point.y = y;
    return point;
}

void DestroySize(Size* s){
    free(s);
}

void DestroyPoint(Point* p){
    free(p);
}
