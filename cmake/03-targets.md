<!-- .slide: data-background="#111111" -->

# `cmake`

## Targety

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Tworzenie aplikacji i bibliotek

[CMake manual](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html#id4)

Poniższe komendy możesz potraktować jako "konstruktory". Tworzą one "targety".

```cmake
add_executable(<name> [source1] [source2 ...])
```

```cmake
add_library(<name> [STATIC | SHARED | MODULE] [source1] [source2 ...])
```

```cmake
add_library(${PROJECT_NAME}-lib STATIC functions.cpp modules.cpp)
add_executable(${PROJECT_NAME} main.cpp functions.cpp modules.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp functions.cpp modules.cpp)
```
<!-- .element: class="fragment fade-in" -->

### Problem
<!-- .element: class="fragment fade-in" -->

Powielona lista plików w różnych "targetach"
<!-- .element: class="fragment fade-in" -->

___

### Problem #1

Powielona lista plików w różnych "targetach"

### Rozwiązanie
<!-- .element: class="fragment fade-in" -->

Wrzucenie listy plików do zmiennej
<!-- .element: class="fragment fade-in" -->

## Zadanie
<!-- .element: class="fragment fade-in" -->

Wrzuć listę plików do zmiennej i skorzystaj z niej
<!-- .element: class="fragment fade-in" -->

___

### Problem #2

Drobne różnice w plikach pomiędzy targetami
<!-- .element: class="fragment fade-in" -->

### Rozwiązanie
<!-- .element: class="fragment fade-in" -->

Utworzenie biblioteki
<!-- .element: class="fragment fade-in" -->
