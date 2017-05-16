#pragma once

#include "TypeList.h"

template< template< typename, typename > typename Z, typename U, typename T > struct ScanlDef;
template< template< typename, typename > typename Z, typename U, typename T, typename ... Ts > struct ScanlDef<Z, U, TypeList<T, Ts...>> { using Type = typename ConsDef< U, typename ScanlDef<Z, typename Z<U, T>::Type, TypeList<Ts...> >::Type >::Type; };
template< template< typename, typename > typename Z, typename U, typename T > struct ScanlDef<Z, U, TypeList<T>> { using Type = TypeList< U, typename Z<U, T>::Type >; };