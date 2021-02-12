# GlacierGenny
Generates a C++ SDK for Glacier Engine games (HITMAN3 only right now) 

Uses [sdkgenny](https://github.com/cursey/sdkgenny) by [@cursey](https://github.com/cursey).

## Background
This project was born out of curiosity and became a real-world application of [sdkgenny](https://github.com/cursey/sdkgenny). I noticed that there was a reflection/introspection system in HITMAN3 when working on [HITMAN3FIX](https://github.com/praydog/HITMAN3FIX) and decided to poke around.

The Glacier engine has something akin to "named pointers" or "pool tags". There's a particular pool named "ioi_typeinforegistry" (`ZTypeRegistry`) which contains a list of all the registered types that can be used for introspection/reflection.

Among the supported types for introspection are:
* Enums
  * Names & Values
* Classes
  * Full inheritance heirarchy
  * Size
  * Fields
    * Offsets
    * Names
    * Types
* Primitive types
* Template classes
