#ifndef MASLOVPYRAMID_H
#define MASLOVPYRAMID_H

namespace common
{
    class MaslovPyramid
    {
    public:
        MaslovPyramid(int hunting_or_running, int drinking, int sleeping, int procreating, int eating=0);

        int getHuntingOrRunningPriority();
        int getDrinkingPriority();
        int getSleepingPriority();
        int getProcreatingPriority();
        int getEatingPriority();

    private:
        int hunting_or_running_; // dla roslinozercy - ucieczka; dla drapieznika - polowanie
        int drinking_;
        int sleeping_;
        int procreating_;
        int eating_;

        /// @todo update, chyba jednak nie potrzebna, dzięki!
        void checkData();
    };
}

#endif // MASLOVPYRAMID_H
