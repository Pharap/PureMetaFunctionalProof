#pragma once

template< typename T, T V >
struct IntegralConstant
{
	using ValueType = T;
	using Type = IntegralConstant;

	constexpr static const ValueType Value = V;

	constexpr operator ValueType(void) const noexcept { return Value; }
	constexpr ValueType operator()(void) const noexcept { return Value; }
};

template< bool B > using BoolConstant = IntegralConstant< bool, B >;
using TrueType = BoolConstant< true >;
using FalseType = BoolConstant< false >;


template< typename T, typename U > struct IsSame : FalseType {};
template< typename T > struct IsSame<T, T> : TrueType {};


template< bool Expr, typename True, typename False > struct If;
template< typename True, typename False > struct If<true, True, False> { using Type = True; };
template< typename True, typename False > struct If<false, True, False> { using Type = False; };
template< bool Expr, typename True, typename False > using IfT = typename If<Expr, True, False>::Type;