// 
// 
// 

#include "tilengine.h"

tilengine::tilengine(dataType getEngineWidth, dataType getEngineHeight, dataType getTileWidth, dataType getTileHeight) {

}

tilengine::~tilengine() {

}

void tilengine::assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y)) {
	pointToTileDrawingFunction = getFunctionPointer;
}

/* T�ll� funktiolla voi tarkistaa onko kyseisess� koordinaatissa palikkaa */
inline bool tilengine::checkTile(dataType getX, dataType getY) {

}

void tilengine::constructMap(dataType width, dataType height, dataType variableSize) {

}