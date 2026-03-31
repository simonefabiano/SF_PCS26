#include <iostream>
#include <concepts>
#include <numeric>

template<typename I>
requires std::integral<I>
class rational {
private:
    I num_;
    I den_;

public:
    rational() : num_(0), den_(1) {}

    rational(I n, I d) : num_(n), den_(d) {
        if (den_ != 0) {
            I comune = std::gcd(num_, den_);
            num_ /= comune;
            den_ /= comune;
        }
    }

    I num() const { return num_; }
    I den() const { return den_; }

    rational& operator+=(const rational& other) {
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        I comune = std::gcd(num_, den_);
        num_ /= comune;
        den_ /= comune;
        return *this;
    }
};

template<typename I>
rational<I> operator+(rational<I> a, const rational<I>& b) {
    a += b;
    return a;
}

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        os << "NaN/Inf";
    } else {
        os << r.num() << "/" << r.den();
    }
    return os;
}