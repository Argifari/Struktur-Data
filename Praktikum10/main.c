/* File : main.c */
/* Deskripsi : main driver ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 26 November 2025*/

#include "pohon1.c"

int main()
{    //kamus
     bintree B;
     infotype X;
     infotype ubah;
     infotype ubahTujuan;
     int level;
     //algoritma
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
     
     printf("\n\n== Test IsEmptyTree ========================\n\n");
     if (IsEmptyTree(B)) {
          printf("Tree kosong\n");
     }else {
          printf("Tree tidak kosong\n");
     }
     printf("\n\n== Test IsUnerLeft ========================\n\n");
     if (IsUnerLeft(B)) {
          printf("Tree hanya memiliki anak kiri\n");
     }else {
          printf("Tree tidak hanya memiliki anak kiri\n");
     }
     printf("\n\n== Test IsUnerRight ========================\n\n");
     if (IsUnerRight(B)) {
          printf("Tree hanya memiliki anak kanan\n");
     }else {
          printf("Tree tidak hanya memiliki anak kanan\n");
     }
     printf("\n\n== Test IsBiner ========================\n\n");
     if (IsBiner(B)) {
          printf("Tree memiliki kedua anak\n");
     }else {
          printf("Tree tidak lengkap dengan dua anak\n");
     }
     printf("\n\n== Test IsDaun ========================\n\n");
     if (IsDaun(B)) {
          printf("Ini adalah daun\n");
     }else {
          printf("Bukan daun\n");
     }

     printf("\n\n== Test GetRight ===========================\n\n");
     printf("GetRight dari Binary Tree B :\n");
     PrintPrefix(GetRight(B));
     
     printf("\n\n== Test GetLeft ============================\n\n");
     printf("GetLeft dari Binary Tree B :\n");
     PrintPrefix(GetLeft(B));

     printf("\n\n== Test PrintPrefix ========================\n\n");
     printf("Print binary tree B : \n");
     PrintPrefix(B);

     printf("\n\n== Test NBElm ==============================\n\n");
     printf("Banyak elemen Binary tree B : %d\n", NbElm(B));
     
     printf("\n\n== Test NBDaun =============================\n\n");
     printf("Banyak daun Binary tree B : %d\n", NbDaun(B));
     
     printf("\n\n== Test Tinggi ==============================\n\n");
     printf("Level Binary tree B : %d\n", Tinggi(B));
     
     printf("\n\n== Test SearchX =============================\n\n");
     X = 'R';
     printf("Mencari %c dalam binary tree B : \n", X);
     if (SearchX(B,X)) {
          printf("Huruf %c ditemukan\n", X);
     }else {
          printf("Huruf %c tidak ditemukan\n", X);
          
     }
     
     printf("\n\n== Test UpdateX =============================\n\n");
     ubah = 'A';
     ubahTujuan = 'p';
     
     printf("Pohon sebelum berubah :\n");
     PrintPrefix(B);
     printf("\n\nMengubah huruf %c jadi huruf %c di binary tree B: \n",ubah,ubahTujuan);
     UpdateX(&B,ubah, ubahTujuan);
     PrintPrefix(B);
     
     printf("\n\n== Test countX ==============================\n\n");
     X = 'p';
     printf("Banyak elemen %c di Binary tree B : %d\n", X, CountX(B,X));
     
     printf("\n\n== Test IsSkewLeft ==========================\n\n");

     if (IsSkewLeft(B)) {
          printf("Binary tree ini adalah pohon condong kiri\n");
     }else {
          printf("Binary tree ini bukan pohon condong kiri\n");
     }
     
     printf("\n\n== Test IsSkewRight =========================\n\n");
     
     if (IsSkewRight(B)) {
          printf("Binary tree ini adalah pohon condong kanan\n");
     }else {
          printf("Binary tree ini bukan pohon condong kanan\n");
     }

     printf("\n\n== Test PrintPrefixRingkas ==================\n\n");
     PrintPrefixRingkas(B);

     printf("\n\n== Test LevelX ==============================\n\n");
     X = 'R';
     printf("Mencari level dari huruf %c dalam pohon : \n",X);
     printf("hasil : %d \n", LevelX(B,X));
     
     printf("\n\n== Test CountLevel ==========================\n\n");
     level = 2;
     printf("Banyaknya node pada level %d : %d\n", level, CountLevel(B,level));
     
     printf("\n\n== Test PrintLevel ==========================\n\n");
     printf("Print node pada level %d :\n", level);
     PrintLevel(B,level);
     
     printf("\n\n== Test GetDaunTerkiri ======================\n\n");
     printf("Daun terkiri dari pohon : %c\n", GetDaunTerkiri(B));
     
     printf("\n\n== Test FrekuensiX ==========================\n\n");
     printf("Frekuensi huruf %c pada pohon : %f\n",X,FrekuensiX(B,X));
     
     printf("\n\n== Test CountVocal ==========================\n\n");
     printf("Banyak huruf vocal pada pohon : %d\n", CountVocal(B));
     
     printf("\n\n== Test PrintVocal ==========================\n\n");
     printf("Print node berhuruf vocal :\n");
     PrintVocal(B);
     
     printf("\n\n== Test CountConsonant ======================\n\n");
     printf("Banyak huruf Konsonan pada pohon : %d\n", CountConsonant(B));
     
     printf("\n\n== Test PrintConsonant ======================\n\n");
     printf("Print node berhuruf konsonan :\n");
     PrintConsonant(B);
     printf("\n\n== Test Modus ===============================\n\n");
     printf("Huruf dengan kemunculan paling banyak : %c\n", Modus(B));



     printf("\n\n== Program Selesai =========================\n\n");
     

    return 0;
}
