#include <stdio.h>

int twostack(int maxSum, int a[], int n, int b[], int m) {
  int sum = 0;
// karena stack = LIFO
  int i = n - 1, j = m - 1;
  int ta = 0, tb = 0;
  
  int tempA[200], tempB[200];
  int bestA[200], bestB[200];
  int best = 0, bestTa = 0, bestTb = 0;

// ambil dari stack A dulu
  while (i >= 0 && sum + a[i] <= maxSum) {
    sum += a[i];
    tempA[ta++] = a[i];
    i--;}
// simpan sebagai best awal
  best = ta;
  bestTa = ta;
  for (int x = 0; x < ta; x++) {
    bestA[x] = tempA[x];}

// coba tambah dari B
  while (j >= 0) {
    sum += b[j];
    tempB[tb++] = b[j];
    j--;
  // kalau melebihi maxSum
    while (sum > maxSum && ta > 0) {
      ta--;
      sum -= tempA[ta];}
  // kalau solusi sekarang lebih bagus
    if (sum <= maxSum && (ta + tb) > best) {
      best = ta + tb;
      bestTa = ta;
      bestTb = tb;//}}
// simpan snapshot terbaik
    for (int x = 0; x < ta; x++) {
        bestA[x] = tempA[x];}
    for (int x = 0; x < tb; x++) {
        bestB[x] = tempB[x];}}}

//output final
  printf("\nTotal Elemen = %d\n", best);
  printf("{ ");
  for (int x = 0; x < bestTa; x++) {
    printf("%d ", bestA[x]);}
  for (int x = 0; x < bestTb; x++) {
    printf("%d ", bestB[x]);}
    printf("}\n");

   /* KALAU TIDAK ADA BEST
   printf("\nTotal Elemen = %d\n", best);
  printf("{ ");
  for (int x = 0; x < ta; x++) {
    printf("%d ", tempA[x]);}
  for (int x = 0; x <tb; x++) {
    printf("%d ", tempB[x]);}
    printf("}\n");*/
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