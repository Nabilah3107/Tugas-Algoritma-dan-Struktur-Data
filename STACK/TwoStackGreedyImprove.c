#include <stdio.h>

int twostack(int maxSum, int a[], int n, int b[], int m) {
  int sum = 0;
// karena stack = LIFO
  int i = n - 1, j = m - 1;
  int count = 0;
  int best, bestTa, bestTb;

// ambil dari stack A dulu
  while (i >= 0 && sum + a[i] <= maxSum) {
    sum += a[i--];
    count++;}
// simpan sebagai best awal
  best = count;
  bestTa = i;
  bestTb = j;

// coba tambah dari B
  while (j >= 0) {
    sum += b[j--];
    count++;
  // kalau melebihi maxSum
    while (sum > maxSum && i < n-1) {
      sum -= a[++i];
      count--;}
  // kalau solusi sekarang lebih bagus
    if (sum <= maxSum && count > best) {
      best = count;
      bestTa = i;
      bestTb = j;}}

//output final
  printf("\nTotal Elemen = %d\n", best);
  printf("{ ");
  for (int x = n-1; x > bestTa; x--) {
    printf("%d ", a[x]);}
  for (int x = m-1; x > bestTb; x--) {
    printf("%d ", b[x]);}
    printf("}\n");
return best;
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
    scanf("%d", &a[i]);}

  printf("\nMasukkan (push) elemen stack 2:\n");
  for (int j = 0; j < m; j++) {
    printf("ke %d = ", j + 1);
    scanf("%d", &b[j]);}

  printf("\nMaxSum = ");
  scanf("%d", &maxSum);

  twostack(maxSum, a, n, b, m);
  return 0;
}