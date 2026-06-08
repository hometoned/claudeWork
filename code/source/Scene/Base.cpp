#include <Scene/Base.h>

using namespace Scene;

Base* Base::m_pBase = nullptr;

Base::Base()
{
}

Base::~Base()
{
}

Base* Base::Instance()
{
    if (m_pBase == nullptr)
    {
        m_pBase = new Base();
    }
    return m_pBase;
}

void Base::SetAppPath(const std::string& strPath)
{
    m_strPath = strPath;
}

const std::string& Base::GetAppPath()
{
    return m_strPath;
}