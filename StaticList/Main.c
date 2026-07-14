#include <stdio.h>
#include "StaticList.h"
int main(void) {

    insert(0, -87);
    insert(1, -456);
    insert(2, 12);
    display();

    insert(1, 0);
    display();


    delete(0);
    display();

    delete(2);
    display();

    return 0;
}
