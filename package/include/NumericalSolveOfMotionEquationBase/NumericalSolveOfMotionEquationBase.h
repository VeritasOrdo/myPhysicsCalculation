#include <functional>
#include <string>   
#include <vector>

#pragma once

template <typename FunctionType>

class NumericalSolveOfMotionEquationBase
{
    private:
        double timeBegin;
        double timeEnd;
        double stepLength;
        std::function<FunctionType> motionEquation;
    public:
        NumericalSolveOfMotionEquationBase();
        NumericalSolveOfMotionEquationBase(double timeBegin, double timeEnd, double stepLength, std::function<FunctionType> motionEquation);
        double getTimeBegin();
        void setTimeBegin(double timeBegin);
        double getTimeEnd();
        void setTimeEnd(double timeEnd);
        double getStepLength();
        void setStepLength(double stepLength);
        std::string getMotionEquationType();
        void setMotionEquation(std::function<FunctionType> motionEquation);
        virtual std::function<FunctionType> getMotionEquation();
        std::vector<double> getTimeList();
        virtual void solve() = 0;
        ~NumericalSolveOfMotionEquationBase();
};

#include "../../src/NumericalSolveOfMotionEquationBase/NumericalSolveOfMotionEquationBase.tpp"