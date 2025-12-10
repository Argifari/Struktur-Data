/* File : pohon2.c */
/* Deskripsi : REALISASI ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124130107 & Muhammad Firdaus Argifari*/
/* Tanggal : 3 December 2025*/

#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(P)) {

        for (int i = 1; i <= H; i++) {
            printf("\t");
        }
        printf("%c\n",akar(P));
        PrintTreeInden(GetLeft(P), H + 1);
        PrintTreeInden(GetRight(P), H + 1);
    }

}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (akar(*P) == X) {
            info(*P) = Y;
        }
        UpdateAllX(&left(*P),X,Y);
        UpdateAllX(&right(*P),X,Y);
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            left(*P) = Tree(X,NIL,NIL);
        }else if (GetLeft(*P) != NIL) {
            AddDaunTerkiri(&left(*P),X);
        }else {
            AddDaunTerkiri(&right(*P),X);
        }
    } 
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }
 ASUMSI : JIKA ADA X DI KANAN DAN DI KIRI, Y AKAN BERJUMLAH 2, 1 DI KANAN DAN 1 DI KIRI*/

void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri) {
    // Kamus Lokal
    boolean found;

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P) && akar(*P) == X) {
            if (Kiri) {
                left(*P) = Tree(Y,NIL,NIL);
            }else {
                right(*P) = Tree(Y,NIL,NIL);
            }
        }else {
            AddDaun(&left(*P),X,Y,Kiri);
            AddDaun(&right(*P),X,Y,Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (!SearchX(*P,X)) {
            if (IsDaun(*P)) {
                left(*P) = Tree(X,NIL,NIL);
            }else { // not IsDaun(P)
                if (IsEmptyTree(right(*P))) {
                    left(*P) = Tree(X,NIL,NIL);
                }else if (IsEmptyTree(left(*P))) {
                    left(*P) = Tree(X,NIL,NIL);
                }else {
                    InsertX(&right(*P),X);
                }
            }
        }
    }else {// jika kosong
        (*P) = Tree(X,NIL,NIL);

    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            (*X) = info(*P);
            DealokasiTree(P);
        }else {
            DelDaunTerkiri(&left(*P),X);
        }
    }

}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P .
 ASUMSI : SEMUA DAUN YANG BERNILAI X DIHAPUS}*/
void DelDaun(bintree *P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P) && info(*P) == X) {
            DealokasiTree(P);
        }else {
            DelDaun(&right(*P),X);
            DelDaun(&left(*P),X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! */
void DeleteX(bintree *P, infotype X) {
    // Kamus Lokal
    bintree temp;

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (akar(*P) == X) {
            if (IsDaun(*P)) {
                DealokasiTree(P);
            }else if (IsUnerLeft(*P)) {
                temp = (*P);
                (*P) = left(*P);
                DealokasiTree(&temp);            
            }else if (IsUnerRight(*P)) {
                temp = (*P);
                (*P) = right(*P);
                DealokasiTree(&temp);
            }else {
                temp = right(*P);
                while (left(temp) != NIL)
                {
                    temp = left(temp);
                }
                akar(*P) = akar(temp);

                DeleteX(&right(*P),akar(temp));
                
            }
        }else {
            DeleteX(&left(*P),X);
            DeleteX(&right(*P),X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
    // Kamus Lokal
    infotype X;

    // Algoritma
    scanf("%c",&X);
    if (n == 1) {
        return Tree(X,NIL,NIL);
    }
    return Tree(X,BuildBalanceTree(n - 1),BuildBalanceTree(n - 1));
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    // Kamus Lokal

    // Algoritma
    return NbElm(GetLeft(P)) == NbElm(GetRight(P));
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }
ASUMSI : JIKA TREE KOSONG, # AKAN DIKEMBALIKAN*/
char maxTree(bintree P) {
    // Kamus Lokal
    char maksKanan;
    char maksKiri;

    // Algoritma
    if (IsEmptyTree(P)) {
        return '#';
    }else {
        maksKanan = (char)max2((int)akar(P),(int)maxTree(GetRight(P)));
        maksKanan = (char)max2((int)akar(P),(int)maxTree(GetLeft(P)));
        return (char)max2((int)maksKanan,(int)maksKiri);
    }
}

/*function min2(a: int, b : int) -> int
{mengembalikan nilai terkecil diantara a dan b}
*/
int min2 (int a, int b) {
    if (a < b) {
        return a;
    }else {
        return b;
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z 
ASUMSI : JIKA POHON KOSONG, ~ AKAN DIKEMBALIKAN}*/
char minTree(bintree P) {
    // Kamus Lokal
    char minKanan;
    char minKiri;

    // Algoritma
    if (IsEmptyTree(P)) {
        return '~';
    }else {
        minKanan = (char)min2((int)akar(P),(int)minTree(GetRight(P)));
        minKiri = (char)min2((int)akar(P),(int)minTree(GetLeft(P)));
        return (char)min2((int)minKanan,(int)minKiri);
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return false;
    }else {
        if (akar(P) == X) {
            return true;
        }else {
            if (akar(P) > X) {
                return BSearch(GetLeft(P),X);
            }else {
                return BSearch(GetRight(P),X);
            }
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
    // Kamus Lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return Tree(X,NIL,NIL);
    }else {
        if (X < akar(P)) {
            left(P) = InsSearch(left(P),X);        
        }else if (X > akar(P)){
            right(P) = InsSearch(right(P),X);        
        }
    }
    return P;
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
    // Kamus Lokal
    bintree temp;

    // Algoritma
    if (!IsEmptyTree(*P)) {
        if (X > akar(*P)) {
            DelBtree(&right(*P),X);
        }else if (X < akar(*P)) {
            DelBtree(&left(*P),X);
        }else {
            if (IsDaun(*P)) {
                DealokasiTree(P);
            }else if (IsUnerRight(*P)) {
                temp = (*P);
                (*P) = right(*P);
                DealokasiTree(&temp);
            }else if (IsUnerLeft(*P)) {
                temp = (*P);
                (*P) = left(*P);
                DealokasiTree(&temp);
            }else {
                temp = right(*P);
                while (left(temp) != NIL)
                {
                    temp = left(temp);
                }
                
                info(*P) = info(temp);
                DelBtree(&right(*P), info(temp));
                
            }
        }
    }
}
