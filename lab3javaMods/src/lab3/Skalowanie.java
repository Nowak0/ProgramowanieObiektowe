package lab3;

public class Skalowanie implements Transformacja{
    private final double skalaX,skalaY;

    public Skalowanie(double skalaX, double skalaY) {
        this.skalaX = skalaX;
        this.skalaY = skalaY;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna()
            throws BrakTransformacjiOdwrotnejException {
        if (skalaX == 0 || skalaY == 0) {
            throw new BrakTransformacjiOdwrotnejException("Brak translacji odwrotnej" +
                    " z powodu dzielenia przez 0");
        }
        return new Skalowanie(1/skalaX, 1/skalaY);
    }

    @Override
    public Punkt transformuj(Punkt p) {
        Transformacja tr = new Translacja(-1*Main.p1.getX(),-1*Main.p1.getY());
        Punkt p1 = tr.transformuj(p);
        Punkt p2 = new Punkt(skalaX*p1.getX(), skalaY*p1.getY());
        Transformacja tr2 = new Translacja(1,1);
        Punkt p3 = tr2.transformuj(p2);
        return p3;
    }

    public double getSkalaX() {
        return skalaX;
    }

    public double getSkalaY() {
        return skalaY;
    }

    @Override
    public String toString() {
        return "Skalowanie "+skalaX+"x oraz "+skalaY+"y";
    }
}
