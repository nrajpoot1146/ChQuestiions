/**
 * class Subtraction
 * parent class Number
 */
public class Subtraction extends Number{

    /**
     * parametrize constructor
     * @param x integer value
     * @param y integer value
     */
    Subtraction(int x, int y){
        super(x, y);
    }

    /**
     * calculate subtraction of two number
     * @return subtraction of two number
     */
    int Subtract(){
        return this.x - this.y;
    }
}
