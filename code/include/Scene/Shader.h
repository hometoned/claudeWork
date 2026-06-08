#pragma once

#include <Scene/Export.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

namespace Scene
{
    class SCENE_EXPORT Shader
    {
    public:
        Shader();
        ~Shader();
        void Use();
        bool ReadShader(const std::string& strShaderFile, unsigned int uiType);
        void AttchShders();
        // utility uniform functions
        // ------------------------------------------------------------------------
        void SetBool(const std::string &name, bool value) const;
        // ------------------------------------------------------------------------
        void SetInt(const std::string &name, int value) const;
        // ------------------------------------------------------------------------
        void SetFloat(const std::string &name, float value) const;
        // ------------------------------------------------------------------------
        void SetVec2(const std::string &name, const glm::vec2 &value) const;
        void SetVec2(const std::string &name, float x, float y) const;
        // ------------------------------------------------------------------------
        void SetVec3(const std::string &name, const glm::vec3 &value) const;
        void SetVec3(const std::string &name, float x, float y, float z) const;
        // ------------------------------------------------------------------------
        void SetVec4(const std::string &name, const glm::vec4 &value) const;
        void SetVec4(const std::string &name, float x, float y, float z, float w) const;
        // ------------------------------------------------------------------------
        void SetMat2(const std::string &name, const glm::mat2 &mat) const;
        // ------------------------------------------------------------------------
        void SetMat3(const std::string &name, const glm::mat3 &mat) const;
        // ------------------------------------------------------------------------
        void SetMat4(const std::string &name, const glm::mat4 &mat) const;

    private:
        std::string ReadShaderFile(const std::string& strShaderFile);
        bool CreateShader(const char* shaderCode, unsigned int shaderType);
    private:
        unsigned int m_pProgramId = 0xffffffff;
        std::vector<unsigned int > m_shaderIds;
    };
}