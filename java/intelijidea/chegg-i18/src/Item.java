import java.util.LinkedList;
import java.util.List;

public class Item {
    public static int ID = 0;

    private int id;
    private String callNumber;
    private int copyNo;

    private List<String> bList;

    Item(String callNumber, int copyNo){
        this.id = ++ID;
        this.callNumber = callNumber;
        this.copyNo = copyNo;
        this.bList = new LinkedList<String>();
    }

    Item(String callNumber){
        this.id = ++ID;
        this.callNumber = callNumber;
        this.copyNo = 1;
        this.bList = new LinkedList<String>();
    }

    public int getId() {
        return id;
    }

    public int getCopyNo() {
        return copyNo;
    }

    public String getCallNumber() {
        return callNumber;
    }

    public void setCopyNo(int copyNo) {
        this.copyNo = copyNo;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setCallNumber(String callNumber) {
        this.callNumber = callNumber;
    }

    public void addBorrower(String borrower){
        for (int i=0; i<this.bList.size(); i++){
            if(this.bList.get(i).equals(borrower)){
                return;
            }
        }
        this.bList.add(borrower);
    }
    public void removeBorrower(String borrower){
        for (int i=0; i<this.bList.size(); i++){
            if(this.bList.get(i).equals(borrower)){
                this.bList.remove(i);
            }
        }
    }
}
