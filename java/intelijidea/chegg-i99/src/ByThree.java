public class ByThree extends Series{
    private int val; // current value of the series
    private int preval; // previous value of the series

    /**
     * parameterize constructor
     * @param start number of the series
     */
    ByThree(int start) {
        super(start);
        this.val = start;
        this.preval = start - 3;
    }

    @Override
    public int getNext() {
        this.preval = this.val - 3;
        int curr = this.val;
        this.val += 3;
        return curr;
    }

    @Override
    public int getPrev() {
        return this.preval;
    }

    @Override
    public void reset() {
        this.val = this.getStart();
        this.preval = this.val - 3;
    }

    public int getVal() {
        return val;
    }

    public void setVal(int val) {
        this.val = val;
    }

    public int getPreval() {
        return preval;
    }

    public void setPreval(int preval) {
        this.preval = preval;
    }
}
