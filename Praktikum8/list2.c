/* File : list2.c */
/* Deskripsi : realisasi ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 12 November 2025*/


#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/*================== PROTOTYPE =======================*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E){
    //kamus lokal
    address P;
    //algoritma 
    P = (address)malloc(sizeof(Elm2)); //casting
    if (P != NIL ) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
} //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
    //kamus lokal
	
	//algoritma
	if ( (*P) != NIL ) {
        free(*P);
	}
	(*P) = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L) {
    // Kamus Lokal

    // Algoritma
    First(*L) = NIL;

}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L) {
    // Kamus Lokal

    // Algoritma
    return First(L) == NIL;
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L) {
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(L);
    return First(L) == next(P);
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
	//kamus lokal 
	address P;

	//algoritma
	P = First(L);
	if (P != NIL) {
		printf("\nElemen = ");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != First(L) );
	}
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
    // Kamus Lokal
    address P;
    boolean last = false;
    int count = 0;

    // Algoritma
    P = First(L);
    
    while (P != NIL && !last)
    {
        count += 1;
        P = next(P);
        if (P == First(L)) {
            last = true;
        }
    }
    return count;

}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ) {
	// Kamus Lokal
	address P;
    address A;
	// Algoritma
	P = Alokasi(V);
	if (P != NIL) {
		if (IsEmptyList(*L)) {
            next(P) = P;
			First(*L) = P;
		}else {
			A = First(*L);
            do {
                A = next(A);
            }while (next(A) != First(*L));
                
            next(P) = First(*L);
            next(A) = P;
            First(*L) = P;
            
		}
	}

}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ) {
	// Kamus Lokal
	address P;
    address A;
	// Algoritma
	P = Alokasi(V);
    A = First(*L);
	if (P != NIL) {
		if (IsEmptyList(*L)) {
            next(P) = P;
			First(*L) = P;
		}else {
            do {
                A = next(A);
            }while (next(A) != First(*L));
                
            next(P) = First(*L);
            next(A) = P;
            
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
    // Kamus Lokal
    address P;
    address A;

    // Algoritma
    P = First(*L);
    A = First(*L);
    if (IsEmptyList(*L)) {
        (*V) = '#';
    }else {
        if (IsOneElm(*L)) {
            (*V) = info(P);
            Dealokasi(&P);
            First(*L) = NIL;
        }else {

            do {
                A = next(A);
            }while (next(A) != First(*L));
    
            next(A) = next(P);
            (*V) = info(P);
            First(*L) = next(A);
            Dealokasi(&P);    
        }
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
    // Kamus Lokal
    address P;
    address A;

    // Algoritma
    P = First(*L);
    A = First(*L);
    if (IsEmptyList(*L)) {
        (*V) = '#';
    }else {
        if (IsOneElm(*L)) {
            (*V) = info(P);
            Dealokasi(&P);
            First(*L) = NIL;
        }else {

            do {
                A = next(A);
            }while (next(next(A)) != First(*L));
            (*V) = info(next(A));
            Dealokasi(&next(A));
            next(A) = First(*L); 
        }
    }

}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
    // Kamus Lokal
    address P;
    address A;
    boolean found = false;
    // Algoritma
    A = First(*L);
    if (!IsEmptyList(*L)) {
        if (info(A) == X) {
            if (IsOneElm(*L)) {
                Dealokasi(&A);
                First(*L) = NIL;
            }else {
                P = First(*L );
                do {
                    P = next(P);
                }while (next(P) != First(*L));
                First(*L) = next(A);
                Dealokasi(&A);
                next(P) = First(*L);   
            }
        }else {

            do {
                if (info(A) == X) {
                    found = true;
                }else {
                    P = A;
                    A = next(A);
                }
            }while(A != First(*L) && !found);
            if (found) {
                next(P) = next(A);
                Dealokasi(&A);
            }
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
    // Kamus Lokal
    address P;

    boolean found = false;

    // Algoritma
   if (!IsEmptyList(L)) {
        P = First(L);

        (*A) = NIL;
        do {
            if (info(P) == X) {
                (*A) = P;
                found = true;
            }
            P = next(P);
        }while (next(P) != First(L) && !found);
   }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
    // Kamus Lokal
    address P;

    // Algoritma
    if (!IsEmptyList(*L)) {
       if (info(First(*L)) == X) {
            info(First(*L)) = Y;
        }
        else {
            SearchX(*L,X,&P);
            if (P != NIL) {
                info(P) = Y;
            }
        }
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
    // Kamus Lokal
    address P;
    address head;
    address beforeP;
    address afterP;

    // Algoritma
    if (!IsEmptyList(*L)) {

        P = First(*L);
        beforeP = NIL;
        head = First(*L);
        do {
            afterP = next(P);
            next(P) = beforeP;
            beforeP = P;
            P = afterP;
        }while (P != head);
        next(head) = beforeP;
        First(*L) = beforeP;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA P = next(P);ngembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
    // Kamus Lokal
    address P;
    int count = 0;

    // Algoritma
    P = First(L);
    if (P == NIL) {
        return count;
    }
    do {
        if (info(P) == X) {
            count += 1;
        }
        P = next(P);
    }while (P != First(L));
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
    // Kamus Lokal
    address P;
    int count = 0;
    int totElm = 0;
    float hasil;
    // Algoritma
    P = First(L);
    if (IsEmptyList(L)) {
        return 0;
    }
    if (IsOneElm(L)) {
        if (info(P) == X) {
            return 1;
        }else {
            return 0;
        }
    }
    do {
        if (info(P) == X) {
            count += 1;
        }
        totElm += 1;
        P = next(P);
    }while (next(P) != First(L));

    hasil = (float)count/(totElm + 1);
    return hasil;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    // Kamus Lokal
	address P;
	int count = 0;
	
	// Algoritma
	P = First(L);
    if (IsEmptyList(L)) {
        return 0;
    }
	do{
        if (info(P) == 'a' || info(P) == 'A' || info(P) == 'i' || info(P) == 'I' ||
		info(P) == 'u' || info(P) == 'U' || info(P) == 'e' || info(P) == 'E' ||
		info(P) == 'o' || info(P) == 'O') {
            count += 1;
		}
		P = next(P);

	}while (P != First(L));
	
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
    // Kamus Lokal
    address P, beforeP;
    int count = 0;
    
    // Algoritma
    if (IsEmptyList(L) || IsOneElm(L)) {
        return 0;
    }else {
        P = First(L);
        do {
            beforeP = P;
            P = next(P);
            if (info(beforeP) == 'N' && info(P) == 'G') {
                count += 1;
            }

        }while (P != First(L));
        return count;
    }
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P;
    address afterP;
    boolean found = false;
    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                found = true;
            }else {
                P = next(P);
            }
        }while(P != First(*L) && !found);
        if (found) {
            afterP = next(P);
            if (afterP == First(*L)) {
                First(*L) = Alokasi(V);
                next(First(*L)) = afterP;
                next(P) = First(*L);
            }else {
                next(P) = Alokasi(V);
                next(next(P)) = afterP;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P;
    address afterP;
    boolean found = false;
    

    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(next(P)) == X) {
                found = true;
            }else {
                P = next(P);
            }
        }while(P != First(*L) && !found);
        if (found) {
            afterP = next(P);
            if (afterP == First(*L)) {
                First(*L) = Alokasi(V);
                next(First(*L)) = afterP;
                next(P) = First(*L);
            }else {
                next(P) = Alokasi(V);
                next(next(P)) = afterP;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    // Kamus Lokal
    address P;
    address afterP;
    boolean found = false;

    // Algoritma
    (*V) = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                found = true;
            }else {
                P = next(P);
            }
        }while (P != First(*L) && !found);

        if (found) {
            afterP = next(P);

            if (afterP == P) {
                (*V) = info(afterP);
                First(*L) = NIL;
                Dealokasi(&afterP);
            }else if (afterP == First(*L)) {
                First(*L) = next(afterP);
                next(P) = next(afterP);
                (*V) = info(afterP);
                Dealokasi(&afterP);
            }else {
                next(P) = next(afterP);
                (*V) = info(afterP);
                Dealokasi(&afterP);

            }

        }
    }
}


/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    // Kamus Lokal
    address P;
    address afterP;
    boolean found = false;

    // Algoritma
    (*V) = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(next(next(P))) == X) {
                found = true;
            }else {
                P = next(P);
            }
        }while (P != First(*L) && !found);

        if (found) {
            afterP = next(P);

            if (afterP == P) {
                (*V) = info(afterP);
                First(*L) = NIL;
                Dealokasi(&afterP);
            }else if (afterP == First(*L)) {
                First(*L) = next(afterP);
                next(P) = next(afterP);
                (*V) = info(afterP);
                Dealokasi(&afterP);
            }else {
                next(P) = next(afterP);
                (*V) = info(afterP);
                Dealokasi(&afterP);

            }

        }
    }
}

// /*Procedure DeleteAllX(input/output L:List2, input X:infotype)
// { I.S. List L tidak kosong }
// { F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
// List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
    // Kamus Lokal
    address P;
    address beforeP;
    address eraseP;
    int i, N;

    // Algoritma
    N = NbElm(*L);

    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (IsOneElm(*L)) {
            if (info(P) == X) {
                First(*L) = NIL;
                Dealokasi(&P);
            }
        }else {
                beforeP = First(*L);
                while (next(beforeP) != First(*L))
                {
                    beforeP = next(beforeP);
                }

                for (int i = 1; i <= N; i++) {
                     if (info(P) == X) {
                        eraseP = P;
                        if (IsOneElm(*L)) {
                            if (info(P) == X) {
                                First(*L) = NIL;
                                Dealokasi(&P);
                            }
                        }
                        else if (P == First(*L)) {
                            First(*L) = next(P);
                            next(beforeP) = First(*L);
                            P = First(*L);
                        }else {
                            next(beforeP) = next(P);
                            P = next(P);
                        }
                        Dealokasi(&eraseP);
                     }else {
                        beforeP = P;
                        P = next(P);
                     }
                }
                
            }
    }

}


/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
    // Kamus Lokal
    address P;
    boolean found = false;
    int i;

    // Algoritma
    P = First(L);
    i = 1;
    printf("Posisi elemen bernilai %c :\n ", X);
    do {
        if (info(P) == X) {
            printf("%d, ",i);
            found = true;
        }
        i += 1;
        P = next(P);
    }while(P != First(L));

    if (!found) {
        printf("0\n");
    }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
     // Kamus Lokal
     address P;
     int maks = 0;
     int temp;

     // Algoritma
     P = First(L);
     maks = CountX(L, info(P));
     
     do {
        temp = CountX(L, info(P));
        if (maks < temp) {
            maks = temp;
        }
        P = next(P);

     }while(P != First(L));
     
     return maks;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
     // Kamus Lokal
     address P;
     int maks = 0;
     int temp;
     infotype maxElm = '#';

     // Algoritma
     P = First(L);
     maks = CountX(L, info(P));
     maxElm = info(P);
     if (IsEmptyList(L)) {
        return maxElm;
     }
     do {
        temp = CountX(L, info(P));
        if (maks < temp) {
            maks = temp;
            maxElm = info(P);
        }
        P = next(P);

     }while(P != First(L));
     
     return maxElm;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    // Kamus Lokal
    address P;
    address pL;
    int i,N;

    // Algoritma
    N = NbElm(L1);
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            P = First(L1);
            First(*L) = Alokasi(info(P));
            next(First(*L)) = First(*L);
            pL = First(*L);
        }else {
            next(pL) = Alokasi(info(P));
            pL = next(pL);
        }

        P = next(P);
    }
    N = NbElm(L2);
    P = First(L2);
    for (int i = 1; i <= N; i++) {
        next(pL) = Alokasi(info(P));
        pL = next(pL);
        P = next(P);
    }
    next(pL) = First(*L);
} 

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
	// Kamus Lokal
	address P;
	int N,i;

	// Algoritma
	N = NbElm(L);
	P = First(L);
	if (!IsEmptyList(L)) {
		if (IsOneElm(L)) {
			InsertVLast(L1,info(First(L)));
		}else {
			for (int i = 1; i <= N/2; i++) {
					InsertVLast(L1,info(P));
					P = next(P);
			}
            
			if (P != First(L)) {
				for (int i = (N/2) + 1; i <= N;i++) {
						InsertVLast(L2, info(P));
						P = next(P);
				}
			}
		}
	}
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
    // Kamus Lokal
    address P;
    address pL;
    int i, N;

    // Algoritma
    N = NbElm(L1);
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            P = First(L1);
            First(*L2) = Alokasi(info(P));
            next(First(*L2)) = First(*L2);
            pL = First(*L2);
        }else {
            next(pL) = Alokasi(info(P));
            pL = next(pL);
        }
        P = next(P);
    }
    next(pL) = First(*L2);
       
}