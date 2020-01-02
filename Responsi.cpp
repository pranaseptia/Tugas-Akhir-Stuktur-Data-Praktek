#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>

#define DRIVER 8
#define MAX 14

using namespace std;

typedef string infotype;
//Data Mobil
typedef struct tNode *address;
typedef bool status;
typedef struct tNode{
	infotype NoTNKB;
	infotype Merk;
	infotype Warna;
	infotype Tahun;
	int biayaSewa;
	status sewa;
	address Next;
}Mobil;
typedef Mobil *List;

//Data Driver
typedef int pos;
typedef struct{
	pos Head;
	pos Tail;
	infotype noKTP[DRIVER];
	infotype Nama[DRIVER];
	infotype Alamat[DRIVER];
	infotype Usia[DRIVER];
	status service[DRIVER];
}Queue;

//Data Konsumen
typedef struct{
	pos Head;
	pos Tail;
	infotype noKTP[MAX];
	infotype Nama[MAX];
	infotype Alamat[MAX];
}Konsumen;

//Tanggal
typedef struct{
	int Tanggal;
	int Bulan;
	int Tahun;
}Date;

//Data Transaksi
typedef struct TNode *ID_Transaksi;
typedef struct TNode{
	infotype Nama_Konsumen;
	infotype Alamat;
	infotype NoTNKB;
	infotype Nama_Driver;
	Date Sewa;
	Date Kembali;
	int biayaSewa;
	ID_Transaksi Next;
}transaksi;
typedef transaksi *Transaksi;

//Data Pembayaran
typedef struct TBayar *ID_Pembayaran;
typedef struct TBayar{
	infotype Nama_Konsumen;
	infotype Alamat;
	infotype NoTNKB;
	infotype Nama_Driver;
	Date Sewa;
	Date Kembali;	
	Date Bayar;
	int Denda;
	int totBiaya;
	ID_Pembayaran Next;
}Pembayaran;
typedef Pembayaran *pembayaran;
