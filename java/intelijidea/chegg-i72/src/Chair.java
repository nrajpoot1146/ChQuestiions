import java.util.Arrays;

public class Chair implements Common{

    private static final int[] SIZE = {2, 1, 3};
    private boolean movable;
    Chair(boolean movable){
        this.movable = movable;
    }

    /**
     * check chair is movable or fixed
     * @return if chair is movable return true otherwise return false
     */
    public boolean isMovable(){
        return movable;
    }

    /**
     * set movability of current chair
     * @param movability of chair
     */
    public void setMovable(boolean movability){
        this.movable = movability;
    }

    @Override
    public boolean needsWater() {
        return false;
    }

    @Override
    public boolean needsElectricity() {
        return false;
    }

    @Override
    public String size() {
        return Arrays.toString(SIZE);
    }
}
