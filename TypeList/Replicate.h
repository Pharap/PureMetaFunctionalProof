#pragma once

#include "TypeList.h"
#include "Cons.h"

template< unsigned long long N, typename T > struct ReplicateDef;
template< unsigned long long N, typename T > struct ReplicateDef { using Type = typename ConsDef< T, typename ReplicateDef< N - 1, T >::Type >::Type; };
template< typename T > struct ReplicateDef < 1, T > { using Type = TypeList<T>; };
template< typename T > struct ReplicateDef < 0, T > { using Type = EmptyTypeList; };