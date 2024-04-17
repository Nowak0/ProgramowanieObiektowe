#include "Zwierze.h"
#define LICZBA_TUR 5

class Czlowiek : public Zwierze {
private:
	int ruch;
	int licznikTur;
	bool czyMoznaAktywowacNiesmiertelnosc;

public:
	Czlowiek(const int polozenieX, const int polozenieY, const int wiek);
	void akcja(Swiat& swiat) override;
	void kolizja(Swiat& swiat, Organizm& atakujacy) override;
	void kolizjaBezNiesmiertelnosci(Swiat& swiat, Organizm& atakujacy);
	void kolizjaNiesmiertelnosc(Swiat& swiat, Organizm& atakujacy);
	char rysowanie() override;
	void setRuchCzlowieka(const int ruch) override;
	void aktywujNiesmiertelnoscCzlowieka(Swiat& swiat) override;
	Organizm* stworzNowySklonowanyObiekt() override;
	void sprawdzLiczenieTur(Swiat& swiat);
	~Czlowiek() override;
};