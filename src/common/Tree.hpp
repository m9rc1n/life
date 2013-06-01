#ifndef COMMON_TREE_HPP
#define COMMON_TREE_HPP

#include "MapObject.hpp"

namespace common
{
   /**
     * @brief Klasa reprezentująca drzewo.
     *
     * Drzewo jest obiektem zapewniającym pożywienie dla roślinożerców. Gdy głodny roślinożerca podchodzi do drzewa, zjada część jego
     * liści, co powoduje zmniejszenie liczby liści na drzewie. Gdy liczba liści spadnie do zera, z drzewa nie można dalej jeść.
     * Takie "zjedzone" drzewo jest oznaczane na mapie szarym kolorem. Liście z czasem odrastają.
     */
    class Tree: public MapObject
    {
    public:
        Tree(double x_pos, double y_pos):
            MapObject(x_pos, y_pos),
            leafs_(100)
        {
            // ...
        }

        /**
         * @brief
         * Tworzy głęboką kopię obiektu
         * 
         * @returns wskaznik do nowego obiektu (utworzonego przez new)
         * 
         * @todo moze zmienic na sprytny wskaznik?
         */
        virtual MapObject *clone()
        {
            return new Tree(*this);
        }
        
        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &);

        /**
         * @brief
         * Zwraca ilość liści na drzewie.
         */
        virtual double getLeafs()
        {
            return leafs_;
        }

        /**
         * @brief
         * Zwiększa ilość liści o zadaną wartość.
         *
         * @pre new_leafs >= 0
         */
        virtual void growLeafs(double new_leafs)
        {
            leafs_ += new_leafs;
            leafs_ = std::min(leafs_, 100.0);
        }

        /**
         * @brief
         * Zmniejsza ilość liści o zadaną wartość.
         *
         * @pre eaten_leafs >= 0
         */
        virtual void eatLeafs(double eaten_leafs)
        {
            leafs_ -= eaten_leafs;
            leafs_ = std::max(leafs_, 0.0);
        }
        
    protected:
        /// Liczba liści na drzewie (double, bo rośnie w sposób ciągły; przy wyświetlaniu można zaokrąglić).
        double leafs_;
    };
}

#endif // TREE_HPP
