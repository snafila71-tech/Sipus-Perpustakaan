#include "sipus.h"

#include <iostream>

void inisialisasiAnggota(DaftarAnggota& daftar, int kapasitasAwal) {
    if (kapasitasAwal < 1) kapasitasAwal = 4;
    daftar.data = new Anggota[kapasitasAwal];
    daftar.n = 0;
    daftar.kapasitas = kapasitasAwal;
}

void bebaskanAnggota(DaftarAnggota& daftar) {
    delete[] daftar.data;
    daftar.data = nullptr;
    daftar.n = 0;
    daftar.kapasitas = 0;
}

Anggota* cariAnggota(DaftarAnggota& daftar, const std::string& id) {
    for (int i = 0; i < daftar.n; ++i) {
        if (daftar.data[i].id == id) return &daftar.data[i];
    }
    return nullptr;
}

bool tambahAnggota(DaftarAnggota& daftar, const Anggota& anggota) {
    if (anggota.id.empty() || cariAnggota(daftar, anggota.id) != nullptr) return false;

    if (daftar.n == daftar.kapasitas) {
        int kapasitasBaru = daftar.kapasitas * 2;
        Anggota* dataBaru = new Anggota[kapasitasBaru];
        for (int i = 0; i < daftar.n; ++i) dataBaru[i] = daftar.data[i];
        delete[] daftar.data;
        daftar.data = dataBaru;
        daftar.kapasitas = kapasitasBaru;
    }

    daftar.data[daftar.n] = anggota;
    ++daftar.n;
    return true;
}

bool ubahAnggota(DaftarAnggota& daftar, const std::string& id) {
    Anggota* anggota = cariAnggota(daftar, id);
    if (anggota == nullptr) return false;

    std::cout << "Nama baru: ";
    std::getline(std::cin >> std::ws, anggota->nama);
    std::cout << "Program studi baru: ";
    std::getline(std::cin, anggota->prodi);
    return true;
}

void tampilkanAnggota(const Anggota& anggota) {
    std::cout << "ID: " << anggota.id
              << " | Nama: " << anggota.nama
              << " | Prodi: " << anggota.prodi
              << " | Sedang pinjam: " << anggota.sedangPinjam << '\n';
}

void tampilkanSemuaAnggota(const DaftarAnggota& daftar) {
    if (daftar.n == 0) {
        std::cout << "Belum ada data anggota.\n";
        return;
    }
    for (int i = 0; i < daftar.n; ++i) tampilkanAnggota(daftar.data[i]);
}
