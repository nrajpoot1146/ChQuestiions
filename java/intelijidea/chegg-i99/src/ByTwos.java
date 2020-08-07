public class ByTwos extends Series{
    private int val; // current value of the series
    private int preval; // previous value of the series

    /**
     * parameterize constructor
     * @param start number of the series
     */
    ByTwos(int start) {
        super(start);
        this.val = start;
        this.preval = start - 2;
    }

    @Override
    public int getNext() {
        this.preval = this.val - 2;
        int curr = this.val;
        this.val += 2;
        return curr;
    }

    @Override
    public int getPrev() {
        return this.preval;
    }

    @Override
    public void reset() {
        this.val = this.getStart();
        this.preval = this.val - 2;
    }

    /**
     * get current value
     * @return
     */
    public int getVal() {
        return val;
    }

    /**
     * set current value
     * @param val
     */
    public void setVal(int val) {
        this.val = val;
    }

    /**
     *
     * get prev value
     * @return
     */
    public int getPreval() {
        return preval;
    }

    /**
     * set previous value
     * @param preval
     */
    public void setPreval(int preval) {
        this.preval = preval;
    }
}
