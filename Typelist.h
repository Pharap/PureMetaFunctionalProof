#pragma once

template< typename ... Ts > struct TypeList {};

using EmptyTypeList = TypeList< void >;

// Cons
template< typename T, typename U > struct ConsDef;
template< typename T > struct ConsDef< T, EmptyTypeList > { using Type = TypeList< T >; };
template< typename T, typename ... Ts > struct ConsDef< T, TypeList< Ts... > > { using Type = TypeList< T, Ts... >; };

// Null
template< typename T > struct NullDef;
template< typename ... Ts > struct NullDef< TypeList< Ts... > > { constexpr static const bool Value = false; };
template< > struct NullDef< EmptyTypeList > { constexpr static const bool Value = true; };

// Length
template< typename T > struct LengthDef;
template< > struct LengthDef< EmptyTypeList > { constexpr static const auto Value = 0ull; };
template< typename T > struct LengthDef< TypeList< T > > { constexpr static const auto Value = 1ull; };
template< typename T, typename ... Ts > struct LengthDef< TypeList< T, Ts... > > { constexpr static const auto Value = 1ull + LengthDef< TypeList< Ts... > >::Value; };

// Head
template< typename T > struct HeadDef;
template< typename T, typename ... Ts > struct HeadDef< TypeList< T, Ts... > > { using Type = T; };

// Tail
template< typename T > struct TailDef;
template< typename T, typename ... Ts > struct TailDef< TypeList< T, Ts... > > { using Type = TypeList< Ts... >; };

// Cons
template< typename T > struct LastDef;
template< typename T > struct LastDef< TypeList< T > > { using Type = T; };
template< typename T, typename ... Ts > struct LastDef< TypeList< T, Ts... > > { using Type = typename LastDef< TypeList< Ts... > >::Type; };

// Init
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

// Reverse
template< typename T > struct ReverseDef;
template< typename ... Ts > struct ReverseDef< TypeList< Ts... > >
{
private:
	template< typename T, typename U > struct ReverseHelper;
	template< typename T, typename ... Ts > struct ReverseHelper< TypeList< T, Ts... >, EmptyTypeList > { using Type = typename ReverseHelper< TypeList< Ts... >, TypeList< T > >::Type; }; // Shift T, Erase void
	template< typename T, typename ... Ts, typename ... Us > struct ReverseHelper< TypeList< T, Ts... >, TypeList< Us... > > { using Type = typename ReverseHelper< TypeList< Ts... >, TypeList< T, Us... > >::Type; }; // Shift T to front
	template< typename T, typename ... Us > struct ReverseHelper< TypeList< T >, TypeList< Us... > > { using Type = TypeList< T, Us... >; }; // The final product

public:
	using Type = typename ReverseHelper< TypeList< Ts... >, EmptyTypeList >::Type;
};

// Concat
template< typename T, typename U > struct ConcatDef;
template< typename ... Ts, typename ... Us > struct ConcatDef< TypeList< Ts... >, TypeList< Us... > > { using Type = TypeList< Ts..., Us... >; };

// Map
template< template< typename > typename Z, typename T > struct MapDef;
template< template< typename > typename Z, typename T, typename ... Ts > struct MapDef< Z, TypeList< T, Ts... > > { using Type = typename ConsDef< typename Z< T >::Type, typename MapDef< Z, TypeList< Ts... > >::Type >::Type; };
template< template< typename > typename Z, typename T > struct MapDef< Z, TypeList< T > > { using Type = TypeList< typename Z< T >::Type >; };

// Foldl
template< template< typename, typename > typename Z, typename U, typename T > struct FoldlDef;
template< template< typename, typename > typename Z, typename U, typename T, typename ... Ts > struct FoldlDef<Z, U, TypeList<T, Ts...>> { using Type = typename FoldlDef<Z, typename Z<U, T>::Type, TypeList<Ts...> >::Type; };
template< template< typename, typename > typename Z, typename U, typename T > struct FoldlDef<Z, U, TypeList<T>> { using Type = typename Z<U, T>::Type; };

// Foldr TODO

// Scanl
template< template< typename, typename > typename Z, typename U, typename T > struct ScanlDef;
template< template< typename, typename > typename Z, typename U, typename T, typename ... Ts > struct ScanlDef<Z, U, TypeList<T, Ts...>> { using Type = typename ConsDef< U,  typename ScanlDef<Z, typename Z<U, T>::Type, TypeList<Ts...> >::Type >::Type; };
template< template< typename, typename > typename Z, typename U, typename T > struct ScanlDef<Z, U, TypeList<T>> { using Type = TypeList< U, typename Z<U, T>::Type >; };

// Scanr
