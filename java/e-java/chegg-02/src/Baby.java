public class Baby {
    private boolean crying;
    private boolean full;
    private boolean diaperChanged;
    private int eatCount;
    private int dailyEatCount;
    private int poopCount;
    private int peeCount;
    private static int diaperCount;

    /**
     * constructor
     */
    public Baby() {
        this.crying = true;
        this.full = false;
        this.diaperChanged = false;
    }

    /**
     * constructor with diaperCount as a parameter
     */
    public Baby(int diaperCount) {
        this.crying = true;
        this.full = false;
        this.diaperChanged = false;
        Baby.diaperCount = diaperCount;
    }

    /**
     * setting initialDiaperCount
     * 
     * @param initialDiaperCount this is the initialized diaper count when creating
     *                           a baby
     */
    public void setDiaperCount(int initialDiaperCount) {
        /* your code goes here */
    	Baby.diaperCount = initialDiaperCount;
    }

    /**
     * adding eatCount adding dailyEatCount setting full to true if eatCount >= 2
     * setting full to false if eatCount >3 and eatCount to 0
     */
    public void isEating() {
        /* your code goes here */
    	this.eatCount +=1;
    	this.dailyEatCount +=1;
    	if(this.eatCount>=2)
    		this.full = true;
    	if(this.eatCount>3) {
    		this.full=false;
    		this.eatCount = 0;
    	}
    }

    /**
     * returning eatCount
     */
    public int getEatCount() {
        /* your code goes here */
    	return this.eatCount;

    }

    /**
     * returning dailyEatCount
     */
    public int getDailyEatCount() {
        /* your code goes here */
    	return this.dailyEatCount;
    }

    /**
     * checking if baby isFull - eatCount >= 2 resets eatCount to 0 and crying to
     * false
     * 
     * @return true or false
     */
    public boolean isFull() {
        /* your code goes here */
    	if(this.eatCount>=2) {
    		this.eatCount = 0;
    		this.crying=false;
    	}
    	return this.full;
    }

    /**
     * adding 1 poopCount subtracting 1 from diaperCount changing crying to true
     * changing diaperChanged to false prints out “no more diapers if diaperCount <
     * 0
     * 
     */
    public void isPooping() {
        /* your code goes here */
    	this.poopCount +=1;
    	Baby.diaperCount -=1;
    	this.crying = true;
    	this.diaperChanged = false;
    	if(this.getDiaperCount()<0) {
    		System.out.println("no more diapers");
    	}
    }

    /**
     * returns poopCount
     * 
     * @return poopCount
     */
    public int getPoopCount() {
        /* your code goes here */
    	return this.poopCount;
    }

    /**
     * adding 1 to peeCount subtracting 1 from diaperCount changing crying to true
     * changing diaperChanged to false
     * 
     * prints out “no more diapers if diaperCount < 0
     */
    public void isPeeing() {
        /* your code goes here */
    	this.peeCount +=1;
    	Baby.diaperCount -=1;
    	this.crying = true;
    	this.diaperChanged = false;
    	if(Baby.diaperCount<0) {
    		System.out.println("no more diaper");
    	}
    }

    /**
     * return peeCount
     * 
     * @return peeCount
     */
    public int getPeeCount() {
        /* your code goes here */
    	return this.peeCount;
    }

    /**
     * return diaperCount
     * 
     * @return diaperCount
     */
    public int getDiaperCount() {

        /* your code goes here */
    	return Baby.diaperCount;
    }

    /**
     * checks to see if isFull and diaperChanged is true or false
     * 
     * @return true or false depending on baby crying
     */
    public boolean isCrying() {
        /* your code goes here */
    	if(this.isFull() && this.diaperChanged) {
    		this.crying = false;
    	}else {
    		this.crying = true;
    	}
    	return this.crying;
    }

    /**
     * changes the value of diaperChanged to true and crying to false
     */
    public void setDiaperChanged() {
    	this.diaperChanged = true;
    	this.crying = false;
        /* your code goes here */
    }
}