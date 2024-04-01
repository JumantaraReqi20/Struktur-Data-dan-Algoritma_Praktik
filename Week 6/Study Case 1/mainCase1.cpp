#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "case1.h"


int main(){
	int pilih;
    infotype kota, warga;
	
	// First = Nil;
	// Last = Nil;
	
	for(;;){
		// system("cls");
        printf("______ \033[92mSelamat datang di Sistem Terpadu Data Warga Kota\033[0;0m ______\n\n");
		printf("\033[34m[\033[0m1\033[34m]\033[0m Tambah Kota");
		printf("\n\033[34m[\033[0m2\033[34m]\033[0m Ubah Nama Kota ");
		printf("\n\033[34m[\033[0m3\033[34m]\033[0m Delete Kota "); 
		printf("\n\033[34m[\033[0m4\033[34m]\033[0m Tambah Warga "); 
		printf("\n\033[34m[\033[0m5\033[34m]\033[0m Ubah Nama Warga ");
		printf("\n\033[34m[\033[0m6\033[34m]\033[0m Delete Between ");
		printf("\n\033[34m[\033[0m7\033[34m]\033[0m Delete Warga ");
		printf("\n\033[34m[\033[0m8\033[34m]\033[0m Lihat Data Warga ");
		printf("\n\033[34m[\033[0m9\033[34m]\033[0m Exit ");
		printf("\nPilih menu: ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:
				printf("Masukkan Nama Kota: ");
				getchar();
				scanf("%s", kota);
				tambahKota(kota);
				break;
			case 2:
				printf("Masukkan Nama Kota yang akan diubah: ");
				getchar();
				scanf("%s", kota);
                printf("Masukkan Nama Kota Baru: ");
				getchar();
                infotype newNamaKota;
				scanf("%s", newNamaKota);
                ubahKota(kota, newNamaKota);
				break;
			case 3:
                printf("Masukkan Nama Kota yang akan diubah: ");
				getchar();
				scanf("%s", kota);
				if(isEmpty()){
					printf("--> Underflow");
					printf("\nKlik apa saja untuk melanjutkan >> "); getch(); 
				}else{
					deleteKota(kota);
					printf("\nHuruf sudah terhapus!");
					printf("\nKlik apa saja untuk melanjutkan>> "); getch();
				}
                getch();
				break;
			case 4:
				printf("Masukkan Nama Kota: ");
				getchar();
				scanf("%s", kota);
                printf("Masukkan Nama Warga: ");
				getchar();
				scanf("%s", warga);
				tambahWarga(kota, warga);
				printf("\nKlik apa saja untuk melanjutkan>> "); getch();
			
				break;	
			case 5:
				
				break;
			case 6:
				// Delete_Between(&Last);
				break;			
			case 7:
				// P = First;
				// printf("\nHuruf yang anda inputkan: \n");
				// viewAsc(First);
				// printf("\nKlik apa saja untuk melanjutkan>> "); getch();
				break;
			case 8:
            if (isEmpty()){
                printf("Data kosong");
            } else {
				displayKota();
				printf("\nKlik apa saja untuk melanjutkan>> "); 
                getch();
            }
				break;
			case 9:
				exit(0);
				break;
			default:
				// printf("\nMaaf Anda salah menginputkan nomor, pilih 1-9\n");
				system("pause");
	    }
    }
		
}
