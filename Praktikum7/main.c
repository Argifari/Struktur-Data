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
  //algoritma
  
  //aplikasi tipe address
  
  // A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  // A->info = 'G';   A->next = NIL;
  
  printf("\n\n=== Testing Alokasi =====================================\n");
  A = Alokasi('G');
  printf("info(A)=%c\t", info(A) );
  // B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  // B->info = 'N';   B->next = A;
  B = Alokasi('N');
  next(B) = A;
  
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List1
  printf("\n\n=== Testing CreateList ==================================\n");
  CreateList(&Senarai);
  printf("Isi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d", NbElm(Senarai));
  printf("\n\n=== Testing InsertVFirst ================================\n");
  InsertVFirst(&Senarai, 'N');
  printf("Isi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d", NbElm(Senarai));
  
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
  printf("Mengubah huruf a menjadi p : \n");
  UpdateAllX(&Senarai, 'a', 'p');
  printf("\nIsi Senarai :");
  PrintList(Senarai);
  printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));


  

  return 0;
}
