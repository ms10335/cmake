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

W katalogu greeter znajdziesz malutki program. Zapoznaj się z jego kodem.

1. Skompiluj program z linii komend i uruchom go.

```bash
g++ -std=c++17 -Wall -Werror -Wextra -pedantic *.cpp - o greeter
./greeter
```

2. Napisz prosty Makefile dla tego programu. Zbuduj go za pomocą `make` i uruchom.
3. Napisz prosty CMakeLists.txt dla programu z katalogu `greeter`, zbuduj go za pomocą `cmake` i uruchom.

___

## Q&A

___

## CMake - zmienne

Zmienne tworzymy za pomocą komendy `set`

```cmake
set(VARIABLE value)
```

Np.

```cmake
set(NAME TheGreatestProject)
```

Odnosimy się do nich później obejmując w nawiasy `{}` i poprzedzając znakiem `$`

```cmake
add_executable(${NAME} main.cpp)
```

Spowoduje to utworzenie targetu `TheGreatestProject`, w ramach którego skompilowany zostanie plik `main.cpp`

___

## CMake - predefiniowane zmienne

CMake domyślnie dostarcza kilka zmiennych. Odwoływanie się do nich bezpośrednio lub ich modyfikacja zazwyczaj nie są uznawane za dobre praktyki.

Możemy za to bez większych problemów wykorzystać zmienną `${PROJECT_NAME}`. Zawiera ona nazwę projektu zdefiniowaną przez komendę `project()`

```cmake
project(vectorFunctions)
add_executable(${PROJECT_NAME} main.cpp vectorFunctions.cpp)
```

___

## Komendy cmake'a

[CMake manual](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html#id4)

* `add_executable(<name> [source1] [source2 ...])`

* `add_library(<name> [STATIC | SHARED | MODULE] [source1] [source2 ...])`

* `add_test(NAME <name> COMMAND <command> [<arg>...])`

```cmake
add_executable(${PROJECT_NAME} main.cpp vectorFunctions.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp vectorFunctions.cpp)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)
```

[Zobacz CMakeLists.txt dla zadania vectorOfSharedPointers](https://github.com/coders-school/kurs_cpp_podstawowy/blob/module3/module3/homework/vectorOfSharedPointers/CMakeLists.txt)

Powyższe komendy możesz potraktować jako "konstruktory". Tworzą one "targety".

___

## Q&A
