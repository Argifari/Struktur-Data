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
	int N;
      infotype X;
      List1 asli;
      List1 asliCopy;
      List1 tambahan;
      List1 baru;
      List1 treeToList;

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
      
      printf("\n\n= Test CountLevel ========================\n\n");
      levelTree = 2;
      N = CountLevelT(W,levelTree);
      printf("jumlah simpul di level %d : %d",levelTree,N);
      
      printf("\n\n= Test PrintPathX ========================\n\n");
      X = 'C';
      printf("Mencari path node %c :\n",X);
      printPathX(W,X);
      
      printf("\n\n= Test PrintPathDaunX ====================\n\n");
      printf("Mencari path node daun %c :\n",X);
      printPathDaunX(W,X);
      
      printf("\n\n= Test PrintAllPath ======================\n\n");
      printf("Menampilkan semua path ke setiap daun :\n");
      printAllPaths(W);

      printf("\n\n= Test Pconcat ===========================\n\n");
      printf("Menggabungkan list tambahan ke list asli : \n");
      CreateList(&asli);
      InsertVLast(&asli,'X');
      InsertVLast(&asli,'B');
      InsertVLast(&asli,'A');
      InsertVLast(&asli,'C');
      CreateList(&asliCopy);
      Pconcat(&asliCopy,asli);
      CreateList(&tambahan);
      InsertVLast(&tambahan,'G');
      InsertVLast(&tambahan,'K');
      InsertVLast(&tambahan,'O');
      printf("\nCetak list asli :");
      PrintList(asli);
      printf("\n\nCetak list tambahan :");
      PrintList(tambahan);
      
      printf("\n\nCetak list asli setelah diconcat list tambahan:");
      Pconcat(&asli,tambahan);
      PrintList(asli);
      
      printf("\n\n= Test Fconcat ===========================\n\n");
      printf("Membuat list baru dengan list asli dan tambahan :\n");
      CreateList(&baru);
      baru = Fconcat(asliCopy,tambahan);
      printf("Hasil list baru:");
      PrintList(baru);
      printf("\n\n= Test LinearPrefix ======================\n\n");
      printf("Representasi pohon W ke list prefix:\n");
      CreateList(&treeToList);
      treeToList = LinearPrefix(W);
      PrintList(treeToList);
      
      printf("\n\n= Test LinearPostfix =====================\n\n");
      printf("Representasi pohon W ke list postfix:\n");
      treeToList = LinearPosfix(W);
      PrintList(treeToList);
      
      printf("\n\n= Test LinearInfix =======================\n\n");
      printf("Representasi pohon W ke list Infix:\n");
      treeToList = LinearInfix(W);
      PrintList(treeToList);
      
      printf("\n\n= Test LinearBreadthFS ===================\n\n");
      printf("Representasi pohon W ke list menyeabar:\n");
      treeToList = LinearBreadthFS(W);
      PrintList(treeToList);


      printf("\n\n= Program Selesai ========================\n\n");
      
	
	return 0;
}