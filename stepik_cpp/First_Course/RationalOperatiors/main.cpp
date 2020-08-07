#include <iostream>

struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator),denominator_(denominator) {}

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv();
    
    double to_double() const {
        return numerator_ / (double) denominator_;
    }

    friend bool operator==(Rational const& left, Rational const &right);
    friend bool operator<(Rational const& left, Rational const &right);

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational ratio)
{
    return ratio;
}

Rational operator-(Rational ratio)
{
    ratio.neg();
    return ratio;
}

Rational & operator+=(Rational & left, Rational const & right)
{
    left.add(right);
    return left;
}

Rational & operator-=(Rational & left, Rational const & right)
{
    left.sub(right);
    return left;
}

Rational & operator*=(Rational & left, Rational const & right)
{
    left.mul(right);
    return left;
}

Rational & operator/=(Rational & left, Rational const & right)
{
    left.div(right);
    return left;
}


Rational operator+(Rational left, Rational const & right)
{
    left.add(right);
    return left;
}

Rational operator-(Rational left, Rational const & right)
{
    left.sub(right);
    return left;
}

Rational operator*(Rational left, Rational const & right)
{
    left.mul(right);
    return left;
}

Rational operator/(Rational left, Rational const & right)
{
    left.div(right);
    return left;
}


std::ostream & operator<<(std::ostream &os,Rational ratio)
{
    return os << ratio.to_double();
}

int main(int argc, char const *argv[])
{
    Rational r1(1);
    Rational r2(1);
    r1 = 6 + r2;
    Rational r3(1);

    r3 = r1 + 2;

    std::cout << r1 << std::endl;

    r1 = -r1;
    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;
    return 0;
}