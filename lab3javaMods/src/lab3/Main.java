package lab3;
import java.util.Scanner;

public class Main {

    public static final Punkt p1 = new Punkt(1,1);

    public static void mod1() throws BrakTransformacjiOdwrotnejException {
        //final Punkt p1 = new Punkt(1,1);
        Transformacja trans = new Translacja(p1.getX(),p1.getY());
        Transformacja obrot = new Obrot(30);
        Transformacja skalowanie = new Skalowanie(p1.getX(),p1.getY());
        Punkt p2;

        //System.out.println(p2);
    }


    public static void mod2() {
        try {
            Punkt p1 = new Punkt(3,3);
            ZlozenieTransformacji t = new ZlozenieTransformacji(3);
            t.setTab(0, new Translacja(5,5));
            t.setTab(1, new Obrot(30));
            t.setTab(2, new Skalowanie(2,10));

            System.out.println(p1.equals(t.getTransformacjaOdwrotna().transformuj(t.transformuj(p1))));
        }
        catch (BrakTransformacjiOdwrotnejException ex) {
            ex.printStackTrace();
        }
    }


    public static void main(String[] args) throws BrakTransformacjiOdwrotnejException {
        mod2();

    }
}
