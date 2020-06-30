public class Driver {

    public static void main(String[] args){
        DialerLock dialerLock = DialerLock.ComboLock(); // create a new dialer instance

        System.out.println("Initially:");
        System.out.println("Locked = "+dialerLock.isLocked()); // check initial locked status
        System.out.println("Open = "+ !dialerLock.isClosed()); // check initial open status

        dialerLock.turnDial(0, 4); // turn the dialler 0 with 4 times up
        dialerLock.turnDial(1, 4); // turn the dialler 1 with 4 times up
        dialerLock.turnDial(2, 8); // turn the dialler 1 with 8 times up

        System.out.println("Dials value = "+dialerLock.getDials()); // check dialer values
        // close the lock

        System.out.println("\nafter closing the lock");
        dialerLock.close();

        System.out.println("Open = "+ !dialerLock.isClosed()); // check close status

        dialerLock.turnDial(0, 5); // turn the dialler 0 with 5 times up
        dialerLock.turnDial(1, 5); // turn the dialler 1 with 5 times up
        dialerLock.turnDial(2, 6); // turn the dialler 2 with 6 times up

        System.out.println("Locked = "+dialerLock.isLocked()); // check lock status, status should be true

        System.out.println("Dials value = "+dialerLock.getDials()); // get dialer value

        System.out.println("\nTried to open lock when lock is locked, open status should be false");
        dialerLock.open(); // tried to open lock when lock is locked
        System.out.println("Open = "+ !dialerLock.isClosed()); // check open status status should be false

        dialerLock.turnDial(0, -5); // turn the dialler 0 with 5 times down
        dialerLock.turnDial(1, -5); // turn the dialler 1 with 5 times down
        dialerLock.turnDial(2, 4);  // turn the dialler 2 with 4 times up

        System.out.println("\nAfter unlocking the lock: ");
        System.out.println("Locked = "+dialerLock.isLocked()); // check lock status, status should be false
        dialerLock.open(); // open lock
        System.out.println("Open = "+ !dialerLock.isClosed()); // check open status, status should be true
    }
}
