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
        int deadPredators;
        int deadHerbivores;
        int populationProcreating;
        int populationSleeping;

        double averageRadiusHerbivores;
        double averageRadiusPredators;

        double averageSpeedHerbivores;
        double averageSpeedPredators;

        double averageFecundityHerbivores;
        double averageFecundityPredators;

        double averageAgePredators;
        double averageAgeHerbivores;

        double averageAnglePredators;
        double averageAngleHerbivores;

        double averageRepletionPredators;
        double averageRepletionHerbivores;

        double averageHydrationPredators;
        double averageHydrationHerbivores;

        double averageEnergyPredators;
        double averageEnergyHerbivores;

        double averageMaxAgePredators;
        double averageMaxAgeHerbivores;

        double averageDieAgePredators;
        double averageDieAgeHerbivores;

        double averageMaxRepletionPredators;
        double averageMaxRepletionHerbivores;

        double averageMaxHydrationPredators;
        double averageMaxHydrationHerbivores;

        double averageMaxEnergyPredators;
        double averageMaxEnergyHerbivores;

        static Statistics *getInstance()
        {
            static Statistics instance;
            return &instance;
        }
    };
}

#endif // STATISTICS_HPP
