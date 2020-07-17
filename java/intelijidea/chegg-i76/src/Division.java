
/**
 * class Division
 * parent class Number
 */
public class Division extends Number{

    /**
     * parametrize constructor
     * @param x integer value
     * @param y integer value
     */
    Division(int x, int y){
        super(x, y);
    }

    /**
     * calculate division of two number
     * @return division
     */
    double Divide(){
        if (this.y != 0)
            return ((double) this.x) / this.y;
        else{
            throw new ArithmeticException();
        }
    }
}
