#pragma once
#include "Personajes.h"
class CBomba:public Personajes
{
public:
	CBomba(int _x, int _y);
	~CBomba();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.4, alto * 0.4);
	}
private:

};

CBomba::CBomba(int _x, int _y)
{
	x = _x;
	y = _y;
	dx = dy = 0;
	ancho = 102;
	alto = 95;
	idx = idy = 0;
}

CBomba::~CBomba()
{
}
void CBomba::dibujar(Graphics^ g, Bitmap^ bmp) {
	Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho *0.4, alto * 0.4);
	g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
}