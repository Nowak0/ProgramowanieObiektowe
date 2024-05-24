package swiat;

import swiat.zwierzeta.Czlowiek;

import java.io.*;

public class Zapis {
    private final Swiat swiat;
    private final String plikZapisu = ".\\src\\swiat\\zapis.txt";
    public Zapis(Swiat swiat) {
        this.swiat = swiat;
    }

    public void zapiszGre() {
        StringBuilder wartosci = new StringBuilder();
        wartosci.append(swiat.getWymiarMapyX()).append(" ").append(swiat.getWymiarMapyY()).append("\n");
        for (int i = 0; i< swiat.getLiczbaOrganizmow(); i++) {
            Organizm o = swiat.getPosortowanyOrganizm(i);
            wartosci.append(o.getNazwa()).append(" ");
            wartosci.append(o.getPolozenieX()).append(" ");
            wartosci.append(o.getPolozenieY()).append(" ");
            wartosci.append(o.getWiek()).append(" ");
            wartosci.append(o.czyNiesmiertelny()).append(" ");

            if (o instanceof Czlowiek) {
                wartosci.append(((Czlowiek) o).getLicznikTur()).append(" ");
                wartosci.append(((Czlowiek) o).getCzyMoznaAktywowacNiesmiertelnosc()).append(" ");
            }

            wartosci.append("\n");
        }

        try {
            zapiszDoPliku(wartosci);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    public void zapiszDoPliku(StringBuilder wartosci) throws IOException {
        String[] elementy = wartosci.toString().split("\n");

        try (BufferedWriter zapis = new BufferedWriter(new FileWriter(plikZapisu))) {

            for (String element : elementy) {
                zapis.write(element);
                zapis.write("\n");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void zaladujGre() {
        File plik = new File(plikZapisu);
        if (!plik.exists()) return;
        try (BufferedReader zapis = new BufferedReader(new FileReader(plikZapisu))) {
            String linia = zapis.readLine();
            String[] elementy = linia.split(" ");
            swiat.ustawianieRozmiaruMapy(Integer.parseInt(elementy[0]), Integer.parseInt(elementy[1]));
            swiat.uaktualnijGraniceMapy();

            while ((linia = zapis.readLine()) != null) {
                elementy = linia.split(" ");
                swiat.dodajOrganizmyZapis(elementy);
            }

           swiat.uaktualnijStanGry();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
