import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class EmailFromFile {
    private Map<String, String> map;
    private String filename;

    /**
     *
     * @param filename name of file in which emails are stored
     */
    EmailFromFile(String filename){
        this.filename = filename;
        map = new HashMap<String, String>();
    }

    /**
     *
     * @return comma separate string of email
     * @throws IOException if any occur
     */
    public String getCommaSeparateEmails() throws IOException {
        File f = new File(this.filename); // open file of emails

        FileInputStream fin = new FileInputStream(f); // input stream to read data from file
        BufferedReader br = new BufferedReader(new InputStreamReader(fin));
        String line = null;

        StringBuilder res = new StringBuilder(); // String builder to store comma separate emails

        while ( (line = br.readLine()) != null){
            String[] strings = line.split(" ");
            String name = strings[1] + " "+ strings[2];
            String email = strings[3].substring(1,strings[3].length()-1);
            if(!map.containsKey(name)){
                map.put(name, email);
                if(res.length() == 0){
                    res.append(email);
                }else
                    res.append(","+email);
            }
        }

        return res.toString();
    }
}
