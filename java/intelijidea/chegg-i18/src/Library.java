import java.util.LinkedList;
import java.util.List;

public class Library implements ILibrary{
    private List<Item> itemList;

    Library(){
        this.itemList = new LinkedList<Item>();
    }

    @Override
    public void addItem(Item item) {
        for (int i = 0; i < this.itemList.size(); i++ ){
            Item itemTemp = this.itemList.get(i);
            if(itemTemp.getCallNumber().equals(item.getCallNumber())){
                itemTemp.setCopyNo(itemTemp.getCopyNo() + 1);
                return;
            }
        }

        itemList.add(item);
    }

    @Override
    public List<Item> getItems() {
        return this.itemList;
    }

    @Override
    public boolean deleteItem(String callNumber, int copy) {

        for (int i = 0; i<this.itemList.size(); i++){
            Item item = this.itemList.get(i);
            if (item.getCallNumber().equals(callNumber) ){
                if( item.getCopyNo() <= copy){
                    itemList.remove(i);
                    return true;
                }else if(item.getCopyNo() > copy){
                    item.setCopyNo(item.getCopyNo() - copy);
                    return true;
                }
            }
        }

        return false;
    }

    @Override
    public boolean checkOut(String callNumber, int copy, String borrower) {
        List<Item> list = this.findItems(callNumber);
        if(list == null){
            return false;
        }
        Item item = list.get(0);
        if(copy >= item.getCopyNo()){
            item.setCopyNo(0);
            item.addBorrower(borrower);
            return true;
        }
        item.setCopyNo(item.getCopyNo()-copy);
        item.addBorrower(borrower);
        return true;
    }

    @Override
    public boolean checkIn(String callNumber, int copy) {
        List<Item> list = this.findItems(callNumber);
        if(list == null){
            return false;
        }
        Item item = list.get(0);
        item.setCopyNo(item.getCopyNo()+copy);
        return true;
    }

    @Override
    public List<Item> findItems(String callNumber) {

        for (int i =0 ; i<this.itemList.size(); i++){
            if(this.itemList.get(i).getCallNumber().equals(callNumber)){
                List<Item> temp = new LinkedList<Item>();
                temp.add(this.itemList.get(i));
                return temp;
            }
        }
        return null;
    }
}
