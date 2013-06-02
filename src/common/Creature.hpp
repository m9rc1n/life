#ifndef COMMON_CREATURE_H
#define COMMON_CREATURE_H

#include "MapObject.hpp"
#include <cmath>
#include <vector>
#include <QMap>

namespace common
{

    /**
    * @brief
    * Abstrakcyjna klasa reprezentująca stworzenie
    */
    class Creature: public MapObject
    {
    public:
        /**
        * @brief
        * Konstruktor wywoływany w momencie narodzin stworzenia. Parametry stworzenia są
        * ustalane na podstawie odpowiednich parametrów ojca i matki.
        *
        * Ten konstruktor zakłada, że matka i ojciec znajdują się w tym samym miejscu.
        * Nowe stworzenie również pojawi się w tym samym miejscu.
        *
        * @param mother referencja do matki
        * @param father referencja do ojca
        */
        Creature(const Creature &mother, const Creature &father):
            MapObject(mother),
            radius_(0),
            angle_(0),
            speed_(0),
            fecundity_(0),
            max_repletion_(0),
            max_hydration_(0),
            max_energy_(0),
            max_age_(0),
            knownObjects(new QMap<int, double >)
        {
            /// @todo write me
        }

        /**
        * @brief
        * Konstruktor wywoływany w przypadku, gdy stworzenie jest generowane na początku gry.
        * Wspolrzedne stworzenia są podawane jako parametry konstruktora.
        *
        * Stworzenie pojawi się w wybranym miejscu na planszy (powinno ono byc wolne).
        */
        Creature(double x_pos, double y_pos):
            MapObject(x_pos, y_pos),
            radius_(0),
            angle_(0),
            speed_(0),
            fecundity_(0),
            max_repletion_(0),
            max_hydration_(0),
            max_energy_(0),
            max_age_(0),
            knownObjects(new QMap<int, double>)
        {
            /// @todo write me
        }

        /**
        * @brief
        * Konstruktor kopiujący
        */
        Creature(const Creature &another):
            MapObject(another),
            radius_(another.radius_),
            angle_(another.angle_),
            speed_(another.speed_),
            fecundity_(another.fecundity_),
            max_repletion_(another.max_repletion_),
            max_hydration_(another.max_hydration_),
            max_energy_(another.max_energy_),
            max_age_(another.max_age_),
            knownObjects(new QMap<int, double >(*another.knownObjects))
        {
            /// @todo write me
        }

        /**
         * @brief
         * Tworzy głęboką kopię obiektu
         *
         * @returns wskaznik do nowego obiektu (utworzonego przez new)
         *
         * @todo moze zmienic na sprytny wskaznik?
         */
        virtual MapObject *clone() = 0;

        virtual ~Creature(){}

        /**
        * @brief
        * Funkcja podaje informację czy stworzenie jest martwe.
        *
        * Dzieje się tak, gdy najedzenie, napojenie lub energia spadnie do zera
        * lub gdy stworzenie osiągnie swój maksymalny wiek.
        *
        * Po stwierdzeniu, że stworzenie jest martwe, funkcja wołająca powinna zniszczyć
        * obiekt klasy Creature.
        *
        * @returns true wtedy i tylko wtedy gdy osobnik jest martwy.
        */
        bool isDead() const
        {
            return is_dead_;
        }

        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &) = 0;

        /**
         * @brief
         * Serializacja
         *
         * Serializuje skladowe obiektu oraz klase bazowa.
         *
         * @see Map::serialize
         */
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & boost::serialization::base_object<MapObject>(*this);
    //         ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(MapObject);
            ar & radius_;
            ar & angle_;
            ar & speed_;
            ar & fecundity_;
            ar & max_repletion_;
            ar & max_hydration_;
            ar & max_energy_;
            ar & max_age_;
            ar & repletion_;
            ar & hydration_;
            ar & energy_;
            ar & age_;
        }

        struct WrongRotationException: public std::exception{};

        /**
         * @brief
         * Obraca zwierzę o zadany kąt wokół własnej osi.
         *
         * @param degrees Zadany kąt w stopniach. Jeśli degrees > 0, to obrót w prawo; gdy degrees < 0 - obrót w lewo.
         * @pre -360 > #degrees > 360
         * @throws WrongRotationException
         * @see direction_
         */
        void rotateByAngleInDegrees(double degrees)
        {
            if(degrees <= -360 or degrees >= 360)
            {
                throw new WrongRotationException();
            }
            direction_ += degrees;
            // pilnujemy niezmiennika
            direction_ += 360.0;
            // fmod - odpowiednik operatora % dla floatów
            direction_ = fmod(direction_, 360.0);
        }

        /**
         * @brief
         * Obraca zwierzę o zadany kąt wokół własnej osi.
         *
         * @param degrees Zadany kąt w radianach. Jeśli radians > 0, to obrót w prawo; gdy radians < 0 - obrót w lewo.
         * @pre -2pi > #degrees > 2pi
         * @throws WrongRotationException
         * @see direction_
         */
        void rotateByAngleInRadians(double radians)
        {
            rotateByAngleInDegrees(radians * 180.0 / M_PI);
        }

        /**
         * @brief
         * Zwraca kierunek patrzenia zwierzęcia w stopniach.
         *
         * @see direction_
         */
        double getDirectionInDegrees()
        {
            return direction_;
        }

        /**
         * @brief
         * Zwraca kierunek patrzenia zwierzęcia w radianach.
         *
         * @see direction_
         */
        double getDirectionInRadians()
        {
            return direction_ * M_PI / 180.0;
        }

        /**
         * @brief
         * Przesuwa zwierzę o zadany dystans w kierunku w którym zwierzę patrzy.
         *
         * @see direction_
         */
        void moveByDistance(double distance)
        {
            moveByVector(sin(getDirectionInRadians()) * distance,
                         cos(getDirectionInRadians()) * distance);
        }

        /**
         * @brief
         * Zwraca kierunek, w którym należałoby obrócić zwierzę, aby patrzyło ono dokładnie na zadany obiekt.
         *
         * @param object obiekt, do którego kierunek wyznaczamy.
         * @return wynik w stopniach
         */
        double getDirectionOfObjectInDegrees(const MapObject &object)
        {
            double x_distance = object.getX() - this->getX();
            double y_distance = object.getY() - this->getY();

            double distance = sqrt(x_distance*x_distance + y_distance*y_distance);

            double x_factor = x_distance / distance; // zmienna sponsorowana przez tvn
            double y_factor = y_distance / distance;

            double arcsin = asin(x_factor) * 180.0 / M_PI; // arcus sinus

            if(y_factor < 0)
            {
                arcsin = 180 - arcsin; // 3. i 4. ćwiartka układu współrzędnych
            }

            return fmod(arcsin + 360, 360);
        }

        /**
         * @brief
         * Obraca zwierzę w taki sposób, aby patrzyło na zadany obiekt.
         *
         * @param object Obiekt na który ma patrzeć zwierzę.
         */
        void turnToObject(const MapObject &object)
        {
            direction_ = getDirectionOfObjectInDegrees(object);
        }

        /**
         * @brief
         * Obraca zwierzę w kierunku zadanego obiektu, ale nie bardziej niz o zadany kąt.
         *
         * @param object Obiekt w kierunku którego ma się obracać zwierzę.
         * @param degrees O ile stopni ma się maksymalnie obrócić zwierzę.
         *
         * @returns false, jeśli zwierzę obróciło się dokładnie o #degrees stopni;
         *          true,  jeśli zwierzę obróciło się o mniej niż #degrees stopni (co oznacza, że teraz zwierzę patrzy na ten obiekt)
         *
         * @todo test me
         */
        bool partiallyTurnToObject(const MapObject &object, double degrees)
        {
            double destined_direction = getDirectionOfObjectInDegrees(object);

            double angle_difference = destined_direction - direction_;
            angle_difference = std::min(angle_difference, 360 + angle_difference);

            double angle_difference_abs = abs(angle_difference);

            if(angle_difference_abs <= degrees)
            {
                direction_ = destined_direction;
                return true;
            }
            else if(angle_difference < 0)
            {
                direction_-= destined_direction;
                return false;
            }
            else //(angle_difference > 0)
            {
                direction_+= destined_direction;
                return false;
            }
        }

        /**
         * @brief Tylko na potrzeby testów
         *
         * @todo remove me
         */
        void moveInSomeRandomDirection()
        {
            x_pos_++;
            y_pos_++;
        }

        /**
         * @return zasięg widzenia zwierzęcia
         */
        int getRadius() const
        {
            return radius_;
        }
        /**
         * @return  kąt widzenia zwierzęcia
         */
        int getAngle() const
        {
            return angle_;
        }

        /**
         * @brief Sprawdza, czy zwierzę jest zmęczone
         * @return 1 wtedy i tylko wtedy, gdy wartość energii zwierzęcia jest niższa od połowy wartości maksymalnej
         */
        bool isTired() const
        {
            return energy_ < 0.5 * max_energy_;
        }

        /**
         * @brief Sprawdza, czy zwierzę jest głodne
         * @return 1 wtedy i tylko wtedy, gdy wartość najedzenia zwierzęcia jest niższa od połowy wartości maksymalnej
         */
        bool isHungry() const
        {
            return repletion_ < 0.5 * max_repletion_;
        }

        /**
         * @brief Sprawdza, czy zwierzę jest spragnione
         * @return 1 wtedy i tylko wtedy, gdy wartość napojenia zwierzęcia jest niższa od połowy wartości maksymalnej
         */
        bool isThirsty() const
        {
            return hydration_ < 0.5 * max_hydration_;
        }

        /**
         * @brief Sprawdza, czy stworzenie zna dany obiekt (tj. czy widziało/słyszało go w ostatnim czasie
         * @return 1 wtedy i tylko wtedy, gdy obiekt znajduje się na liście znanych obiektów
         */
        bool isObjectKnown(const MapObject &object) const
        {
            return knownObjects->find(object.getIdentifier()) != knownObjects->end();
        }

        /**
         * @brief
         * Dodaje obiekt do listy znanych obiektów (jeśli go tam nie ma) lub oznacza dotyczący go wpis jako aktualny
         */
        void setObjectKnown(const MapObject &object)
        {
            QMap<int, double>::iterator iter = knownObjects->find(object.getIdentifier());
            // i did not use isObjectKnown because of performance reasons... but it's the same
            if(iter != knownObjects->end())
            {
                *iter = 0; // ostatnio widziany: wlasnie teraz
            }
            else
            {
                knownObjects->insert(object.getIdentifier(), .0); // dodajemy
            }
        }

        /**
         * @brief
         * Aktualizuje listę znanych obiektów
         *
         * Zwiększa czas w elementach o zadaną wartość i usuwa te elementy, dla których czas przekroczy pewną wartość.
         *
         * @param Czas kroku symulacji (wartość o jaką będą zwiększone wartości w liście)
         */
        void updateListOfKnownObjects(double time)
        {
            for(QMap<int, double >::iterator iter = knownObjects->begin(); iter != knownObjects->end();)
            {
                *iter += time;
                std::cout << *iter << std::endl;
                if(*iter > 3000) // 3000 ms
                {
                    knownObjects->erase(iter++);
                }
                else
                {
                    ++iter;
                }
            }
        }


    /// @todo zaprzyjaznic z wizytatorami? protected:

    public:

        /// Zasięg widzenia
        const int radius_;

        /// Kąt widzenia
        const int angle_;

        /// Prędkość poruszania się
        const int speed_;

        /// Płodność
        const int fecundity_;

        /// Maksymalny poziom najedzenia (inaczej: odporność na głód)
        const int max_repletion_;

        /// Maksymalny poziom napojenia (inaczej: odporność na pragnienie)
        const int max_hydration_;

        /// Maksymalny poziom energii (inaczej: odporność na zmęczenie)
        const int max_energy_;

        /// Maksymalna długość życia
        const int max_age_;

        /**
         * @brief
         * Kierunek, w którym obrócone jest zwierzę, wyrażony w stopniach.
         *
         * Kąt liczony jest zgodnie z kierunkiem ruchu wskazówek zegara.
         * 0 oznacza, że zwierzę jest skierowane (patrzy) w kierunku północnym (w górę ekranu).
         * 90 - w kierunku wschodnim (w prawo)
         * 180 - w kierunku południowym (w dół)
         * 270 - w kierunku zachodnim (w lewo)
         *
         * Wartość tego pola powinna zawsze zawierać się w zakresie <0; 360)
         */
        double direction_;

        /// Obecny poziom najedzenia
        double repletion_;

        /// Obecny poziom napojenia
        double hydration_;

        /// Obecny poziom energii
        double energy_;

        /// Obecny wiek
        double age_;

        /// Czy zwierzę jest martwe?
        bool is_dead_;  

        /// Czy zwierzę robi teraz coś konkretnego (true) czy błąka się bez celu (false)?
        bool is_active_;

        /// Zbiór innych obiektów, o których isteniu zwierzę wie w danej chwili
        QMap<int, double > *knownObjects;

    };
}

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Creature)

#endif
