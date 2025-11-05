#include <stdio.h>
#include "tabel.c"
/*Deskripsi : driver ADT tabel integer*/
/* NIM/Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 10 September 2025*/

int main() {
	/*kamus*/
	Tabel T;
	Tabel T2;
	int pos;
	
	/*algoritma*/
	//createTable(&T1);
	createTable(&T);
	printf("T.size :  %d", getSize(T));
	printf("\nisEmptyTable(T): %d", isEmptyTable(T));
	printf("\nisFullTable(T) : %d", isFullTable(T));
	//addXTable(&T1,'A');
	addXTable(&T, 'A');
	addXTable(&T, 'u');
	printf("\nIsi Tabel : \n");
	viewTable(T);
	printf("Size T sekarang : %d\n", getSize(T));
	searchX(T,'A', &pos);
	printf("SearchX(T,'A',pos) : %d", pos);
	printf("\ncountX(T,'A') : %d", countX(T,'A'));
	printf("\ncountVocal(T) : %d", countVocal(T));
	printf("\naddXTable(&T, 'O') :");
	addXTable(&T,'O');
	printf("\nIsi tabel sekarang : \n");
	viewTable(T);
	printf("addUniqueXTable(&T, 'O') :");
	addUniqueXTable(&T, 'O');
	printf("\nIsi tabel sekarang : \n");
	viewTable(T);
	printf("addUniqueXTable(&T, 'k') :\n");
	addUniqueXTable(&T, 'k');
	viewTable(T);
	
	printf("delXTable(&T, 'k') : \n");
	delXTable(&T,'k');
	printf("Isi tabel sekarang : \n");
	viewTable(T);
	printf("printTable(T): ");
	printTable(T);
	addXTable(&T,'O');
	addXTable(&T,'O');
	addXTable(&T,'O');
	addXTable(&T,'Y');
	printf("Isi tabel sekarang : \n");
	viewTable(T);
	delAllXTable(&T,'O');
	printf("delAllXTable(&T,'O') : \n");
	printf("Isi tabel sekarang : \n");
	printf("isi Size : %d\n", getSize(T));
	viewTable(T);
	printf("populateTable(&T,5): \n");
	populateTable(&T,5);
	
	viewTable(T);
	printf("Modus(T) : %c\n", Modus(T));
	
	printf("Tabel T2: ");
	T2 = T;
	viewTable(T2);
	printf("IsEqualTable(T,T2): %d\n",isEqualTable(T,T2));
	
	printf("Isi tabel sekarang : \n");
	viewTable(T);
	inverseTable(&T);
	
	printf("Isi tabel sekarang : \n");
	viewTable(T);

	
	
	//viewTable(T1);
	//addXTable(&T1,'B');
	//delXTable(&T1,'A');
	//viewTable(T1);
	//dst ...
	return 0;
}
