/* ------------------------------------------------------------------------------------------------------------------ */ 
/* File        : PTR12.cpp            */ 
/* Deskripsi   : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */ 
/*      		 Melakukan offset terhadap tabel tergantung fungsi f  */ 
/* ------------------------------------------------------------------------------------------------------------------ */ 
 
 #include<stdio.h>
 
/* Kamus Global */ 
 int N;    /* ukuran efektif */ 
 
/* Prototype, fungsi yang diberikan sebagai parameter aktual */ 
void succ (int *i);  /* suksessor, berupa procedure dg parameter passing by ref */ 
void pred (int *i);  /* predesessor, berupa procedure dg parameter passing by ref */ 
 
/* Prosedur dengan parameter sebuah fungsi */ 
void geser (int *TT, void (*f) (int *)); 
 
/* Program Utama */ 
int main() 
{ 
	/* kamus lokal */ 
	int MyTab[10]; //deklarasi var 'MyTab', array bertipe int dg 10 elemen
	int i; 
	
	/* program */
	//Inisialisasi isi array tersebut dengan bilangan dari 0 - 10  
	N = 10; 
	for (i = 0; i < N; i++) 
	{ 
		MyTab[i] = i; 
	}
	
	//Mencetak isi dari arrray MyTab sebelum dikenakan operasi 
	printf("Isi tabel dalam main sebelum pemanggilan : \n"); 
	for (i = 0; i < N; i++) 
	{ 
		printf(" %d ", MyTab[i]); 
	} 
	printf("\n"); 
	
	
	/* Pakai geser dengan parameter succ */ 
	printf("Geser dengan succ \n");
	/*	Operasi oleh fungsi geser dengan mengirimkan argumen berupa alamat dari
		array MyTab, dan juga fungsi succ yang akan memberikan operasi successor
		terhadap anggota array MyTab
	*/ 
	geser (MyTab, succ);
	
	//Mencetak isi dari array MyTab setelah dikenakan operasi successor 
	printf(" dalam main \n"); 
	for (i = 0; i < N; i++) 
	{ 
		printf(" %d ", MyTab[i]); 
	} 
	printf("\n"); 
	
	/* Pakai geser dengan parameter pred */ 
	printf("Geser dengan pred \n");
	/*	Operasi oleh fungsi geser dengan mengirimkan argumen berupa alamat dari
		array MyTab, dan juga fungsi succ yang akan memberikan operasi successor
		terhadap anggota array MyTab
	*/  
	geser (MyTab, pred);
	
	//Mencetak isi dari array MyTab setelah dikenakan operasi predecesor  
	printf(" dalam main setelah aplikasi pred \n"); 
	for (i = 0; i < N; i++) 
	{ 
		printf(" %d ", MyTab[i]); 
	} 
	printf("\n"); 
	return 0; 
} 
 
/* Body Function */
//Mengubah nilai pada alamat yang ditunjuk oleh var i, yaitu menjadi 'i + 1' 
void succ (int *i) 
{ 
	*i = *i+1; 
} 
 
//Mengubah nilai pada alamat yang ditunjuk oleh var i, yaitu menjadi 'i - 1' 
void pred (int *i) 
{ 
	*i = *i-1; 
} 
 
//Prosedur menggeser anggota dalam suatu array dengan suatu operasi tertentu
void geser (int *TT, void (*f) (int *)) 
{ 
	int i; 
	
	printf(" dalam geser \n"); 
	for (i = 0; i < N; i++) 
	{ 
		f (&TT[i]); 
		printf(" %d ", TT[i]); 
	} 
	printf("\n"); 
} 
