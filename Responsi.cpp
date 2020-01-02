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


//ADT Mobil
typedef Mobil *List;
void CreateEmpty(List &L);
bool IsEmpty(List L);
bool IsOneElement(List L);
bool isRent(List L);
void RentPertama(List &L,infotype *tnkb,int *biayasewa);
void Rent(List &L,infotype &tnkb,int &biayasewa,pos pilih,int no);
void insertFirst(List &L,address P);
void insertAfter(List &L,address Prec,address P);
address alokasi(infotype tnkb,infotype merk,infotype warna,infotype tahun,int biaya);
void addMobil(List &L,address P);
void delFirst(List &L);
void delMobil(List &L,int select,int no);
void updateTarif(List &L,int biaya,int select,int no);
void printMobil(List L,int no);
void availableMobil(List L,int no);
void inisialisasiMobil(List &L,infotype tnkb);

//ADT Driver
void CreateEmpty(Queue *D);
bool isEmpty(Queue D);
bool isFull(Queue D);
bool isTask(Queue D);
bool isOneElement(Queue D);
void addDriver(Queue *D,infotype ktp,infotype nama,infotype alamat,infotype usia);
void Task(Queue *D,infotype *nama);
void updateDriver(Queue *D,infotype update,pos select);
void delDriver(Queue *D,pos select);
void printDriver(Queue D);
void inisialisasiDriver(Queue *D,infotype nama);

//ADT Konsumen
void CreateEmpty(Konsumen *K);
bool isEmpty(Konsumen K);
bool isFull(Konsumen K);
bool isOneElement(Konsumen K);
void addKonsumen(Konsumen *K,infotype ktp,infotype nama,infotype alamat);
void printKonsumen(Konsumen K);
void delKonsumen(Konsumen *K,pos select);
void delKonsumen(Konsumen *K,infotype *nama,infotype *alamat);

//ADT Transaksi
void CreateEmpty(Transaksi &T);
bool IsEmpty(Transaksi T);
bool IsOneElement(Transaksi T);
void insertFirst(Transaksi &T,ID_Transaksi P);
void insertAfter(Transaksi &T,ID_Transaksi sblm,ID_Transaksi P);
void delPenyewaan(Transaksi &L);
void addPenyewaan(Transaksi &T,ID_Transaksi P);
ID_Transaksi Alokasi(infotype nama_Konsumen,infotype alamat,infotype tnkb,
	infotype nama_Driver,Date sewa,Date kembali,int biayasewa);
infotype getNama(Konsumen K);
void printPenyewaan(Transaksi T,int no);
void delTransaksi(Transaksi &T,infotype *nama_konsumen,infotype *alamat,infotype *tnkb,
	Date *sewa,Date *kembali,infotype *nama_driver,int *biayasewa,pos select,int no);

//Data Pembayaran
void CreateEmpty(pembayaran &B);
bool IsEmpty(pembayaran T);
bool IsOneElement(pembayaran T);
ID_Pembayaran Alokasi(infotype nama,infotype alamat,
	infotype tnkb,infotype nama_driver,Date sewa,Date bayar,int denda,int totbiaya);
int hitungBayar(int denda,int sewa,int biaya);
void insertFirst(pembayaran &B,ID_Pembayaran P);
void insertAfter(pembayaran &B,ID_Pembayaran Prec,ID_Pembayaran P);
void addPembayaran(pembayaran &B,ID_Pembayaran P);
void bayarSewa(infotype Nama_Driver,Date kembali,Date Bayar,Date Sewa,int biayaSewa,int &totdenda,int &totbayar);
void printPembayaran(pembayaran T,int no);

