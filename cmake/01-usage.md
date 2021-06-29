<!-- .slide: data-background="#111111" -->

# `cmake`

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## CMake

* <!-- .element: class="fragment fade-in" --> automatyzuje proces budowania dla C/C++
* <!-- .element: class="fragment fade-in" --> obsługuje generowanie projektów dla wielu IDE
* <!-- .element: class="fragment fade-in" --> może składać się z wielu modułów, które się łączy (odpowiednik #include)
* <!-- .element: class="fragment fade-in" --> niezależny od platformy (jeśli jest dobrze napisany)
* <!-- .element: class="fragment fade-in" --> konfiguracja budowania w pliku CMakeLists.txt
* <!-- .element: class="fragment fade-in" --> generuje system budowania (np. pliki Makefile, solution dla VS)

___

## Minimalny `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.10)
project(ProjectName)

add_executable(execName main.cpp file.cpp)
```

___

## Budowanie za pomocą CMake'a

```bash
mkdir build     # tworzymy katalog z wynikami budowania
cd build        # wchodzimy do tego katalogu
cmake ..        # generujemy system budowania podając ścieżkę do pliku CMakeLists.txt
cmake --build . # budujemy projekt
```

`cmake --build .` można zamienić na `make` jeśli wiemy, że na pewno generujemy Makefile.
<!-- .element: class="fragment fade-in" -->

`cmake --build .` jest bardziej uniwersalne.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Napisz prosty CMakeLists.txt dla programu z katalogu `greeter`, zbuduj go za pomocą `cmake` i uruchom.

Zauważ, że są tutaj też testy. Dopisz dodatkowy target dla testów.
