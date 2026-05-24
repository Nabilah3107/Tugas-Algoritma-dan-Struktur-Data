#include <stdio.h>

int best = 0;
int bestA = 0, bestB = 0;

void solve(int a[], int n, int b[], int m,
           int i, int j,
           int sum, int count,
           int maxSum) {

    // kalau melebihi batas
    if (sum > maxSum)
        return;

    // simpan solusi terbaik
    if (count > best) {
        best = count;
        bestA = i;
        bestB = j;
    }

    // ambil dari stack A
    if (i < n)
        solve(a, n, b, m,
              i + 1, j,
              sum + a[n - 1 - i],
              count + 1,
              maxSum);

    // ambil dari stack B
    if (j < m)
        solve(a, n, b, m,
              i, j + 1,
              sum + b[m - 1 - j],
              count + 1,
              maxSum);
}

int main() {
    int n, m, maxSum;
    int a[100], b[100];

    printf("\t\tTWO STACK\n\n");

    printf("Masukkan jumlah elemen stack 1 = ");
    scanf("%d", &n);

    printf("Masukkan jumlah elemen stack 2 = ");
    scanf("%d", &m);

    printf("\nMasukkan (push) elemen stack 1:\n");
    for (int i = 0; i < n; i++) {
        printf("ke %d = ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nMasukkan (push) elemen stack 2:\n");
    for (int i = 0; i < m; i++) {
        printf("ke %d = ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nMaxSum = ");
    scanf("%d", &maxSum);

    solve(a, n, b, m, 0, 0, 0, 0, maxSum);

    printf("\nTotal Elemen = %d\n", best);

    printf("{ ");

    for (int i = 0; i < bestA; i++)
        printf("%d ", a[n - 1 - i]);

    for (int i = 0; i < bestB; i++)
        printf("%d ", b[m - 1 - i]);

    printf("}\n");

    return 0;
}