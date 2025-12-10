/*Nama file:  main.c */
/*Deskripsi:   Main Driver ADT Tree 3 Binary tree dengan address parent*/
/*Tanggal  :  10 Desember 2025*/
/*Pembuat  :   Muhammad Firdaus Argifari 24060124130107*/

// header
#include "pohon3.h"

int main() {
	//kamus
	bintree3 W;
      int tinggiTree;
      int levelTree;
      int nDaun;
      int nElemen;
	
	//algoritma
	//bukalah komentar ini untuk menguji (aplikasi) Tree3
      printf("\n\n= Program Dimulai ========================\n\n");
      printf("= Test Tree3 =============================\n");
      W = Tree3(NIL,'A',false,
            Tree3(W,'B',false, 
                  NIL, 
                  Tree3(left(W),'D',false,NIL,NIL)),
            Tree3(W,'C',false, 
                        Tree3(right(W),'E',false,NIL,NIL),
                        Tree3(right(W),'F',false,NIL,NIL)));
      printf("= Test printDFS ==========================\n\n");
	printDFS(W);
      
      printf("\n\n= Test Tinggi ============================\n\n");
      printf("Mencari nilai tinggi dari W: \n");
      tinggiTree = Tinggi(W);
      printf("Tinggi W : %d\n",tinggiTree);
      printf("\n\n= Test PrintLevel ========================\n\n");
      levelTree = 3;
      printf("Mencetak level %d pada bintree3 W :\n");
      PrintLevel(W,levelTree);
      printf("\n");
      
      printf("\n\n= Test IsEmptyTree =======================\n\n");
      if (IsEmptyTree(W)) {
            printf("Bintree3 ini kosong\n");
      }else {
            printf("Bintree3 ini tidak kosong\n");
      }
      
      printf("\n\n= Test IsDaun ============================\n\n");
      
      if (IsDaun(W)) {
            printf("Bintree3 ini sebuah daun\n");
      }else {
            printf("Bintree3 ini bukan daun\n");
      }
      
      printf("\n\n= Test IsUnerLeft ========================\n\n");
      if (IsUnerLeft(W)) {
            printf("Bintree3 ini hanya memiliki anak kiri\n");
      }else {
            printf("Bintree3 ini tidak hanya memiliki anak kiri\n");
      }
      
      printf("\n\n= Test IsUnerRight =======================\n\n");
      if (IsUnerRight(W)) {
            printf("Bintree3 ini hanya memiliki anak kanan\n");
      }else {
            printf("Bintree3 ini tidak hanya memiliki anak kanan\n");
      }
      printf("\n\n= Test IsBiner ===========================\n\n");
      if (IsBiner(W)) {
            printf("Bintree3 ini kedua anak\n");
      }else {
            printf("Bintree3 ini tidak lengkap anaknya\n");
      }

      printf("\n\n= Test PrintBFS ==========================\n\n");
      printf("Melakukan Print BFS:\n");
      PrintBFS(W);

      printf("\n\n= Test NbDaun ============================\n\n");
      nDaun = NbDaun(W);
      printf("Banyak daun pada bintree3 W: %d",nDaun);
      
      printf("\n\n= Test NbElemTree ========================\n\n");
      nElemen = NbElmTree(W);
      printf("Banyak elemen pada bintree3 W: %d",nElemen);


      printf("\n\n= Test Level =============================\n\n");
      levelTree = Level(W);
      printf("Level bintree3 W:%d\n",levelTree);

      printf("\n\n= Program Selesai ========================\n\n");
      
	
	return 0;
}