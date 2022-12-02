#pragma once
#include <iostream>
using namespace System::Drawing;
class Personajes
{
public:
	Personajes();
	~Personajes();
	virtual void mover() {}
	virtual void dibujar(Graphics^ g, Bitmap^ bmp) {}
	
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
	bool visible;
};

Personajes::Personajes()
{
	visible = true;
}

Personajes::~Personajes()
{
}