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

## Komendy cmake'a - tworzenie binarek i bibliotek

[CMake manual](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html#id4)

Poniższe komendy możesz potraktować jako "konstruktory". Tworzą one "targety".

* `add_executable(<name> [source1] [source2 ...])`
* `add_library(<name> [STATIC | SHARED | MODULE] [source1] [source2 ...])`

```cmake
add_library(${PROJECT_NAME}-lib STATIC functions.cpp modules.cpp)
add_executable(${PROJECT_NAME} main.cpp functions.cpp modules.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp functions.cpp modules.cpp)
```

### Problem

Powielona lista plików

### Rozwiązanie

* Wrzucenie plików do zmiennej

### Zadanie

Wrzuć listę plików do zmiennej i skorzystaj z niej

___

### Problem

Drobne różnice w plikach pomiędzy targetami

### Rozwiązanie

* Utworzenie biblioteki

___

## Komendy cmake'a - linkowanie

* `target_link_libraries(<target> ... <item>... ...)`

```cmake
add_library(${PROJECT_NAME}-lib STATIC functions.cpp modules.cpp)
add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
```

### Zadanie

* Utwórz bibliotekę, która będzie zawierać powtarzające się pliki cpp i zlinkuj z nią targety, które ich używały

___

## Komendy cmake'a - flagi kompilacji

`target_compile_options(<target> [BEFORE] <INTERFACE|PUBLIC|PRIVATE> [items1...] [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])`

```cmake
add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -Werror -pedantic)
```

### Zadanie

Dodaj flagi kompilacji `-Wall -Wextra -Werror -pedantic -Wconversion` do projektu greeter

___

## Włączanie standardu C++17

```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

Powyższe może nie działać dla MSVC.

```cmake
add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
```

### Zadanie

Włącz standard C++17 w projekcie greeter

___

## Dodawanie testów do CTest

`add_test(NAME <name> COMMAND <command> [<arg>...])`

```cmake
enable_testing()
add_test(NAME someTests COMMAND ${PROJECT_NAME}-ut)
```

### Zadanie

Dodaj binarkę z testami, która powinna być odpalana za pomocą `ctest`

___

## CMake - from zero to something

Dla poszerzenia wiedzy fajna prezentacja z Wro.cpp

[https://muttleyxd.github.io](https://muttleyxd.github.io)

___

## Q&A
