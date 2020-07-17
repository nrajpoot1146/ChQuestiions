import java.time.LocalDate;
import java.time.Period;
import java.util.Arrays;

/**
 * A horse, of course.
 *
 */
public class Horse implements Common{
    /**
     * The name of this horse.
     */
    public String name;

    private final String breed;
    private final LocalDate born;

    public static final int[] PONY_STALL_SIZE = { 200, 100, 200 };
    public static final int[] LARGE_STALL_SIZE = { 400, 300, 400 };
    public static final int[] STANDARD_STALL_SIZE = { 400, 200, 300 };

    /**
     * Create a record for a horse that was just born.
     * @param breed horse breed (in lower case)
     */
    public Horse(String breed) {
        this(breed, null, LocalDate.now());
    }

    /**
     * Create a record for a Horse that was born some time ago.
     * @param breed horse breed (in lower case)
     * @param name name of the horse
     * @param born date the horse was born
     */
    public Horse(String breed, String name, LocalDate born) {
        this.breed = breed;
        this.name = name;
        this.born = born;
    }

    /**
     * Whether or not the given breed is described as a "pony"
     * @param breed horse breed (in lower case)
     * @return true if the breed is classified as a pony
     */
    public static boolean isPony(String breed) {
        switch (breed) {
            case "shetland":
            case "guoxia":
            case "danish sport":
                return true;
            default:
                return false;
        }
    }

    /**
     * Get the age (in years) of this horse.
     * @return number of years old
     */
    public int getAge() {
        return Period.between(LocalDate.now(), born).getYears();
    }

    /**
     * Get the minimum size of stall needed to stable this horse.
     * @return a 3-dimensional array of measurements in centimeters
     */
    @Override
    public String size() {
        if (Horse.isPony(this.breed)) {
            return Arrays.toString(PONY_STALL_SIZE);
        } else {
            switch (breed) {
                case "arabian":
                    return Arrays.toString(LARGE_STALL_SIZE);
                default:
                    return Arrays.toString(STANDARD_STALL_SIZE);
            }
        }
    }

    /**
     * Horses do not necessarily need electricity in their stables.
     * @return false
     */
    @Override
    public boolean needsElectricity() { return false; }

    /**
     * Since horses are living creatures, they all need a source of water to survive.
     * @return true
     */
    @Override
    public boolean needsWater() { return true; }

    /**
     * Whether or not this breed requires a heated stable.
     * @return true if the this horse breed is known to have poor health
     *     outcomes in unheated stables.
     */
    public boolean needsHeat() {
        return Horse.isPony(this.breed);
    }
}