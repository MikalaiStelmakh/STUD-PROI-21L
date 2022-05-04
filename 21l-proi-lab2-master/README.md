###### PROI, semestr 21L

## Laboratorium 2

##### Zadanie:

Napisać funkcję zwracającą wartość średnią dla wartości z tablicy dwuwymiarowej liczb całkowitych uwzględniając tylko liczby spełniające warunek: w reprezentacji dziesiętnej danej liczby:

- suma cyfr na pozycjach nieparzystych (na pozycjach: 1, 3, 5 …) jest równa sumie cyfr na pozycjach parzystych (na pozycjach: 2, 4, 6 …).

Pozycję cyfr liczymy od 1 od najmniej znaczącej cyfry. Zakładamy, że wszystkie liczby w tablicy mają wartości większe od zera. Napisać testy jednostkowe dla napisanej funkcji.

##### Rozwiązanie:

Funkcje `evenSum` i `oddSum` obliczają sumę cyfr odpowiednio na pozycjach parzystych i nieparzystych dla danej liczby. Funkcja `checkNumber` zwraca wartość `true`, jeśli sumy cyfr są równe, w przeciwnym przypadku zwraca `false`.  Funkcja `average` przechodzi przez całą tablicę, sprawdzając każdą liczbę za pomocą funkcji `checkNumber`. Wszystkie liczby spełniające podany warunek są dodawane i dzielone przez ich liczbę.

###### Użyte środowisko: Visual Studio 2019

###### Sposób testowania: UnitTest

###### Mikalai Stelmakh, 316951

