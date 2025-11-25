#pragma once
#include <stdio.h>
// 02 Struct
typedef struct Point {
    int x, y;
} Point;

void move(Point* p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}
int main()
{
    struct Point u = { 1,2 };
    move(&u, 3, 4);
    printf("u= %i , %i", u.x, u.y);
    return 0;
}

#include <stdio.h>

int main() {
    int a[3];  // локальний масив без ініціалізації

    for (int i = 0; i < 3; i++) {
        printf("%d ", a[i]);  // значення "сміттєві"
    }
    printf("\n");
    return 0;
}

