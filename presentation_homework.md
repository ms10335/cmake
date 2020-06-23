<!-- .slide: data-background="#111111" -->

# Narzędzia #3

## Podsumowanie

<a href="https://coders.school">
    <img width="500" data-src="coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Co pamiętasz z dzisiaj?

### Napisz na czacie jak najwięcej haseł
<!-- .element: class="fragment fade-in" -->

___

### Pre-work

* Dowiedzcie się czym jest problem diamentowy
* Poczytajcie o zasadach SOLID, dotyczących pisania dobrego kodu obiektowego
* Lektura o wzorcach projektowych z przykładami w C++ - [refactoring.guru](https://refactoring.guru/design-patterns)

___

### Post-work

Dorzućcie do projektu SHM system budowania `cmake` (20 punktów, 2 za każdy podpunkt)

Dostarczenie przed niedzielą 05.07.2020 23:59 (+2 punkty)

* Użyj zmiennej `${PROJECT_NAME}`
* Lista plików cpp w zmiennej
* Wszystko poza plikiem `main.cpp` powinno kompilować się do biblioteki statycznej
* Binarka (main.cpp) powinna linkować się z powyższą biblioteką.
* Utwórz proste testy do projektu SHM (co najmniej 1 test metodą Copy&Paste z innych prac domowych)
* Poczytaj pliki CMakeLists.txt i wywnioskuj z nich w jaki sposób dodawana jest biblioteka `gtest` do testów
* Skopiuj odpowiednie pliki, które pozwolą Ci na użycie `gtesta`
* Dodaj binarkę z testami co CMakeLists.txt
* Dodaj odpalanie testów za pomocą `ctest`
* Napisz odpowiedni plik `.github/workflows/main.yml` który spowoduje, że GitHub będzie automatycznie uruchamiał kompilację i testy dla każdego nowego commita.
