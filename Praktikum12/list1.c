/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 5 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* PROTOTYPE */
/**************** OPERATOR ALOKASI ****************/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
} //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
	if ( P != NIL ) {
		next(P) = NIL;
	}
	P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L) {
	// Kamus Lokal

	// Algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L) {
	// Kamus Lokal

	// Algoritma
	return First(L) == NIL;
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{Proses: menampilkan info semua elemen list L} */
void PrintList(List1 L) {
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
	}
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L) {
	// Kamus Lokal
	int count = 0;
	address P;
	// Algoritma
	P = First(L);
	while (P != NIL) {
		count += 1;
		First(L) = next(P);
		P = First(L);
	}
	return count;	
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ) {
	// Kamus Lokal
	address P;

	// Algoritma
	P = Alokasi(V);
	if (P != NIL) {
		if (IsEmptyList(*L)) {
			First(*L) = P;
		}else {
			next(P) = First(*L);
			First(*L) = P;
		}
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ) {
	// Kamus Lokal
	address P;
	address Q;
	// Algoritma
	P = Alokasi(V);
	
	if (P != NIL) {
		if (IsEmptyList(*L)) {
			First(*L) = P;
		}else {
			Q = First(*L);
			while (next(Q) != NIL)
			{
				Q = next(Q);
			}
			next(Q) = P;
		}
	}

	
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V) {
	// Kamus Lokal
	address P;

	// Algoritma
	if (IsEmptyList(*L)) {
		(*V) = '#';
	}else {
		P = First(*L);
		(*V) = info(P);
		First(*L) = next(P);
		Dealokasi(P);
	}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V) {
	// Kamus Lokal
	int N;
	address P;
	address Q;

	// Algoritma
	N = NbElm(*L)-1;
	if (IsEmptyList(*L)) {
		(*V) = '#';
	}else {
		P = First(*L);
		if (next(P) == NIL) {
			(*V) = info(P);
			First(*L) = NIL;
			Dealokasi(P);
		}else {
			while (next(next(P)) != NIL) {
				P = next(P);
			}
			Q = next(P);
			(*V) = info(Q);
			next(P) = NIL;
			Dealokasi(Q);
		}
	}
	
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address A) {
	// Kamus Lokal
	boolean found = false;
	address P;

	// Algoritma
	if (IsEmptyList(L)) {
		A = NIL;
	}else {

		P = First(L);
		while (P != NIL && !found) {
			if (X == info(P)) {
				found = true;

			} else {
				P = next(P);
			}
		}
		A = P; 

	}
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y) {
	// Kamus Lokal
	boolean found = false;
	address P;

	// Algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		while (P != NIL && !found) {
			if (X == info(P)) {
				found = true;
				info(P) = Y;
			} else {
				P = next(P);
			}
		} 
	}
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L) {
	 // Kamus Lokal
	 address P;
	 address temp;
	 int N;
	 int i;

	 // Algoritma
	 N = NbElm(*L);
	 for (int i = 1; i <= N; i++) {
		P = First(*L);
		if (next(P) != NIL) {	
			First(*L) = next(P);
		}
		if (i == 1) {
			temp = P;
			next(P) = NIL;
		}else {
			next(P) = temp;
			temp = P;
		}
	}
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountVocal(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List1 L) {
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

/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X) {
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

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X) {
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

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X) {
	// Kamus Lokal
	address P;
	int N,i;

	// Algoritma
	 N = NbElm(L);

	 for (int i = 1; i <= N; i++) {
		if (i == 1) {
			P = First(L);
		}
		if (info(P) == X) {
			printf(" %d,", i);
		}
		P = next(P);
	 }

}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y) {
	// Kamus Lokal
	address P;

	// Algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		while (P != NIL) {
			if (X == info(P)) {
				info(P) = Y;
			} else {
				P = next(P);
			}
		} 
	}
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ) {
	// Kamus Lokal
	address P;
	address temp;
	boolean found = false;

	// Algoritma
	P = First(*L);
	while (P != NIL && !found) {
		if (info(P) == V) {
			found = true;
		}else {
			P = next(P);
		}
	}
	temp = Alokasi(VA);
	next(temp) = next(P);
	next(P) = temp;
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L) {
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

/*function NbModus(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int NbModus(List1 L) {
	// Kamus Lokal
	address P;
	int count = 0;
	infotype temp;

	// Algoritma
	P = First(L);
	temp = Modus(L);
	while (P != NIL)
	{
		if (info(P) == temp) {
			count += 1;
		}
		P = next(P);
	}
	return count;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L) {
	// Kamus Lokal
	address P;
	address Q;

	// Algoritma
	First(*L) = First(L1);
	P = First(L1);

	while (P != NIL) {
		P = next(P);

	}
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2) {
	// Kamus Lokal
	address P;
	int N,i;

	// Algoritma
	N = NbElm(L);
	P = First(L);
	if (!IsEmptyList(L)) {
		if (next(First(L)) == NIL) {
			InsertVLast(L1,info(First(L)));
		}else {
			for (int i = 1; i <= N/2; i++) {
				if (P != NIL) {
					InsertVLast(L1,info(P));
					P = next(P);
				}
			}
			if (P != NIL) {
				for (int i = (N/2) + 1; i <= N;i++) {
					if (P != NIL) {
						InsertVLast(L2, info(P));
						P = next(P);
					}
				}
			}
		}
	}

}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2) {
	// Kamus Lokal
	address P;
	int N,i;

	// Algoritma
	N = NbElm(L1);
	P = First(L1);
	for (int i = 1; i <= N; i++) {
		InsertVLast(L2, info(P));
		P = next(P);
	}
}

