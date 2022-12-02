#pragma once
#include "Personajes.h"

class CEnemy:public Personajes
{
public:
	CEnemy();
	~CEnemy();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	void mover(Graphics^ g);
	void disminuirvida(){ vida--; }
	int getvida(){ return vida; }
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.5, alto * 0.5);
	}
private:
	
	int vida; 
};

CEnemy::CEnemy()
{
	vida = 4;
	x =  rand()%827/2;
	y = rand ()%300;
	dx = dy = 5;
	ancho = 553 / 4;
	alto = 484 / 4;
	idx = idy = 0;
}

CEnemy::~CEnemy()
{
}
void CEnemy::dibujar(Graphics^ g, Bitmap^ bmp) {
	Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 0.5, alto * 0.5);
	g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
}
void CEnemy::mover(Graphics^ g) {
	if (x + ancho * 0.5 > g->VisibleClipBounds.Width || x < 0)dx *= -1;
	if (dx > 0) {
		idy = 2;
	}
	else {
		idy = 1;
	}
	x += dx;
	
}