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
        return new Punkt(skalaX*p.getX(), skalaY*p.getY());
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
