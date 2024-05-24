package swiat.grafika;

import javax.swing.*;
import java.awt.*;

import swiat.Organizm;
import swiat.Swiat;
import swiat.Zapis;
import swiat.zwierzeta.*;
import swiat.rosliny.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class SterowanieGra extends JPanel implements ActionListener {
    private final Swiat swiat;
    private Zapis zapis;

    public SterowanieGra(Swiat swiat) {
        this.swiat = swiat;
        this.zapis = new Zapis(swiat);
        repaint();
        dodajPrzyciski();
    }


    @Override
    public void paint(Graphics g) {
        super.paint(g);
        wypiszWiadomosci(g);
    }


    private void dodajPrzyciski() {
        JButton nowaTura = new JButton("Nowa Tura");
        JButton zapisz = new JButton("Zapisz Gre");
        JButton zaladuj = new JButton("Zaladuj Gre");
        JButton niesmiertelnosc = new JButton(("Aktywuj Niesmiertelnosc"));
        JButton dodawanieOrganizmu = new JButton(("Dodaj Organizm"));
        final int BRAK_RUCHU = -1;

        nowaTura.addActionListener(e -> {
            swiat.wykonajTure(BRAK_RUCHU);
        });

        zapisz.addActionListener(e -> {
            zapis.zapiszGre();
        });

        zaladuj.addActionListener(e -> {
            zapis.zaladujGre();
        });

        niesmiertelnosc.addActionListener(e -> {
            if (!swiat.czyCzlowiekZyje()) return;
            akcjaDlaPrzyciskuNiesmiertelnosc();
        });

        dodawanieOrganizmu.addActionListener(e -> {
            akcjaDlaPrzyciskuDodawanieOrganizmu();
        });

        ustawStylePrzyciskow(nowaTura, zapisz, zaladuj, niesmiertelnosc, dodawanieOrganizmu);
        add(nowaTura);
        add(zapisz);
        add(zaladuj);
        add(niesmiertelnosc);
        add(dodawanieOrganizmu);
        nowaTura.setFocusable(false);
        zapisz.setFocusable(false);
        zaladuj.setFocusable(false);
        niesmiertelnosc.setFocusable(false);
        dodawanieOrganizmu.setFocusable(false);
    }


    private void ustawStylePrzyciskow(JButton nowaTura, JButton zapisz, JButton zaladuj, JButton niesmiertelnosc, JButton dodawanieOrganizmu) {
        int wysokoscPrzycisku = 100;
        int szerokoscPrzycisku = 200;
        nowaTura.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        zapisz.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        zaladuj.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        niesmiertelnosc.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        dodawanieOrganizmu.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        nowaTura.setBackground(Color.darkGray);
        zapisz.setBackground(Color.darkGray);
        zaladuj.setBackground(Color.darkGray);
        niesmiertelnosc.setBackground(Color.darkGray);
        dodawanieOrganizmu.setBackground(Color.darkGray);
        nowaTura.setForeground(Color.white);
        zapisz.setForeground(Color.white);
        zaladuj.setForeground(Color.white);
        niesmiertelnosc.setForeground(Color.white);
        dodawanieOrganizmu.setForeground(Color.white);
        nowaTura.setVisible(true);
        zapisz.setVisible(true);
        zaladuj.setVisible(true);
        niesmiertelnosc.setVisible(true);
        dodawanieOrganizmu.setVisible(true);
    }


    private void wypiszWiadomosci(Graphics g) {
        g.setColor(Color.BLACK);
        g.setFont(new Font("Helvetica", Font.PLAIN, 20));
        int poczatkowyY = 250, poczatkowyX = 100, przesuniecie = 50;
        for (int i = 0; i < swiat.getIloscWiadomosci(); i++) {
            String wiadomosc = swiat.getWiadomosci(i);
            g.drawString(wiadomosc, poczatkowyX, poczatkowyY + przesuniecie * i);
        }
    }


    private void akcjaDlaPrzyciskuNiesmiertelnosc() {
        Organizm czlowiek = swiat.znajdzCzlowieka();
        if (((Czlowiek) czlowiek).aktywujNiesmiertelnoscCzlowieka()) {
            JOptionPane.showMessageDialog(null, "Aktywowano niesmiertelnosc", "Info", JOptionPane.INFORMATION_MESSAGE);
        } else {
            JOptionPane.showMessageDialog(null, "Nie mozna aktywowac niesmiertelnosci", "Info", JOptionPane.WARNING_MESSAGE);
        }
    }


    private void akcjaDlaPrzyciskuDodawanieOrganizmu() {
        String[] opcje = {"Antylopa", "Lis", "Owca", "Wilk", "Zolw", "Barszcz", "Guarana", "Mlecz", "Trawa", "WilczeJagody"};
        int odpowiedz = JOptionPane.showOptionDialog(
                null,
                "Wybierz organizm do dodania",
                "Dodawanie organizmu",
                JOptionPane.YES_NO_OPTION,
                JOptionPane.PLAIN_MESSAGE,
                null,
                opcje,
                null
        );
        sprecyzujOrganizm(odpowiedz);
    }


    private void sprecyzujOrganizm(final int odpowiedz) {
        Organizm organizm = null;
        switch (odpowiedz) {
            case 0:
                organizm = new Antylopa(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 1:
                organizm = new Lis(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 2:
                organizm = new Owca(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 3:
                organizm = new Wilk(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 4:
                organizm = new Zolw(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 5:
                organizm = new Barszcz(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 6:
                organizm = new Guarana(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 7:
                organizm = new Mlecz(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 8:
                organizm = new Trawa(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;
            case 9:
                organizm = new WilczeJagody(0, 0, 0);
                swiat.dodajOrganizmyDoSwiataLosowo(organizm);
                break;

        }
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        repaint();
    }
}
