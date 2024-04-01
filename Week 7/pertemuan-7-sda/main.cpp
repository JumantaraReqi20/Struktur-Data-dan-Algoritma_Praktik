#include <stdio.h>
#include "kota.h"

int main(void){
    tambahKota("Cimahi");
    tambahKota("Bandung");
    tambahKota("Jakarta");
    tambahKota("Samarinda");
    tambahKota("Bali");
    tambahKota("Solo");
    tambahKota("Medan");

    tambahMahasiswaDalamKota("Cimahi", "Udin Sanjaya");
    tambahMahasiswaDalamKota("Cimahi", "Bagas Dribble");

    tambahMahasiswaDalamKota("Bandung", "Kipas Angin");
    tambahMahasiswaDalamKota("Bandung", "Royco Bergerak");

    tambahMahasiswaDalamKota("Jakarta", "Kipas Angin");
    tambahMahasiswaDalamKota("Jakarta", "Royco Bergerak");

    tambahMahasiswaDalamKota("Samarinda", "Kipas Angin");
    tambahMahasiswaDalamKota("Samarinda", "Royco Bergerak");

    tambahMahasiswaDalamKota("Bali", "Kipas Angin");
    tambahMahasiswaDalamKota("Bali", "Royco Bergerak");

    tambahMahasiswaDalamKota("Solo", "Kipas Angin");
    tambahMahasiswaDalamKota("Solo", "Royco Bergerak");

    tambahMahasiswaDalamKota("Medan", "Kipas Angin");
    tambahMahasiswaDalamKota("Medan", "Royco Bergerak");

    tampilKota();

    deleteKota("Bali");

    tampilKota();

    return 0;
}