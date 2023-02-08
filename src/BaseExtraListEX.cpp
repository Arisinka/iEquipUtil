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

namespace RE
{
	BaseExtraList::~BaseExtraList()
	{	
		while (data) {
			auto xData = data;
			data = xData->next;
			delete xData;
		}
		data = nullptr;
		free(presence);
		presence = nullptr;

		BaseExtraListEx::Dtor(this);
		stl::memzero(this);
	}
}
