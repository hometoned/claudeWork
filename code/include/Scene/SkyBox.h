#pragma once

#include <Scene/Export.h>
#include <Scene/Shader.h>

#include <string>
#include <vector>

namespace Scene
{
    class SCENE_EXPORT SkyBox
    {
    public:
        SkyBox();
        ~SkyBox();
        void Init();
        void Create();

        void Draw();
        void SetMPVMatrix(const glm::mat4& view, const glm::mat4& projection);
    private:
        unsigned int LoadImage(std::vector<std::string> strPath);

    private:
        unsigned int m_uiTextureId;
        unsigned int m_uiSkyboxVAO, m_uiSkyboxVBO;
        Shader* m_pShader = nullptr;
    };

}