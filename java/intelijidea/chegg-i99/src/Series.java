abstract public class Series {
    private int start;

    /**
     * parameterize constructor
     * @param start number of the series
     */
    Series(int start){
        this.start = start;
    }

    /**
     * method get next element of the series
     * @return next element of the series
     */
    abstract public int getNext();

    /**
     * method get previous element of the series
     * @return previous element of the series
     */
    abstract public int getPrev();

    /**
     * restart the series
     */
    abstract public void reset();

    /**
     * sets the start b=value of the series on an integer parameter
     * @param start
     */
    public void setStart(int start){
        this.start = start;
    }

    /**
     * get start of the series
     * @return start of the series
     */
    public int getStart(){
        return this.start;
    }
}
