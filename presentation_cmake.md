<!-- .slide: data-background="#111111" -->

# `cmake`

<a href="https://coders.school">
    <img width="500" data-src="coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## CMake

* automatyzuje proces budowania dla C/C++
* obsługuje generowanie projektów dla wielu IDE
* może składać się z wielu modułów, które się łączy (odpowiednik #include)
* niezależny od platformy (jeśli jest dobrze napisany)
* konfiguracja budowania w pliku `CMakeLists.txt`
* generuje system budowania (np. pliki `Makefile`)

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
cmake --build   # budujemy projekt
```

`cmake --build` można zamienić na `make` jeśli wiemy, że na pewno generujemy Makefile.

`cmake --build` jest uniwersalne.

___

## Zadanie

Napisz prosty CMakeLists.txt dla programu z katalogu `greeter`, zbuduj go za pomocą `cmake` i uruchom.

___

## Q&A

___

## CMake - zmienne

Zmienne tworzymy za pomocą komendy `set`

```cmake
set(VARIABLE value)
```

Przykładowo

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

## Tworzenie aplikacji i bibliotek

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

Powielona lista plików w różnych "targetach"

___

### Problem

Powielona lista plików w różnych "targetach"

### Rozwiązanie

Wrzucenie listy plików do zmiennej

### Zadanie

Wrzuć listę plików do zmiennej i skorzystaj z niej

___

### Problem

Drobne różnice w plikach pomiędzy targetami

### Rozwiązanie

Utworzenie biblioteki

___

## Linkowanie bibliotek

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

## Flagi kompilacji

```cmake
target_compile_options(<target> [BEFORE]
                                <INTERFACE|PUBLIC|PRIVATE> [items1...]
                                [<INTERFACE|PUBLIC|PRIVATE> [items2...]
                                ...])
```

```cmake
add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
```

### Zadanie

Dodaj flagi kompilacji `-Wall -Wextra -Werror -pedantic -Wconversion -O3` do projektu greeter

___

## Włączanie standardu C++17

```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

Powyższe może nie działać dla MSVC.

```cmake
set_target_properties(${PROJECT_NAME} PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON)
```

```cmake
add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
```

### Zadanie

Włącz standard C++17 w projekcie greeter

___

## Dodawanie testów do `ctest`

`enable_testing()`

`add_test(NAME <name> COMMAND <command> [<arg>...])`

```cmake
enable_testing()
add_test(NAME someTests COMMAND ${PROJECT_NAME}-ut)
```

### Zadanie

Dodaj binarkę z testami, która powinna być odpalana za pomocą `ctest`

___

## Budowanie w trybie debug

Domyślnie budowany jest tryb "Release" (bez symboli debugowania)

```cmake
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

Jeśli chcemy wspierać budowanie w trybach Debug i Release powinniśmy mieć do nich oddzielne katalogi z rezultatami budowania

```bash
mkdir buildDebug
cd buildDebug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build
```

___

## Linki dla poszerzenia wiedzy

* [CMake - from zero to something - prezentacja z Wro.cpp](https://muttleyxd.github.io)
* [19 reasons why CMake is actually awesome](https://kubasejdak.com/19-reasons-why-cmake-is-actually-awesome)
* [Modern CMake is like inheritance](https://kubasejdak.com/modern-cmake-is-like-inheritance)
* [CMake basics](https://www.siliceum.com/en/blog/post/cmake_01_cmake-basics)

___

## Q&A
