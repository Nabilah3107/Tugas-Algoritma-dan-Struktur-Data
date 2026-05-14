#include <stdio.h>

// fungsi utama greedy
int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int sum = 0;
    int i = 0, j = 0; 
    int count = 0;

    // ambil dari A sebanyak mungkin dulu
    while (i < n && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
    }

    count = i;

    // lalu coba tambah dari B
    while (j < m) {
        sum += b[j];
        j++;

        // kalau melebihi maxSum, kurangi dari A
        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }

        // kalau masih valid, update hasil
        if (sum <= maxSum && (i + j) > count) {
            count = i + j;
        }
    }
    return count;
}

int main() {
    int maxSum = 10;

    int a[] = {3,4,2,1};
    int b[] = {6, 7, 8};

    int n = 4, m = 3;

    int result = twoStacks(maxSum, a, n, b, m);

    printf("Hasil maksimum: %d\n", result);

    return 0;
}