#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "case1.h"
#include <string.h>
#include <windows.h>


int main(){
	int pilih;
    infotype kota, warga;
	kt* first;
	first = Nil;
	
	for(;;){
		system("cls");
		displayKota(first);
		printf("______ \033[92mSelamat datang di Sistem Terpadu Data Warga Kota\033[0;0m ______\n\n");
		printf("\033[34m[\033[0m1\033[34m]\033[0m Tambah Kota");
		printf("\n\033[34m[\033[0m2\033[34m]\033[0m Tambah Warga "); 
		printf("\n\033[34m[\033[0m3\033[34m]\033[0m Ubah Nama Kota ");
		printf("\n\033[34m[\033[0m4\033[34m]\033[0m Ubah Nama Warga ");
		printf("\n\033[34m[\033[0m5\033[34m]\033[0m Delete Kota "); 
		printf("\n\033[34m[\033[0m6\033[34m]\033[0m Delete Warga ");
		printf("\n\033[34m[\033[0m7\033[34m]\033[0m Lihat Data Warga ");
		printf("\n\033[34m[\033[0m8\033[34m]\033[0m Exit ");
		printf("\nPilih menu: ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:
				printf("Masukkan Nama Kota: ");
				getchar();
				scanf("%s", kota);
				tambahKota(&first, kota);
				printf("\nKlik apa saja untuk melanjutkan>> "); getch();
				break;
			case 2:
			printf("Masukkan Nama Kota: ");
				getchar();
				scanf("%s", kota);
                printf("Masukkan Nama Warga: ");
				getchar();
				scanf("%s", warga);
				tambahWarga(first, kota, warga);
				printf("\nKlik apa saja untuk melanjutkan>> "); getch();
			
				break;
			case 3:
				printf("Masukkan Nama Kota yang akan diubah: ");
				getchar();
				scanf("%s", kota);
                printf("Masukkan Nama Kota Baru: ");
				getchar();
                infotype newNamaKota;
				scanf("%s", newNamaKota);
                ubahKota(first, kota, newNamaKota);
				printf("\nKlik apa saja untuk melanjutkan>> "); getch();

				break;
			case 4:
				printf("Masukkan Nama Kota: ");
				getchar();
				scanf("%s", kota);
                printf("Masukkan Nama Warga yang akan diubah: ");
				getchar();
				scanf("%s", warga);
				printf("Masukkan Nama Warga yang baru: ");
				getchar();
				infotype namaBaru;
				scanf("%s", namaBaru);
				ubahWarga(first, kota, warga, namaBaru);
				printf("\nKlik apa saja untuk melanjutkan>> "); getch();

				break;
				
			case 5:
				printf("Masukkan Nama Kota yang akan dihapus: ");
				getchar();
				scanf("%s", kota);
				if(isEmpty(first)){
					printf("--> Underflow");
					printf("\nKlik apa saja untuk melanjutkan >> "); getch(); 
				}else{
					deallocKota(&first, kota);
					printf("\nKota sudah terhapus!");
					printf("\nKlik apa saja untuk melanjutkan>> "); getch();
				}

				break;
			case 6:
				printf("Masukkan Nama Kota: ");
				getchar();
				scanf("%s", kota);
                printf("Masukkan Nama Warga: ");
				getchar();
				scanf("%s", warga);
				deallocWarga(&first, kota, warga);
				printf("\nKlik apa saja untuk melanjutkan>> "); getch();
				break;			
			case 7:
				if (isEmpty(first)){
                printf("Data kosong");
            	} else {
				displayKota(first);
				printf("\nKlik apa saja untuk melanjutkan>> "); 
                getch();
            	}
				break;
			case 8:
				exit(0);
				break;
				
			default:
				printf("Maaf Anda salah menginputkan nomor, pilih 1-9\n");
				printf("\nKlik apa saja untuk melanjutkan>> "); getch();
				break;
	    }
    }
		
}
