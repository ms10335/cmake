# Narzędzia #3

## `make` i `cmake`

___

CMake to generator systemów budowania. Domyślnie generuje on pliki Makefile do budowania za pomocą `make`.

___

## Makefile

Struktura pliku Makefile

```Makefile
VARIABLE = value

targetA: dependencyA1 dependencyA2
[TAB] command

targetB: dependencyB1
[TAB] command
```

___

## Makefile - przykłady

### Generowanie prezentacji w LaTeX

```Makefile
TEX = pdflatex -shell-escape -interaction=nonstopmode -file-line-error
MAKE = make
CODE_DIR = src

.PHONY: all view

all: calculator pdf

view:
	evince ContractProgramming.pdf

pdf: ContractProgramming.tex
	$(TEX) ContractProgramming.tex

calculator:
	$(MAKE) -C $(CODE_DIR)
```

___

### Kompilacja w C++

```Makefile
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

main: $(OBJECTS)
    g++ $^ -o $@

$(OBJECTS): src/%.o : src/%.cpp
    g++ -c $< -o $@
```

Źródło: [cpp-polska.pl][cpp-polska]

[cpp-polska]: https://cpp-polska.pl/post/potwor-przeszlosci-makefile-cz-2

### Zmienne w Makefile

* <!-- .element: class="fragment fade-in" --> <code>$@</code> - nazwa pliku targetu w aktualnie uruchomionej regule
* <!-- .element: class="fragment fade-in" --> <code>$<</code> - nazwa pierwszej zależności
* <!-- .element: class="fragment fade-in" --> <code>$^</code> - lista wszystkich zależności (zawiera ewentualne duplikaty)
* <!-- .element: class="fragment fade-in" --> <code>$?</code> - lista wszystkich zależności, które są nowsze niż target

___

## CMake

* automatyzuje proces budowania
* może składać się z wielu modułów, które się łączy (include)
* niezależny od platformy (jeśli jest dobrze napisany)
* konfiguracja budowania w pliku `CMakeLists.txt`

___

## Minimalny CMakeLists.txt

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
cmake --build   # budujemy projekt
```

___

## Zadanie

Napisz prosty CMakeLists.txt dla programu z katalogu `greeter`, zbuduj go za pomocą cmake'a i uruchom.

___

## Q&A
