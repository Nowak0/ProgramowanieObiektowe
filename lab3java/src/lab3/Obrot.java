package lab3;
import java.lang.Math;

public class Obrot implements Transformacja {
    private final double alfa;

    public Obrot(double alfa) {
        this.alfa = alfa;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() {
        return new Obrot(-alfa);
    }

    @Override
    public Punkt transformuj(Punkt p) {
        double xp = p.getX()*Math.cos(alfa) - p.getY()*Math.sin(alfa);
        double yp = p.getX()*Math.sin(alfa) + p.getY()*Math.cos(alfa);
        return new Punkt(xp,yp);
    }

    public double getAlfa() {
        return alfa;
    }

    @Override
    public String toString() {
        return "Obrot o kat alfa = "+alfa;
    }
}
