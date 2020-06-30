import java.util.ArrayList;
import java.util.Arrays;

public class PlaylistEntry {
    public String title;
    public String artist;
    public int duration; //in seconds
    public Integer rating; //should be null if not rated
    public PlaylistEntry previous;
    public PlaylistEntry next;

    /**
     *
     * @param t (title)
     * @param a (artist)
     * @param d (duration as either mm:ss or hh:mm:ss)
     */
    public PlaylistEntry(String t, String a, String d) {
        this.title = t;
        this.artist = a;
        String[] s = d.split(":");
        this.duration = Integer.parseInt(s[0]) * 60 + Integer.parseInt(s[1]);
        this.rating = -1;
    }

    /**
     *
     * @param t (title)
     * @param a (artist)
     * @param d (duration as either mm:ss or hh:mm:ss)
     * @param r (rating)
     */
    public PlaylistEntry(String t, String a, String d, Integer r) {
        this.title = t;
        this.artist = a;
        String[] s = d.split(":");
        this.duration = Integer.parseInt(s[0]) * 60 + Integer.parseInt(s[1]);
        this.rating = r;
    }

    /**
     *
     * @param t (title)
     * @param a (artist)
     * @param d (duration) in seconds
     * @param r (rating)
     */
    public PlaylistEntry(String t, String a, int d, Integer r) {
        this.title  = t;
        this.artist = a;
        this.duration = d;
        this.rating = r;
    }

    /**
     * update the rating of the calling object
     * @param r: assign r to rating (constrained between 1 and 5)
     */
    public void rate(Integer r) {
        this.rating = r;
    }

    /**
     *
     * @param song
     * add an instance copy (and not a reference copy) of the passed song to the end of the list
     * for example,
     * let the ID shown in Eclipse during debug mode
     * for p be 110,
     * for p.next be 115,
     * for song be 120 and
     * for song.next be 125
     * if p.title = "a", p.next.title = "b"
     * song.title = "c", song.next.title = "d"
     *
     * p.addToEnd(song);
     *
     * should result in p.next.next.title = "c", p.title = "a", p.next.title = "b"
     * and p.next.next.next = null (not the song "d")
     * also, the ID shown in Eclipse for p.next should NOT be 120.
     * (because we are adding an instance copy)
     *
     * upon executing
     * p.next.next.title = "e"
     * should result in p.title = "a", p.next.title = "b", p.next.next.title = "e"
     *
     * song.title should still remain "c" (that's what it means by instance copy)
     */
    public void addToEnd(PlaylistEntry song) {
        PlaylistEntry current = this;
        while (current.next != null){
            current = current.next;
        }
        current.next = song;
    }

    /**
     *
     * @param song
     * add an instance copy (and not a reference copy) of the passed song to the front of the list
     * for example,
     * let the ID shown in Eclipse during debug mode
     * for p be 110,
     * for p.previous be 115,
     * for song be 120 and
     * for song.previous be 125
     * if p.title = "a", p.previous.title = "b"
     * song.title = "c", song.previous.title = "d"
     *
     * p.addToFront(song);
     *
     * should result in p.previous.previous.title = "c", p.title = "a", p.previous.title = "b" and
     * p.previous.previous.previous = null (not the song "d")
     * also, the ID shown in Eclipse for p.previous should NOT be 120.
     * (because we are adding an instance copy)
     *
     * upon executing
     * p.previous.previous.title = "e"
     * should result in p.title = "a", p.previous.title = "b", p.previous.previous.title = "e"
     *
     * song.title should still remain "c" (that's what it means by instance copy)
     */
    public void addToFront(PlaylistEntry song) {
        PlaylistEntry current = this;
        while (current.previous != null){
            current = current.previous;
        }
        current.previous = song;
    }

    /**
     *
     * @return the total duration (in seconds) of the playlist in which the calling object exists
     */
    public int totalDuration() {
        PlaylistEntry current = this;
        int sum=0;
        while (current != null){
            sum+=current.duration;
            current = current.next;
        }
        current = previous;

        while (current != null){
            sum+=current.duration;
            current = current.previous;
        }
        return sum;
    }

    /**
     *
     * @return the number of songs of the playlist in which the calling object exists
     */

    public int countSongs() {
        PlaylistEntry current = this;
        int sum=0;
        while (current != null){
            sum+=1;
            current = current.next;
        }
        current = previous;

        while (current != null){
            sum+=1;
            current = current.previous;
        }
        return sum;
    }

    /**
     *
     * @return index of the calling object in the list.
     * first song in the list is at index 0
     */
    public int indexOf() {
        int index = 0;
        PlaylistEntry current = this;
        while (current != null){
            index++;
            current = current.previous;
        }
        return index;
    }

    /**
     *
     * @return the first song in the list in which the calling object exists
     */
    public PlaylistEntry getFirstSong() {
        PlaylistEntry current = this;
        while (current.previous != null){
            current = current.previous;
        }
        return current;
    }

    /**
     *
     * @return the last song in the list in which the calling object exists
     */
    public PlaylistEntry getLastSong() {
        PlaylistEntry current = this;
        while (current.next != null){
            current = current.next;
        }
        return current;
    }

    /**
     *
     * @param targetTitle
     * @return index in the list (indices begin with 0) of the required song (-1 if it doesn't exist)
     */
    public int indexOf(String targetTitle) {
        PlaylistEntry first = this.getFirstSong();

        int i=0;
        while (first != null){
            if(first.title.equalsIgnoreCase(targetTitle)){
                return i;
            }
            i++;
            first = first.next;
        }

        return -1;
    }

    /**
     *
     * @param idx
     * @return song at given index (null if index invalid)
     */
    public PlaylistEntry get(int idx) {
        PlaylistEntry first = this.getFirstSong();

        int i=0;
        while (first != null){
            if(i == idx){
                return first;
            }
            i++;
            first = first.next;
        }
        return null;
    }

    /**
     *
     * @return string representation of the calling object only (not the whole list)
     */
    public String toStringIndividual() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Title: "+this.title);
        stringBuilder.append("Artist: "+this.artist);
        stringBuilder.append("Duration: "+this.duration);
        stringBuilder.append("Rating: "+this.rating);
        return stringBuilder.toString();
    }

    /**
     * get a string representation of the list in which the calling object exists
     * see JUnit tests about structure of returned String required
     */
    public String toString() {
        PlaylistEntry first = this.getFirstSong();
        ArrayList<String> arrayList = new ArrayList<String>();
        while (first != null){
            arrayList.add(first.title);
        }
        return Arrays.toString(arrayList.toArray());
    }

    /**
     *
     * @return top rated song in the list in which the calling object exists (null if all are unrated)
     */
    public Integer topRating() {
        PlaylistEntry current = this;
        int max = 0;
        while (current != null){
            if(current.rating > max){
                max = current.rating;
            }
            current = current.next;
        }

        current = current.previous;
        while (current != null){
            if(current.rating > max){
                max = current.rating;
            }
            current = current.previous;
        }
        if(rating == 0){
            return null;
        }
        return max;
    }

    /**
     *
     * @return string with list of all songs in the list in which the calling object exists that are top rated
     */
    public String listFavouriteSongs() {
        PlaylistEntry current = next;
        PlaylistEntry fav = this;
        while (current != null){
            if(current.rating > fav.rating){
                fav = current;
            }
            current = current.next;
        }

        current = current.previous;
        while (current != null){
            if(current.rating > fav.rating){
                fav = current;
            }
            current = current.previous;
        }

        return fav.title;
    }

    /**
     *
     * @param artist
     * @return number of songs by specified artist in the list in which the calling object exists
     */
    public int countSongsBy(String artist) {
        int count = 0;
        PlaylistEntry current = this;
        while (current != null){
            if(current.artist.equalsIgnoreCase(artist)){
                count++;
            }
            current = current.next;
        }

        current = current.previous;

        while (current != null){
            if(current.artist.equalsIgnoreCase(artist)){
                count++;
            }
            current = current.previous;
        }
        return count;
    }

    /**
     *
     * @param artist
     * @return an array containing the titles of all songs by given artist.
     * return null if there are no songs by the artist
     */
    public String[] getSongsBy(String artist) {
        ArrayList<String> arrayList = new ArrayList<String>();
        PlaylistEntry current = this;
        while (current.previous!=null){
            current = current.previous;
        }
        while (current != null){
            if(current.artist.equalsIgnoreCase(artist)){
                arrayList.add(current.title);
            }
            current = current.next;
        }
        String[] res = new String[arrayList.size()];
        if (arrayList.size() < 1){
            return null;
        }
        int i=0;
        for (String s : arrayList){
            res[i] = s;
            i++;
        }
        return res;
    }

    /**
     *
     * @param other
     * @return a list containing all songs in the list containing the calling object followed by
     * all songs in the list containing the parameter object. see JUnit tests to see more details
     */
    public PlaylistEntry merge(PlaylistEntry other) {
        PlaylistEntry first = this.getFirstSong();
        this.getLastSong().next = other.getFirstSong();
        other.getFirstSong().next = this.getLastSong();
        PlaylistEntry last = other.getLastSong();
        return first;
    }
}