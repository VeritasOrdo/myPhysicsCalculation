#include "../../include/NumericalSolveOfMotionEquationBase/NumericalSolveOfMotionEquationBase.h"
#include "../../include/Dimension3Vector/Dimension3Vector.h"
#include <typeinfo>
#include <cxxabi.h>
#include <memory>

template <typename FunctionType>
NumericalSolveOfMotionEquationBase<FunctionType>::NumericalSolveOfMotionEquationBase(double timeBegin, double timeEnd, double stepLength, std::function<FunctionType> motionEquation) {
    this->timeBegin = timeBegin;
    this->timeEnd = timeEnd;
    this->stepLength = stepLength;
    this->motionEquation = motionEquation;
}

template <typename FunctionType>
double NumericalSolveOfMotionEquationBase<FunctionType>::getTimeBegin() {
    return this->timeBegin;
}

template <typename FunctionType>
void NumericalSolveOfMotionEquationBase<FunctionType>::setTimeBegin(double timeBegin) {
    this->timeBegin = timeBegin;
}

template <typename FunctionType>
double NumericalSolveOfMotionEquationBase<FunctionType>::getTimeEnd() {
    return this->timeEnd;
}

template <typename FunctionType>
void NumericalSolveOfMotionEquationBase<FunctionType>::setTimeEnd(double timeEnd) {
    this->timeEnd = timeEnd;
}

template <typename FunctionType>
double NumericalSolveOfMotionEquationBase<FunctionType>::getStepLength() {
    return this->stepLength;
}

template <typename FunctionType>
void NumericalSolveOfMotionEquationBase<FunctionType>::setStepLength(double stepLength) {
    this->stepLength = stepLength;
}

template <typename FunctionType>
std::string NumericalSolveOfMotionEquationBase<FunctionType>::getMotionEquationType() {
    int status;
    std::unique_ptr<char, decltype(&std::free)> res {
        abi::__cxa_demangle(typeid(this->motionEquation).name(), nullptr, nullptr, &status),
        std::free
    };
    return (status == 0) ? std::string(res.get()) : typeid(this->motionEquation).name();
}

template <typename FunctionType>
void NumericalSolveOfMotionEquationBase<FunctionType>::setMotionEquation(std::function<FunctionType> motionEquation) {
    this->motionEquation = motionEquation;
}

template <typename FunctionType>
NumericalSolveOfMotionEquationBase<FunctionType>::~NumericalSolveOfMotionEquationBase() {
}
