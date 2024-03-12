package lab3;

public class Punkt {
    private final double x,y;

    public Punkt(double givenX, double givenY) {
        this.x = givenX;
        this.y = givenY;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    @Override
    public boolean equals(Object object) {
        if (object instanceof Punkt) {
            Punkt other = (Punkt) object;
            if (x == other.x && y == other.y) return true;
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hashX = 59*Double.hashCode(x)+7;
        int hashY = 59*Double.hashCode(y)+7;
        return hashX+hashY;
    }

    @Override
    public String toString() {
        return "Punkt("+x+","+y+")";
    }

    public static final Punkt O = new Punkt(0,0);
    public static final Punkt E_X = new Punkt(1,0);
    public static final Punkt E_Y = new Punkt(0,1);
}
