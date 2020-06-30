
public class ListOfFriends {
    private ArrayList<Profile> arrayList;
    private Profile profile;
    ListOfFriends(){
        this.arrayList = new ArrayList<Profile>();
    }

    public void addFriend(Profile profile){
        if(this.getFriend(profile.getId()) == null) {
            this.arrayList.add(profile);
            profile.getListOfFriends().addFriend(this.getProfile());
        }
    }

    public boolean removeFriend(int id){
        for(int i=0; i<this.arrayList.size(); i++){
            if(this.arrayList.get(i).getId() == id){
                this.arrayList.remove(i);
                return true;
            }
        }
        return false;
    }

    public Profile getFriend(int id){
        for(int i=0; i<this.arrayList.size(); i++){
            if(this.arrayList.get(i).getId() == id){
                return this.arrayList.get(i);
            }
        }
        return null;
    }

    public int getSize(){
        return this.arrayList.size();
    }

    public void setProfile(Profile profile) {
        this.profile = profile;
    }

    public Profile getProfile() {
        return profile;
    }
}
