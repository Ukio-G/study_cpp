#ifndef __RATIONAL__H_
#define __RATIONAL__H_

#include <iostream>
struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator),denominator_(denominator) {}

    void add(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    
    double to_double() const;


    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;

    operator double() const
    {
    	return this->to_double();
    }

    friend bool operator==(Rational const& left, Rational const &right){
  		return ((left.numerator_ * right.denominator_) == (right.numerator_ * left.denominator_));
	}
    friend bool operator<(Rational const& left, Rational const &right){
    	return ((left.numerator_ * right.denominator_) < (right.numerator_ * left.denominator_));
    }
    

private:
    int numerator_;
    int denominator_;
};

std::ostream& operator<<(std::ostream& os, Rational ratio);

	bool operator>(Rational const& left, Rational const &right);

    bool operator>=(Rational const& left, Rational const &right);

    bool operator<=(Rational const& left, Rational const &right);

    bool operator!=(Rational const& left, Rational const &right);
#endif