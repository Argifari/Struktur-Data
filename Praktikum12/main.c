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
      printf("\n\n= Test IsUnerRight =======================\n\n");
      
      if (IsDaun(W)) {
            printf("Bintree3 ini sebuah daun\n");
      }else {
            printf("Bintree3 ini bukan daun\n");
      }
      
      printf("\n\n= Test IsUnerLeft ========================\n\n");
      if (IsDaun(W)) {
            printf("Bintree3 ini sebuah daun\n");
      }else {
            printf("Bintree3 ini bukan daun\n");
      }
      

      printf("\n\n= Program Selesai ========================\n\n");
      
	
	return 0;
}