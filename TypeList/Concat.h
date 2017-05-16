#pragma once

#include "TypeList.h"

template< typename T, typename U > struct ConcatDef;
template< typename ... Ts, typename ... Us > struct ConcatDef< TypeList< Ts... >, TypeList< Us... > > { using Type = TypeList< Ts..., Us... >; };