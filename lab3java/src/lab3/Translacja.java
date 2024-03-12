package lab3;

public class Translacja implements Transformacja {
    private final double dX, dY;

    public Translacja(double givenDX, double givenDY) {
        this.dX = givenDX;
        this.dY = givenDY;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() {
        return new Translacja(-dX, -dY);
    }

    @Override
    public Punkt transformuj(Punkt p) {
        return new Punkt(p.getX()+dX,p.getY()+dY);
    }

    public double getdX() {
        return dX;
    }

    public double getdY() {
        return dY;
    }

    @Override
    public String toString() {
        return "Translacja o wektor {"+dX+", "+dY+")";
    }
}
