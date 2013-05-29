#ifndef MASLOVPYRAMID_H
#define MASLOVPYRAMID_H

namespace common
{
    class MaslovPyramid
    {
    public:
        MaslovPyramid(int hunting_or_running, int drinking, int sleeping, int procreating);

        int getHuntingOrRunningPriority();
        int getDrinkingPriority();
        int getSleepingPriority();
        int getProcreatingPriority();

    private:
        int hunting_or_running_; // dla roslinozercy - ucieczka; dla drapieznika - polowanie
        int drinking_;
        int sleeping_;
        int procreating_;

        void checkData();
    };
}

#endif // MASLOVPYRAMID_H
