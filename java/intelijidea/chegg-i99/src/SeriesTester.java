public class SeriesTester {
    public static void main(String[] args) throws NonNegativeNumber {

        // four object of series class
        Series[] series = new Series[4];
        series[0] = new ByTwos(2);
        series[1] = new ByTwos(5);
        series[2] = new ByThree(2);
        series[3] = new ByThree(5);

        // object of series container class
        SeriesContainer seriesContainer = new SeriesContainer(5,4);
        for (int i=0; i<4; i++){
            seriesContainer.addSeries(series[i]);
        }

        // print output
        System.out.println(seriesContainer.toString());
    }
}
