#include "Zwierze.h"


class Czlowiek : public Zwierze {
public:
	Czlowiek();
	void akcja() override;
	void kolizja() override;
	~Czlowiek() override;
};