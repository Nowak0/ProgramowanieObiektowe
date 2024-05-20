package swiat.rosliny;

import swiat.Organizm;
import swiat.Swiat;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public abstract class Roslina extends Organizm {
    @Override
    public void akcja(Swiat swiat) {
        Random random = new Random();
        int rozsiewanie = random.nextInt(100 + 1);
        if (rozsiewanie <= 90) return;

        int wymiarMapyX = swiat.getWymiarMapyX(), wymiarMapyY = swiat.getWymiarMapyY(), polozenieX = getPolozenieX(), polozenieY = getPolozenieY();
        List<Integer> mozliweMiejscaX = new ArrayList<>();
        List<Integer> mozliweMiejscaY = new ArrayList<>();

        for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
        {
            if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
            for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
            {
                if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
                if (x == polozenieX && y == polozenieY) continue;
                if (swiat.getOrganizm(x, y) == null) {
                    mozliweMiejscaX.add(x);
                    mozliweMiejscaY.add(y);
                }
            }
        }

        if (mozliweMiejscaX.size() == 0) return;

        int ruch = random.nextInt(mozliweMiejscaX.size());
        int nowyX = mozliweMiejscaX.get(ruch), nowyY = mozliweMiejscaY.get(ruch);
        Organizm nowaRoslina = this.stworzNowySklonowanyObiekt();
        nowaRoslina.setPolozenieX(nowyX);
        nowaRoslina.setPolozenieY(nowyY);
        nowaRoslina.setWiek(swiat.getLiczbaOrganizmow() + 1);
        swiat.dodajOrganizm(nowaRoslina, nowyX, nowyY);
    }
}
