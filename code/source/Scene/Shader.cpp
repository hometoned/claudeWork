#include <glad/glad.h>

#include <Scene/Shader.h>

#include <fstream>
#include <sstream>

using namespace Scene;

Shader::Shader()
{
}

Shader::~Shader()
{
}

bool Shader::ReadShader(const std::string& strShaderFile, unsigned int uiType)
{
    std::string vShaderCode = ReadShaderFile(strShaderFile);
    if (vShaderCode.empty())
    {
        return false;
    }
    const char* cShaderCode = vShaderCode.c_str();
    CreateShader(cShaderCode, uiType);

    return true;
}

void Shader::AttchShders()
{
    if (m_shaderIds.size() == 0)
    {
        return;
    }
    m_pProgramId = glCreateProgram();
    for (unsigned int& uiId : m_shaderIds)
    {
        glAttachShader(m_pProgramId, uiId);
    }
    glLinkProgram(m_pProgramId);
    for (unsigned int& uiId : m_shaderIds)
    {
        glDeleteShader(uiId);
    }
}

std::string Shader::ReadShaderFile(const std::string& strShaderFile)
{
    std::string shaderCode = "";
    std::ifstream shaderFile;
    shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    shaderFile.open(strShaderFile);
    if (!shaderFile.is_open())
    {
        shaderFile.close();
        return shaderCode;
    };
    std::stringstream vShaderStream;
    vShaderStream << shaderFile.rdbuf();
    shaderFile.close();
    shaderCode = vShaderStream.str();
    return shaderCode;
}

bool Shader::CreateShader(const char* shaderCode, unsigned int shaderType)
{
    std::string strShaderType = "";
    switch (shaderType)
    {
    case GL_VERTEX_SHADER:
    {
        strShaderType = "GL_VERTEX_SHADER";
    }
        break;
    case GL_FRAGMENT_SHADER:
    {
        strShaderType = "GL_FRAGMENT_SHADER";
    }
        break;
    case GL_GEOMETRY_SHADER:
    {
        strShaderType = "GL_GEOMETRY_SHADER";
    }
    default:
        strShaderType = "UNKnow";
        break;
    }
    unsigned int shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderCode, NULL);
    glCompileShader(shaderId);
    GLint success;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (success == 0)
    {
        char infoLog[512];
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        std::cout << strShaderType << " Compile erro, message is " << infoLog << std::endl;
        return false;
    }
    m_shaderIds.push_back(shaderId);
    return true;
}

void Shader::Use()
{
    glUseProgram(m_pProgramId);
}

// utility uniform functions
// ------------------------------------------------------------------------
void Shader::SetBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(m_pProgramId, name.c_str()), (int)value); 
}
// ------------------------------------------------------------------------
void Shader::SetInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(m_pProgramId, name.c_str()), value); 
}
// ------------------------------------------------------------------------
void Shader::SetFloat(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(m_pProgramId, name.c_str()), value); 
}
// ------------------------------------------------------------------------
void Shader::SetVec2(const std::string &name, const glm::vec2 &value) const
{ 
    glUniform2fv(glGetUniformLocation(m_pProgramId, name.c_str()), 1, &value[0]); 
}
void Shader::SetVec2(const std::string &name, float x, float y) const
{ 
    glUniform2f(glGetUniformLocation(m_pProgramId, name.c_str()), x, y); 
}
// ------------------------------------------------------------------------
void Shader::SetVec3(const std::string &name, const glm::vec3 &value) const
{ 
    glUniform3fv(glGetUniformLocation(m_pProgramId, name.c_str()), 1, &value[0]); 
}
void Shader::SetVec3(const std::string &name, float x, float y, float z) const
{ 
    glUniform3f(glGetUniformLocation(m_pProgramId, name.c_str()), x, y, z); 
}
// ------------------------------------------------------------------------
void Shader::SetVec4(const std::string &name, const glm::vec4 &value) const
{ 
    glUniform4fv(glGetUniformLocation(m_pProgramId, name.c_str()), 1, &value[0]); 
}
void Shader::SetVec4(const std::string &name, float x, float y, float z, float w) const
{ 
    glUniform4f(glGetUniformLocation(m_pProgramId, name.c_str()), x, y, z, w); 
}
// ------------------------------------------------------------------------
void Shader::SetMat2(const std::string &name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(m_pProgramId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::SetMat3(const std::string &name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(m_pProgramId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_pProgramId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}