#pragma once

#include "TypeList.h"
#include "Cons.h"

template< template< typename > typename Z, typename T > struct MapDef;
template< template< typename > typename Z, typename T, typename ... Ts > struct MapDef< Z, TypeList< T, Ts... > > { using Type = typename ConsDef< typename Z< T >::Type, typename MapDef< Z, TypeList< Ts... > >::Type >::Type; };
template< template< typename > typename Z, typename T > struct MapDef< Z, TypeList< T > > { using Type = TypeList< typename Z< T >::Type >; };
