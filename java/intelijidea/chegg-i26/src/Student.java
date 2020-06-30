import java.util.ArrayList;

public class Student {
    private int id;
    private ArrayList<Integer> quizScores;

    Student(int id){
        this.id = id;
        quizScores = new ArrayList<Integer>();
    }

    public int getId() {
        return id;
    }

    public ArrayList<Integer> getQuizScores() {
        return quizScores;
    }

    public void addQuizScore(int score){
        this.quizScores.add(score);
    }
}
