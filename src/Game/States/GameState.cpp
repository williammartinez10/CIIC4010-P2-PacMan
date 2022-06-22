#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	music.load("music/pacman_chomp.wav");
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
}
void GameState::tick() {
	if(!music.isPlaying()){
			music.play();
	}
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);

		map = MapBuilder().createMap(mapImage);

	}
	if(spawnCounter == 0){
        if(map->getPlayer()->getScore() == 1000){
            map->getGhostSpawner()->spawnPeekABooGhost("PeekABooGhost");
            spawnCounter++;
        }
    }

}

void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);

	if(key=='y'){
		setFinished(true);
		setNextState("win");
		map->getPlayer()->setHealth(3);
		map->getPlayer()->setScore(0);

		map = MapBuilder().createMap(mapImage);
	}

	if(key=='p'){
		setFinished(true);
		setNextState("pause");
		//if nextstate==menu
		if(getNextState()=="Menu"){
			map = MapBuilder().createMap(mapImage);
		}
	}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}