/**
 * class Average
 * parent class Addition
 */
public class Average extends Addition{

    /**
     * parametrize constructor
     * @param x integer value
     * @param y integer value
     */
    Average(int x, int y){
        super(x, y);
    }

    /**
     * calculate average of two number
     * @return average of two number
     */
    double Avg(){
        int sum = super.Add();
        return ((double) sum) / 2;
    }
}
