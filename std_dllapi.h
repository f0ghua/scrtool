#pragma once

#include <windows.h>

class AbstractFunction
{
public:
    using Adress = void(*)();
    AbstractFunction(const char *moduleName, const char *funcName)
        : m_moduleName(moduleName)
        , m_funcName{funcName}
    {}

    ~AbstractFunction()
    {
        if (m_moduleHandle) {
            FreeLibrary(m_moduleHandle);
        }
    }

    void resolveFunction()
    {
        if(m_funcName) {
            getProcAdress(m_funcName);
        }
    }

    const char *name() const {return m_funcName;}
    Adress adress() const {return m_funcAdress;}

protected:
    Adress m_funcAdress{nullptr};


private:
    void getProcAdress(const char *name)
    {
        m_moduleHandle = LoadLibraryA(m_moduleName);
        if (m_moduleHandle != nullptr) {
            auto p = reinterpret_cast<void *>(GetProcAddress(m_moduleHandle, name));
            m_funcAdress = reinterpret_cast<Adress>(p);
        }
    }

    const char *m_moduleName;
    const char *m_funcName;
    HMODULE m_moduleHandle{nullptr};
};

template<typename ReturnType, typename... Args>
class Function : public AbstractFunction
{
public:

    using FunctionPointer =  ReturnType(*)(Args...);

    Function(const char *moduleName, const char *funcName)
        : AbstractFunction{moduleName, funcName}
    {}

    ReturnType operator()(Args... arguments)
    {
        if(m_funcAdress)
            return reinterpret_cast<FunctionPointer>(m_funcAdress)(arguments...);
        else
        {
            resolveFunction();
            return reinterpret_cast<FunctionPointer>(m_funcAdress)(arguments...);
        }
    }
};

