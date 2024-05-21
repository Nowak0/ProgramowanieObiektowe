package swiat.zwierzeta;

import swiat.Organizm;
import swiat.Swiat;

import java.awt.Color;

public class Czlowiek extends Zwierze {
    private int ruch;
    private int licznikTur;
    private boolean czyMoznaAktywowacNiesmiertelnosc;
    private final int LICZBA_TUR_NIESMIERTELNOSC = 5;


    public Czlowiek(final int polozenieX, final int polozenieY, final int wiek) {
        setNazwa("Czlowiek");
        setSymbol('C');
        setSila(5);
        setInicjatywa(4);
        setWiek(wiek);
        setPolozenieX(polozenieX);
        setPolozenieY(polozenieY);
        this.ruch = RUCH_NIEAKTYWNY;
        this.licznikTur = LICZBA_TUR_NIESMIERTELNOSC;
        setNiesmiertelnosc(false);
        this.czyMoznaAktywowacNiesmiertelnosc = true;
    }


    @Override
    public Organizm stworzNowySklonowanyObiekt() {
        return null;
    }


    @Override
    public void akcja(Swiat swiat) {
        if (ruch == RUCH_PRAWO && getPolozenieX() + 1 < swiat.getWymiarMapyX()) {
            akcjaRuchWPrawo(swiat);
        }

        else if (ruch == RUCH_LEWO && getPolozenieX() - 1 >= 0) {
            akcjaRuchWLewo(swiat);
        }

        else if (ruch == RUCH_DOL && getPolozenieY() + 1 < swiat.getWymiarMapyY()) {
            akcjaRuchWDol(swiat);
        }

        else if (ruch == RUCH_GORA && getPolozenieY() - 1 >= 0) {
            akcjaRuchWGore(swiat);
        }

        setRuchCzlowieka(RUCH_NIEAKTYWNY);
    }


    private void akcjaRuchWPrawo(Swiat swiat) {
        // przesun czlowieka jezeli jest wolne miejsca
        if (swiat.getOrganizm(getPolozenieX() + 1, getPolozenieY()) == null) {
            swiat.usunOrganizm(this, getPolozenieX(), getPolozenieY());
            setPolozenieX(getPolozenieX() + 1);
            swiat.dodajOrganizm(this, getPolozenieX(), getPolozenieY());
        }

        else if (!czyNiesmiertelny() || swiat.getOrganizm(getPolozenieX() + 1, getPolozenieY()).getSila() <= getSila()) {
            swiat.getOrganizm(getPolozenieX() + 1, getPolozenieY()).kolizja(swiat, this);
        }
    }


    private void akcjaRuchWLewo(Swiat swiat) {
        if (swiat.getOrganizm(getPolozenieX() - 1, getPolozenieY()) == null) {
            swiat.usunOrganizm(this, getPolozenieX(), getPolozenieY());
            setPolozenieX(getPolozenieX() - 1);
            swiat.dodajOrganizm(this, getPolozenieX(), getPolozenieY());
        }

        else if (!czyNiesmiertelny() || swiat.getOrganizm(getPolozenieX() - 1, getPolozenieY()).getSila() <= getSila()) {
            swiat.getOrganizm(getPolozenieX() - 1, getPolozenieY()).kolizja(swiat, this);
        }
    }


    private void akcjaRuchWGore(Swiat swiat) {
        if (swiat.getOrganizm(getPolozenieX(), getPolozenieY() - 1) == null) {
            swiat.usunOrganizm(this, getPolozenieX(), getPolozenieY());
            setPolozenieY(getPolozenieY() - 1);
            swiat.dodajOrganizm(this, getPolozenieX(), getPolozenieY());
        }

        else if (!czyNiesmiertelny() || swiat.getOrganizm(getPolozenieX(), getPolozenieY() - 1).getSila() <= getSila()) {
            swiat.getOrganizm(getPolozenieX(), getPolozenieY() - 1).kolizja(swiat, this);
        }
    }


    private void akcjaRuchWDol(Swiat swiat) {
        if (swiat.getOrganizm(getPolozenieX(), getPolozenieY() + 1) == null) {
            swiat.usunOrganizm(this, getPolozenieX(), getPolozenieY());
            setPolozenieY(getPolozenieY() + 1);
            swiat.dodajOrganizm(this, getPolozenieX(), getPolozenieY());
        }

        else if (!czyNiesmiertelny() || swiat.getOrganizm(getPolozenieX(), getPolozenieY() + 1).getSila() <= getSila()) {
            swiat.getOrganizm(getPolozenieX(), getPolozenieY() + 1).kolizja(swiat, this);
        }
    }


    public void setRuchCzlowieka(final int ruch) {
        if (ruch == RUCH_PRAWO || ruch == RUCH_LEWO || ruch == RUCH_GORA || ruch == RUCH_DOL) this.ruch = ruch;
        else this.ruch = RUCH_NIEAKTYWNY;
    }


    @Override
    public void kolizja(Swiat swiat, Organizm atakujacy) {
        if (czyNiesmiertelny() && atakujacy.getSila() >= getSila()) kolizjaNiesmiertelnosc(swiat, atakujacy);
        else kolizjaBezNiesmiertelnosci(swiat, atakujacy);
    }


    private void kolizjaNiesmiertelnosc(Swiat swiat, Organizm atakujacy) {
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();

        for (int y = polozenieY - 1; y <= polozenieY + 1; y++)
        {
            if (y < 0 || y >= swiat.getWymiarMapyY()) continue;
            for (int x = polozenieX - 1; x <= polozenieX + 1; x++)
            {
                if (x < 0 || x >= swiat.getWymiarMapyX()) continue;
                if (swiat.getOrganizm(x, y) == null) {
                    swiat.usunOrganizm(this, polozenieX, polozenieY);
                    swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
                    setPolozenieX(x);
                    setPolozenieY(y);
                    atakujacy.setPolozenieX(polozenieX);
                    atakujacy.setPolozenieY(polozenieY);
                    swiat.dodajOrganizm(this, x, y);
                    swiat.dodajOrganizm(atakujacy, polozenieX, polozenieY);
                    swiat.wypiszWiadomosc("Czlowiek unika ataku " + atakujacy.getNazwa());
                    return;
                }
            }
        }

        swiat.wypiszWiadomosc("Czlowiek unika ataku " + atakujacy.getNazwa());
    }


    private void kolizjaBezNiesmiertelnosci(Swiat swiat, Organizm atakujacy) {
        int polozenieX = getPolozenieX(), polozenieY = getPolozenieY(), polozenieXAtak = atakujacy.getPolozenieX(), polozenieYAtak = atakujacy.getPolozenieY();
        boolean czyPrzetrwal = czyOdbilAtak(atakujacy, this);

        if (czyPrzetrwal) {
            atakujacy.setCzyZyje(false);
            swiat.wypiszWiadomosc("Czlowiek zabija " + atakujacy.getNazwa() + " " + polozenieX + " " + polozenieY);
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
        }
        else {
            setCzyZyje(false);
            swiat.usunOrganizm(this, polozenieX, polozenieY);
            atakujacy.setPolozenieX(polozenieX);
            atakujacy.setPolozenieY(polozenieY);
            swiat.dodajOrganizm(atakujacy, polozenieX, polozenieY);
            swiat.usunOrganizm(atakujacy, polozenieXAtak, polozenieYAtak);
            swiat.wypiszWiadomosc(atakujacy.getNazwa() + " zabija Czlowieka" + " " + polozenieX + " " + polozenieY);
        }
    }


    @Override
    public Color rysowanie() {
        return Color.CYAN;
    }


    public void aktywujNiesmiertelnoscCzlowieka() {
        if (czyMoznaAktywowacNiesmiertelnosc && !czyNiesmiertelny()) {
            setNiesmiertelnosc(true);
            czyMoznaAktywowacNiesmiertelnosc = false;
            licznikTur = LICZBA_TUR_NIESMIERTELNOSC;
        }
    }


    public void sprawdzLiczenieTur() {
        if (licznikTur == 0) {
            setNiesmiertelnosc(false);
            czyMoznaAktywowacNiesmiertelnosc = false;
        }
        else if (licznikTur == LICZBA_TUR_NIESMIERTELNOSC) {
            czyMoznaAktywowacNiesmiertelnosc = true;
        }

        if (czyNiesmiertelny()) licznikTur--;
        else if (!czyNiesmiertelny() && !czyMoznaAktywowacNiesmiertelnosc) licznikTur++;
    }
}
