#pragma once
#include <vector>
#include "Enemy.h"
#include "Heroe.h"
#include "Bomba.h"
using namespace std;
class Controller
{
public:
	Controller();
	~Controller();

	void agregarBomba(); 
	void mostrarTodo(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpHeroe, Bitmap^ bmpEnemy);
	void moverTodo(Graphics^ g);

	void colision(); 
	int getPuntos() { return puntos; }
	int getEnemigosEliminados() { return enemigosEliminados;  }

	CHeroe* getHero() { return objHeroe; }
	vector<CEnemy*>* getEnemis() { return enemigos;  }

private:
	CHeroe* objHeroe; 
	vector<CEnemy*>*enemigos;
	vector<CBomba*>*bomba; 
	int puntos; 
	int enemigosEliminados; 
};

Controller::Controller()
{
	enemigosEliminados = 0; 
	puntos = 0; 

	objHeroe = new CHeroe(); 
	enemigos = new vector<CEnemy*>();
	bomba = new vector<CBomba*>();


	enemigos->push_back(new CEnemy());
	enemigos->push_back(new CEnemy());
	enemigos->push_back(new CEnemy());
	
	
}

Controller::~Controller()
{
}
void Controller::agregarBomba(){
	bomba->push_back(new CBomba(objHeroe->getx(), objHeroe->gety())); 
}
void Controller::mostrarTodo(Graphics^ g, Bitmap^ bmpBomba, Bitmap^bmpHeroe, Bitmap^bmpEnemy){
	objHeroe->dibujar(g, bmpHeroe);

	for (int i = 0; i < bomba->size(); i++)
	{
		bomba->at(i)->dibujar(g, bmpBomba);
	}
	for (int i = 0; i < enemigos->size(); i++)
	{
		enemigos->at(i)->dibujar(g, bmpEnemy);
	}
}


void Controller::moverTodo(Graphics^ g){
	for (int i = 0; i < enemigos->size(); i++)
	{
		enemigos->at(i)->mover(g);
	}
}

void Controller::colision(){
	/*for (int i = 0; i < enemigos->size(); i++) {
		if(objHeroe->getRectangle().IntersectsWith(enemigos->at(i)->getRectangle())){
			enemigos->at(i)->disminuirvida(); 
			if (enemigos->at(i)->getvida() == 0) {
				enemigosEliminados = +1;
			}
			
		}
		

	}*/

	for (int i = 0; i < bomba->size(); i++)
	{
		for (int  j= 0; j < enemigos->size(); j++)
		{
			if (bomba->at(i)->getRectangle().IntersectsWith(enemigos->at(j)->getRectangle())) {
				puntos += 9;
				bomba->erase(bomba->begin() + i);
				enemigos->erase(enemigos->begin() + j);
				return;
			}
		}
		
	}
	
}