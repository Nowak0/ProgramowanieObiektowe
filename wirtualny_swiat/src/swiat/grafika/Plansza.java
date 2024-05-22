package swiat.grafika;

import swiat.Organizm;
import swiat.Swiat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.List;


public class Plansza extends JPanel implements ActionListener, KeyListener {
    private final List<List<Organizm>> organizmy;
    private final int wymiarMapyY;
    private final int wymiarMapyX;
    private final Swiat swiat;


    public Plansza(Swiat swiat, List<List<Organizm>> kopia) {
        organizmy = kopia;
        this.swiat = swiat;
        wymiarMapyY = swiat.getWymiarMapyY();
        wymiarMapyX = swiat.getWymiarMapyX();
        addKeyListener(this);
        setFocusable(true);
    }


    @Override
    public void paint(Graphics g) {
        g.setFont(new Font("Helvetica", Font.PLAIN, 20));
        final int poczatkowyX = 0;
        final int poczatkowyY = -1;
        for (int i = 0; i < wymiarMapyY; i++) {
            for (int j = 0; j < wymiarMapyX; j++) {
                if (organizmy.get(i).get(j) == null) {
                    g.setColor(Color.lightGray);
                    g.fillRect((poczatkowyX + j + 1) * 30, (poczatkowyY + i + 1) * 30, 30, 30);
                } else {
                    g.setColor(organizmy.get(i).get(j).rysowanie());
                    g.fillRect((poczatkowyX + j + 1) * 30, (poczatkowyY + i + 1) * 30, 30, 30);
                    g.setColor(Color.BLACK);
                    char s = organizmy.get(i).get(j).getSymbol();
                    g.drawString(String.valueOf(s), (poczatkowyX + j + 1) * 30 + 7, (poczatkowyY + i + 1) * 30 + 20);
                }

            }
        }
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        repaint();
    }


    @Override
    public void keyPressed(KeyEvent e) {
        final int RUCH_PRAWO = 1;
        final int RUCH_LEWO = 2;
        final int RUCH_GORA = 3;
        final int RUCH_DOL = 4;
        switch (e.getKeyCode()) {
            case KeyEvent.VK_UP -> swiat.wykonajTure(RUCH_GORA);
            case KeyEvent.VK_DOWN -> swiat.wykonajTure(RUCH_DOL);
            case KeyEvent.VK_RIGHT -> swiat.wykonajTure(RUCH_PRAWO);
            case KeyEvent.VK_LEFT -> swiat.wykonajTure(RUCH_LEWO);
        }
    }


    public void keyTyped(KeyEvent e) {
    }


    public void keyReleased(KeyEvent e) {
    }
}
