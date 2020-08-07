public class Fraction
{
    // question 1
    private int numerator;
    private int denominator ;

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
        reduce();
    }

    private int gcd(int n1, int n2){
        if (n2 == 0){
            return n1;
        }
        return gcd(n2, n1 % n2);
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
        res.reduce();
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
        reduce();
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
        reduce();
    }

    // Function to print output
    public void printOutput ()
    {
        System.out.println("Fraction is :"+ numerator +"/" + denominator);
    }

    private void reduce(){
        int gd = this.gcd(this.numerator, this.denominator);
        numerator = numerator / gd;
        denominator = denominator / gd;
    }

}