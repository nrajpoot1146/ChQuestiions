import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

public class Solution {
    private static JTextField editTextScore1; // text field for score 1
    private static JTextField editTextScore2; // text field for score 2
    private static JTextField editTextScore3; // text field for score 3
    private static JTextField textViewAverage; // text field for average
    private static JTextField textViewGrade;  // text field for grade
    public static void main(String... args){
        JLabel jLabel1 = new JLabel("Score 1"); // label for score 1
        JLabel jLabel2 = new JLabel("Score 2"); // label for score 2
        JLabel jLabel3 = new JLabel("Score 3"); // label for score 3
        JLabel jLabel4 = new JLabel("Average"); // label for average
        JLabel jLabel5 = new JLabel("Grade");   // label for grade

        // initialize text field variable;
        editTextScore1 = new JTextField(20);
        editTextScore1.setHorizontalAlignment(JTextField.CENTER);
        editTextScore2 = new JTextField(20);
        editTextScore2.setHorizontalAlignment(JTextField.CENTER);
        editTextScore3 = new JTextField(20);
        editTextScore3.setHorizontalAlignment(JTextField.CENTER);
        textViewAverage = new JTextField(20);
        textViewAverage.setHorizontalAlignment(JTextField.CENTER);
        textViewGrade = new JTextField(20);
        textViewGrade.setHorizontalAlignment(JTextField.CENTER);

        // disable editable average and grade textView
        textViewAverage.setEditable(false);
        textViewGrade.setEditable(false);

        // add label and textfield to jpanel
        JPanel jPanel = new JPanel();
        jPanel.add(jLabel1);
        jPanel.add(editTextScore1);

        jPanel.add(jLabel2);
        jPanel.add(editTextScore2);

        jPanel.add(jLabel3);
        jPanel.add(editTextScore3);

        jPanel.add(jLabel4);
        jPanel.add(textViewAverage);

        jPanel.add(jLabel5);
        jPanel.add(textViewGrade);

        JFrame jFrame = new JFrame();
        jFrame.setBounds(100, 100, 300, 200);
        jFrame.add(jPanel);
        jFrame.setResizable(false);
        jFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        jFrame.setVisible(true);


        // attach text change listeners
        editTextScore1.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                calGradeAverage();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                calGradeAverage();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                calGradeAverage();
            }
        });

        editTextScore2.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                calGradeAverage();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                calGradeAverage();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                calGradeAverage();
            }
        });

        editTextScore3.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                calGradeAverage();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                calGradeAverage();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                calGradeAverage();
            }
        });
    }

    /**
     * function to calculate grade and average
     * update grade and average to corresponding text fields
     */
    public static void calGradeAverage(){
        if (editTextScore1.getText().isEmpty() ||
                editTextScore2.getText().isEmpty() ||
                editTextScore3.getText().isEmpty()){
            textViewAverage.setText("");
            textViewGrade.setText("");
            return;
        }

        try {
            double score1 = Double.parseDouble(editTextScore1.getText());
            double score2 = Double.parseDouble(editTextScore2.getText());
            double score3 = Double.parseDouble(editTextScore3.getText());

            double average = (score1 + score2 + score3) / 3;
            String grade;

            if (average >= 90 && average <= 100){
                grade = "A+";
            } else if (average >= 90 && average < 90){
                grade = "A";
            } else if (average >= 70 && average < 80){
                grade = "B+";
            } else if (average >= 60 && average < 70){
                grade = "B";
            } else if (average > 60){
                grade = "B-";
            } else {
                grade = "fail";
            }

            textViewAverage.setText(String.format("%3.2f", average));
            textViewGrade.setText(grade);
        } catch (NumberFormatException e) {
            System.out.println(e.getMessage());
        }
    }
}
