#include <stdio.h>

struct point {
    int x;
    int y;
};


struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y) {
    struct point temp;
    
    temp.x = x;
    temp.y = y;

    return temp;
};


int main() {
    //struct point p = {0,0};

    struct point p;
    struct rect r;
    p.x=0;
    p.y=0; 

    r.pt1 = makepoint(0,0);
    r.pt2 = makepoint(5,10);

}