#pragma once

#include "TypeList.h"

template< typename T, typename U > struct ConsDef;
template< typename T > struct ConsDef< T, EmptyTypeList > { using Type = TypeList< T >; };
template< typename T, typename ... Ts > struct ConsDef< T, TypeList< Ts... > > { using Type = TypeList< T, Ts... >; };