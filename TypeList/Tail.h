#pragma once

#include "TypeList.h"

template< typename T > struct TailDef;
template< typename T, typename ... Ts > struct TailDef< TypeList< T, Ts... > > { using Type = TypeList< Ts... >; };