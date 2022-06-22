#include "GhostSpawner.h"
#include "Ghost.h"
#include "RandomGhost.h"
#include "Player.h"
#include "PeekABooGhost.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, EntityManager* em, ofImage sprite) : Entity(x, y, width, height){
    this->em = em;
    this->sprite = sprite;
    spawnGhost("red");
    spawnGhost("pink");
    spawnGhost("cyan");
    spawnGhost("orange");

}

void GhostSpawner::tick(){
    // std::vector<string> colors;
    
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("cyan");
    colors.push_back("orange");

    if(em->ghosts.size()<4){
        if(spawnCounter == 0){
            spawnGhost(colors[ofRandom(4)]);
            spawnCounter = 30*5;
        }else{
            spawnCounter--;
        }
    }
}
void GhostSpawner::spawnGhost(string color){
    Ghost* g = new Ghost(x,y,width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
}

void GhostSpawner::spawnRandomGhost(string color){
    int value=rand()%em->entities.size(); //gets random val to put in to search what dot to replace
    RandomGhost* g = new RandomGhost(em->entities.at(value)->getX(),em->entities.at(value)->getY(),width-2,height-2,sprite,em, color);
    em->ghosts.push_back(g);
    
}

void GhostSpawner::spawnPeekABooGhost(string color){
    PeekABooGhost* pg = new PeekABooGhost(x,y,width-2,height-2,sprite,em,color);
    em->ghosts.push_back(pg);
}

void GhostSpawner::keyPressed(int key){
    if(key == 'g'){
        spawnGhost(colors[ofRandom(colors.size())]); // Displays a ghost with a different color every time 'g' is pressed
        
    }
}