<!-- .slide: data-background="#111111" -->

# `cmake`

## Flagi kompilacji

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Flagi kompilacji

```cmake
target_compile_options(<target> [BEFORE]
                                <INTERFACE|PUBLIC|PRIVATE> [items1...]
                                [<INTERFACE|PUBLIC|PRIVATE> [items2...]
                                ...])
```
<!-- .element: class="fragment fade-in" -->

```cmake
add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
```
<!-- .element: class="fragment fade-in" -->

### Zadanie
<!-- .element: class="fragment fade-in" -->

Dodaj flagi kompilacji `-Wall -Wextra -Werror -pedantic -Wconversion -O3` do projektu greeter
<!-- .element: class="fragment fade-in" -->

___

## Włączanie standardu C++17

```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```
<!-- .element: class="fragment fade-in" -->

Powyższe może nie działać dla MSVC.
<!-- .element: class="fragment fade-in" -->

```cmake
set_target_properties(${PROJECT_NAME} PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON)
```
<!-- .element: class="fragment fade-in" -->

```cmake
add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
```
<!-- .element: class="fragment fade-in" -->

### Zadanie
<!-- .element: class="fragment fade-in" -->

Włącz standard C++17 w projekcie greeter
<!-- .element: class="fragment fade-in" -->
