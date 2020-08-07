#include "Rational.h"

void Rational::add(Rational rational) {
  numerator_ =
      numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
  denominator_ *= rational.denominator_;
}

void Rational::sub(Rational rational) {
  numerator_ =
      numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
  denominator_ *= rational.denominator_;
}

void Rational::mul(Rational rational) {
  numerator_ *= rational.numerator_;
  denominator_ *= rational.denominator_;
}

void Rational::div(Rational rational) {
  numerator_ *= rational.denominator_;
  denominator_ *= rational.numerator_;
}

void Rational::neg() { numerator_ = -numerator_; }

double Rational::to_double() const { return numerator_ / (double)denominator_; }

Rational& Rational::operator+=(Rational rational) {
  add(rational);
  return *this;
}

Rational& Rational::operator-=(Rational rational) {
  sub(rational);
  return *this;
}

Rational& Rational::operator*=(Rational rational) {
  mul(rational);
  return *this;
}

Rational& Rational::operator/=(Rational rational) {
  div(rational);
  return *this;
}

Rational Rational::operator-() const {
  return Rational(-this->numerator_, this->denominator_);
}

Rational Rational::operator+() const { return *this; }

std::ostream& operator<<(std::ostream& os, Rational ratio) {
  return os << ratio.to_double();
}

    bool operator>(Rational const& left, Rational const &right)
    {
        return right<left;
    }

    bool operator>=(Rational const& left, Rational const &right)
    {
        return !(left<right);
    }

    bool operator<=(Rational const& left, Rational const &right)
    {
        return !(right<left);
    }

    bool operator!=(Rational const& left, Rational const &right)
    {
        return !(right==left);
    }