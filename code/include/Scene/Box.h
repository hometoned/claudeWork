#pragma once

#include <Scene/Export.h>
#include <Scene/Shader.h>

#include <string>

namespace Scene
{
    class SCENE_EXPORT Box
    {
    public:
        Box();
        ~Box();

        void Init();
        void SetTexture(const std::string& strFile);
        void SetMPVMatrix(const glm::mat4& model, const glm::mat4& view, const glm::mat4& projection);
        void Draw();
    private:
        unsigned int m_uiTextureId;
        unsigned int m_uiBoxVAO, m_uiBoxVBO;
        Shader* m_pShader = nullptr;
    };
}