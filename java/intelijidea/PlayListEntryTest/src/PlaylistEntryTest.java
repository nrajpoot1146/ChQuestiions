import static org.junit.jupiter.api.Assertions.*;

import java.io.IOException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;

import org.junit.jupiter.api.*;

class PlaylistEntryTest {
    public static String currentMethodName = null;
    public static int score = 0;
    public static String result = "";
    PlaylistEntry playlist1, playlist2, playlist3;
    public static ArrayList<String> methodsPassed = new ArrayList<String>();

    @BeforeEach
    public void run() {
        currentMethodName = null;
        playlist1 = new PlaylistEntry("Song1", "Artist1", "3:01", 4);

        playlist1.next = new PlaylistEntry("Song2", "Artist2", "1:3:02", 2);
        playlist1.next.previous = playlist1;

        playlist1.next.next = new PlaylistEntry("Song3", "Artist1", "3:03", 5);
        playlist1.next.next.previous = playlist1.next;

        playlist1.next.next.next = new PlaylistEntry("Song4", "Artist2", "3:04", 5);
        playlist1.next.next.next.previous = playlist1.next.next;

        playlist1.next.next.next.next = new PlaylistEntry("Song5", "Artist1", "3:05", 3);
        playlist1.next.next.next.next.previous = playlist1.next.next.next;

        playlist2 = new PlaylistEntry("Song6", "Artist3", "4:01", 1);

        playlist2.next = new PlaylistEntry("Song7", "Artist3", "4:02", 1);
        playlist2.next.previous = playlist2;

        playlist2.next.next = new PlaylistEntry("Song8", "Artist3", "3:07", 1);
        playlist2.next.next.previous = playlist2.next;

        playlist2.next.next.next= new PlaylistEntry("Song9", "Artist3", "4:16", 1);
        playlist2.next.next.next.previous = playlist2.next.next;

        playlist2.next.next.next.next= new PlaylistEntry("Song10", "Artist3", "4:05", 1);
        playlist2.next.next.next.next.previous = playlist2.next.next.next;

        playlist2.next.next.next.next.next= new PlaylistEntry("Song11", "Artist3", "3:07", 1);
        playlist2.next.next.next.next.next.previous = playlist2.next.next.next.next;

        playlist2.next.next.next.next.next.next= new PlaylistEntry("Song12", "Artist3", "4:12", 1);
        playlist2.next.next.next.next.next.next.previous = playlist2.next.next.next.next.next;

        playlist2.next.next.next.next.next.next.next= new PlaylistEntry("Song13", "Artist3", "4:35", 1);
        playlist2.next.next.next.next.next.next.next.previous = playlist2.next.next.next.next.next.next;

        playlist3 = new PlaylistEntry("Song12", "Artist3", "4:01");

        playlist3.next = new PlaylistEntry("Song13", "Artist3", "4:02");
        playlist3.next.previous = playlist3;

        playlist3.next.next = new PlaylistEntry("Song14", "Artist3", "4:35");
        playlist3.next.next.previous = playlist3.next;
    }

    @Test //@Graded(description="getSongsByStringBasic", marks=8)
    public void testGetSongsByStringBasic() {
        assertNotNull(Arrays.toString(playlist2.getSongsBy("Artist3")));
        assertEquals("[Song6, Song7, Song8, Song9, Song10, Song11, Song12, Song13]", Arrays.toString(playlist2.getSongsBy("Artist3")));
        assertNotNull(Arrays.toString(playlist3.getSongsBy("Artist3")));
        assertEquals("[Song12, Song13, Song14]", Arrays.toString(playlist3.getSongsBy("Artist3")));
        assertNull(playlist1.getSongsBy("Artist3"));
        assertNotNull(playlist1.getSongsBy("Artist1"));
        assertEquals("[Song1, Song3, Song5]", Arrays.toString(playlist1.getSongsBy("Artist1")));
        currentMethodName = new Throwable().getStackTrace()[0].getMethodName();
    }

    @Test //@Graded(description="getSongsByStringAdvanced", marks=2)
    public void testGetSongsByStringAdvanced() {
        testGetSongsByStringBasic();
        assertNotNull(Arrays.toString(playlist2.next.next.next.next.getSongsBy("artist3")));
        assertEquals("[Song6, Song7, Song8, Song9, Song10, Song11, Song12, Song13]", Arrays.toString(playlist2.next.next.next.next.getSongsBy("Artist3")));
        assertNotNull(Arrays.toString(playlist3.next.getSongsBy("artist3")));
        assertEquals("[Song12, Song13, Song14]", Arrays.toString(playlist3.next.getSongsBy("Artist3")));
        assertNull(playlist1.next.next.getSongsBy("Artist3"));
        assertNotNull(playlist1.next.next.getSongsBy("Artist1"));
        assertEquals("[Song1, Song3, Song5]", Arrays.toString(playlist1.next.next.getSongsBy("Artist1")));
        currentMethodName = new Throwable().getStackTrace()[0].getMethodName();
    }


    @AfterAll
    public static void wrapUp() throws IOException {
        if(result.length() != 0) {
            result = result.substring(0, result.length()-1); //remove the last "\n"
        }
        System.out.println("Indicative score: "+score);
        System.out.println(result);
    }
}

