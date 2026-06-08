#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <Scene/SkyBox.h>
#include <Scene/Base.h>

#include <iostream>

using namespace Scene;

SkyBox::SkyBox()
{
}

SkyBox::~SkyBox()
{
    delete m_pShader;
    m_pShader = nullptr;

    glDeleteVertexArrays(1, &m_uiSkyboxVAO);
    glDeleteBuffers(1, &m_uiSkyboxVBO);
}

void SkyBox::Init()
{
    std::vector<std::string> vectorImages = {
        "right.jpg",
        "left.jpg",
        "top.jpg",
        "bottom.jpg",
        "front.jpg",
        "back.jpg"
    };
    std::string strPath = Base::Instance()->GetAppPath() + "/data/images/skybox/";
    for (std::string& str : vectorImages)
    {
        str = strPath + str;
        //std::cout << str << std::endl;
    }
    LoadImage(vectorImages);
}

unsigned int SkyBox::LoadImage(std::vector<std::string> strPath)
{
    m_uiTextureId = 0;
    glGenTextures(1, &m_uiTextureId);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_uiTextureId);

    int width, height, nrComponents;
    for (unsigned int i = 0; i < strPath.size(); i++)
    {
        unsigned char *data = stbi_load(strPath[i].c_str(), &width, &height, &nrComponents, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << strPath[i] << std::endl;
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return m_uiTextureId;
}

void SkyBox::Create()
{
    float fLength = 1.0f;
    float skyboxVertices[] = {
        // positions          
        -fLength,  fLength, -fLength,
        -fLength, -fLength, -fLength,
        fLength, -fLength, -fLength,
        fLength, -fLength, -fLength,
        fLength,  fLength, -fLength,
        -fLength,  fLength, -fLength,

        -fLength, -fLength,  fLength,
        -fLength, -fLength, -fLength,
        -fLength,  fLength, -fLength,
        -fLength,  fLength, -fLength,
        -fLength,  fLength,  fLength,
        -fLength, -fLength,  fLength,

        fLength, -fLength, -fLength,
        fLength, -fLength,  fLength,
        fLength,  fLength,  fLength,
        fLength,  fLength,  fLength,
        fLength,  fLength, -fLength,
        fLength, -fLength, -fLength,

        -fLength, -fLength,  fLength,
        -fLength,  fLength,  fLength,
        fLength,  fLength,  fLength,
        fLength,  fLength,  fLength,
        fLength, -fLength,  fLength,
        -fLength, -fLength,  fLength,

        -fLength,  fLength, -fLength,
        fLength,  fLength, -fLength,
        fLength,  fLength,  fLength,
        fLength,  fLength,  fLength,
        -fLength,  fLength,  fLength,
        -fLength,  fLength, -fLength,

        -fLength, -fLength, -fLength,
        -fLength, -fLength,  fLength,
        fLength, -fLength, -fLength,
        fLength, -fLength, -fLength,
        -fLength, -fLength,  fLength,
        fLength, -fLength,  fLength
    };
    //unsigned int skyboxVAO, skyboxVBO;
    glGenVertexArrays(1, &m_uiSkyboxVAO);
    glGenBuffers(1, &m_uiSkyboxVBO);
    glBindVertexArray(m_uiSkyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_uiSkyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    m_pShader = new Shader();
    std::string strPath = Base::Instance()->GetAppPath() + "/data/shader/SkyBox/";
    m_pShader->ReadShader(strPath + "skybox.vs", GL_VERTEX_SHADER);
    m_pShader->ReadShader(strPath + "skybox.fs", GL_FRAGMENT_SHADER);
    m_pShader->AttchShders();
    m_pShader->Use();
    m_pShader->SetInt("skybox", 0);
}

void SkyBox::Draw()
{
    //glDepthMask(GL_FALSE);
    glBindVertexArray(m_uiSkyboxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_uiTextureId);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS); // set depth function back to default
    //glDepthMask(GL_TRUE);
}

void SkyBox::SetMPVMatrix(const glm::mat4& view, const glm::mat4& projection)
{
    glDepthFunc(GL_LEQUAL);
    m_pShader->Use();
    m_pShader->SetMat4("view", view);
    m_pShader->SetMat4("projection", projection);
}