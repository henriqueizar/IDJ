#include "TileSet.h"
TileSet::TileSet(int tileWidth, int tileHeight, std::string file) : tileSet(file), tileWidth(tileWidth), tileHeight(tileHeight), tileCount(0){
    if (tileSet.IsOpen()){
        int columns = tileSet.GetWidth() / tileWidth;
        int rows = tileSet.GetHeight() / tileHeight;
        tileCount = columns*rows;
        tileSet.SetFrameCount(columns, rows);
    }
}

void TileSet::RenderTile(unsigned index, float x, float y){
    if (index>=0 & index<= tileCount-1){
        tileSet.SetFrame(index);
        tileSet.Render(x,y,tileWidth,tileHeight);
    }
}

int TileSet::GetTileWidth(){
    return tileWidth;
}

int TileSet::GetTileHeight(){
    return tileHeight;
}