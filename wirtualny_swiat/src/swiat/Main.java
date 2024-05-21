package swiat;
import swiat.rosliny.*;
import swiat.zwierzeta.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Main {
    public static void dodajOrganizmyDoSwiataKonkretnie(Swiat swiat, List<Organizm> noweOrganizmy) {
        for (Organizm o : noweOrganizmy) {
            swiat.dodajOrganizm(o, o.getPolozenieX(), o.getPolozenieY());
        }
    }


    public static void dodajOrganizmyDoSwiataLosowo(Swiat swiat, List<Organizm> noweOrganizmy) {
        Random random = new Random();
        int wolneMiejsca = swiat.getWymiarMapyX() * swiat.getWymiarMapyY();

        for (Organizm o : noweOrganizmy) {
            boolean dodano = false;

            while (!dodano && wolneMiejsca > 0)
            {
                int polozenieX = random.nextInt(swiat.getWymiarMapyX());
                int polozenieY = random.nextInt(swiat.getWymiarMapyY());
                if (swiat.getOrganizm(polozenieX, polozenieY) == null) {
                    o.setPolozenieX(polozenieX);
                    o.setPolozenieY(polozenieY);
                    o.setWiek(swiat.getLiczbaOrganizmow() + 1);
                    swiat.dodajOrganizm(o, o.getPolozenieX(), o.getPolozenieY());
                    wolneMiejsca--;
                    dodano = true;
                }
            }
        }
    }


    public static void dodajOrganizmyRecznie(List<Organizm> noweOrganizmy) {
        noweOrganizmy.add(new Czlowiek(0, 0, 0));
        noweOrganizmy.add(new Lis(0, 0, 0));
        noweOrganizmy.add(new Antylopa(0, 0, 0));
        noweOrganizmy.add(new Zolw(0, 0, 0));
        noweOrganizmy.add(new Owca(0, 0, 0));
        noweOrganizmy.add(new Trawa(0, 0, 0));
        //noweOrganizmy.add(new Barszcz(0, 0, 0));
        noweOrganizmy.add(new Guarana(0, 0, 0));
        noweOrganizmy.add(new Guarana(0, 0, 0));
        noweOrganizmy.add(new Mlecz(0, 0, 0));
        noweOrganizmy.add(new Mlecz(0, 0, 0));
        noweOrganizmy.add(new Wilk(0, 0, 0));
        noweOrganizmy.add(new WilczeJagody(0, 0, 0));
    }


    public static void przeprowadzGre(Swiat swiat, List<Organizm> noweOrganizmy) {
        if (noweOrganizmy.size() == 0) {
            dodajOrganizmyRecznie(noweOrganizmy);
            dodajOrganizmyDoSwiataLosowo(swiat, noweOrganizmy);
        }
        else dodajOrganizmyDoSwiataKonkretnie(swiat, noweOrganizmy);

        swiat.rysujSwiat();
    }


    public static void main(String[] args) {
        Swiat swiat = new Swiat(5,5);
        List<Organizm> noweOrganizmy = new ArrayList<>();
        przeprowadzGre(swiat, noweOrganizmy);

    }
}
