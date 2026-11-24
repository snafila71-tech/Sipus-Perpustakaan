#ifndef SIPUS_H
#define SIPUS_H

#include <string>

const int JML_BULAN = 12;
const int JML_KATEGORI = 5;

struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

struct Buku {
    std::string kode;
    std::string judul;
    std::string penulis;
    std::string kategori;
    int tahun;
    int stok;
    int totalDipinjam;
};

struct Anggota {
    std::string id;
    std::string nama;
    std::string prodi;
    int sedangPinjam;
};

struct Transaksi {
    int nomor;
    std::string idAnggota;
    std::string kodeBuku;
    Tanggal tglPinjam;
    Tanggal tglKembali;
    bool selesai;
    int denda;
};

struct DaftarBuku {
    Buku* data;
    int n;
    int kapasitas;
};

struct DaftarAnggota {
    Anggota* data;
    int n;
    int kapasitas;
};

struct DaftarTransaksi {
    Transaksi* data;
    int n;
    int kapasitas;
};

// F1 - Kelola Buku
void inisialisasi(DaftarBuku& daftar, int kapasitasAwal = 4);
void bebaskan(DaftarBuku& daftar);
bool tambahBuku(DaftarBuku& daftar, const Buku& buku);
bool ubahBuku(DaftarBuku& daftar, const std::string& kode);
bool hapusBuku(DaftarBuku& daftar, const std::string& kode);
Buku* cariKode(DaftarBuku& daftar, const std::string& kode);
void tampilkanBuku(const Buku& buku);
void tampilkanSemuaBuku(const DaftarBuku& daftar);

// F2 - Kelola Anggota
void inisialisasiAnggota(DaftarAnggota& daftar, int kapasitasAwal = 4);
void bebaskanAnggota(DaftarAnggota& daftar);
bool tambahAnggota(DaftarAnggota& daftar, const Anggota& anggota);
bool ubahAnggota(DaftarAnggota& daftar, const std::string& id);
Anggota* cariAnggota(DaftarAnggota& daftar, const std::string& id);
void tampilkanAnggota(const Anggota& anggota);
void tampilkanSemuaAnggota(const DaftarAnggota& daftar);

#endif
