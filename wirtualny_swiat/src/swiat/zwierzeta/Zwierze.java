package swiat.zwierzeta;

import swiat.Organizm;
import swiat.Swiat;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public abstract class Zwierze extends Organizm {
    @Override
    public void akcja(Swiat swiat) {
        Random random = new Random();
        final int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY();
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
        List<Integer> mozliweMiejscaX = new ArrayList<>();
        List<Integer> mozliweMiejscaY = new ArrayList<>();

        for (int y = polozenieY - 1; y <= polozenieY + 1; y++) {
            if (y < 0 || y >= wymiarMapyY) continue;
            for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
            {
                if (x < 0 || x >= wymiarMapyX) continue;
                if (x == polozenieX && y == polozenieY) continue;
                mozliweMiejscaX.add(x);
                mozliweMiejscaY.add(y);
            }
        }

        if (mozliweMiejscaX.isEmpty()) return;

        int ruch = random.nextInt(mozliweMiejscaX.size());
        int nowyX = mozliweMiejscaX.get(ruch), nowyY = mozliweMiejscaY.get(ruch);

        if (swiat.getOrganizm(nowyX,nowyY) == null) {
            setPolozenieX(nowyX);
            setPolozenieY(nowyY);
            swiat.dodajOrganizm(swiat.getOrganizm(polozenieX, polozenieY) , nowyX, nowyY);
            swiat.usunOrganizm(swiat.getOrganizm(polozenieX, polozenieY), polozenieX, polozenieY);
        }

        else if (swiat.getOrganizm(nowyX, nowyY).getSymbol() == swiat.getOrganizm(polozenieX, polozenieY).getSymbol()) {
            Organizm noweZwierze = this.stworzNowySklonowanyObiekt();
            kolizja(swiat, noweZwierze);
        }

        else {
            swiat.getOrganizm(nowyX, nowyY).kolizja(swiat, this);
        }
    }

    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        int polozenieX = atakujacy.getPolozenieX(), polozenieY = atakujacy.getPolozenieY();
        for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
        {
            if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
            for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
            {
                if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
                if (swiat.getOrganizm(x, y) == null) {
                    atakujacy.setPolozenieX(x);
                    atakujacy.setPolozenieY(y);
                    atakujacy.setWiek(swiat.getLiczbaOrganizmow() + 1);
                    swiat.dodajOrganizm(atakujacy, x, y);
                    swiat.wypiszWiadomosc("Nowe zwierze " + atakujacy.getNazwa() + wypiszPolozenie(x,y));
                    return;
                }
            }
        }
    }
}
