public class Main {
    public static void main(String[] args){
        SocialNetwork socialNetwork = new SocialNetwork("New Network");

        socialNetwork.addProfile(socialNetwork.createProfile("narendra", OnlineStatus.ONLINE));
        socialNetwork.addProfile(socialNetwork.createProfile("sumesh", OnlineStatus.ONLINE));

        socialNetwork.getProfile(1).getListOfFriends().addFriend(socialNetwork.getProfile(2));
        socialNetwork.getProfile(2).setOnlineStatus(new OnlineStatus(OnlineStatus.OFFLINE));

        socialNetwork.getProfile(1).print();
        socialNetwork.getProfile(2).print();

        System.out.println("Before removing a user.");
        socialNetwork.print();
        socialNetwork.removeProfile(1);
        System.out.println("After removing a user.");
        socialNetwork.print();
    }
}
