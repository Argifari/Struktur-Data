/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal   : 3 September 2025*/
/***********************************/
#include <stdio.h>
#include "titik.h"
#include "titik.c"

int main() {
	//kamus main
	//Titik T1;
	Titik T;
	Titik T1;
	Titik T2;
	Titik X;
	//algoritma
	makeTitik0(&T);

	printf("\nHalo, ini driver modul Titik /n");

	printf("\nTitik T: \n\tnilai absis: %d \n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	makeTitik(&T, 3, 4);

	printf("\n\nTitik T setelah diubah: \n\tnilai absis : %d  \n\tnilai ordinat : %d \n", getAbsis(T), getOrdinat(T));
	setAbsis(&T, -4);
	printf("\nTitik T setelah : \n\tSetAbsis(-4): %d", getAbsis(T));
	setOrdinat(&T, 10);
	printf("\n\tSetOrdinat(10): %d", getOrdinat(T));
	makeTitik0(&T1);
	makeTitik0(&T2);
	
	printf("\nJika: \n\tT1: %d %d",getAbsis(T1), getOrdinat(T1));
	printf("\n\tT2: %d %d",getAbsis(T2), getOrdinat(T2));
	printf("\nJadi IsOrigin(T1): %d", isOrigin(T1));
	printf("\nJadi IsOrigin(T2): %d\n", isOrigin(T2));
	
	printf("\nTitik T: \n\tnilai absis: %d \n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	printf("\nIsOnSumbuX(T): %d", isOnSumbuX(T));
	setOrdinat(&T,0);
	printf("\n\nTitik T: \n\tnilai absis: %d \n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	printf("\nIsOnSumbuX(T): %d", isOnSumbuX(T));
	setOrdinat(&T, -8);
	
	printf("\n\nTitik T: \n\tnilai absis: %d \n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	printf("\nIsOnSumbuY(T): %d", isOnSumbuY(T));
	setAbsis(&T,0);
	printf("\n\nTitik T: \n\tnilai absis: %d \n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	printf("\nIsOnSumbuY(T): %d", isOnSumbuY(T));

	printf("\nJika: \n\tT1: %d %d",getAbsis(T1), getOrdinat(T1));
	printf("\n\tT2: %d %d",getAbsis(T2), getOrdinat(T2));
	printf("\nJadi IsEqual(T1,T2): %d", isEqual(T1,T2));
	setAbsis(&T1,2);
	setOrdinat(&T1, -9);
	setAbsis(&T2, 19);
	setOrdinat(&T2, 1);

	printf("\nJika: \n\tT1: %d %d",getAbsis(T1), getOrdinat(T1));
	printf("\n\tT2: %d %d",getAbsis(T2), getOrdinat(T2));
	printf("\nJadi IsEqual(T1,T2): %d", isEqual(T1,T2));
	
	geser(&T,4,5);
	printf("\n\nTitik T setelah di geser(T,4,5): \n\tnilai absis: %d\n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	
	refleksiX(&T);
	printf("\n\nTitik T setelah di refleksiX(T): \n\tnilai absis: %d\n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	
	refleksiY(&T);
	printf("\n\nTitik T setelah di refleksiY(T): \n\tnilai absis: %d\n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	
	dilatasi(&T, 12);
	printf("\n\nTitik T setelah di dilatasi(T,12): \n\tnilai absis: %d\n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	makeTitik(&X,2,5);
	dilatasiX(&T, X, -5);
	printf("\n\nTitik X : \n\tnilai absis: %d\n\tnilai ordinat: %d", getAbsis(X), getOrdinat(X));
	printf("\n\nTitik T setelah di dilatasiX(T,X,-5): \n\tnilai absis: %d\n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	
	printf("\n\nTitik T : \n\tnilai absis: %d\n\tnilai ordinat: %d", getAbsis(T), getOrdinat(T));
	printf("\nkuadran(T): %d", kuadran(T));

	return 0;
}
