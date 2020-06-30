import java.util.ArrayList;

public class Statistics {
    public static Integer[] getLowest(Student[] students){
        ArrayList<Integer> lowest = new ArrayList<Integer>();

        for(Student s : students){
            ArrayList<Integer> quizScores = s.getQuizScores();
            if(lowest.size() == 0) {
                for (Integer score : quizScores) {
                    lowest.add(score);
                }
            }else {
                for (int i = 0; i < quizScores.size(); i++) {
                    if (lowest.get(i) > quizScores.get(i)){
                        lowest.set(i, quizScores.get(i));
                    }
                }
            }
        }

        return lowest.toArray(new Integer[lowest.size()]);
    }

    public static Integer[] getHighest(Student[] students){
        ArrayList<Integer> highest = new ArrayList<Integer>();

        for(Student s : students){
            ArrayList<Integer> quizScores = s.getQuizScores();
            if(highest.size() == 0) {
                for (Integer score : quizScores) {
                    highest.add(score);
                }
            }else {
                for (int i = 0; i < quizScores.size(); i++) {
                    if (highest.get(i) < quizScores.get(i)){
                        highest.set(i, quizScores.get(i));
                    }
                }
            }
        }

        return highest.toArray(new Integer[highest.size()]);
    }

    public static Double[] getAverage(Student[] students){
        ArrayList<Double> average = new ArrayList<Double>();

        for(Student s : students){
            ArrayList<Integer> quizScores = s.getQuizScores();
            if(average.size() == 0) {
                for (Integer score : quizScores) {
                    average.add(Double.valueOf(score));
                }
            }else {
                for (int i = 0; i < quizScores.size(); i++) {
                    average.set(i, average.get(i) + quizScores.get(i));
                }
            }
        }
        int len = students.length;
        for ( int i = 0; i<average.size(); i++){
            average.set(i, average.get(i)/len);
        }

        return average.toArray(new Double[average.size()]);
    }
}
