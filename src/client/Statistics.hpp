#ifndef STATISTICS_HPP
#define STATISTICS_HPP


namespace client
{
    /**
    * @brief
    * Klasa przechowujaca komplet statystyk.
    *
    * Singleton.
    */

    class Statistics
    {

    private:
        // singleton
        Statistics();
        Statistics(Statistics &);

    public:

        int populationPredators;
        int populationHerbivores;

        static Statistics *getInstance()
        {
            static Statistics instance;
            return &instance;
        }
    };
}

#endif // STATISTICS_HPP
