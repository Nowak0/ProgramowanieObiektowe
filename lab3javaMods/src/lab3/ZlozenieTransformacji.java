package lab3;
import java.util.Arrays;

public class ZlozenieTransformacji implements Transformacja {
    private final Transformacja[] tab;

    public ZlozenieTransformacji(int n) {
        tab = new Transformacja[n];
    }

    public Transformacja[] getTab() {
        return tab.clone();
    }

    public void setTab(int i, Transformacja value) {
        if(i<tab.length) this.tab[i] = value;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
        ZlozenieTransformacji t = new ZlozenieTransformacji(tab.length);
        int j = tab.length - 1;
        for(int i = j ;i>=0;i--) {
            t.setTab(j-i, tab[i].getTransformacjaOdwrotna());
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
