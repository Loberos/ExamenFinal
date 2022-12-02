#pragma once
#include "Personajes.h"
class CHeroe:public Personajes
{
public:
	CHeroe();
	~CHeroe();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	void mover(Graphics^ g, char key);
	int getx() { return x; }
	int gety() { return y; }
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 1.0, alto * 1.0);
	}

private:
	int vida; 
};

CHeroe::CHeroe()
{
	x = 827 / 2; 
	y = 539 / 2; 
	dx = dy = 5; 
	ancho = 256 / 4; 
	alto = 256 / 4; 
	idx = idy = 0; 
	 
}

CHeroe::~CHeroe()
{
}
void CHeroe::dibujar(Graphics^ g, Bitmap^ bmp){
	Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
	g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
}


void CHeroe::mover(Graphics^ g, char key) {
	switch (key)
	{
		case char(75) :
			if (x > 0) {
				x -= dx;
				idy = 1;
			}
		break;

		case char(77) :
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			}
		break;

		case char(72) :
			if (y > 0) {
				y -= dy;
				idy = 3;
			}
		break;

		case char(80) :
			if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
		break;
	}
	idx++;
	if (idx > 3)idx = 0;
}
