#pragma once

#include <Scene/Export.h>
#include <Scene/SkyBox.h>

namespace Scene
{
    class SCENE_EXPORT Viewer
    {
    public:
        Viewer();
        ~Viewer();
        void Init();
        void SetViewport(int ix, int iy, int iWidth, int iHeight);
        void Clear();

        void AddSkyBox(Scene::SkyBox* pSkyBox);
    private:

    };
}