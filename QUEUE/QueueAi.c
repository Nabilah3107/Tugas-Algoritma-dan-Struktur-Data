#include <stdio.h>

int in[100000], out[100000];
int topIn = -1, topOut = -1;

void enqueue(int x) {
    in[++topIn] = x;
}

void shift() {
    if (topOut == -1) {
        while (topIn >= 0) {
            out[++topOut] = in[topIn--];
        }
    }
}

void dequeue() {
    shift();
    if (topOut >= 0) {
        topOut--;
    }
}

void printFront() {
    shift();
    if (topOut >= 0) {
        printf("%d\n", out[topOut]);
    }
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if (type == 2) {
            dequeue();
        }
        else if (type == 3) {
            printFront();
        }
    }

    return 0;
}