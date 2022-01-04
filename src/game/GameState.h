//
// Created by Chloe on 29/12/2021.
//

#ifndef SATELLITESIM_GAMESTATE_H
#define SATELLITESIM_GAMESTATE_H


class GameState {
protected:
    AssetManager* assetManager;
public:
    virtual ~GameState() {}
    virtual void setup(AssetManager* assetManager) {}
    virtual void update() {}
    virtual void render() {}
};


#endif //SATELLITESIM_GAMESTATE_H
