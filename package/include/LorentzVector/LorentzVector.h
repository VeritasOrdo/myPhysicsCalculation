#include<vector>
#include<cmath>
#include<complex>

#pragma once

template <typename T>

class LorentzVector {
    private:
        std::vector<T> vector;
    public:
        LorentzVector();
        LorentzVector(T t, T x, T y, T z);
        LorentzVector(const LorentzVector<T>& vector);
        ~LorentzVector();
        T getT() const;
        T getX() const;
        T getY() const;
        T getZ() const;
        void setT(T t);
        void setX(T x);
        void setY(T y);
        void setZ(T z);
        T getInvariant() const;
        LorentzVector<T> operator+(const LorentzVector<T>& vector) const;
        LorentzVector<T> operator-(const LorentzVector<T>& vector) const;
        LorentzVector<T> operator*(T scalar) const;
        LorentzVector<T> operator/(T scalar) const;
        T operator*(const LorentzVector<T>& vector) const;
        //std::complex<double> operator*(const LorentzVector<double>& vector) const;
        LorentzVector<T> operator^(const LorentzVector<T>& vector) const;
        LorentzVector<T> operator-() const;
        bool operator==(const LorentzVector<T>& vector) const;
        bool operator!=(const LorentzVector<T>& vector) const;
        LorentzVector<T>& operator=(const LorentzVector<T>& vector);
        LorentzVector<T>& operator+=(const LorentzVector<T>& vector);
        LorentzVector<T>& operator-=(const LorentzVector<T>& vector);
        LorentzVector<T>& operator*=(T scalar);
        LorentzVector<T>& operator/=(T scalar);
        T operator[](int index) const;
        LorentzVector<T> transformVariante() const;
        operator LorentzVector<std::complex<double>>() const;
        friend std::ostream& operator<<(std::ostream& os, const LorentzVector<T>& vector) {
            os << "(" << vector.vector[0] << "," << vector.vector[1] << "," << vector.vector[2] << "," << vector.vector[3] << ")";
            return os;
        }
};


