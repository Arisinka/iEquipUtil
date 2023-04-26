#include "pch.h"
#include "BaseExtraListEx.h"
#include "Offsets.h"

void BaseExtraListEx::Dtor(RE::BaseExtraList *a)
{
	BaseExtraListEx::_Dtor(a);
}

void BaseExtraListEx::InstallHooks()
{
	// Hook the Dtor that is now in the vtable and call that when the Dtor here is called
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
