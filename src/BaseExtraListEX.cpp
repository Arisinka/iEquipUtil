#include "pch.h"
#include "BaseExtraListEx.h"
#include "Offsets.h"

void BaseExtraListEx::Dtor(RE::BaseExtraList *a)
{
	BaseExtraListEx::_Dtor(a);
}

void BaseExtraListEx::InstallHooks()
{
	// Override to prevent the Native StatsMenu from doing anything.
	REL::Relocation<std::uintptr_t> vTable(IEquip::Offsets::BaseExtraListEx::Vtbl);
	BaseExtraListEx::_Dtor = vTable.write_vfunc(0x0, &BaseExtraListEx::Dtor);
}

void BaseExtraListEx::Ctor()
{
    using func_t = decltype(&BaseExtraListEx::Ctor);
    REL::Relocation<func_t> func{ IEquip::Offsets::BaseExtraListEx::Ctor };
    return func();
}

namespace RE
{
	// BaseExtraList::BaseExtraList()
	// {
	// 	BaseExtraListEx::Ctor();
	// }


// 		ExtraDataList* ConstructExtraDataList()
// {
//     using func_t = ExtraDataList*(*)();
//     REL::Relocation<func_t> func{ RELOCATION_ID(???, 11583) };
//     return func();
// }

// For the address ID, I dumped the AE addresses and found 1401135B0.
// How would I go about finding the ID for SE, as I only know the address for 1.6.640?


// ExtraDataList::Constructor_1401135B0
	//}

	BaseExtraList::~BaseExtraList()
	{
		// Corresponding members are already deleted by RE
		BaseExtraListEx::Dtor(this);
		stl::memzero(this);
	}
}
