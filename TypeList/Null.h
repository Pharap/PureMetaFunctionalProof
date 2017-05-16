#pragma 

#include "TypeList.h"

template< typename T > struct NullDef;
template< typename ... Ts > struct NullDef< TypeList< Ts... > > { constexpr static const bool Value = false; };
template< > struct NullDef< EmptyTypeList > { constexpr static const bool Value = true; };