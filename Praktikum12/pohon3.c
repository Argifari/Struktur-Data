/*Nama file:  pohon3.c */
/*Deskripsi:   REALISASI ADT Tree 3 Binary tree dengan address parent*/
/*Tanggal  :  10 Desember 2025*/
/*Pembuat  :   Muhammad Firdaus Argifari 24060124130107*/

#include "pohon3.h"


/************************ PROTOTYPE ************************/
/********** PEMBUATAN POHON BARU ***********/
/*function Alokasi(X:infotype) --> bintree3
{Fungsi untuk alokasi pohon3}*/
bintree3 AlokasiTree3 (infotype X) {
    // Kamus Lokal
    bintree3 P;
    // Algoritma
    P = (bintree3)malloc(sizeof(node3));
    if (P != NIL) {
        parent(P) = NIL;
        info(P) = X;
        visited(P) = false;
        left(P) = NIL;
        right(P) = NIL;
        
    }
    return P;
}

/* function Tree3 (A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan) {
    // Kamus Lokal
    bintree3 P;

    // Algoritma
    P = AlokasiTree3(X);
    if (P != NIL) {
        parent(P) = A;
        info(P) = X;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
    }
    return P;
}

/* penelusuran */
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P == NIL) {
        printf("()");
    }else {
        printf("%c(",info(P));
        printDFS(left(P));
        printf(",");
        printDFS(right(P));
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2 (int a, int b) {
    // Kamus Lokal

    // Algoritma
    if (a > b) {
        return a;
    }else {
        return b;
    }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P) || IsDaun(P)) {
        return 0;
    }
    else {
        return Max2(1 + Tinggi(right(P)), 1 + Tinggi(left(P)));
    }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel (bintree3 P, int N) {
   //kamus lokal
    
    //algoritma 
    if (P != NIL) {
        if (N == 1) {
            printf(" ");
            printf("%c",info(P));
            printf(" ");
        }else {
            PrintLevel(left(P),N - 1);
            PrintLevel(right(P),N - 1);
        }
    }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P) {
    // Kamus Lokal
    int i;
    int N;

    // Algoritma
    if (IsEmptyTree(P)) {
        printf("()");
    }else {
        for (int i = 1; i <= N;i++) {
            PrintLevel(P,i);
        }
    }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    return P == NIL;
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    return left(P) == NIL && right(P) == NIL;
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P) {
    // Kamus Lokal
    
    // Algoritma
    return left(P) != NIL && right(P) != NIL;
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    return left(P) != NIL && right(P) == NIL;
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    return left(P) == NIL && right(P) != NIL;
}
/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchXTree(bintree3 P, infotype X) {    
    // Kamus Lokal

    // Algoritmac
    if (IsEmptyTree(P)) {
        return false;
    }
    if (info(P) == X) {
        return true;
    }
    return SearchXTree(left(P),X) || SearchXTree(right(P), X); 
}

/*PENELUSURAN*/
/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (P != NIL) {
        visited(P) = false;
        resetVisited(left(P));
        resetVisited(right(P));
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(P)) {
        if (info(P) == X) {
            printf("%c",info(P));
        }else if (SearchXTree(left(P),X)) {
            printf("%c -> ",info(P));
            printPathX(left(P),X);
        }else if (SearchXTree(right(P),X)) {
            printf("%c -> ",info(P));
            printPathX(right(P),X);
        }
    }else {
        printf("()");
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X) {
    // Kamus Lokal
    
    // Algoritma
    if (!IsEmptyTree(P)) {
        if (info(P) == X && IsDaun(P)) {
            printf("%c",info(P));
        }else if (SearchXTree(left(P),X)) {
            printf("%c -> ",info(P));
            printPathDaunX(left(P),X);
        }else if (SearchXTree(right(P),X)) {
            printf("%c -> ",info(P));
            printPathDaunX(right(P),X);
        }else {
            printf("()");
        }
    }else {
        printf("()");
    }
    
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths (bintree3 P) {
    // Kamus Lokal
    int N,i;

    // Algoritma
    N = NbDaun(P);
    if (!IsEmptyTree(P)) {
        if (IsDaun(P)) {
            printPathDaunX()
        }else {
            
        }
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }else if (IsUnerLeft(P)) {
        return 1 + NbElmTree(left(P));
    }else if (IsUnerRight(P)) {
        return 1 + NbElmTree(right(P));
    }else if (IsBiner(P)) {
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }else if (IsDaun(P)) {
        return 1;
    }else {
        return 0;
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P) {
    // Kamus Lokal
    
    // Algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }else if (IsUnerLeft(P)) {
        return NbDaun(left(P));
    }else if (IsUnerRight(P)) {
        return NbDaun(right(P));
    }else if (IsBiner(P)) {
        return NbDaun(left(P)) + NbDaun(right(P));
    }else if (IsDaun(P)) {
        return 1;
    }
}
/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P) {
    // Kamus Lokal

    // Algoritma
    return Tinggi(P) + 1;
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T) {
    // Kamus Lokal
    
    // Algoritma
    if (IsEmptyTree(P)) {
        return 0;
    }else {
        if (T == 1) {
            return 1;
        }else {
            return CountLevelT(left(P),T - 1) + CountLevelT(right(P), T - 1);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
//printList sudah ADA di List1.h

/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan) {

} 

/*function fconcat( Asli:List1, Tambahan:List1) -> List1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan); 

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> List1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix (bintree3 P);

/*function linearPosfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix (bintree3 P);

/*function linearInfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P);

/*function linearBreadthFS(P:bintree3) -> List1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS (bintree3 P);