import java.io.*;

public class Driver {
    public static void main(String[] args) throws IOException {
        File f = new File("input.txt");

        FileInputStream fileInputStream = new FileInputStream(f);
        BufferedReader br = new BufferedReader(new InputStreamReader(fileInputStream));
        String line = null;

        Train train = new Train();

        while ((line = br.readLine()) != null){
            System.out.println("Processing command: "+line);
            if(line.startsWith("PICKUP")){
                int n = Integer.parseInt(line.substring(line.indexOf(' ')+1));
                int engineC = 0;
                int carC = 0;
                for (int i=0; i<n; i++){
                    String cars = br.readLine();
                    if(cars.equalsIgnoreCase("engine")){
                        train.addEngine(new Node("engine"));
                        engineC++;
                    }else{
                        String[] temp = cars.split(" ");
                        Node newNode = new Node(temp[0], Double.parseDouble(temp[1]));
                        train.add(newNode);
                        carC++;
                    }
                }
                System.out.println(engineC+" engines and "+carC+" cars added to train");

            }else if (line.startsWith("DROPLAST")){
                int n = Integer.parseInt(line.substring(line.indexOf(" ")+1));
                train.dropLast(n);
            }else if (line.startsWith("DROPFIRST")){
                int n = Integer.parseInt(line.substring(line.indexOf(" ")+1));
                train.dropFirst(n);
            }else if (line.startsWith("DROP")){
                String temp = line.substring(line.indexOf(' ')+1);
                String[] data = temp.split(" ");
                train.drop(data[0], Integer.parseInt(data[1]));
            }else if (line.startsWith("PRINT")){
                int[] count = train.getCount();
                System.out.println("Total number of engines: " + count[0] + ", " +
                        "Total number of cargo cars: "+count[1]+", " +
                        "Total value of cargo: $"+count[2]);
                System.out.println("The cars on the train are: "+train.toString());
            }
        }
    }
}
