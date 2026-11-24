#include "sipus.h"

#include <iostream>

void inisialisasi(DaftarBuku& daftar, int kapasitasAwal) {
    if (kapasitasAwal < 1) kapasitasAwal = 4;
    daftar.data = new Buku[kapasitasAwal];
    daftar.n = 0;
    daftar.kapasitas = kapasitasAwal;
}

void bebaskan(DaftarBuku& daftar) {
    delete[] daftar.data;
    daftar.data = nullptr;
    daftar.n = 0;
    daftar.kapasitas = 0;
}

Buku* cariKode(DaftarBuku& daftar, const std::string& kode) {
    for (int i = 0; i < daftar.n; ++i) {
        if (daftar.data[i].kode == kode) return &daftar.data[i];
    }
    return nullptr;
}

bool tambahBuku(DaftarBuku& daftar, const Buku& buku) {
    if (buku.kode.empty() || cariKode(daftar, buku.kode) != nullptr) return false;

    if (daftar.n == daftar.kapasitas) {
        int kapasitasBaru = daftar.kapasitas * 2;
        Buku* dataBaru = new Buku[kapasitasBaru];
        for (int i = 0; i < daftar.n; ++i) dataBaru[i] = daftar.data[i];
        delete[] daftar.data;
        daftar.data = dataBaru;
        daftar.kapasitas = kapasitasBaru;
    }

    daftar.data[daftar.n] = buku;
    ++daftar.n;
    return true;
}

bool ubahBuku(DaftarBuku& daftar, const std::string& kode) {
    Buku* buku = cariKode(daftar, kode);
    if (buku == nullptr) return false;

    std::cout << "Judul baru: ";
    std::getline(std::cin >> std::ws, buku->judul);
    std::cout << "Penulis baru: ";
    std::getline(std::cin, buku->penulis);
    std::cout << "Kategori baru: ";
    std::getline(std::cin, buku->kategori);
    std::cout << "Tahun terbit baru: ";
    std::cin >> buku->tahun;
    std::cout << "Stok baru: ";
    std::cin >> buku->stok;
    return true;
}

bool hapusBuku(DaftarBuku& daftar, const std::string& kode) {
    int indeks = -1;
    for (int i = 0; i < daftar.n; ++i) {
        if (daftar.data[i].kode == kode) {
            indeks = i;
            break;
        }
    }
    if (indeks == -1) return false;

    for (int i = indeks; i < daftar.n - 1; ++i) {
        daftar.data[i] = daftar.data[i + 1];
    }
    --daftar.n;
    return true;
}

void tampilkanBuku(const Buku& buku) {
    std::cout << "Kode: " << buku.kode
              << " | Judul: " << buku.judul
              << " | Penulis: " << buku.penulis
              << " | Kategori: " << buku.kategori
              << " | Tahun: " << buku.tahun
              << " | Stok: " << buku.stok
              << " | Total dipinjam: " << buku.totalDipinjam << '\n';
}

void tampilkanSemuaBuku(const DaftarBuku& daftar) {
    if (daftar.n == 0) {
        std::cout << "Belum ada data buku.\n";
        return;
    }
    for (int i = 0; i < daftar.n; ++i) tampilkanBuku(daftar.data[i]);
}
