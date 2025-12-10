/* File : main.c */
/* Deskripsi : main driver ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124130107 & Muhammad Firdaus Argifari*/
/* Tanggal : 3 December 2025*/

#include "pohon2.h"

int main () {
    // Kamus 
    bintree B;
    bintree binaryTree;
    bintree balanceTree;
    infotype Y;
    infotype X;
    int n;

    // Algoritma
    printf("\n\n== Program dimulai =========================\n");
    printf("\n\n== Test Tree ===============================\n");
    B = Tree('T',
        Tree('I',
            Tree('N',NIL,NIL),
            Tree('F',
                Tree('O',NIL,NIL),
                NIL)),
        Tree('R',
                    Tree('M',
                        Tree('A',NIL,NIL),
                        Tree('T',NIL,NIL)),
                    Tree('I',
                            NIL,
                            Tree('K',
                                NIL,
                                Tree('A',NIL,NIL))))
    );
    
    printf("\n\n== Test PrintTreeInden =====================\n");
    printf("Hasil print seperti explorer : \n");
    PrintTreeInden(B,1);
    
    printf("\n\n== Test UpdateAllX =========================\n");
    X = 'I';
    Y = 'H';
    printf("Memperbarui semua yang bernilai %c dengan %c : \n", X,Y);
    UpdateAllX(&B,X,Y);
    printf("Hasil print seperti explorer : \n");
    PrintTreeInden(B,1);
    
    printf("\n\n== Test AddDaunTerkiri =====================\n");
    X = 'P';
    printf("Menambahkan elemen %c pada daun terkiri :\n",X);
    AddDaunTerkiri(&B,X);
    printf("Hasil print seperti explorer : \n");
    PrintTreeInden(B,1);
    
    printf("\n\n== Test AddDaun ============================\n");
    X = 'A';
    Y = 'C';
    printf("Menambahkan elemen %c pada daun dengan elemen %c :\n",Y,X);
    AddDaun(&B,X,Y,true);
    printf("Hasil print seperti explorer : \n");
    PrintTreeInden(B,1);
    
    printf("\n\n== Test InsertX ============================\n");
    X = 'L';
    printf("Menambahkan elemen %c ke dalam pohon : \n",X);
    InsertX(&B,X);
    printf("Hasil print seperti explorer : \n");
    PrintTreeInden(B,1);
    PrintPrefix(B);

    printf("\n\n== Test DelDaunTerkiri =====================\n");
    printf("Pohon sebelum dihapus daun terkirinya : \n");
    PrintTreeInden(B,1);
    PrintPrefixRingkas(B);
    DelDaunTerkiri(&B,&X);
    printf("\n\nPohon setelah dihapus daun terkirinya (%c): \n",X);
    PrintTreeInden(B,1);
    PrintPrefixRingkas(B);
    
    printf("\n\n== Test DelDaun ============================\n");
    X = 'C';
    printf("Menghapus daun dengan nilai %c : \n",X);
    DelDaun(&B,X);
    PrintTreeInden(B,1);
    PrintPrefixRingkas(B);
    
    printf("\n\n== Test DeleteX ============================\n");
    X = 'M';
    printf("Menghapus semua simpul %c : \n", X);
    DeleteX(&B,X);
    PrintTreeInden(B,1);
    PrintPrefixRingkas(B);
    
    printf("\n\n== Test BuildBalanceTree ===================\n");
    n = 3;
    printf("Membuat Balance tree dengan %c node :\n",n);
    balanceTree = BuildBalanceTree(n);
    PrintTreeInden(balanceTree,1);
    PrintPrefixRingkas(balanceTree);
    
    printf("\n\n== Test IsBalanceTree ======================\n");
    printf("Mengecek pohon Tree seimbang :\n");
    if (IsBalanceTree(balanceTree)) {
        printf("Tree Seimbang\n");
    }else {
        
        printf("Tree Tidak Seimbang\n");
    }

    printf("\n\n== Test maxTree ============================\n");
    printf("Mencari huruf terbesar dalam Tree : \n");
    X = maxTree(B);
    printf("Huruf terbesar : %c\n",X);
    printf("Nilai ascii : %d\n",(int)X);
    
    printf("\n\n== Test minTree ============================\n");
    printf("Mencari huruf terkecil dalam Tree : \n");
    X = minTree(B);
    printf("Huruf terkecil : %c\n",X);
    printf("Nilai ascii : %d\n",(int)X);
    
    printf("\n\n== Test InsSearch ==========================\n");
    printf("Memasukkan X ke dalam binary search tree :\n");
    binaryTree = NIL;
    binaryTree = InsSearch(binaryTree,'H');
    binaryTree = InsSearch(binaryTree,'J');
    binaryTree = InsSearch(binaryTree,'L');
    binaryTree = InsSearch(binaryTree,'A');
    binaryTree = InsSearch(binaryTree,'D');
    binaryTree = InsSearch(binaryTree,'O');
    binaryTree = InsSearch(binaryTree,'Q');
    binaryTree = InsSearch(binaryTree,'W');
    binaryTree = InsSearch(binaryTree,'I');
    PrintTreeInden(binaryTree,1);
    PrintPrefixRingkas(binaryTree);

    printf("\n\n== Test BSearch ============================\n");
    
    X = 'W';
    printf("Mencari %c dengan binary search :\n",X);
    if (BSearch(binaryTree,X)) {
        printf("%c ditemukan\n",X);
    }else {
        printf("%c tidak ditemukan\n",X);
        
    }
    printf("\n\n== Test DelBTree ===========================\n");
    X = 'L';
    printf("Menghapus %c pada binary search tree:\n",X);
    DelBtree(&binaryTree,X);
    PrintTreeInden(binaryTree,1);
    PrintPrefixRingkas(binaryTree);
    
    printf("\n\n== Program Selesai==========================\n");

    return 0;

}