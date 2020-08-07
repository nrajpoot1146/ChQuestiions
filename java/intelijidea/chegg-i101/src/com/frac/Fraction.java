package com.frac;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
public class Fraction
{
    // question 1
    private int numerator;
    private int denominator ;

    public Fraction(){
        this.numerator = 0;
        this.denominator = 1;
    }

    public Fraction(int numerator, int denominator){
        if (denominator == 0){
            denominator = 1;
        }
        this.numerator = denominator<0 ? numerator * -1 : numerator;
        this.denominator = denominator<0 ? denominator * -1 : denominator;
        this.simplify();
    }

    // Function to get input
    public void get_input( int n ,int d)
    {
        // for question 4
        if (d == 0){
            d = 1;
        } else if (d<0){
            n *= -1;
            d *= -1;
        }
        numerator=n;
        denominator=d;
        simplify();
    }

    private int gcd(int n1, int n2){
        if (n2 == 0){
            return n1;
        }
        return gcd(n2, n1 % n2);
    }

    public double dblValue(){
        return ((double) this.numerator) / this.denominator;
    }

    // question 2
    public boolean isZero(){
        return numerator == 0;
    }

    // question 3
    public boolean equals(Fraction o){
        return numerator == o.numerator && denominator == o.denominator;
    }

    // question 3
    public Fraction add(Fraction o){
        int denom = denominator * o.denominator;
        int num = (denom / denominator) * numerator + (denom / o.denominator) * o.numerator;
        Fraction res = new Fraction();
        res.numerator = num;
        res.denominator = denom;
        res.simplify();
        return res;
    }

    public int getDenominator() {
        return denominator;
    }

    public int getNumerator() {
        return numerator;
    }

    public void setDenominator(int denominator) {
        if (denominator < 0){
            numerator *= -1;
            denominator *= -1;
        } else if (denominator == 0){
            denominator = 1;
        }
        this.denominator = denominator;
        simplify();
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
        simplify();
    }

    // Function to print output
    public void printOutput ()
    {
        System.out.println("Fraction is :"+ numerator +"/" + denominator);
    }

    private void simplify(){
        int gd = this.gcd(this.numerator, this.denominator);
        numerator = numerator / gd;
        denominator = denominator / gd;
    }

    @Override
    public String toString() {
        return this.numerator+"/"+this.denominator;
    }
}