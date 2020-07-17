
/**
 * class Multiplication
 * parent class Number
 */
public class Multiplication extends Number{

    /**
     * parametrize constructor
     * @param x integer value
     * @param y integer value
     */
    Multiplication(int x, int y){
        super(x, y);
    }

    /**
     * calculate multiplication of two number
     * @return multiplication of two number
     */
    int Multiply(){
        return this.x * this.y;
    }
}
