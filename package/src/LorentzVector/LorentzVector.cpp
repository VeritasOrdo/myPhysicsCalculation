#include "../../include/LorentzVector/LorentzVector.h"

template <typename T>
LorentzVector<T>::LorentzVector() {
    vector = std::vector<T>(4);
}

template <typename T>
LorentzVector<T>::LorentzVector(T t, T x, T y, T z) {
    vector = std::vector<T>(4);
    vector[0] = t;
    vector[1] = x;
    vector[2] = y;
    vector[3] = z;
}

template <typename T>
LorentzVector<T>::LorentzVector(const LorentzVector<T>& vector) {
    this->vector = vector.vector;
}

template <typename T>
LorentzVector<T>::~LorentzVector() {
    vector.clear();
}

template <typename T>
T LorentzVector<T>::getT() const {
    return vector[0];
}

template <typename T>
T LorentzVector<T>::getX() const {
    return vector[1];
}

template <typename T>
T LorentzVector<T>::getY() const {
    return vector[2];
}

template <typename T>
T LorentzVector<T>::getZ() const {
    return vector[3];
}

template <typename T>
void LorentzVector<T>::setT(T t) {
    vector[0] = t;
}

template <typename T>
void LorentzVector<T>::setX(T x) {
    vector[1] = x;
}

template <typename T>
void LorentzVector<T>::setY(T y) {
    vector[2] = y;
}

template <typename T>
void LorentzVector<T>::setZ(T z) {
    vector[3] = z;
}

template <typename T>
T LorentzVector<T>::getInvariant() const {
    return vector[0] * vector[0] - vector[1] * vector[1] - vector[2] * vector[2] - vector[3] * vector[3];
}

template <typename T>
LorentzVector<T> LorentzVector<T>::operator+(const LorentzVector<T>& vector) const {
    return LorentzVector<T>(this->vector[0] + vector.vector[0], this->vector[1] + vector.vector[1], this->vector[2] + vector.vector[2], this->vector[3] + vector.vector[3]);
}

template <typename T>
LorentzVector<T> LorentzVector<T>::operator-(const LorentzVector<T>& vector) const {
    return LorentzVector<T>(this->vector[0] - vector.vector[0], this->vector[1] - vector.vector[1], this->vector[2] - vector.vector[2], this->vector[3] - vector.vector[3]);
}

template <typename T>
LorentzVector<T> LorentzVector<T>::operator*(T scalar) const {
    return LorentzVector<T>(this->vector[0] * scalar, this->vector[1] * scalar, this->vector[2] * scalar, this->vector[3] * scalar);
}

template <typename T>
LorentzVector<T> LorentzVector<T>::operator/(T scalar) const {
    return LorentzVector<T>(this->vector[0] / scalar, this->vector[1] / scalar, this->vector[2] / scalar, this->vector[3] / scalar);
}

template <typename T>
T LorentzVector<T>::operator*(const LorentzVector<T>& vector) const {
    return this->vector[0] * vector.vector[0] - this->vector[1] * vector.vector[1] - this->vector[2] * vector.vector[2] - this->vector[3] * vector.vector[3];
}

template <typename T>
LorentzVector<T> LorentzVector<T>::operator^(const LorentzVector<T>& vector) const {
    return LorentzVector<T>(this->vector[0] * vector.vector[0] - this->vector[1] * vector.vector[1] - this->vector[2] * vector.vector[2] - this->vector[3] * vector.vector[3], this->vector[0] * vector.vector[1] + this->vector[1] * vector.vector[0], this->vector[0] * vector.vector[2] + this->vector[2] * vector.vector[0], this->vector[0] * vector.vector[3] + this->vector[3] * vector.vector[0]);
}

template <typename T>
LorentzVector<T> LorentzVector<T>::operator-() const {
    return LorentzVector<T>(-this->vector[0], -this->vector[1], -this->vector[2], -this->vector[3]);
}

template <typename T>
bool LorentzVector<T>::operator==(const LorentzVector<T>& vector) const {
    return this->vector[0] == vector.vector[0] && this->vector[1] == vector.vector[1] && this->vector[2] == vector.vector[2] && this->vector[3] == vector.vector[3];
}

template <typename T>
bool LorentzVector<T>::operator!=(const LorentzVector<T>& vector) const {
    return this->vector[0] != vector.vector[0] || this->vector[1] != vector.vector[1] || this->vector[2] != vector.vector[2] || this->vector[3] != vector.vector[3];
}

template <typename T>
LorentzVector<T>& LorentzVector<T>::operator=(const LorentzVector<T>& vector) {
    this->vector = vector.vector;
    return *this;
}

template <typename T>
LorentzVector<T>& LorentzVector<T>::operator+=(const LorentzVector<T>& vector) {
    this->vector[0] += vector.vector[0];
    this->vector[1] += vector.vector[1];
    this->vector[2] += vector.vector[2];
    this->vector[3] += vector.vector[3];
    return *this;
}

template <typename T>
LorentzVector<T>& LorentzVector<T>::operator-=(const LorentzVector<T>& vector) {
    this->vector[0] -= vector.vector[0];
    this->vector[1] -= vector.vector[1];
    this->vector[2] -= vector.vector[2];
    this->vector[3] -= vector.vector[3];
    return *this;
}

template <typename T>
LorentzVector<T>& LorentzVector<T>::operator*=(T scalar) {
    this->vector[0] *= scalar;
    this->vector[1] *= scalar;
    this->vector[2] *= scalar;
    this->vector[3] *= scalar;
    return *this;
}

template <typename T>
LorentzVector<T>& LorentzVector<T>::operator/=(T scalar) {
    this->vector[0] /= scalar;
    this->vector[1] /= scalar;
    this->vector[2] /= scalar;
    this->vector[3] /= scalar;
    return *this;
}

template <typename T>
T LorentzVector<T>::operator[](int index) const {
    return vector[index];
}

template <typename T>
LorentzVector<T> LorentzVector<T>::transformVariante() const {
    return LorentzVector<T>(this->vector[0], -this->vector[1], -this->vector[2], -this->vector[3]);
}

template <typename T>
LorentzVector<T>::operator LorentzVector<std::complex<double>>() const
{
    return LorentzVector<std::complex<double>>(std::complex<double>(this->vector[0]), std::complex<double>(this->vector[1]), std::complex<double>(this->vector[2]), std::complex<double>(this->vector[3]));
}

template class LorentzVector<int>;
template class LorentzVector<float>;
template class LorentzVector<double>;
template class LorentzVector<std::complex<double>>;




