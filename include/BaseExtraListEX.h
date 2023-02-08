class BaseExtraListEx
{
	public:
		static void InstallHooks();
		static void Dtor(RE::BaseExtraList *a);
		static void Ctor();
		using Dtor_t = decltype(&BaseExtraListEx::Dtor);
		static inline REL::Relocation<Dtor_t> _Dtor; 
};