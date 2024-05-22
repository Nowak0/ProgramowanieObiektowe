package swiat.grafika;
import javax.swing.*;
import java.awt.*;

import swiat.Organizm;
import swiat.Swiat;
import swiat.zwierzeta.Czlowiek;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class Sterowanie extends JPanel implements ActionListener {
    private final Swiat swiat;


    public Sterowanie(Swiat swiat) {
        this.swiat = swiat;
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
        final int BRAK_RUCHU = -1;

        nowaTura.addActionListener(e -> {
                swiat.wykonajTure(BRAK_RUCHU);
        });

        zapisz.addActionListener(e -> {
            swiat.zapiszGre();
        });

        zaladuj.addActionListener(e -> {
            swiat.zaladujGre();
        });

        niesmiertelnosc.addActionListener(e -> {
            if(!swiat.czyCzlowiekZyje()) return;
            Organizm czlowiek = swiat.znajdzCzlowieka();
            ((Czlowiek) czlowiek).aktywujNiesmiertelnoscCzlowieka();
        });

        ustawStylePrzyciskow(nowaTura, zapisz, zaladuj, niesmiertelnosc);
        add(nowaTura);
        add(zapisz);
        add(zaladuj);
        add(niesmiertelnosc);
        nowaTura.setFocusable(false);
        zapisz.setFocusable(false);
        zaladuj.setFocusable(false);
        niesmiertelnosc.setFocusable(false);
    }


    private void ustawStylePrzyciskow(JButton nowaTura, JButton zapisz, JButton zaladuj, JButton niesmiertelnosc) {
        int wysokoscPrzycisku = 100;
        int szerokoscPrzycisku = 200;
        nowaTura.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        zapisz.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        zaladuj.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        niesmiertelnosc.setPreferredSize(new Dimension(szerokoscPrzycisku, wysokoscPrzycisku));
        nowaTura.setBackground(Color.darkGray);
        zapisz.setBackground(Color.darkGray);
        zaladuj.setBackground(Color.darkGray);
        niesmiertelnosc.setBackground(Color.darkGray);
        nowaTura.setForeground(Color.white);
        zapisz.setForeground(Color.white);
        zaladuj.setForeground(Color.white);
        niesmiertelnosc.setForeground(Color.white);
        nowaTura.setVisible(true);
        zapisz.setVisible(true);
        zaladuj.setVisible(true);
        niesmiertelnosc.setVisible(true);
    }


    private void wypiszWiadomosci(Graphics g) {
        g.setColor(Color.BLACK);
        g.setFont(new Font("Helvetica", Font.PLAIN,20));
        int poczatkowyY = 150, poczatkowyX = 100, przesuniecie = 50;
        for (int i = 0; i < swiat.getIloscWiadomosci(); i++) {
            String wiadomosc = swiat.getWiadomosci(i);
            g.drawString(wiadomosc, poczatkowyX, poczatkowyY+przesuniecie*i);
        }
    }


    @Override
    public void actionPerformed(ActionEvent e){
        repaint();
    }
}
