package lab3;
import java.util.Scanner;

public class Main {
    public static void zadanie1() {
        System.out.println("Podaj x i y:");
        double x = 13, y = 21;
        Punkt punkt = new Punkt(x,y);
        Punkt punkt2 = new Punkt(x+2,y+2);
        System.out.println(punkt.toString()+" hash: "+punkt.hashCode()+" is equal? "+punkt.equals(punkt2));
        System.out.println("points: " + Punkt.E_X);
    }


    public static void zadanie2() {
        try {
            Punkt p1 = Punkt.E_X;
            System.out.println(p1);
            Transformacja tr = new Translacja(5, 6);
            System.out.println(tr);
            Punkt p2 = tr.transformuj(p1);
            System.out.println(p2);
            Transformacja trr = tr.getTransformacjaOdwrotna();
            System.out.println(trr);
            Punkt p3 = trr.transformuj(p2);
            System.out.println(p3);

        } catch (BrakTransformacjiOdwrotnejException ex) {
            ex.printStackTrace();
        }
        System.out.println();

        try {
            Punkt p1 = new Punkt(2, 2);
            System.out.println(p1);
            Transformacja tr2 = new Skalowanie(5, 4);
            System.out.println(tr2);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        } catch (BrakTransformacjiOdwrotnejException ex) {
            ex.printStackTrace();
        }
        System.out.println();

        try
        {
            Punkt p1 = new Punkt(2, 2);
            Transformacja tr2 = new Skalowanie(5, 0);
            System.out.println(tr2);
            System.out.println(p1);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();
    }


    public static void zadanie3() {
        try {
            Punkt p1 = new Punkt(2,2);
            Transformacja t = new Obrot(45);
            System.out.println(t);
            System.out.println(p1);
            Punkt p2 = t.transformuj(p1);
            System.out.println(p2);
            Transformacja t2 = t.getTransformacjaOdwrotna();
            System.out.println(t2);
            Punkt p3 = t.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
            {
                ex.printStackTrace();
            }
        System.out.println();
    }


    public static void zadanie4() {
        try {
            Punkt p1 = new Punkt(3,3);
            System.out.println(p1);
            ZlozenieTransformacji t = new ZlozenieTransformacji(3);
            Transformacja[] thisTab = t.getTab();
            thisTab[0] = new Translacja(5,5);
            thisTab[1] = new Obrot(30);
            thisTab[2] = new Skalowanie(2,10);
            Punkt p2 = t.transformuj(p1);
            System.out.println(p2);
            Transformacja t2 = t.getTransformacjaOdwrotna();
            System.out.println(t2);
            Punkt p3 = t2.transformuj(p2);
        }
        catch (BrakTransformacjiOdwrotnejException ex) {
            ex.printStackTrace();
        }
    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        zadanie4();

    }
}
