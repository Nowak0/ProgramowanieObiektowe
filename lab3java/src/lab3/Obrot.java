package lab3;
import java.lang.Math;

public class Obrot implements Transformacja {
    private final double xp,yp;

    public Obrot(double givenX, double givenY) {
        double alfa = givenY / givenX;
        this.xp = givenX*Math.cos(alfa) - givenY*Math.sin(alfa);
        this.yp = givenX*Math.sin(alfa) + givenY*Math.cos(alfa);
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() {
        return new Obrot(xp, yp);
    }

    @Override
    public Punkt transformuj(Punkt p) {
        return new Punkt(xp,yp);
    }

    public double getXP() {
        return xp;
    }

    public double getYP() {
        return yp;
    }

    @Override
    public String toString() {
        return "Obrot o wektor {"+xp+", "+yp+")";
    }
}
