#pragma once
#include "clsDate.h"

class clsPeriod
{
public:
    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;
    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::compareDates(Period2.EndDate, Period1.StartDate) == clsDate::enCompare::before ||
            clsDate::compareDates(Period2.StartDate, Period1.EndDate) == clsDate::enCompare::after)
            return false;
        else
            return true;
    }

    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.print();

        cout << "Period End: ";
        EndDate.print();
    }
};