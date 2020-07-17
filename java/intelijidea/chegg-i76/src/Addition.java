/**
 * class Addition
 * parent class Number
 */
public class Addition extends Number{
    /**
     * parametrize constructor
     * @param x integer value
     * @param y integer value
     */
    Addition(int x, int y){
        super(x, y);
    }
    /**
     * calculate sum of two number
     * @return sum of x and y
     */
    int Add(){
        return this.x + this.y;
    }
}
