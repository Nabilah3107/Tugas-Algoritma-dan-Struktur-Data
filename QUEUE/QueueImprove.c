#include <stdio.h>

int in[100000], out[100000];
int topIn = -1, topOut = -1;
int servedCount = 0;

// enqueue
void enqueue(int x) {
  in[++topIn] = x;}

// pindahkan dari IN ke OUT
void shift() {
  if (topOut == -1) {
    while (topIn >= 0) {
        out[++topOut] = in[topIn--];}}}

// dequeue
void dequeue() {
  shift();
  if (topOut >= 0) {
    printf("Antrian keluar: %d\n", out[topOut]);
    topOut--;
    servedCount++;
  } else {
    printf("Antrian kosong!\n");}}

// print front
void printFront() {
  shift();
  if (topOut >= 0) {
    printf("Antrian paling depan: %d\n", out[topOut]);
  } else {
    printf("Antrian kosong!\n");}}

// tampilkan stack IN
void showIn() {
  printf("Ruang tunggu (IN): ");
  if (topIn == -1) {
    printf("Kosong");
  } else {
    for (int i = topIn; i >= 0; i--) {
      printf("%d ", in[i]);}}
      printf("\n");}

// tampilkan stack OUT
void showOut() {
  printf("Stack OUT: ");
  if (topOut == -1) {
    printf("Kosong");
  } else {
    for (int i = topOut; i >= 0; i--) {
      printf("%d ", out[i]);}}
      printf("\n");}
  
//tampilkan nasabah yang sudah dilayani
void served(){
  printf("Total Yang Sudah Dilayani = %d", servedCount);}


int main() {
  int type;
  printf("\t\t\tKAMU SEBAGAI KASIR\n");
  printf("\n============================\n");
  printf("\n============TYPE============\n");
  printf("1 = Masukkan antrian\n");
  printf("2 = Panggil / dequeue\n");
  printf("3 = Lihat antrian depan\n");
  printf("4 = Lihat berapa orang yang sudah dilayani\n");
  printf("0 = Keluar program\n");
  printf("============================\n");
  while (1) {
    printf("Masukkan type: ");
    scanf("%d", &type);
    // EXIT
      if (type == 0) {break;}

    // ENQUEUE
    else if (type == 1) {
      int n;
      printf("Masukkan jumlah antrian yang kamu inginkan: ");
      scanf("%d", &n);
      for (int i = 0; i < n; i++) {
        int x;
        printf("Masukkan nomor antrian ke-%d: ", i + 1);
        scanf("%d", &x);
        enqueue(x);}

      printf("\nSETELAH MASUK KE RUANG TUNGGU (IN) = \n");
      showIn();}
      
  // SHIFT + DEQUEUE
    else if (type == 2) {
      printf("\nSEBELUM KELUAR DARI RUANG TUNGGU (SHIFT) = \n");
      showIn();
      shift();
      printf("SETELAH KELUAR DARI RUANG TUNGGU (OUT) = \n");
      showOut();
      dequeue();}
        
  // PRINT FRONT
    else if (type == 3) {
      shift();
      printf("\nSETELAH SHIFT KE OUT\n");
      showOut();
      printFront();}
    
  // Meliht Jumlh yng sudah dilayani
    else if (type == 4) {
      served();printf("\n");}
          
    else {
      printf("Type tidak valid!\n");}}
return 0;
}