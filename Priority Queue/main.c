#include <stdio.h>
#include "PriorityQueue.h"


int main(void) {
			enqueue(-100, 1);
			enqueue(-200,3);
			enqueue(45, 4);
			enqueue(-98, 2);

			displayQueue();

			dequeue();
			displayQueue();
			return 0;
}
