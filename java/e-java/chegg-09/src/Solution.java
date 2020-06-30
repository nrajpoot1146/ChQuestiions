import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * java code.
 * @author naren
 *
 */
public class Solution {
	
	/**
	 * 
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		
		File f = new File("tag.txt");
		@SuppressWarnings("resource")
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
		
		String line = "";
		while((line = br.readLine()) !="" && line != null) {
			String[] words = line.split(" ");
			
			String res = "";
			
			for(int i=0; i<words.length; i++) {
				if(words[i].contains(",")){
					words[i] = words[i].substring(0,words[i].length()-1);
				}
				if(words[i].startsWith("#") && !words[i-1].equals("TRAP")) {
					res += "\"#\"";
				}else if(words[i].startsWith("#")) {
					res+= "\""+words[i]+"\"";
				}else if(words[i].startsWith("$")) {
					res+="\"$\"";
					res+="\""+words[i].substring(1)+"\"";
				}else {
					res += "\""+words[i]+"\"";
				}
			}
			
			System.out.println(res);
		}
	}

}
