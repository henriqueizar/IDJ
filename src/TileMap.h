#ifndef TILEMAP_H
#define TILEMAP_H

#include "Component.h"
#include <vector>
#include "GameObject.h"
#include "TileSet.h"

class TileMap : public Component{
    public:
        TileMap(GameObject& associated, std::string file, TileSet* tileSet);
        void Load(std::string file);
        void SetTileSet(TileSet* tileSet);
        int& At(int x, int y, int z = 0);
        void Render();
        void RenderLayer(int layer);
        int GetWidth();
        int GetHeight();
        int GetDepth();
        void Update(float dt);
    private:
        std::vector<int> tileMatrix;
        std::unique_ptr<TileSet> tileSet;
        int mapWidth;
        int mapHeight;
        int mapDepth;
};


#endif