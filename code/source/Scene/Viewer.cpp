#include <glad/glad.h>
#include <Scene/Viewer.h>

namespace Scene
{

    Viewer::Viewer()
    {
    }

    Viewer::~Viewer()
    {
    }

    void Viewer::Init()
    {
        gladLoadGL();
    }

    void Viewer::SetViewport(int ix, int iy, int iWidth, int iHeight)
    {
        glViewport(ix, iy, iWidth, iHeight);
    }

    void Viewer::Clear()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Viewer::AddSkyBox(Scene::SkyBox* pSkyBox)
    {
    }
}