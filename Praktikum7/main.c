/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 5 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.c"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  infotype V;
  List1 Senarai;
  List1 Senarai1;
  List1 Senarai2;
  List1 CopySenarai;
  //algoritma
  
  //aplikasi tipe address
  
  
  printf("\n\n=== Testing Alokasi =====================================\n");
  A = Alokasi('G');
  printf("info(A)=%c\t", info(A) );
  B = Alokasi('N');
  next(B) = A;
  printf("info(B)=%c\n", B->info );
  
  printf("\n\n=== Testing Dealokasi ===================================\n");
  Dealokasi(B);
  B = NIL;
  Dealokasi(A);
  if (B == NIL) {
    printf("Dealokasi berhasil\n");
  }else {
    printf("Dealokasi tidak berhasil\n");
    
  }

  //aplikasi tipe List1
  printf("\n\n=== Testing CreateList ==================================\n");
  CreateList(&Senarai);
  CreateList(&Senarai1);
  CreateList(&Senarai2);
  CreateList(&CopySenarai);
  printf("Isi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d", NbElm(Senarai));

  printf("\n\n=== Testing InsertVFirst ================================\n");
  InsertVFirst(&Senarai, 'N');
  printf("Isi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d", NbElm(Senarai));

  printf("\n\n=== Testing EmptyList ===================================\n");
  if (IsEmptyList(Senarai)) {
    printf("Senarai kosong\n");
  }else {
    printf("Senarai tidak kosong\n");
  }
   
  printf("\n\n=== Testing InsertVLast =================================\n");
  InsertVLast(&Senarai, 'G');
  InsertVLast(&Senarai, 'a');
  InsertVLast(&Senarai, 'f');
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d", NbElm(Senarai));

  printf("\n\n=== Test DeleteVFirst ===================================\n");
  
  DeleteVFirst(&Senarai, &V);
  
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  
  DeleteVLast(&Senarai, &V);
  
  printf("\n\n=== Test DeleteVLast ====================================\n");
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  
  printf("\n\n=== Test SearchX ========================================\n");
  printf("Mencari huruf a : \n");
  SearchX(Senarai, 'a', P);
  if (P == NIL) {
    printf("Huruf a tidak ditemukan\n");
  }else {
    printf("Huruf a ditemukan");
  }
  printf("\n\n=== Test UpdateX ========================================\n");
  printf("Mengubah huruf a menjadi p : \n");
  UpdateX(&Senarai, 'a', 'p');
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  
  printf("\n\n=== Reset Senarai =======================================\n");
  InsertVLast(&Senarai,'a');  
  InsertVLast(&Senarai,'a');  
  InsertVLast(&Senarai,'a');  
  InsertVLast(&Senarai,'a');
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));

  printf("\n\n=== Test UpdateAllX =====================================\n");
  printf("Mengubah huruf a menjadi i : \n");
  UpdateAllX(&Senarai, 'a', 'i');
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));

  printf("\n\n=== Test Invers =========================================\n");
  Invers(&Senarai);
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));

  printf("\n\n=== Test CountVocal =====================================\n");
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  printf("Hitung elemen berhuruf vocal : %d\n", CountVocal(Senarai));

  printf("\n\n=== Test CountX ==========================================\n");
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  printf("Hitung elemen berhuruf p : %d\n", CountX(Senarai, 'p'));

  printf("\n\n=== Test FrekuensiX ======================================\n");
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  printf("Hitung frekuensi elemen berhuruf i : %f\n", FrekuensiX(Senarai, 'i'));
  
  printf("\n\n=== Test SearchAllX ======================================\n");
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  printf("\nMelakukan pencarian huruf i :");
  SearchAllX(Senarai, 'i');
  
  printf("\n\n=== Test InsertVAfter ====================================\n");
  printf("\nMengisi elemen 'B' setelah elemen 'p:");
  InsertVAfter(&Senarai, 'p', 'B');
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  
  printf("\n\n=== Test Modus ===========================================\n");
  InsertVAfter(&Senarai, 'p', 'B');
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  printf("Elemen yang paling banyak muncul : %c\n", Modus(Senarai));
  
  printf("\n\n=== Test NbModus =========================================\n");
  InsertVAfter(&Senarai, 'p', 'B');
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
  printf("Banyaknya Elemen yang paling banyak muncul : %d\n", NbModus(Senarai));
  
  printf("\n\n=== Test SplitList =======================================\n");
  SplitList(Senarai, &Senarai1, &Senarai2);
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHasil Splitlist :");
  printf("\nIsi Senarai1 :");
  PrintList(Senarai1);
  printf("\nIsi Senarai2 :");
  PrintList(Senarai2);
  
  printf("\n\n=== Test CopyList ========================================\n");
  CopyList(Senarai, &CopySenarai);
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHasil Copylist :");
  printf("\nIsi CopySenarai :");
  PrintList(CopySenarai);
  
  
  printf("\n\n=== Program Selesai ======================================\n");
  return 0;
}
 