package swiat.grafika;

import swiat.Organizm;
import swiat.Swiat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.List;
import java.util.ArrayList;

public class Ekran extends JPanel implements ActionListener, KeyListener {
    private final List<List<Organizm>> organizmy;
    private final int wymiarMapyY;
    private final int wymiarMapyX;
    private final Swiat swiat;
    private final JFrame wyswietlanie;


    public Ekran(JFrame wyswietlanie, Swiat swiat, List<List<Organizm>> kopia) {
        organizmy = kopia;
        this.swiat = swiat;
        wymiarMapyY = swiat.getWymiarMapyY();
        wymiarMapyX = swiat.getWymiarMapyX();
        this.wyswietlanie = wyswietlanie;
        repaint();
        addKeyListener(this);
        setFocusable(true);
    }


    @Override
    public void paint(Graphics g) {
        super.paint(g);
        g.setFont(new Font("Helvetica", Font.PLAIN, 20));
        for (int i = 0; i < wymiarMapyY; i++) {
            for (int j = 0; j < wymiarMapyX; j++) {
                if (organizmy.get(i).get(j) == null) {
                    g.setColor(Color.lightGray);
                    g.fillRect((j + 1) * 30, (i + 1) * 30, 30, 30);
                } else {
                    g.setColor(organizmy.get(i).get(j).rysowanie());
                    g.fillRect((j + 1) * 30, (i + 1) * 30, 30, 30);
                    g.setColor(Color.BLACK);
                    char s = organizmy.get(i).get(j).getSymbol();
                    g.drawString(String.valueOf(s), (j + 1) * 30 + 7, (i + 1) * 30 + 20);
                }

            }
            System.out.println();
        }

    }


    @Override
    public void actionPerformed(ActionEvent e) {
        repaint();
    }


    @Override
    public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()) {
            case KeyEvent.VK_UP -> swiat.wykonajTure(swiat.RUCH_GORA);
            case KeyEvent.VK_DOWN -> swiat.wykonajTure(swiat.RUCH_DOL);
            case KeyEvent.VK_RIGHT -> swiat.wykonajTure(swiat.RUCH_PRAWO);
            case KeyEvent.VK_LEFT -> swiat.wykonajTure(swiat.RUCH_LEWO);
        }
    }


    public void keyTyped(KeyEvent e) {
    }


    public void keyReleased(KeyEvent e) {
    }
}
