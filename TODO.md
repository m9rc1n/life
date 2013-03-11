Wstępna propozycja szkicu dokumentacji funkcjonalnej

Fragmenty oznaczone kursywą to funkcjonalności których nie jestem pewien (czy damy radę, czy warto etc.)

Budowa programu

```cpp
Aplikacja będzie się składać z dwóch modułów, nazwanych roboczo Klient i Serwer.
Klient – program, którego zadaniem jest komunikacja z użytkownikiem. Na początku wyświetla okno z opcjami (zwane dalej ekranem startowym), w którym użytkownik może dobrać pewne parametry „rozgrywki”. Następnie uruchamia Serwer i przesyła mu zebrane dane, wtedy rozpoczyna się właściwa symulacja. Podczas symulacji Klient odbiera od Serwera informacje o obecnych wynikach symulacji i na bieżąco wyświetla graficzną planszę oraz wysyła Serwerowi informacje o kliknięciach użytkownika (w czasie symulacji użytkownik może przyspieszać, zwalniać lub wstrzymywać symulację). Do wyświetlania planszy klient używa biblioteki OpenGL. 
Serwer – program, którego zadaniem jest obliczać kolejne kroki symulacji z zadaną częstotliwością i wysyłać wyniki obliczeń do klienta. Serwer może także przyspieszać, zwalniać lub wstrzymywać symulację na żądanie użytkownika (przekazywane za pośrednictwem klienta).
Klient i serwer komunikują się za pomocą współdzielonej pamięci, która jest zrealizowana przy pomocy biblioteki Boost::Interprocess. 
```

„Świat gry”
Symulacja rozgrywa się na prostokątnej planszy, której wymiary ustala użytkownik na ekranie startowym. Początkowo obiekty zostają umieszczone w sposób losowy, ale z ograniczeniami opisanymi niżej. Rodzaje obiektów:
osobnik (roślinożerca lub drapieżnik), posiada zestaw indywidualnych cech; stanowi punkt (nie ma wymiarów), może się poruszać
drzewo – źródło pożywienia dla roślinożerców; stanowi punkt (nie ma wymiarów) 
wodopój – źródło wody dla osobników; stanowi punkt (nie ma wymiarów) 
jaskinia – miejsce, w którym osobniki mogą spać; stanowi punkt (nie ma wymiarów) 
skały – obszar na planszy, po którym osobniki nie mogą chodzić, stanowi koło o promieniu 5 jednostek; takie koła mogą się częściowo nakładać, tworząc większe struktury
Cechy (parametry) osobników
Każdy osobnik posiada zestaw indywidualnych cech, ustalanych w momencie narodzin (liczby całkowite):
Zasięg widzenia (ozn. R), R ∈ [5, 100]
Szybkość biegu (V), V ∈ [5, 100]
Odporność na głód (F), F ∈ [5, 100]
Odporność na pragnienie (W), W ∈ [5, 100]
Wytrzymałość [odporność na zmęczenie] (S), S ∈ [5, 100]
Wydajność reprodukcyjna (P), P ∈ [5, 100]
Maksymalny czas życia (L), L ∈ [5, 100]
Płeć (X), X ∈ {„F”, „M”}
Indywidualne cechy osobnika (z wyjątkiem płci) mają tę własność, że „więcej = lepiej”. Spełniają one warunek: R+V+F+W+S+P = 200
A także parametry chwilowe (liczby rzeczywiste, zmieniające się w sposób pseudo-ciągły):
Poziom najedzenia (ozn. f), f ∈ [0, F], maleje w stałym tempie
Jeśli poziom najedzenia spadnie poniżej połowy (f ∈ [0, ½F]), to osobnik znajduje się w stanie „głodny”
Jeśli głodny osobnik dotrze do drzewa (roślinożerca) lub złapie roślinożercę (drapieżnik) jego poziom napojenia natychmiast rośnie do poziomu F. Roślinożerca zjedzony przez drapieżnika znika z gry.
Jeśli poziom najedzenia spadnie do zera, osobnik umiera z głodu
Poziom napojenia (w) w ∈  [0, W], maleje w stałym tempie
Jeśli poziom napojenia spadnie poniżej połowy (w ∈ [0, ½w]), to osobnik znajduje się w stanie „spragniony”.
Jeśli spragniony osobnik dotrze do wodopoju, jego poziom napojenia natychmiast rośnie do poziomu W
Jeśli poziom napojenia spadnie do zera, osobnik umiera z pragnienia
Poziom energii (wypoczęcia) (s) s ∈ [0, S], maleje w zmiennym tempie
Jeśli poziom energii spadnie poniżej połowy (s ∈ [0, ½S]), to osobnik znajduje się w stanie „zmęczony”. 
Jeśli głodny osobnik dotrze do kryjówki, jego poziom napojenia energii rośnie do poziomu S, ale jednocześnie zapada on w sen trwający stały czas TS. W czasie snu osobnik nie porusza się, jest niewidoczny dla innych osobników, ale może zostać zjedzony przez drapieżnika, który akurat wejdzie do tej samej kryjówki.
Jeśli poziom energii spadnie do zera, osobnik umiera z wycieńczenia
Poziom energii maleje dwa razy szybciej podczas biegu.
Czas do reprodukcji (p), p ∈ [0, 1], maleje w stałym tempie (zależnym od wartości P)
Jeśli p = 0, to osobnik może się rozmnażać; po akcie „kopulacji” wartość p jest ustawiana na 1. Wartość ta maleje w tempie P/1000 na sekundę (czyli osobnik o najwyższej możliwej zdolności reprodukcyjnej P=100 będzie „pauzować” 10 sekund, a o najniższej możliwej P=5, będzie „pauzować” 200 sekund).
Wiek (l), l ∈ [0, L],  rośnie w stałym tempie
Przy narodzinach jest ustawiane l = 0, po osiągnięciu l = L osobnik umiera ze starości
Zachowanie osobników
Każdy osobnik porusza się po planszy w sposób losowy, dopóki w jego polu widzenia (okrąg o promieniu R) nie znajdzie się jakiś interesujący go obiekt:
Jeśli w polu widzenia osobnika znajduje się jaskinia i osobnik jest zmęczony, to idzie w stronę wodopoju – priorytet 1.
Jeśli w polu widzenia osobnika znajduje się drzewo, osobnik jest głodny i jest roślinożercą, to osobnik idzie w stronę drzewa – priorytet 2.
Jeśli w polu widzenia osobnika znajduje się wodopój i osobnik jest spragniony, to osobnik idzie w stronę wodopoju – priorytet 3.
Jeśli w polu widzenia osobnika znajduje się drugi osobnik tego samego gatunku i przeciwnej płci oraz oba te osobniki mają p=0 (są gotowe do reprodukcji) oraz żaden z nich nie jest głodny, spragniony, ani zmęczony, to osobniki idą w swoim kierunku – priorytet 4.
Jeśli w polu widzenia osobnika znajduje się roślinożerca, osobnik jest głodny i jest drapieżnikiem, to osobnik biegnie w stronę roślinożercy (poluje) – priorytet 5.
Jeśli w polu widzenia osobnika znajduje się drapieżnik i osobnik jest roślinożercą, to osobnik biegnie w stronę przeciwną (ucieka), niezależnie od tego, czy drapieżnik jest głodny – priorytet 5.
Jakieś zachowania społeczne – osobniki mogą trzymać się innych osobników swojego gatunku, wspólnie polować etc. – tylko nie mam pojęcia, jak to realizować. 
Jeśli w zasięgu wzroku osobnika znajduje się kilka interesujących obiektów, to wybiera akcję o najwyższym priorytecie (najpierw polowanie / ucieczka itd.).
Rozmnażanie
Jeśli dwa osobniki tego samego gatunku i różnych płci spotkają się, następuje akt prokreacji – pojawia się nowy osobnik, którego cechy (R, V, F, W, S, P, L) wynikają z odpowiednich cech rodziców:
RDZIECKA = random(ROJCA, RMATKI) + random(-10, 10) (analogicznie dla pozostałych cech)
gdzie random(a,b) jest funkcją zwracającą losową wartość z zakresu [min(a,b);max(a,b)]. Cechy są skalowane w taki sposób, aby spełniały warunki: R+V+F+W+S+P+L=200; R, V, F, W, S, P, L ∈ [5, 100].
Możliwości modyfikacji scenariusza
Na ekranie startowym użytkownik może ustalić pewne parametry symulacji, takie jak: wielkość planszy, gęstość rozmieszczenia drzew, wodopojów, skał, ilość drapieżników i roślinożerców etc., a także wpłynąć na określone cechy całej populacji (np. dodać wszystkim roślinożercom +30 do szybkości). Do programu będzie też dołączonych kilka (wybranych przez twórców gry) ciekawych scenariuszy. 
Wizualizacja
Osobniki i inne obiekty będą reprezentowane przez proste figury geometryczne, po najechaniu myszką na obiekt wyświetli się więcej informacji o nim.
