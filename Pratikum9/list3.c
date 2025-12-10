/* File : list3.c */
/* Deskripsi : Realisasi ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 19 November 2025*/

#include "list3.h"
#include <stdio.h>
#include <stdlib.h>

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = (address)malloc(sizeof(Elm));
    if (P != NIL) {
        info(P) = E;
        prev(P) = NIL;
        next(P) = NIL;
    }
    return P;
} //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
    // Kamus Lokal

    // Algoritma
    if ( (*P) != NIL ) {
        free(*P);
	}
	(*P) = NIL;
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L) {
    // Kamus Lokal

    // Algoritma
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L) {
    // Kamus Lokal

    // Algoritma
    return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
	//kamus lokal 
	address P;

	//algoritma
	P = First(L);
	if (P != NIL) {
		printf("\nElemen = ");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != NIL );
        printf("\n");
	}
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
	// Kamus Lokal
	int count = 0;
	address P;

	// Algoritma
	P = First(L);
	while (P != NIL) {
		count += 1;
		P = next(P);
	}
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
        }else {
            next(P) = First(*L);
            prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ) {
    // Kamus Lokal
    address P;
    address last;

    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
        }else {
            last = First(*L);
            while (next(last) != NIL)
            {
                last = next(last);
            }
            next(last) = P;
            prev(P) = last;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
    // Kamus Lokal
    address P;

    // Algoritma
    (*V) = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (prev(P) == NIL && next(P) == NIL) {
            First(*L) = NIL;
            (*V) = info(P);
            Dealokasi(&P);
            
        }else {
            (*V) = info(P);
            prev(next(P)) = NIL;
            First(*L) = next(P);
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
    // Kamus Lokal
    address P;
    
    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (prev(P) == NIL && next(P) == NIL) {
            First(*L) = NIL;
            (*V) = info(P);
            Dealokasi(&P);
            
        }else {
            while (next(P) != NIL)
            {
                P = next(P);
            }
            next(prev(P)) = NIL;
            (*V) = info(P);
            Dealokasi(&P);
            
        }

    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
    // Kamus Lokal
    address P;
    boolean found;
    
    // Algoritma
    found = false;
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (prev(P) == NIL && next(P) == NIL) {
            if (info(P) == X) {
                Dealokasi(&P);
            }
        }else {
            if (info(P) == X) {
                prev(next(P)) = NIL;
                First(*L) = next(P);
                Dealokasi(&P);
            }else {

                while (P != NIL && !found)
                {
                    if (info(P) == X) {
                        found = true;
                    }else {
                        P = next(P);
                    }
                }
                if (found) {
                    if (next(P) == NIL) {
                        next(prev(P)) = NIL;
                        Dealokasi(&P);
                    }else {
                        next(prev(P)) = next(P);
                        prev(next(P)) = prev(P);
                        Dealokasi(&P);
                    }
                }
            }
            
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
    // Kamus Lokal
    address P;

    // Algoritma
    (*A) = NIL;
    if (!IsEmptyList(L)) {
        P = First(L);
        if (info(P) == X) {
            (*A) = P;
        }else {
            while (P != NIL && (*A) == NIL)
            {
                if (info(P) == X) {
                    (*A) = P;
                }else {
                    P = next(P);
                }
            }
            
        }
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
    // Kamus Lokal
    address P;

    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (P != NIL && info(P) != X) {
            P = next(P);
        }
        if (info(P) == X) {
            info(P) = Y;
        }
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
    // Kamus Lokal
    address P, temp, newFirst;
    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        while (P != NIL)
        {
            newFirst = P;
            temp = next(P);
            next(P) = prev(P);
            prev(P) = temp;
            P = temp;
        }
        First(*L) = newFirst;
        
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P;
    address pointerX;

    // Algoritma
    pointerX = First(*L);
    while (pointerX != NIL && info(pointerX) != X) {
        pointerX = next(pointerX);
    }
    if ( pointerX != NIL && info(pointerX) == X) {
        P = Alokasi(V);
        if (P != NIL) {

            next(P) = next(pointerX);
            prev(P) = pointerX;
            
            if (next(pointerX) != NIL) {
                prev(next(pointerX)) = P;
            }
            next(pointerX) = P;

        }
    }
    
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P, pointerX;

    // Algoritma
    pointerX = First(*L);
    while (pointerX != NIL && info(pointerX) != X) {
        pointerX = next(pointerX);
    }
    if (pointerX != NIL && info(pointerX) == X) {
        P = Alokasi(V);
        if (P != NIL) {
            next(P) = pointerX;
            
            if (pointerX == First(*L)) {
                First(*L) = P; 
                prev(P) = NIL;
            }else {
                
                prev(P) = prev(pointerX);
                next(prev(pointerX)) = P; 
                prev(pointerX) = P;
            }
    
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
    // Kamus Lokal
    address P;

    //Algoritma
    P = First(*L);
    while (P != NIL && info(P) != X)
    {
        P = next(P);
    }
    if (P != NIL && info(P) == X) {
        if (next(P) != NIL) {
            P = next(P);
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            Dealokasi(&P); 
        }
    }
    
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(*L);
    while (P != NIL && info(P) != X)
    {
        P = next(P);
    }
    if (P != NIL && info(P) == X) {
        if (prev(P) == First(*L)) {
            prev(P) = NIL;
            First(*L) = P;
            P = prev(P);
            Dealokasi(&P);
        }else if (P != First(*L)){
            P = prev(P);
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);

            Dealokasi(&P);
        }
    }
    
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
	// Kamus Lokal
	address P;
	int count = 0;
	
	// Algoritma
	P = First(L);
	while (P != NIL)
	{
		if (info(P) == X) {
			count += 1;
		}
		P = next(P);
	}
	return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X) {
	// Kamus Lokal
	address P;
	int count = 0;
	float rasio = 0;
	
	// Algoritma
	P = First(L);
	while (P != NIL)
	{
		if (info(P) == X) {
			count += 1;
		}
		P = next(P);
	}
	if (NbElm(L) != 0 ) {
		rasio = (float)count /NbElm(L);
	}
	return rasio;
}


/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L);

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L) {
	// Kamus Lokal
	address P;
	infotype result;
	int maks = 0;
	int count;

	// Algoritma
	P = First(L);
	while (P != NIL) {
		count = CountX(L,info(P));
		if (maks < count) {
			maks = count;
			result = info(P);
		}
		P = next(P);
	}
	return result;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
	// Kamus Lokal
	address P;
	int count = 0;
	
	// Algoritma
	P = First(L);
	while (P != NIL)
	{
		if (info(P) == 'a' || info(P) == 'A' || info(P) == 'i' || info(P) == 'I' ||
		info(P) == 'u' || info(P) == 'U' || info(P) == 'e' || info(P) == 'E' ||
		info(P) == 'o' || info(P) == 'O') {
			count += 1;
		}
		P = next(P);
	}
	return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L);

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X);

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X);

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L); 

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2);

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2);

