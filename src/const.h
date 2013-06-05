#ifndef CONST_H
#define CONST_H

/// suma parametrów, do których mają się normalizować parametry stworzenia
const int PARAMETERS_SUM = 200;

/// ile liści zjada roślinożerca za 1 razem
const int LEAFS_EATEN_AT_ONCE = 10;

/// czas (w ms) jaki odrasta 1 liść
const int TIME_TO_GROW_A_LEAF = 50;

/// maksymalna (i zarazem początkowa) liczba liści na drzewie
const int MAX_TREE_LEAFS_FOR_EXAMPLE_100 = 100;

/// na jaką odległość muszą zbliżyć się 2 osobniki, aby nawiązać interakcję (np. zjadać się, romnażać)
const double DISTANCE_TO_ASSUME_TARGET_ACHIEVED = 1;

/// szerokość mapy
const int DEFAULT_MAP_WIDTH = 100;

/// wysokość mapy
const int DEFAULT_MAP_HEIGHT = 100;

/// czas przez jaki zwierzę "pamięta" obiekt w swoim otoczeniu (w milisekundach)
const int REMEMBER_FOR = 3000;

/// czas stosunku, w ms
const int PROCREATION_TIME = 3000;

/// czas snu, w ms
const int SLEEP_TIME = 4000;

/// wspolczynnik szybkosci chodzenia, gdy zwierzę nie ma nic do roboty i błądzi bez celu (im więcej tym wolniej)
const int WALKING_FACTOR_WHILE_NOT_ACTIVE = 42000;

/// wspolczynnik szybkosci obrotu, gdy zwierzę nie ma nic do roboty i błądzi bez celu (im więcej tym wolniej)
const int ROTATING_FACTOR_WHILE_NOT_ACTIVE = 6000;

// parametry globalne dla predatorów (wyznaczone eksperymentalnie)

/// globalny współczynnik odporności na głód/pragnienie/zmęczenie dla drapieżników (im większy, tym wolniej będą robić się głodne, sprawgnione i zmęczone)
const int TIME_FACTOR_FOR_PREDATORS = 45000;

/// globalny współczynnik odporności na starzenie dla drapieżników (im większy, tym wolniej będą robić się starzeć)
const int AGE_TIME_FACTOR_FOR_PREDATORS = 15000;

/// globalny współczynnik skłonności do rozmnażania dla drapieżników (im większy, rzadziej będą się rozmnażać)
const int PROCREATING_TIME_FACTOR_FOR_PREDATORS = 35000;

// parametry globalne dla herbivore'ów (wyznaczone eksperymentalnie)

/// globalny współczynnik odporności na głód/pragnienie/zmęczenie dla roślinożerców (im większy, tym wolniej będą robić się głodne, sprawgnione i zmęczone)
const int TIME_FACTOR_FOR_HERBIVORES = 45000;

/// globalny współczynnik odporności na starzenie dla roślinożerców (im większy, tym wolniej będą robić się starzeć)
const int AGE_TIME_FACTOR_FOR_HERBIVORES = 15000;

/// globalny współczynnik skłonności do rozmnażania dla roślinożerców (im większy, rzadziej będą się rozmnażać)
const int PROCREATING_TIME_FACTOR_FOR_HERBIVORES = 12000; // lekka faworyzacja

/// maksymalna ilość dzieci z 1 "miotu" dla drapieżników
const int MAX_CHILDREN_FOR_PREDATORS = 1;

/// maksymalna ilość dzieci z 1 "miotu" dla roślinożerców (pozwala mocno wpływać na rozgrywkę)
const int MAX_CHILDREN_FOR_HERBIVORES = 2; // "lekka" faworyzacja

// inne

/// im więcej,tym stworzenia wolniej się poruszają
const int SPEED_FACTOR_FOR_MOVING = 1800;

/// im więcej,tym stworzenia wolniej się obracają
const int SPEED_FACTOR_FOR_ROTATING = 18000;

/// "dopalacz" dla uciekających roślinożerców (im więcej tym szybciej uciekają)
const double BOOST_FOR_RUNNING = 1.15;

/// zasięg "słyszenia" obiektów przez zwierzęta
const int HEAR_RADIUS = 12;

#endif // CONST_H
