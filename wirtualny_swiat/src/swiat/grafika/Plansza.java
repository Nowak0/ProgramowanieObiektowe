package swiat.grafika;

import swiat.Organizm;
import swiat.Swiat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.List;


public class Plansza extends JPanel implements ActionListener, KeyListener {
    private List<List<Organizm>> organizmy;
    private final Swiat swiat;


    public Plansza(Swiat swiat, List<List<Organizm>> kopia) {
        uaktualnijOrganizmy(kopia);
        this.swiat = swiat;
        addKeyListener(this);
        setFocusable(true);
    }


    @Override
    public void paint(Graphics g) {
        g.setFont(new Font("Helvetica", Font.PLAIN, 20));
        for (int i = 0; i < swiat.getWymiarMapyY(); i++) {
            for (int j = 0; j < swiat.getWymiarMapyX(); j++) {
                if (organizmy.get(i).get(j) == null) {
                    g.setColor(Color.lightGray);
                    g.fillRect((j + 1) * 30, (i) * 30, 30, 30);
                }
                else {
                    g.setColor(organizmy.get(i).get(j).rysowanie());
                    g.fillRect((j + 1) * 30, (i) * 30, 30, 30);
                    g.setColor(Color.BLACK);
                    char s = organizmy.get(i).get(j).getSymbol();
                    g.drawString(String.valueOf(s), (j + 1) * 30 + 7, (i) * 30 + 20);
                }

            }
        }
    }


    @Override
    public void actionPerformed(ActionEvent e) {

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


    public void uaktualnijOrganizmy(List<List<Organizm>> kopia) {
        organizmy = kopia;
    }
}
