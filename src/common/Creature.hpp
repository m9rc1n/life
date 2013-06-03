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
            repletion_(4),
            hydration_(4),
            energy_(4),
            age_(0),
            is_dead_(0),
            is_active_(1),
            max_repletion_(10),
            max_hydration_(10),
            max_energy_(10),
            max_age_(10),
            knownObjects(new QMap<int, double >),
            action_time(0),
            is_sleeping_(0),
            time_sleeping_(0),
            is_procreating_(0),
            time_procreating_(0),
            time_to_procreate_(100)
        {
        }

        /**
        * @brief
        * Konstruktor wywoływany w przypadku, gdy stworzenie jest generowane na początku gry.
        * Wspolrzedne stworzenia są podawane jako parametry konstruktora.
        *
        * Stworzenie pojawi się w wybranym miejscu na planszy (powinno ono byc wolne).
        */
        Creature(double x_pos, double y_pos, double direction,
                 int radius, int angle, int speed,
                 int max_repletion, int max_hydration, int max_energy,
                 int fecundity, int max_age):
            MapObject(x_pos, y_pos),
            direction_(direction),
            radius_(radius),
            angle_(angle),
            speed_(speed),
            fecundity_(fecundity),
            repletion_(max_repletion / 2),
            hydration_(max_hydration / 2),
            energy_(max_energy_ / 2),
            age_(0),
            is_dead_(0),
            is_active_(0),
            max_repletion_(max_repletion),
            max_hydration_(max_hydration),
            max_energy_(max_energy),
            max_age_(max_age),
            knownObjects(new QMap<int, double >),
            action_time(0),
            is_sleeping_(0),
            time_sleeping_(0),
            is_procreating_(0),
            time_procreating_(0),
            time_to_procreate_(100)
        {
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
            direction_(another.direction_),
            repletion_(another.repletion_),
            hydration_(another.hydration_),
            energy_(another.energy_),
            age_(another.age_),
            is_dead_(another.is_dead_),
            is_active_(another.is_active_),
            action_time(another.action_time),
            fecundity_(another.fecundity_),
            max_repletion_(another.max_repletion_),
            max_hydration_(another.max_hydration_),
            max_energy_(another.max_energy_),
            max_age_(another.max_age_),
            knownObjects(new QMap<int, double >(*another.knownObjects)),
            is_sleeping_(another.is_sleeping_),
            time_sleeping_(another.time_sleeping_),
            is_procreating_(another.is_procreating_),
            time_procreating_(another.time_procreating_),
            time_to_procreate_(another.time_to_procreate_)
        {
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
         * @brief Podaje, o ile stopni musi się obrócić stworzenie, aby patrzeć na obiekt
         */
        double getAngleDifference(const MapObject &object)
        {
            double destined_direction = getDirectionOfObjectInDegrees(object);

            double angle_difference = destined_direction - direction_;
            angle_difference = std::min(angle_difference, 360 + angle_difference);

            return angle_difference;
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
            assert(degrees - fabs(degrees) < 0.01);
            double destined_direction = getDirectionOfObjectInDegrees(object);
            double angle_difference = getAngleDifference(object);
            double angle_difference_abs = fabs(angle_difference);

            if(angle_difference_abs <= degrees)
            {
                direction_ = destined_direction;
                direction_ = fmod(direction_, 360);
                return true;
            }
            else if(angle_difference < 0)
            {
                direction_-= degrees;
                direction_ = fmod(direction_, 360);
                return false;
            }
            else //(angle_difference > 0)
            {
                direction_+= degrees;
                direction_ = fmod(direction_, 360);
                return false;
            }
        }
        /**
         *
         * @brief
         * Obraca zwierzę w kierunku przeciwnym do zadanego obiektu, ale nie bardziej niz o zadany kąt.
         *
         * @see #partiallyTurnToObject
         */
        bool partiallyTurnFromObject(const MapObject &object, double degrees)
        {
            assert(degrees - fabs(degrees) < 0.01);
            double destined_direction = getDirectionOfObjectInDegrees(object);
            destined_direction = fmod(destined_direction + 180, 360);
            double angle_difference = getAngleDifference(object);
            double angle_difference_abs = fabs(angle_difference);

            if(angle_difference_abs <= degrees)
            {
                direction_ = destined_direction;
                direction_ = fmod(direction_, 360);
                return true;
            }
            else if(angle_difference < 0)
            {
                direction_-= degrees;
                direction_ = fmod(direction_, 360);
                return false;
            }
            else //(angle_difference > 0)
            {
                direction_+= degrees;
                direction_ = fmod(direction_, 360);
                return false;
            }
        }

        /**
         * @brief
         * Obraca się odrobinę w kierunku stworzenia, jednocześnie robiąc krok do przodu
         */
        void partiallyTurnAndMoveToObject(const MapObject &object, double degrees, double distance)
        {
            partiallyTurnToObject(object, degrees);
            double angle_difference = getAngleDifference(object);
            if(fabs(angle_difference) < 90)
            {
                moveByDistance(distance);
            }
        }

        /**
         * @brief
         * Obraca się odrobinę w kierunku przeciwnym do danego obiektu, jednocześnie próbując od niego uciec
         */
        void partiallyTurnOppositeAndMoveFromObject(const MapObject &object, double degrees, double distance)
        {
            partiallyTurnFromObject(object, degrees);
            double angle_difference = getAngleDifference(object);
            if(fabs(angle_difference) >= 90)
            {
                moveByDistance(distance);
            }
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
         * @brief zmniejsza współczynnik najedzenia zwierzęcia
         * @param time czas jako upłynął w kroku symulacji
         */
        void makeHungry(double time)
        {
            repletion_ -= time;
            if(repletion_ < 0)
            {
                die();
            }
        }

        /**
         * @brief zmniejsza współczynnik napojenia zwierzęcia
         * @param time czas jako upłynął w kroku symulacji
         */
        void makeThirsty(double time)
        {
            hydration_ -= time;
            if(hydration_ < 0)
            {
                die();
            }
        }

        /**
         * @brief zmniejsza współczynnik energii zwierzęcia
         * @param time czas jako upłynął w kroku symulacji
         */
        void makeTired(double time)
        {
            energy_ -= time;
            if(energy_ < 0)
            {
                die();
            }
        }

        /**
         * @brief Zwiększa wiek zwierzęcia
         * @param time czas jako upłynął w kroku symulacji, w milisekundach
         */
        void makeOlder(double time)
        {
            age_ += time;
            if(age_ > max_age_)
            {
                die();
            }
        }

        /**
         * @brief Zwiększa czas snu, o ile zwierzę śpi
         * @param time czas jako upłynął w kroku symulacji, w milisekundach
         */
        void updateSleepTime(double time)
        {
            time_sleeping_ += time;
            if(time_sleeping_  > 4000) // 4 sec
            {
                is_sleeping_ = 0;
                time_sleeping_ = 0;
            }
        }

        /**
         * @brief Zwiększa czas kopulacji, o ile zwierzę kopuluje
         * @param time czas jako upłynął w kroku symulacji, w milisekundach
         */
        void updateProcreatingTime(double time)
        {
            time_procreating_ += time;
            if(time_sleeping_  > 6000) // 6 sec
            {
                is_procreating_ = 0;
                time_procreating_ = 0;
            }
        }

        /**
         * @brief Umiera ze starości, głodu, pragnienia lub wycieńczenia
         */
        void die()
        {
            is_dead_ = 1;
        }

        /**
         * @brief Pije wodę z wodopoju, zwiększając poziom napojenia do maksimum.
         */
        void drink()
        {
            hydration_ = max_hydration_;
        }

        /**
         * @brief Zapada w sen, zwiększając poziom wypoczęcia do maksimum.
         */
        void fallAsleep()
        {
            energy_ = max_energy_;
            is_sleeping_ = 1;
            time_sleeping_ = 0;
        }

        /**
         * @brief Je (liście lub roślinożercę), zwiększając poziom najedzenia do maksimum.
         */
        void eat()
        {
            repletion_ = max_repletion_ ;
        }

        /**
         * @brief Sprawia, że zwierzę staje się zjedzone.
         */
        void beEaten()
        {
            is_dead_ = 1;
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
                if(*iter > 2000) // 2000 ms
                {
                    knownObjects->erase(iter++);
                }
                else
                {
                    ++iter;
                }
            }
        }

        /**
         * @brief Sprawdza, czy zwierzę zna dany obiekt
         */
        bool knows(MapObject &object)
        {
            return knownObjects->find(object.getIdentifier()) != knownObjects->end();
        }

        /// Zwraca zasięg widzenia
        int getRadius() const
        {
            return radius_;
        }

        /// Zwraca kąt widzenia
        int getAngle() const
        {
            return angle_;
        }

        /// Zwraca prędkość poruszania się
        int getSpeed() const
        {
            return speed_;
        }

        /// Zwraca płodność
        int getFecundity() const
        {
            return fecundity_;
        }

        /// Zwraca maksymalny poziom najedzenia (inaczej: odporność na głód)
        int getMaxRepletion() const
        {
            return max_repletion_;
        }

        /// Zwraca maksymalny poziom napojenia (inaczej: odporność na pragnienie)
        int getMaxHydration() const
        {
            return max_hydration_;
        }

        /// Zwraca maksymalny poziom energii (inaczej: odporność na zmęczenie)
        int getMaxEnergy() const
        {
            return max_energy_;
        }

        /// Zwraca maksymalna długość życia
        int getMaxAge() const
        {
            return max_age_;
        }

        /// Ustawia zwierzę jako nieaktywne
        void setInactive()
        {
            is_active_ = 0;
            action_time = 0;
        }

        /// Ustawia zwierzę jako aktywne
        void setActive()
        {
            is_active_ = 1;
        }

        /// Sprawdza, czy zwierzę jest aktywne
        bool isActive() const
        {
            return is_active_;
        }

        /// Sprawdza, czy zwierzę śpi
        bool isSleeping() const
        {
            return is_sleeping_;
        }

        /// Sprawdza, czy zwierzę teraz kopuluje
        bool isProcreating() const
        {
            return is_procreating_;
        }

        /// Zaczyna kopulację
        void startProcreating()
        {
            is_procreating_ = 1;
            time_procreating_ = 0;
            time_to_procreate_ = 100;
        }

        /// Aktualizuje czas do następnej prokreacji
        void updateTimeToProcreate(double time)
        {
            time_to_procreate_ -= time * fecundity_ * 4;
            if(time_to_procreate_ < 0)
            {
                time_to_procreate_ = 0;
            }
            std::cout << time_to_procreate_ << std::endl;
        }

        /// Zwraca czas do następnej prokreacji
        double getTimeToProcreate() const
        {
            return time_to_procreate_;
        }

        /// Robi jakąś akcję, gdy zwierzę nie ma nic do roboty
        void doSomething(double time)
        {
            action_time += time;
            if(action_time > 1800) // 1,8 sec
            {
                int random = rand()%4;
                switch(random)
                {
                    case 0: current_action = WALKING;       break;
                    case 1: current_action = STAYING;       break;
                    case 2: current_action = ROTATING_LEFT; break;
                    case 3: current_action = ROTATING_RIGHT;break;
                }
                action_time = 0;
            }
            switch (current_action)
            {
                case WALKING: moveByDistance(time*speed_/42000); break;
                case STAYING: break;
                case ROTATING_LEFT: rotateByAngleInDegrees(-time*speed_/3000); break;
                case ROTATING_RIGHT: rotateByAngleInDegrees(time*speed_/3000); break;
            }
        }

        /**
         * @brief Podaje piramidę potrzeb zwierzęcia.
         *
         * W przyszłości być moze będzie podawać indywidualną piramidę; póki co jest ona globalna.
         */
        virtual MaslovPyramid *getMaslovPyramid() = 0;

    /// @todo zaprzyjaznic z wizytatorami? protected:
    public:
    // protected:

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

        /// Czynność wykonywana aktualnie przez zwierzę (ważne tylko gdy #is_active_ == false)
        enum {WALKING, STAYING, ROTATING_RIGHT, ROTATING_LEFT} current_action;

        /// Czas, od jakiego zwierzę wykonuje akcję (ważne tylko gdy #is_active_ == false)
        double action_time;

        /// Czy zwierzę śpi (w jaskini)?
        bool is_sleeping_;

        /// Od jak dawna zwierzę śpi (w milisekundach)
        double time_sleeping_;

        /// Czy zwierzę teraz kopuluje?
        bool is_procreating_;

        /// Jeśli zwierzę teraz kopluje, to od jakiego czasu (w milisekundach)
        double time_procreating_;

        /// Czas za jaki zwierzę będzie mogło się znowu rozmnażać (maleje od 100 do 0)
        double time_to_procreate_;
    };
}

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Creature)

#endif
