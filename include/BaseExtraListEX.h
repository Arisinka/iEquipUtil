class BaseExtraListEx
{
	public:
		static void InstallHooks();
		static void Dtor(RE::BaseExtraList *a);
		using Dtor_t = decltype(&BaseExtraListEx::Dtor);
		static inline REL::Relocation<Dtor_t> _Dtor; 
};