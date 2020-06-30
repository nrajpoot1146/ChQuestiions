import java.io.*;
import java.util.ArrayList;

public class util {
    public static Student[] readFromFile(String fileName) throws IOException {
        File file = new File(fileName);
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        String line = null;
        ArrayList<Student> students = new ArrayList<Student>();
        while ( (line = br.readLine()) != null){
            String[] data = line.split(" ");
            Student student = new Student(Integer.parseInt(data[0]));
            for (int i = 1; i< data.length; i++){
                student.addQuizScore(Integer.parseInt(data[i]));
            }
            students.add(student);
        }
        return students.toArray(new Student[students.size()]);
    }
}
