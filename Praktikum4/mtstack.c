/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal   : 24 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.c"
/* include tstack+boolean */

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	char x;
	char kata[30];
	/* algoritma */
	createStack( &A );

	printf("Print semua elemen stack A: \n");
	printf("Top Stack A: %d\n", top(A));
	printStack(A);

	push(&A,'c');
	push(&A,'a');
	push(&A,'n');
	push(&A,'t');

	printf("Stack A sekarang: \n");
	printf("Top Stack A: %d\n", top(A));
	printf("Info Top Stack A: %d\n", infotop(A));
	viewStack(A);
	
	pop(&A,&x);
	printf("Stack A setelah dipop: \n");
	printf("Top Stack A: %d\n", top(A));
	viewStack(A);
	
	printf("Character yang dipop: %c\n", x);
	
	printf("isEmptyStack(A): %d\n", isEmptyStack(A));
	printf("isFullStack(A): %d\n", isFullStack(A));
	printf("isPalindrom(A B A): %d\n",isPalindrom("A B A"));
	
	pushN(&A,12);
	printf("Stack A sekarang: \n");
	printf("Top Stack A: %d\n", top(A));
	viewStack(A);
	
	return 0;
}
