<!-- .slide: data-background="#111111" -->

# `cmake`

## Zmienne

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Zmienne

Zmienne tworzymy za pomocą komendy `set`
<!-- .element: class="fragment fade-in" -->

```cmake
set(VARIABLE value)  # Konwencja - UPPERCASE_WITH_UNDERSCORE
```
<!-- .element: class="fragment fade-in" -->

Przykładowo
<!-- .element: class="fragment fade-in" -->

```cmake
set(NAME TheGreatestProject)
```
<!-- .element: class="fragment fade-in" -->

Odnosimy się do nich później obejmując w nawiasy `{}` i poprzedzając znakiem `$`
<!-- .element: class="fragment fade-in" -->

```cmake
add_executable(${NAME} main.cpp)
```
<!-- .element: class="fragment fade-in" -->

Spowoduje to utworzenie targetu `TheGreatestProject`, w ramach którego skompilowany zostanie plik `main.cpp`
<!-- .element: class="fragment fade-in" -->

___

## Predefiniowane zmienne

CMake domyślnie dostarcza kilka zmiennych. Odwoływanie się do nich bezpośrednio lub ich modyfikacja zazwyczaj nie są uznawane za dobre praktyki.
<!-- .element: class="fragment fade-in" -->

Możemy za to bez większych problemów wykorzystać zmienną `${PROJECT_NAME}`. Zawiera ona nazwę projektu zdefiniowaną przez komendę `project()`
<!-- .element: class="fragment fade-in" -->

```cmake
project(vectorFunctions)
add_executable(${PROJECT_NAME} main.cpp vectorFunctions.cpp)
```
<!-- .element: class="fragment fade-in" -->
