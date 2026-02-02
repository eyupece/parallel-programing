# OpenMP Paralel Programlama Ornekleri

Bu repo, OpenMP kullanarak CPU ve GPU uzerinde paralel programlama orneklerini icerir. Ornekler temel kavramlardan baslayip ileri duzeye kadar ilerler.

## Gereksinimler

- GCC 9+ veya Clang (OpenMP destekli)
- GPU ornekleri icin: LLVM/Clang with offloading veya NVIDIA HPC SDK

## Derleme

CPU ornekleri icin:
```bash
g++ -fopenmp dosya.cpp -o dosya
```

GPU ornekleri icin:
```bash
clang++ -fopenmp -fopenmp-targets=nvptx64 dosya.cpp -o dosya
```

## Klasor Yapisi

```
.
├── 01-basics/              # Temel OpenMP kullanimi
├── 02-synchronization/     # Thread senkronizasyonu
├── 03-parallel-for/        # Paralel donguler ve reduction
├── 04-scheduling/          # Is dagilim stratejileri
├── 05-tasks-sections/      # Task ve section yapilari
├── 06-gpu-offloading/      # GPU hesaplama (target)
└── 07-applications/        # Uygulama ornekleri
```

## Ornekler

### 01-basics
Paralel bolge olusturma, thread ID alma, temel cikti islemleri.

### 02-synchronization
- `atomic_counter.cpp` - Atomic islemlerle guvenli sayac
- `critical_counter.cpp` - Critical bolge kullanimi
- `barrier.cpp` - Thread senkronizasyonu
- `master.cpp` - Sadece master thread calistirma
- `single.cpp` - Tek thread calistirma (nowait)

### 03-parallel-for
- Temel for donguleri
- Reduction islemleri (toplam, maksimum, ortalama)
- SIMD vektorlestirme

### 04-scheduling
Static, dynamic ve guided zamanlama stratejileri.

### 05-tasks-sections
Sections ile statik is bolumleme, task ile dinamik gorev olusturma.

### 06-gpu-offloading
`#pragma omp target` ile GPU'ya veri aktarimi ve hesaplama.

### 07-applications

**pi-calculation/** - Monte Carlo benzeri Pi hesabi (CPU ve GPU)

**matrix-operations/** - Matris-vektor carpimi ornekleri

**comparison/** - Ayni algoritmanin seri, CPU paralel ve GPU paralel versiyonlari:
- Dizi carpimi
- Maksimum bulma
- Toplam hesaplama

**advanced-algorithms/** - Ozel algoritmalar:
- Fibonacci (paralellestirme zorluklari)
- Matris carpimi (NxN)
- Prefix sum (kumutatif toplam)