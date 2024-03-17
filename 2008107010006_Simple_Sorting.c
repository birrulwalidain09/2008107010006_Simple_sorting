// Birrul Walidain
// 2008107010006
// Tugas 2 SDA


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Menghasilkan bilangan acak
int generateBilanganAcak() {
  return rand() % 1000000;
}

// Menukar nilai 2 variable
void tukar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// bubble sort
void bubbleSort(int *data, int jumlahData) {
  for (int i = 0; i < jumlahData - 1; i++) {
    for (int j = 0; j < jumlahData - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        tukar(&data[j], &data[j + 1]);
      }
    }
  }
}

// selection sort
void selectionSort(int *data, int jumlahData) {
  for (int i = 0; i < jumlahData - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < jumlahData; j++) {
      if (data[j] < data[minIndex]) {
        minIndex = j;
      }
    }
    tukar(&data[minIndex], &data[i]);
  }
}

// insertion sort
void insertionSort(int *data, int jumlahData) {
  for (int i = 1; i < jumlahData; i++) {
    int key = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > key) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
  }
}

// Fungsi untuk menuliskan bilagan ke file txt
void tulisKeFile(int *data, int jumlahData, char *namaFile) {
  FILE *fp = fopen(namaFile, "w");
  for (int i = 0; i < jumlahData; i++) {
    fprintf(fp, "%d ", data[i]);
  }
  fclose(fp);
}

int main() {
  clock_t waktuAwal, waktuAkhir; 

  // Generate random numbers
  srand(time(NULL));

  for (int jumlahData = 100000; jumlahData <= 1000000; jumlahData += 100000) {
    printf("Mengurutkan %d data...\n", jumlahData);
    
    // Array to store numbers
    int *data = malloc(jumlahData * sizeof(int));

    // Generate random numbers
    for (int i = 0; i < jumlahData; i++) {
      data[i] = generateBilanganAcak();
    }

    // Menuliskan bilangan acak ke dalam file txt
    tulisKeFile(data, jumlahData, "data_acak.txt");

    // Menghitung waktu eksekusi bubble sort
    waktuAwal = clock();
    bubbleSort(data, jumlahData);
    waktuAkhir = clock();
    double waktuBubbleSort = (double)(waktuAkhir - waktuAwal) / CLOCKS_PER_SEC;

    // Menuliskan hasil bubble sort ke dalam file
    tulisKeFile(data, jumlahData, "data_bubble_sort.txt");

    // Menghitung waktu eksekusi selection sort
    waktuAwal = clock();
    selectionSort(data, jumlahData);
    waktuAkhir = clock();
    double waktuSelectionSort = (double)(waktuAkhir - waktuAwal) / CLOCKS_PER_SEC;

    // Menuliskan hasil selection sort kedalam file
    tulisKeFile(data, jumlahData, "data_selection_sort.txt");

    // Menghitung waktu eksekusi insertion sort 
    waktuAwal = clock();
    insertionSort(data, jumlahData);
    waktuAkhir = clock();
    double waktuInsertionSort = (double)(waktuAkhir - waktuAwal) / CLOCKS_PER_SEC;

    // Menuliskan Hasil insertion sort kedalam file
    tulisKeFile(data, jumlahData, "data_insertion_sort.txt");

    // tabel Hasil 
    printf("| Algoritma Pengurutan | Jumlah Data | Waktu (Detik) |\n");
    printf("|----------------------|-------------|---------------|\n");
    printf("|     Bubble Sort      | %d          | %.6f          |\n", jumlahData, waktuBubbleSort);
    printf("|   Selection Sort     | %d          | %.6f          |\n", jumlahData, waktuSelectionSort);
    printf("|   Insertion Sort     | %d          | %.6f          |\n", jumlahData, waktuInsertionSort);
    printf("|----------------------|-------------|---------------|\n");
    
    free(data);
  }

  return 0;
}

