#pragma once

#include "TypeList.h"

template< typename T > struct LengthDef;
template< > struct LengthDef< EmptyTypeList > { constexpr static const auto Value = 0ull; };
template< typename T > struct LengthDef< TypeList< T > > { constexpr static const auto Value = 1ull; };
template< typename T, typename ... Ts > struct LengthDef< TypeList< T, Ts... > > { constexpr static const auto Value = 1ull + LengthDef< TypeList< Ts... > >::Value; };