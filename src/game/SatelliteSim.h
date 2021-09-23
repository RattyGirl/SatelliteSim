//
// Created by chloe on 16/06/2021.
//

#ifndef SATELLITESIM_SATELLITESIM_H
#define SATELLITESIM_SATELLITESIM_H

#include "../gfx/Camera2D.h"
#include "../gfx/AssetManager.h"

namespace SatelliteSim {
    class SatelliteSim {
    private:
        AssetManager* assetManager;
        Camera2D* camera;
    public:
        SatelliteSim(AssetManager* assetManager, Camera2D* camera) {
            this->assetManager = assetManager;
            this->camera = camera;
        }
        void loadAssets();
        void update(float dt);
        void render(Camera2D* camera);
    };
}


#endif //SATELLITESIM_SATELLITESIM_H
