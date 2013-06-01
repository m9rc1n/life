#ifndef AWARENESSDETECTOR_HPP
#define AWARENESSDETECTOR_HPP

/**
 * @brief
 * Klasa grupująca różne funkcje, których zadaniem jest sprawdzanie, czy stworzenia są świadome obiektów
 * w swoim otoczeniu.
 *
 * Stworzenie może być uświadomione o istnieniu obiektu w swoim otoczeniu na 2 sposoby:
 *
 * + Może go zobaczyć - stanie się to wtedy, gdy obiekt znajdzie się w zasięgu widzenia zwierzęcia.
 *   Pole widzenia zwierzęcia jest wycinkiem okręgu. Promień okręgu stanowi zasięg widzenia zwierzęcia,
 *   zaś szerokość kątowa wycinka to kąt widzenia zwierzęcia. Oba te parametry są indywidualnymi cechami
 *   każdego stworzenia.
 *
 * + Może go usłyszeć - gdy drugie zwierzę znajdzie się w odległości mniejszej niż 5 jednostek. Kierunek
 *   jest w tym wypadku nieistotny.
 *
 * Stworzenie może podejmować akcje związane z innym obiektem (iść do niego, uciekać przed nim) tylko
 * wtedy, gdy jest go świadome. Jeśli stworzenie staci obiekt z pola widzenia i słyszenia, to przez pewien
 * czas wciąż "pamięta" o jego istnieniu (dlatego np. uciekający roślinożerca kontynuuje ucieczkę jescze
 * chwilę po tym, jak zgubi drapieżnika).
 */

class AwarenessDetector
{
public:
    AwarenessDetector();
};

#endif // AWARENESSDETECTOR_HPP
