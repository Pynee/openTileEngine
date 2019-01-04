// 
// 
// 

#include "mushroomGame.h"
#include "variableType.h"

/*-- Kun pelist� luodaan olio --*/
mushroomGame::mushroomGame(tilengine * engine) {
	player.x = 8;	// Aseta pelaajan koordinaateiksi (8,8)
	player.y = 8;

	localEngine = engine;
}

/*-- Kun peli k�ynnistet��n muista m��ritt�� pelaajan koko --*/
void mushroomGame::initialize(dataType width, dataType height) {
	player.width = width;
	player.height = height;
}

/*--  --*/
void mushroomGame::assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y)) {
	pointToPlayerDrawingFunction = getFunctionPointer;
}

/*-- Pelin p��funktio --*/
void mushroomGame::run() {

	/* P�ivit� pelifunktiota n. 62,5 kertaa sekunnissa */
	if (millis() - oldMushroomUpdateTime > 16) {
		draw();	// Piirr� kartta ja pelaaja

		localEngine->checkCollision(&player);	// Laske t�rm�ykset pelaajalle

		if (!localEngine->COLLISION_BELOW) {
			playerPhysics.calculateGravity(&player, 0.2, millis() - oldUpdateTime);		// Laske painovoima pelaajalle
		}

		oldUpdateTime = millis();
	}
	
}

/*--  --*/
void mushroomGame::draw() {
	localEngine->drawMap();	// Piirr� kartta
	pointToPlayerDrawingFunction(player.x, player.y);	// Piirr� pelaaja
}

/*--  --*/
void mushroomGame::loadMap(mapDataType * m) {
	localEngine->loadMap(m);
}