#include <string>

namespace utils
{
    class DynamicLibrary
	{
		void* m_handle = nullptr;

	public:
        DynamicLibrary() = default;
        DynamicLibrary(const std::string& path);

        ~DynamicLibrary();

		bool load(const std::string& path);
		void close();

	private:
		void* get_impl(const std::string& name) const;

	public:
		template <typename Type = void>
		Type* get(const std::string& name) const
		{
			Type* result;
			*reinterpret_cast<void**>(&result) = get_impl(name);
			return result;
		}

		template <typename Type>
		bool get(Type*& function, const std::string& name) const
		{
			*reinterpret_cast<void**>(&function) = get_impl(name);

			return function != nullptr;
		}

		bool loaded() const;
		explicit operator bool() const;
	};

	// (assume the lib is always loaded)
	void* get_proc_address(const char* lib, const char* name);

	template <typename F>
    struct DynamicImport
	{
		static_assert(sizeof(F) == 0, "Invalid function type");
	};

	template <typename R, typename... Args>
    struct DynamicImport<R(Args...)>
	{
		R (*ptr)(Args...);
		const char* const lib;
		const char* const name;

		// Constant initialization
        constexpr DynamicImport(const char* lib, const char* name)
		    : ptr(nullptr)
		    , lib(lib)
		    , name(name)
		{
		}

		void init()
		{
			if (!ptr)
			{
				// TODO: atomic
				ptr = reinterpret_cast<R (*)(Args...)>(get_proc_address(lib, name));
			}
		}

		operator bool()
		{
			init();

			return ptr;
		}

		// Caller
		R operator()(Args... args)
		{
			init();

			return ptr(args...);
		}
	};
}

#define DYNAMIC_IMPORT(lib, name, ...) inline utils::DynamicImport<__VA_ARGS__> name(lib, #name);
