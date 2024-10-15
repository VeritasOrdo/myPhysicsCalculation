#include <functional>
#include <string>   

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
        NumericalSolveOfMotionEquationBase(double timeBegin, double timeEnd, double stepLength, std::function<FunctionType> motionEquation);
        double getTimeBegin();
        void setTimeBegin(double timeBegin);
        double getTimeEnd();
        void setTimeEnd(double timeEnd);
        double getStepLength();
        void setStepLength(double stepLength);
        std::string getMotionEquationType();
        void setMotionEquation(std::function<FunctionType> motionEquation);
        ~NumericalSolveOfMotionEquationBase();
};

#include "../../src/NumericalSolveOfMotionEquationBase/NumericalSolveOfMotionEquationBase.tpp"