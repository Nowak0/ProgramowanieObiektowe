package lab3;
import java.util.Arrays;

public class ZlozenieTransformacji implements Transformacja {
    private final Transformacja[] tab;

    public ZlozenieTransformacji(int n) {
        tab = new Transformacja[n];
    }

    public Transformacja[] getTab() {
        return tab;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
        ZlozenieTransformacji t = new ZlozenieTransformacji(tab.length);
        for(int i=0;i< tab.length;i++) {
            t.getTab()[i] = tab[i].getTransformacjaOdwrotna();
        }
        return t;
    }

    @Override
    public Punkt transformuj(Punkt p) {
        for (Transformacja t : tab) {
            p = t.transformuj(p);
        }
       return p;
    }

    @Override
    public String toString() {
       return "Tablica z transformacjami: "+ Arrays.toString(tab);
    }
}
