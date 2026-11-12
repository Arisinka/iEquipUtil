#include "pch.h"
#include "AmmoExt.h"


namespace AmmoExt
{
	bool IsAmmoBound(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, const RE::TESAmmo* a_ammo)
	{
		if (!a_ammo) {
			a_vm->TraceStack("a_ammo is a NONE form!", a_stackID, Severity::kWarning);
			return false;
		}

		auto dobj = RE::BGSDefaultObjectManager::GetSingleton();
		auto weapTypeBoundArrow = dobj->GetObject<RE::BGSKeyword>(RE::DefaultObjectID::kKeywordWeaponTypeBoundArrow);
		return weapTypeBoundArrow && a_ammo->AsKeywordForm()->HasKeyword(*weapTypeBoundArrow);
	}


	bool RegisterFuncs(VM* a_vm)
	{
		a_vm->RegisterFunction("IsAmmoBound", "iEquip_AmmoExt", IsAmmoBound, true);

		return true;
	}
}
