## `inline`

I assumed that an `inline` or `always_inline` declared fn could be used anywhere in the codebase and would not have an external symbol.  It looks like `inline` prevents a fn from being used outside its own compilation unit.

```
nm -gAC inline
inline: 0000000100003e30  T one()
inline: 0000000100003f30  T zero()
inline: 0000000100003f40  T three()
inline: 0000000100000000  T __mh_execute_header
inline: 0000000100003e40  T _main
inline:                   U _printf
inline:                   U dyld_stub_binder
```
