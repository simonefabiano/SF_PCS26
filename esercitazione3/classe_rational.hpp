#ifndef CLASSE_RATIONAL_HPP
#define CLASSE_RATIONAL_HPP

#include <iostream>
#include <concepts>
#include <numeric>

template<typename I>
requires std::integral<I>
class rational {
private:
    I num_;
    I den_;

    void simplify() {
        if (den_ == 0) return; 
        I common = std::gcd(num_, den_);
        num_ /= common;
        den_ /= common;
        if (den_ < 0) { num_ = -num_; den_ = -den_; }
    }

public:
    rational() : num_(0), den_(1) {}

    rational(I n, I d) : num_(n), den_(d) {
        simplify();
    }

    I num() const { return num_; }
    I den() const { return den_; }
    
    rational& operator+=(const rational& other) {
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ *= other.den_;
        simplify();
        return *this;
    }

    rational& operator-=(const rational& other) {
        num_ = num_ * other.den_ - other.num_ * den_;
        den_ *= other.den_;
        simplify();
        return *this;
    }

    rational& operator*=(const rational& other) {
        num_ *= other.num_;
        den_ *= other.den_;
        simplify();
        return *this;
    }

    rational& operator/=(const rational& other) {
        num_ *= other.den_;
        den_ *= other.num_;
        simplify();
        return *this;
    }
};

template<typename I>
rational<I> operator+(rational<I> lhs, const rational<I>& rhs) {
    lhs += rhs;
    return lhs;
}

template<typename I>
rational<I> operator-(rational<I> lhs, const rational<I>& rhs) {
    lhs -= rhs;
    return lhs;
}

template<typename I>
rational<I> operator*(rational<I> lhs, const rational<I>& rhs) {
    lhs *= rhs;
    return lhs;
}

template<typename I>
rational<I> operator/(rational<I> lhs, const rational<I>& rhs) {
    lhs /= rhs;
    return lhs;
}

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        if (r.num() == 0) os << "NaN";
        else os << "Inf";             
    } else {
        os << r.num();
        if (r.den() != 1) os << "/" << r.den();
    }
    return os;
}

#endif

// IA impiegata per il tentativo di risoluzione (fallito) di problemi segnalati dal compiler che
// impediscono di runnare il programma, e di cui si cercherà una risoluzione nelle vacanze di Pasqua