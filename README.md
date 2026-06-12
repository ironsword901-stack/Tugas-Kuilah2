# Sistem Manajemen Toko Online - Aplikasi Data Structures

## 📋 Deskripsi Aplikasi

Aplikasi ini adalah sistem manajemen toko online yang mengintegrasikan 3 jenis struktur data fundamental:

1. **Array/Vector** - Manajemen katalog produk
2. **Stack** - Riwayat transaksi dan fitur undo/redo
3. **Graph (Weighted Directed)** - Sistem rekomendasi produk dan rute pengiriman antar warehouse

## 🎯 Fitur Utama

### 1. Manajemen Produk (Array)
- Tambah produk baru ke katalog
- Cari produk berdasarkan ID atau nama
- Update harga produk
- Tampilkan seluruh katalog produk

### 2. Riwayat Transaksi (Stack)
- Catat setiap transaksi pembelian
- Fitur UNDO untuk membatalkan transaksi terakhir
- Fitur REDO untuk mengembalikan transaksi yang dibatalkan
- Lihat riwayat transaksi terbaru

### 3. Rekomendasi Produk & Rute Pengiriman (Graph)
- Sistem rekomendasi produk berdasarkan kategori yang terhubung
- Simulasi rute pengiriman termurah antar warehouse menggunakan Dijkstra's Algorithm
- Visualisasi hubungan antar kategori produk

## 📁 Struktur File

```
Tugas-Kuilah2/
├── README.md
├── main.cpp
├── Product.h
├── ShoppingCart.h
├── TransactionHistory.h
├── WarehouseGraph.h
└── CMakeLists.txt
```

## 🛠️ Teknologi

- **Bahasa**: C++
- **Compiler**: C++11 atau lebih tinggi
- **Build System**: CMake (opsional)

## 📚 Struktur Data yang Digunakan

### 1. Array (Vector)
```cpp
vector<Product> productCatalog;  // Menyimpan semua produk
```

**Operasi:**
- Insert: O(1) amortized
- Search: O(n) linear search
- Update: O(n)
- Delete: O(n)

### 2. Stack (LIFO - Last In First Out)
```cpp
stack<Transaction> transactionHistory;
stack<Transaction> redoStack;
```

**Operasi:**
- Push: O(1)
- Pop: O(1)
- Top: O(1)

**Kegunaan:**
- Menyimpan riwayat transaksi
- Implementasi undo/redo

### 3. Graph (Weighted Directed)
```cpp
map<string, vector<pair<string, int>>> graph;  // Adjacency list
```

**Algoritma:**
- **DFS (Depth First Search)**: Untuk rekomendasi produk
- **Dijkstra's Algorithm**: Untuk menemukan rute pengiriman termurah

**Kegunaan:**
- Node: Kategori produk / Warehouse
- Edge: Hubungan antar kategori / Jarak antar warehouse dengan biaya

## 🚀 Cara Menggunakan

### Compile
```bash
g++ -std=c++11 main.cpp -o toko_online
```

### Run
```bash
./toko_online
```

## 💡 Contoh Use Case

### Use Case 1: Manajemen Produk
1. Admin menambah produk "Laptop" dengan kategori "Elektronik"
2. Pelanggan mencari produk dengan keyword tertentu
3. Harga produk diperbarui, sistem menyimpan perubahan

### Use Case 2: Riwayat Transaksi
1. Pelanggan membeli produk A → Stack push
2. Pelanggan membeli produk B → Stack push
3. Pelanggan membatalkan pembelian terakhir (UNDO) → Stack pop
4. Pelanggan mengembalikan transaksi (REDO) → Restore dari redo stack

### Use Case 3: Rekomendasi & Rute Pengiriman
1. Pelanggan membeli produk dari kategori "Laptop"
2. Sistem merekomendasikan produk dari kategori terkait seperti "Aksesori Komputer"
3. Sistem menghitung rute pengiriman termurah dari warehouse terdekat ke alamat pelanggan

## 📖 Referensi

- Data Structures and Algorithms in C++ (Goodrich, Tamassia, Mount)
- GeeksforGeeks: Data Structures Tutorial
- Dijkstra's Algorithm: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

---

**Penulis:** Ironsword901-stack  
**Tanggal:** Juni 2026
