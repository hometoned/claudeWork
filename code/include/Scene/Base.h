#pragma once

#include <Scene/Export.h>

#include <string>

namespace Scene
{
    class SCENE_EXPORT Base
    {
    public:
        Base();
        ~Base();
        static Base* Instance();

        void SetAppPath(const std::string& strPath);
        const std::string& GetAppPath();
    private:
        static Base* m_pBase;
        std::string m_strPath = "";
    };

}