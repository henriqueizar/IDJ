#include "TileMap.h"
#include <fstream>
#include <iostream>

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet)
    : Component(associated), tileSet(tileSet), mapWidth(0), mapHeight(0), mapDepth(0) {
    Load(file);
}

void TileMap::Load(std::string file){
    std::ifstream arquivo(file);
    //3 primeiros valores sao width, height e depth
    if (!arquivo.is_open()) {
    std::cerr << "TileMap: num abriu " << file << std::endl;
    return;
}

    arquivo >> mapWidth;
    if (arquivo.peek() == ',') arquivo.ignore();
    arquivo >> mapHeight;
    if (arquivo.peek() == ',') arquivo.ignore();
    arquivo >> mapDepth;
    if (arquivo.peek() == ',') arquivo.ignore();
    int matrixSize = mapWidth*mapHeight*mapDepth;

    tileMatrix.resize(matrixSize);
    for(int z = 0; z <= mapDepth - 1; z ++){
        for(int y = 0; y <= mapHeight - 1; y ++){
            for(int x = 0; x <= mapWidth - 1; x ++){
                arquivo >> At(x,y,z);
                //tilemap pode ou nao ter virgula (usando 'Tiled' tem):
                if (arquivo.peek() == ',') arquivo.ignore();
            }
        }
    }
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet.reset(tileSet); //reset deleta e atribui de novo o uniqueptr
}

int& TileMap::At(int x, int y, int z){
    int position = x + y * mapWidth + z * mapWidth * mapHeight;
    return tileMatrix.at(position);
}

void TileMap::Render(){
    for (int z = 0; z < mapDepth; z++) {
            RenderLayer(z);
        }
}

void TileMap::RenderLayer(int layer) {
    if (tileSet == nullptr) return;

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            // (x, y) -> posicao na tela
            float posX = associated.box.x + x * tileSet->GetTileWidth();
            float posY = associated.box.y + y * tileSet->GetTileHeight();
            tileSet->RenderTile(At(x, y, layer), posX, posY);
        }
    }
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}

void TileMap::Update(float dt) {

}