#pragma once
#include "Organizm.h"


class Roslina : public Organizm {
public:
	virtual void akcja(Swiat& swiat) override;
	virtual ~Roslina() override;
};