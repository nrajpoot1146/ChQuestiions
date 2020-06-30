

public class SocialNetwork {
    private ArrayList<Profile> users;
    private String netWorkName;
    int count;
    SocialNetwork(String netWorkName){
        this.netWorkName = netWorkName;
        users = new ArrayList<Profile>();
        this.count = 0;
    }

    public Profile createProfile(String name, short status){
        this.count++;
        Profile profile = new Profile(this.count, name, status);
        return profile;
    }

    public void addProfile(Profile profile){
        this.users.add(profile);
    }

    public Profile getProfile(int id){
        for(int i=0; i<this.users.size(); i++){
            if(id == this.users.get(i).getId()){
                return this.users.get(i);
            }
        }
        return null;
    }

    public boolean removeProfile(int id){
        for(int i=0; i<this.users.size(); i++){
            if(id == this.users.get(i).getId()){
                this.users.remove(i);
                return true;
            }
        }
        return false;
    }

    public String getNetWorkName() {
        return netWorkName;
    }

    public void print(){
        System.out.println("Network Name: "+this.netWorkName);
        System.out.println("Total user: "+this.users.size());
    }
}