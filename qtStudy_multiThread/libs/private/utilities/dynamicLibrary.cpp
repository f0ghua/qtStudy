//#include "stdafx.h"
#include "dynamicLibrary.h"

#ifdef _WIN32
	#include <Windows.h>
#else
	#include <dlfcn.h>
#endif

namespace utils
{
    DynamicLibrary::DynamicLibrary(const std::string& path)
	{
		load(path);
	}

    DynamicLibrary::~DynamicLibrary()
	{
		close();
	}

    bool DynamicLibrary::load(const std::string& path)
	{
#ifdef _WIN32
		m_handle = LoadLibraryA(path.c_str());
#else
		m_handle = dlopen(path.c_str(), RTLD_LAZY);
#endif
		return loaded();
	}

    void DynamicLibrary::close()
	{
#ifdef _WIN32
		FreeLibrary(reinterpret_cast<HMODULE>(m_handle));
#else
		dlclose(m_handle);
#endif
		m_handle = nullptr;
	}

    void* DynamicLibrary::get_impl(const std::string& name) const
	{
#ifdef _WIN32
		return reinterpret_cast<void*>(GetProcAddress(reinterpret_cast<HMODULE>(m_handle), name.c_str()));
#else
		return dlsym(m_handle, name.c_str());
#endif
	}

    bool DynamicLibrary::loaded() const
	{
		return m_handle != nullptr;
	}

    DynamicLibrary::operator bool() const
	{
		return loaded();
	}

	void* get_proc_address(const char* lib, const char* name)
	{
#ifdef _WIN32
		return reinterpret_cast<void*>(GetProcAddress(GetModuleHandleA(lib), name));
#else
		return dlsym(dlopen(lib, RTLD_NOLOAD), name);
#endif
	}
}
