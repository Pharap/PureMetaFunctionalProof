#pragma once

#include "TypeList.h"

template< typename T > struct LastDef;
template< typename T > struct LastDef< TypeList< T > > { using Type = T; };
template< typename T, typename ... Ts > struct LastDef< TypeList< T, Ts... > > { using Type = typename LastDef< TypeList< Ts... > >::Type; };