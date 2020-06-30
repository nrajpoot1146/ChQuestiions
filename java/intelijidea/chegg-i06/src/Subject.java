public class Subject {
    private int id;
    private String name;

    Subject(int id, String name){
        this.id = id;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void print(){
        System.out.println("Id: "+this.id);
        System.out.println("Name: "+this.name);
        System.out.println();
        System.out.println();
    }
}
