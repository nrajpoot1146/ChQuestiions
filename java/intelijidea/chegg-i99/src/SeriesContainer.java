public class SeriesContainer {
    private Series[] series;
    private int numOfSeries;
    private int numOfTimes;

    SeriesContainer(int numOfTimes, int size) throws NonNegativeNumber {
        if (numOfTimes < 0){
            throw new NonNegativeNumber("Error: number of times should be a positive number!");
        }
        this.numOfTimes = numOfTimes;
        this.series = new Series[size];
        this.numOfSeries = 0;
    }

    public void addSeries(Series series){
        if (this.numOfSeries == this.series.length){
            return;
        }
        this.series[this.numOfSeries] = series;
        this.numOfSeries++;
    }

    @Override
    public String toString() {
        String res = "";
        for (int i=0; i<this.numOfSeries; i++){
            for (int j=0; j<this.numOfTimes; j++){
                res += " " + this.series[i].getNext();
            }
            res += "\n";
        }
        return res;
    }
}
