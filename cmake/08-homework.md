<!-- .slide: data-background="#111111" -->

# `cmake`

## Praca domowa

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

### Pre-work

* Poczytaj o zasadach SOLID, dotyczących pisania dobrego kodu obiektowego
* Poczytaj o zasadach dobrego kodu w C++ na [CppCoreGuidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)
* Dowiedz się czym jest system budowania Make

___

### Post-work

* Dorzućcie do projektu university-db system budowania `cmake` (10 XP)

___

### `cmake` w university-db

* Użyjcie zmiennej `${PROJECT_NAME}`
* Lista plików cpp w zmiennej
* Wszystko poza plikiem `main.cpp` powinno kompilować się do biblioteki statycznej
* Binarka (main.cpp) powinna linkować się z powyższą biblioteką.
* Napiszcie odpowiedni plik `.github/workflows/main.yml` który spowoduje, że GitHub będzie automatycznie uruchamiał kompilację projektu dla każdego nowego commita.

___

### `cmake` w SHM (Premium)

* Użyjcie zmiennej `${PROJECT_NAME}`
* Lista plików cpp w zmiennej
* Wszystko poza plikiem `main.cpp` powinno kompilować się do biblioteki statycznej
* Binarka (main.cpp) powinna linkować się z powyższą biblioteką.
* Napiszcie odpowiedni plik `.github/workflows/main.yml` który spowoduje, że GitHub będzie automatycznie uruchamiał kompilację projektu dla każdego nowego commita.

___

### Podwaliny pod testy w SHM (Premium)

Na podstawie lektury plików CMakeLists.txt z prac domowych wywnioskujcie, w jaki sposób dodawana jest biblioteka `gtest` do testów

* Utwórzcie proste testy do projektu SHM (co najmniej 1 test metodą Copy&Paste z innych prac domowych)
* Skopiujcie odpowiednie pliki, które pozwolą na użycie `gtesta`
* Dodajcie binarkę z testami do CMakeLists.txt. Nazwijcie ją `${PROJECT_NAME}-ut`
* Dodajcie odpalanie testów za pomocą `ctest`
* Zmodyfikujcie plik `.github/workflows/main.yml` aby GitHub dodatkowo uruchamiał jeszcze testy
