import java.lang.reflect.Constructor;
import java.lang.reflect.Modifier;
import java.util.Arrays;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;

public class ColourTest {
private static String INVALID_ARG_MESSAGE = "invalid arg message";
    @Test
    public void restrictiveInstantiation() {
        Constructor<?>[] constructors = Colour.class.getDeclaredConstructors();
        Arrays.stream(constructors)
                .map(constructor -> Modifier.isPrivate(constructor.getModifiers()))
                .forEach(Assertions::assertTrue);
    }

    @Test
    public void  fromRGB(){
        Colour white = Colour.fromRGB(255, 255, 255);
        Colour black = Colour.fromRGB(0, 0, 0);
        Colour green = Colour.fromRGB(0, 255, 0);

        Assertions.assertEquals(white, Colour.fromRGB(255, 255, 255));
        Assertions.assertEquals(black, Colour.fromRGB(0, 0, 0));
        Assertions.assertEquals(green, Colour.fromRGB(0, 255, 0));
    }

    @Test
    public void invalidArguments(){
        Throwable exceptionA = Assertions
                .assertThrows(IllegalArgumentException.class, () -> Colour.fromRGB(-1, 0, 0));
        Assertions.assertEquals(exceptionA.getMessage(), INVALID_ARG_MESSAGE);
        Assertions.assertEquals(exceptionA.getMessage(), INVALID_ARG_MESSAGE);
    }
}
