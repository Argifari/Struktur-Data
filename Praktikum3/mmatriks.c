/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal   : 17 September 2025*/
/***********************************/

#include <stdio.h>
#include "matriks.c"
int main() {
	while (!IsEmptyStack(S) && InfoTop(S) !=  ‘(' && ((kata[i] = ‘+’ || kata[i] == ‘-’) || 
(kata[i] == "*" || kata[i] == ‘/’)) || 
(InfoTop(S) == ‘*’ || InfoTop(S) == ‘/’)) {
}
	/*kamus*/
	Matriks M;	
	Matriks M1;	
	Matriks M2;	
	Matriks K;
	Matriks hasil;	
	int row,col;
	/*algoritma*/
	initMatriks(&M);
	initMatriks(&M1);
	initMatriks(&M2);

	printf("Matriks semuanya : \n");
	printMatriks(M);

	printf("Matriks isi dengan populateMatriks(&M,2,3): \n");
	populateMatriks(&M,2,3);

	printf("Matriks sekarang: \n");
	printf("Matriks nbaris:%d \n", getNBaris(M));
	printf("Matriks nkolom:%d \n", getNKolom(M));
	viewMatriks(M);
	
	printf("Matriks identitas: \n");
	isiMatriksIdentitas(&M,5);
	viewMatriks(M);
	initMatriks(&M);
	
	printf("Matriks isi random: \n");
	isiMatriksRandom(&M,5,4);
	viewMatriks(M);
	
	printf("Hapus X delX(&M,2) di Matriks: \n");
	delX(&M,2);
	viewMatriks(M);
	
	printf("IsEmptyMatriks(M): %d\n", isEmptyMatriks(M));
	printf("IsFullMatriks(M): %d\n", isFullMatriks(M));
	viewMatriks(M);
	
	printf("Matriks sekarang setelah addX(&M,5,2,2): \n");
	addX(&M,5,2,2);
	viewMatriks(M);
	
	printf("Matriks M1: \n");
	isiMatriksRandom(&M1,3,2);
	viewMatriks(M1);

	printf("Matriks M2: \n");
	isiMatriksRandom(&M2,2,4);
	viewMatriks(M2);
	
	printf("Matriks Hasil penjumlahan M1 dan M2: \n");
	hasil = addMatriks(M1,M2);
	viewMatriks(hasil);
	
	printf("Matriks Hasil pengurangan M1 dan M2: \n");
	hasil = subMatriks(M1,M2);
	viewMatriks(hasil);

	printf("Matriks Hasil perkalian M1 dan M2: \n");
	hasil = kaliMatriks(M1,M2);
	viewMatriks(hasil);

	transposeMatriks(&hasil);
	printf("Matriks Hasil yang ditransposkan: \n");
	viewMatriks(hasil);

	printf("Matriks M : \n");
	viewMatriks(M);
	
	printf("Matriks M setelah ditranspos: \n");
	viewMatriks(getTransposeMatriks(M));

	printf("Matriks M yang dipadding 1: \n");
	viewMatriks(addPadding(M, 1));

	initMatriks(&M);
	isiMatriksRandom(&M,4,4);
	printf("Matriks M sekarang : \n");
	viewMatriks(M);

	printf("Matriks M yang dimaxPooling(M, 2) : \n");
	viewMatriks(maxPooling(M,2));

	printf("Matriks M yang diavgPooling(M, 2) : \n");
	viewMatriks(avgPooling(M,2));
	
	printf("Matriks M sekarang : \n");
	viewMatriks(M);

	printf("Mencari nilai X = 73 di Matriks M: \n");
	searchX(M,64,&row,&col);
	printf("X = 64 ada di row %d col %d", row,col);

	initMatriks(&M);
	isiMatriksIdentitas(&M,5);
	
	printf("Matriks M sekarang : \n");
	viewMatriks(M);

	printf("Mencari jumlah nilai X = 1 di Matriks M: \n");
	printf("countX(M,1) : %d\n", countX(M,1));

	initMatriks(&K);
	initMatriks(&M);
	populateMatriks(&M,3,3);
	populateMatriks(&K,3,3);
	printf("Konvolusi Matriks M dan kernel K: \n");
	
	printf("Matriks M sekarang: \n");
	viewMatriks(M);

	printf("Kernel k sekarang: \n");
	viewMatriks(K);

	printf("Hasil konvolusi: \n");
	viewMatriks(conv(M,K));


	return 0;
}
