import java.awt.*;

public class Profile {
    private int id;
    private String name;
    private Image image;
    private OnlineStatus onlineStatus;

    private ListOfFriends listOfFriends;
    Profile(int id, String name, short status){
        this.listOfFriends = new ListOfFriends();
        this.listOfFriends.setProfile(this);
        this.name = name;
        this.id = id;
        this.image = null;
        onlineStatus = new OnlineStatus(status);
    }

    public OnlineStatus getOnlineStatus() {
        return onlineStatus;
    }

    public Image getImage() {
        return image;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public ListOfFriends getListOfFriends() {
        return listOfFriends;
    }

    public void setImage(Image image) {
        this.image = image;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setOnlineStatus(OnlineStatus onlineStatus) {
        this.onlineStatus = onlineStatus;
    }

    public void print(){
        System.out.println("Id: "+this.id);
        System.out.println("Name: "+this.name);
        System.out.println("Online Status: "+this.onlineStatus.getStatusString());
        System.out.println("Friends: "+this.listOfFriends.getSize());
    }
}

class OnlineStatus{
    public static short ONLINE = 1;
    public static short OFFLINE = 0;
    public static short BUSY = 2;

    short status;
    OnlineStatus(short staus){
        this.status = staus;
    }

    public short getStatus() {
        return status;
    }

    public void setStatus(short status) {
        this.status = status;
    }

    public String getStatusString(){
        if(this.status == OnlineStatus.ONLINE){
            return "online";
        }else if(this.status == OnlineStatus.OFFLINE){
            return "offline";
        }else{
            return "busy";
        }
    }
}
