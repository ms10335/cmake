<!-- .slide: data-background="#111111" -->

# `make`

<a href="https://coders.school">
    <img width="500" data-src="coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Pliki Makefile

### Struktura pliku Makefile

```Makefile
VARIABLE = value

targetA: dependencyA1 dependencyA2
[TAB] command $(VARIABLE)

targetB: dependencyB1
[TAB] command
```

___

## Przykład - generowanie prezentacji w LaTeX

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

## Kompilacja w C++

### Pamiętacie fazy kompilacji?

```Makefile
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

main: $(OBJECTS)
	g++ $^ -o $@

$(OBJECTS): src/%.o : src/%.cpp
	g++ -c $< -o $@
```

### Zmienne pamiętające kontekst

* <!-- .element: class="fragment fade-in" --> <code>$@</code> - nazwa pliku targetu w aktualnie uruchomionej regule
* <!-- .element: class="fragment fade-in" --> <code>$<</code> - nazwa pierwszej zależności
* <!-- .element: class="fragment fade-in" --> <code>$^</code> - lista wszystkich zależności (zawiera ewentualne duplikaty)
* <!-- .element: class="fragment fade-in" --> <code>$?</code> - lista wszystkich zależności, które są nowsze niż target

___

## Zadanie

W katalogu greeter znajdziesz malutki program. Zapoznaj się z jego kodem.

* Skompiluj program z linii komend i uruchom go.
* Napisz prosty Makefile dla tego programu. Zbuduj go za pomocą `make` i uruchom.

### Zaklęcie kompilacji

```bash
g++ -std=c++17 -Wall -Werror -Wextra -pedantic *.cpp - o greeter
./greeter
```

___

## Polecenie `make`

* domyślnie szuka w bieżącym katalogu pliku `Makefile`
* automatyzuje czynności poprzez wykonywanie receptur zapisanych w plikach `Makefile`
* domyślnie wykonuje pierwszą recepturę
* pozwala na warunkowe wykonywanie czynności
* pozwala definiować wiele zależności
* domyślnie uwzględnia daty modyfikacji zależności i na tej podstawie podejmuje decyzję, czy wykonać daną recepturę

___

## Q&A

### Linki

[cpp-polska.pl](https://cpp-polska.pl/post/potwor-przeszlosci-makefile-cz-2)
