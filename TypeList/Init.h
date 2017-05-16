#pragma once

#include "TypeList.h"

template< typename T > struct InitDef;
template< typename ... Ts > struct InitDef< TypeList< Ts... > >
{
private:
	template< typename T, typename U > struct InitDefHelper;
	template< typename T, typename ... Ts > struct InitDefHelper< TypeList< T, Ts... >, EmptyTypeList > { using Type = typename InitDefHelper< TypeList<Ts...>, TypeList< T > >::Type; }; // Shift T, Erase void
	template< typename T, typename ... Ts, typename... Us > struct InitDefHelper< TypeList< T, Ts... >, TypeList< Us... > > { using Type = typename InitDefHelper<TypeList< Ts... >, TypeList< Us..., T > >::Type; }; // Shift T to end
	template< typename T, typename ... Us > struct InitDefHelper< TypeList< T >, TypeList< Us... > > { using Type = TypeList< Us... >; };

public:
	using Type = typename InitDefHelper< TypeList< Ts... >, EmptyTypeList >::Type;
};
template< typename T > struct InitDef< TypeList< T > > { using Type = T; };