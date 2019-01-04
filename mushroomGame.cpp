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
	player.width = width;		// M��rit� pelaajan leveys ja korkeus
	player.height = height;
	io.begin();					// Aseta pinnien tilat
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

		/* Tarkista onko pelaaja ilmassa vai maassa */
		if (!localEngine->COLLISION_BELOW) {
			playerPhysics.calculateGravity(&player, millis() - oldUpdateTime);		// Laske painovoima pelaajalle
		} else {
			if (io.returnKey(io.KEY_JUMP)) {	// Jos hyppynappia painetaan
				player.vSpeed = -40.0f;
				player.y -= 1;	// Nosta pelaajaa yhdell� pikselill� jotta tilengine ei luule ett� pelaaja olisi jo maassa
			}
		}

		/* Jos pelaaja liikkuu vasemmalle */
		if (!localEngine->COLLISION_LEFT) {
			if (io.returnKey(io.KEY_LEFT)) {
				player.x -= 1;
			}
		}

		/* Jos pelaaja liikkuu oikealle */
		if (!localEngine->COLLISION_RIGHT) {
			if (io.returnKey(io.KEY_RIGHT)) {
				player.x += 1;
			}
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