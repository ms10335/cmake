<!-- .slide: data-background="#111111" -->

# `cmake`

## Biblioteki

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Biblioteki

Moja definicja biblioteki - zlepek wielu plików cpp bez funkcji `main()`. Biblioteki nie można z tego powodu uruchomić.
<!-- .element: class="fragment fade-in" -->

### Analogia do programowania obiektowego
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Biblioteka = klasa (bazowa)
  * <!-- .element: class="fragment fade-in" --> pola, metody = pliki cpp
* <!-- .element: class="fragment fade-in" --> Binarka = klasa pochodna
  * <!-- .element: class="fragment fade-in" --> finalna, nie można po niej dziedziczyć
* <!-- .element: class="fragment fade-in" --> Linkowanie = dziedziczenie
  * <!-- .element: class="fragment fade-in" --> zlinkowanie binarki z biblioteką oznacza dorzucenie do niej kodu z biblioteki
  * <!-- .element: class="fragment fade-in" --> biblioteki można ze sobą wzajemnie linkować

___

## Linkowanie bibliotek

```cmake
target_link_libraries(<target> ... <item>... ...)
```
<!-- .element: class="fragment fade-in" -->

```cmake
add_library(lib STATIC functions.cpp modules.cpp)
add_executable(main main.cpp)
add_executable(ut tests.cpp)
target_link_libraries(main lib)
target_link_libraries(ut lib)
```
<!-- .element: class="fragment fade-in" -->

### Zadanie
<!-- .element: class="fragment fade-in" -->

Utwórz bibliotekę, która będzie zawierać powtarzające się pliki cpp i zlinkuj z nią targety, które ich używały.
<!-- .element: class="fragment fade-in" -->
