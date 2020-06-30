public class DialerLock {
    private boolean isClosed;
    private int dialValue;
    private int combination;

    private DialerLock(boolean isClosed, int combination, int dialValue){
        this.isClosed = false;
        this.combination = combination;
        this.dialValue = dialValue;
    }

    public static DialerLock ComboLock(){
        return new DialerLock(false, 0, 0);
    }

    /**
     *
     * @return true if this lock is locked (closed and dial value is different from stored combination)
     */
    public boolean isLocked(){
        if(this.isClosed() && this.combination != this.dialValue){
            return true;
        }
        return false;
    }

    /**
     * close the lock (does nothing if lock is already closed)
     */
    public void close(){
        if(this.isLocked()){
            return;
        }
        this.isClosed = true;
    }

    /**
     * opens the lock if it is not locked, otherwise does nothing
     */
    public void open(){
        if(!this.isLocked()){
            this.isClosed = false;
            return;
        }
    }

    /**
     *
     * @return true if this lock is closed, false otherwise
     */
    public boolean isClosed(){
        return this.isClosed;
    }

    /**
     *
     * @return the dial values as a single integer in the range 0-999, treating dial o as the ones digit
     */
    public int getDials(){
        return this.dialValue;
    }

    /**
     * Turns one of the dials up or down by a specified amount. if the given value of whichDial is any number other then 0, 1 or 2 this method does nothing. The howMuch parameter may be any positive or
     * negative integer and the resulting dial value should wrap modulo 10. For example, if dial o is 3, then after turnDial(0, 24), it should hav value 7, that is , (3+24) % 10. If dial o is 3, then after turnDial(0, -24)
     * it should have value 9. (Note that (3-24) % 10 is -1 in java, so 10 has to be added to get the value to wrap properly.)
     *
     * @param whichDial - whiich of thre dials to turn (0, 1, or  2)
     * @param howMuch - how many steps to turn the dial up or down
     */
    public void turnDial(int whichDial, int howMuch){
        int value[] = this.getNthDialValue();

        int newValue = (value[whichDial] + howMuch) % 10;
        if(newValue < 0){
            newValue -= 10;
        }
        value[whichDial] = newValue;

        this.dialValue = value[2] * 100 + value[1] * 10 + value[0];

        if(!isClosed){
            this.combination = this.dialValue;
        }
    }

    private int[] getNthDialValue(){
        int[] values = new int[3];
        values[0] = this.dialValue % 10;
        values[1] = (this.dialValue / 10) % 10;
        values[2] = (this.dialValue / 100) % 10;
        return values;
    }



}
