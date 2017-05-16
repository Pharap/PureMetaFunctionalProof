#pragma once

#include "TypeList.h"
#include "Scanl.h"

template< template< typename, typename > typename Z, typename T > struct Scanl1Def;
template< template< typename, typename > typename Z, typename T, typename ... Ts > struct Scanl1Def<Z, TypeList<T, Ts...>> { using Type = typename ScanlDef<Z, T, TypeList<Ts...> >::Type; };