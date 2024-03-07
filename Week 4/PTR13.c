/* ------------------------------------------------------------------------------------------------------------------ */ 
/* File        : PTR13.cpp          */ 
/* Author	   : Reqi Jumantara Hapid	*/
/* Deskripsi   : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */ 
/*      		 Melakukan offset terhadap tabel tergantung fungsi f     */ 
/* ------------------------------------------------------------------------------------------------------------------ */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 
/* Kamus Global */ 
 int N;    /* ukuran efektif */ 
 enum MyType	//enu
  { 
   bulat, karakter 
  }; 
 
/* Prototype, fungsi yang diberikan sebagai parameter aktual */ 
void succI (int *i);  /* suksessor, berupa procedure by ref */ 
void predI (int *i);  /* predesessor */ 
void succC (char *c); /* suksessor, berupa procedure by ref */ 
void predC (char *c); /* predesessor */ 
 
/* print tabel yang belum ketahuan type datanya */ 
//Kita akan memberitahu kan tipe datanya melalui var enum 'ty'
void printtab (void *T, enum MyType Ty); 
 
/* Prosedur dengan parameter sebuah fungsi */
//f adalah sebuah pointer ke fungsi yang menerima parameter (void *) 
void geser (void *TT, void (*f) (void *), enum MyType Ty); 
 
/* Program Utama */ 
int main() 
{ 
	/* kamus lokal */ 
	void *MyTabInt; //deklarasi var pointer tanpa tipe data
	void *MyTabC; //deklarasi var pointer tanpa tipe data
	int i; 
	
	/* program */ 
	N = 10; 
	MyTabInt = (int *) malloc (N * sizeof(int)); //Alokasi memori untuk var bertipe int
	MyTabC   = (char *) malloc (N * sizeof(char)); //Alokasi memori untuk var bertipe char
	*((int *)MyTabInt) = 1; //inisialisasi var 'MyTabInt' dengan nilai 1, dicasting dulu
	for (i = 0; i < N; i++) //Mengisi array 'MyTabInt' dan array 'MyTabChar'
	{ 
		*((int *)MyTabInt + i) = i; 
		*((char *)MyTabC + i) = 'Z' + i; 
	} 
	
	//Menampilkan isi tabel sebelum dikenai operasi
	printf("Isi tabel dalam main sebelum pemanggilan : \n"); 
	
	printf("    Tabel integer \n"); 
	printtab ((int *) MyTabInt, bulat); 
	printf("\n    Tabel charakter \n"); 
	printtab ((char *) MyTabC, karakter); 
	
	printf("\n"); 
	
	/* Pakai geser dengan parameter succ */ 
	printf("\nGeser dengan succ \n"); 
	geser ((int *)MyTabInt, (void (*)( void *)) succI, bulat); 
	geser ((char *)MyTabC, (void (*)(void *)) succC, karakter); 
	printf(" dalam main \n"); 
	printf("    Tabel integer \n"); 
	printtab ((int *) MyTabInt, bulat); 
	printf("\n    Tabel charakter \n"); 
	printtab ((char *) MyTabC, karakter); 
	printf("\n"); 
	
	/* Pakai geser dengan parameter pred */ 
	printf("Geser dengan pred \n"); 
	geser (MyTabInt, (void (*) (void *)) predI, bulat); 
	geser (MyTabC, (void (*) (void *))predC, karakter); 
	printf(" dalam main \n"); 
	printf("    Tabel integer \n"); 
	printtab ((int *) MyTabInt, bulat); 
	printf("\n    Tabel charakter \n"); 
	printtab ((char *) MyTabC, karakter); 
	printf("\n"); 
	
	return 0; 
} 
	
	/* Body Function */
//Mengubah nilai pada alamat yang ditunjuk oleh var i, yaitu menjadi 'i + 1' 	 
void succI (int *i) 
{ 
	*i = *i+1; 
} 

//Mengubah nilai pada alamat yang ditunjuk oleh var i, yaitu menjadi 'i - 1'  
void predI (int *i) 
{ 
	*i = *i-1; 
} 

 //Mengubah nilai pada alamat yang ditunjuk oleh var c, yaitu menjadi 'c + 1' 
void succC (char *c) 
{ 
	*c = *c+1; 
} 

//Mengubah nilai pada alamat yang ditunjuk oleh var c, yaitu menjadi 'c - 1'  
void predC (char *c) 
{ 
	*c = *c-1; 
} 
 
 
 //Prosedur menggeser anggota dalam suatu array dengan suatu operasi tertentu
 //sesuai dengan fungsi yang dipanggil sebagai argumen dan juga tipe datanya
void geser ( void *TT, void (*f) (void *), enum MyType Ty) 
{ 
	int i; 
	
	printf(" dalam geser \n"); 
	for (i = 0; i < N; i++) 
	{ 
	switch (Ty){
		case bulat: 
			f (&((int *)TT)[i]); 
			printf(" %d ", ((int *)TT)[i]); 
			break;
		case karakter:
			f (&((char *)TT)[i]);
			printf(" %c ", ((char *)TT)[i]);
			break;
	}
	
	} 
	printf("\n"); 
} 


//Menampilkan nilai yang terdapat pada array tergantung dengan tipe datanya
void printtab (void *T, enum MyType Ty) 
{ 
	int i; 
	for (i = 0; i < N; i ++) 
	{ 
		switch (Ty) 
		{ 
			case bulat : printf("%d ", *((int *)T + i)); break; 
			case karakter : printf("%c ", *((char *)T + i)); break; 
		} 
	} 
}
