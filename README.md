# PureMetaFunctionalProof
Proof that C++ templates are effectively a pure functional programming language.

In order to prove this, the library reimagines many of Haskell's common types and functions to show that they can be implemented in C++'s template system.

![Bjarne Stroustrup: I Accidentally; A meta programming language](http://aras-p.info/blog/wp-content/uploads/2009/03/cppaccident.jpg)

---

## TypeList

Like Haskell's basic `[a]` type, but operating on types rather than values.

### Included Features:

- `TypeList< Ts ... >`
- `EmptyTypeList`
- `Cons< T, TypeList< Ts ... > >`
- `Null< TypeList< Ts ... > >`
- `Length< TypeList< Ts ... > >`
- `Head< TypeList< Ts ... > >`
- `Tail< TypeList< Ts ... > >`
- `Last< TypeList< Ts ... > >`
- `Init< TypeList< Ts ... > >`
- `Concat< TypeList< Ts ... >, TypeList< Us ... > >`
- `Reverse< TypeList< Ts ... > >`
- `Map< template< typename > Z, U, TypeList< Ts ... > >`
- `Foldl< template< typename, typename > Z, U, TypeList< Ts ... > >`
- `Scanl< template< typename, typename > Z, U, TypeList< Ts ... > >`

### Planned Features:

- `Foldr< template< typename, typename > Z, U, TypeList< Ts ... > >`
- `Scanr< template< typename, typename > Z, U, TypeList< Ts ... > >`
- `Uncons`
- `Intersperse`
- `Foldl1`
- `Foldr1`
- `Scanl1`
- `Scanr1`
- `Replicate`
- `Take`
- `Drop`
- `SplitAt`
- `TakeWhile`
- `DropWhile`
- `Inits`
- `Tails`
- `Elem`
- `NotElem`
