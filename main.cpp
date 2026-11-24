
#include "sipus.h"
#include <iostream>
#include <limits>
using namespace std;

void tampilkanKelompok() {
    cout << "\n========================================\n";
    cout << "          ANGGOTA KELOMPOK 12\n";
    cout << "========================================\n";
    cout << "1. Sarah Nafila Hawwa\n";
    cout << "   NIM: 260530911100\n";
    cout << "2. Ni Kadek Kesya Putri\n";
    cout << "   NIM: 260530911089\n";
    cout << "Kelas: E\n";
    cout << "========================================\n";
}

void menuBuku(DaftarBuku& daftar) {
    int pilihan;

    do {
        cout << "\n========== KELOLA BUKU ==========\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Semua Buku\n";
        cout << "3. Ubah Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Kembali\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid!\n";
            continue;
        }

        switch (pilihan) {
            case 1: {
                Buku buku;

                cout << "\n===== TAMBAH BUKU =====\n";
                cout << "Kode buku: ";
                cin >> buku.kode;

                cout << "Judul buku: ";
                getline(cin >> ws, buku.judul);

                cout << "Penulis: ";
                getline(cin, buku.penulis);

                cout << "Kategori: ";
                getline(cin, buku.kategori);

                cout << "Tahun terbit: ";
                cin >> buku.tahun;

                cout << "Stok: ";
                cin >> buku.stok;

                buku.totalDipinjam = 0;

                if (tambahBuku(daftar, buku)) {
                    cout << "Buku berhasil ditambahkan!\n";
                } else {
                    cout << "Gagal! Kode buku sudah digunakan atau kosong.\n";
                }
                break;
            }

            case 2:
                cout << "\n===== DAFTAR BUKU =====\n";
                tampilkanSemuaBuku(daftar);
                break;

            case 3: {
                string kode;
                cout << "Masukkan kode buku yang ingin diubah: ";
                cin >> kode;

                if (ubahBuku(daftar, kode)) {
                    cout << "Data buku berhasil diubah!\n";
                } else {
                    cout << "Buku tidak ditemukan!\n";
                }
                break;
            }

            case 4: {
                string kode;
                cout << "Masukkan kode buku yang ingin dihapus: ";
                cin >> kode;

                if (hapusBuku(daftar, kode)) {
                    cout << "Buku berhasil dihapus!\n";
                } else {
                    cout << "Buku tidak ditemukan!\n";
                }
                break;
            }

            case 5:
                cout << "Kembali ke menu sebelumnya...\n";
                break;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilihan != 5);
}

void menuAnggota(DaftarAnggota& daftar) {
    int pilihan;

    do {
        cout << "\n========== KELOLA ANGGOTA ==========\n";
        cout << "1. Tambah Anggota\n";
        cout << "2. Tampilkan Semua Anggota\n";
        cout << "3. Ubah Anggota\n";
        cout << "4. Kembali\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid!\n";
            continue;
        }

        switch (pilihan) {
            case 1: {
                Anggota anggota;

                cout << "\n===== TAMBAH ANGGOTA =====\n";
                cout << "ID anggota: ";
                cin >> anggota.id;

                cout << "Nama lengkap: ";
                getline(cin >> ws, anggota.nama);

                cout << "Program studi: ";
                getline(cin, anggota.prodi);

                anggota.sedangPinjam = 0;

                if (tambahAnggota(daftar, anggota)) {
                    cout << "Anggota berhasil ditambahkan!\n";
                } else {
                    cout << "Gagal! ID anggota sudah digunakan atau kosong.\n";
                }
                break;
            }

            case 2:
                cout << "\n===== DAFTAR ANGGOTA =====\n";
                tampilkanSemuaAnggota(daftar);
                break;

            case 3: {
                string id;
                cout << "Masukkan ID anggota yang ingin diubah: ";
                cin >> id;

                if (ubahAnggota(daftar, id)) {
                    cout << "Data anggota berhasil diubah!\n";
                } else {
                    cout << "Anggota tidak ditemukan!\n";
                }
                break;
            }

            case 4:
                cout << "Kembali ke menu sebelumnya...\n";
                break;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilihan != 4);
}

void menuProgram(DaftarBuku& buku, DaftarAnggota& anggota) {
    int pilihan;

    do {
        cout << "\n========== MENU SiPus ==========\n";
        cout << "1. Kelola Buku\n";
        cout << "2. Kelola Anggota\n";
        cout << "3. Kembali ke Menu Utama\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid!\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                menuBuku(buku);
                break;

            case 2:
                menuAnggota(anggota);
                break;

            case 3:
                cout << "Kembali ke menu utama...\n";
                break;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilihan != 3);
}

int main() {
    DaftarBuku daftarBuku;
    DaftarAnggota daftarAnggota;

    inisialisasi(daftarBuku);
    inisialisasiAnggota(daftarAnggota);

    int pilihan;

    do {
        cout << "\n========================================\n";
        cout << " SISTEM PEMINJAMAN PERPUSTAKAAN MINI\n";
        cout << "                 SiPus\n";
        cout << "========================================\n";
        cout << "1. Lihat Anggota Kelompok\n";
        cout << "2. Masuk ke Program SiPus\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid!\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                tampilkanKelompok();
                break;

            case 2:
                menuProgram(daftarBuku, daftarAnggota);
                break;

            case 3:
                cout << "Terima kasih telah menggunakan SiPus!\n";
                break;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilihan != 3);

    bebaskan(daftarBuku);
    bebaskanAnggota(daftarAnggota);

    return 0;
}
