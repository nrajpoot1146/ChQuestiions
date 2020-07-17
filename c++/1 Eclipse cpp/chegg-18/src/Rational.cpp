/*
 * Rational.cpp
 *
 *  Created on: 10-Jul-2020
 *      Author:
 */

#include "Rational.h"

Rational::Rational(int numerator = 0, int denominator = 1) : numer(numerator), denom(denominator) {
	if (this->denom == 0){
		this->denom = 1;
	}
	this->reduce();
}

Rational& Rational::add(const Rational &r){
	Rational *res = new Rational();
	int resDenom = this->denom * r.denom;
	res->denom = resDenom;
	res->numer = this->numer * (resDenom / this->denom) + r.numer * (resDenom / r.denom);
	res->reduce();
	return *res;
}

Rational& Rational::sub(const Rational &r){
	Rational *res = new Rational();
	int resDenom = this->denom * r.denom;
	res->denom = resDenom;
	res->numer = this->numer * (resDenom / this->denom) - r.numer * (resDenom / r.denom);
	res->reduce();
	return *res;
}

Rational& Rational::mult(const Rational &r){
	Rational *res = new Rational();
	res->denom = this->denom * r.denom;
	res->numer = this->numer * r.numer;
	res->reduce();
	return *res;
}

Rational& Rational::divi(const Rational &r){
	Rational *res = new Rational();
	res->denom = this->denom * r.numer;
	res->numer = this->numer * r.denom;
	res->reduce();
	return *res;
}

std::string Rational::toRationalString(){
	std::stringstream ss;
	ss<<this->numer;
	std::string num;
	ss>>num;
	ss.clear();
	ss<<this->denom;
	std::string den;
	ss>>den;
	return num + "/" + den;
}

void Rational::reduce(){
	int g = this->gcd(this->numer, this->denom);
	this->numer /= g;
	this->denom /= g;

}

int Rational::gcd(int a, int b){
	if (b == 0){
		return a;
	}

	return gcd (b, a % b);
}

double Rational::toDouble(){
	return ((double) this->numer) / this->denom;
}

Rational::~Rational() {}

