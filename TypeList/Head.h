#pragma once

#include "TypeList.h"

template< typename T > struct HeadDef;
template< typename T, typename ... Ts > struct HeadDef< TypeList< T, Ts... > > { using Type = T; };