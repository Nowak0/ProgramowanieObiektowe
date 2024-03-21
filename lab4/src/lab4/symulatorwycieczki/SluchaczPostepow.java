package lab4.symulatorwycieczki;

@FunctionalInterface
public interface SluchaczPostepow {
    void aktualizujPostep(ElementWycieczki elementWycieczki, int lp, int liczbaElementow);
}
