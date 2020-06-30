public class Fraction {
    private Integer num;
    private Integer denom;

    /**
     *
     * @param num numerator of fraction number
     * @param denom denominator of fraction number
     */
    Fraction(Integer num, Integer denom){
        this.num = num < 0 ? -num : num;
        if(denom == 0){
            this.denom = 1;
        }
        this.denom = denom < 0 ? -denom : denom;
        reduce();
    }

    /**
     * getter method for denominator
     * @return denominator of fraction number
     */
    public Integer getDen() {
        return denom;
    }

    /**
     * getter method for numerator of fraction number
     * @return numerator of fraction number
     */
    public Integer getNum() {
        return num;
    }

    /**
     * setter method for numerator of fraction number
     * @param num numerator of fraction number
     */
    public void setNum(Integer num) {
        this.num = num;
        reduce();
    }

    /**
     * setter method for denominator of fraction number
     * @param denom denominator of fraction number
     */
    public void setDen(Integer denom) {
        this.num = num < 0 ? -num : num;
        if(denom == 0){
            this.denom = 1;
        }
        this.denom = denom < 0 ? -denom : denom;
        reduce();
    }

    /**
     *
     * @return string that represent a fraction number
     */
    @Override
    public String toString() {
        return num + "/" + denom;
    }

    /**
     * this function use to reduce fraction to lowest
     * by finding largest common denominator
     */
    private void reduce() {
        Integer nTemp = this.num;
        Integer dTemp = this.denom;
        Integer larg;

        // find the largest of numerator and denominator
        nTemp = this.num < 0 ? -this.num : this.num;
        larg = nTemp > dTemp ? nTemp : dTemp;

        //find largest divisor of numerator and denominator
        Integer gcd = 0;
        Integer i = larg;
        while (i>=2){
            if( this.num % i == 0 && this.denom % i == 0){
                gcd = i;
                break;
            }
            i--;
        }

        // reduce numerator and denominator
        if (gcd != 0) {
            this.num = this.num / gcd;
            this.denom = this.denom / gcd;
        }
    }
}
