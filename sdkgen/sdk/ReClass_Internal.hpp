// Created with ReClass.NET 1.1 by KN4CK3R

class ClassFieldDescriptor
{
public:
    char* field_name; //0x0000
    uint64_t field_hash; //0x0008
    class Type_CLASS* field_type; //0x0010
    uint32_t field_offset; //0x0018
    char pad_001C[4]; //0x001C
    uint32_t N00000051; //0x0020
    char pad_0024[20]; //0x0024
}; //Size: 0x0038

class Type_ENUM
{
public:
    uint16_t N0000007E; //0x0000
    uint16_t N0000019E; //0x0002
    char pad_0004[4]; //0x0004
    class EnumDescriptor* descriptor; //0x0008
    int32_t N00000081; //0x0010
    int32_t N000000F0; //0x0014
}; //Size: 0x0018

class BaseTypeDescriptor
{
public:
    void* funcptrs; //0x0000
    uint16_t size; //0x0008
    uint16_t unk_int; //0x000A
    uint32_t type_index; //0x000C
    char* name; //0x0010
    class Type_CLASS* class_type; //0x0018
    char pad_0020[8]; //0x0020
    void* asdfadsg; //0x0028
}; //Size: 0x0030

class EnumDescriptor : public BaseTypeDescriptor
{
public:
    class EnumFieldDescriptor(*enum_start)[32]; //0x0030
    class EnumFieldDescriptor* enum_end; //0x0038
}; //Size: 0x0040

class EnumFieldDescriptor
{
public:
    char* name; //0x0000
    uint64_t value; //0x0008
}; //Size: 0x0010

class TypeDescriptor
{
public:
    void* funcptrs; //0x0000
    char pad_0008[8]; //0x0008
    char* name; //0x0010
    char pad_0018[40]; //0x0018
}; //Size: 0x0040

class ClassDescriptor : public BaseTypeDescriptor
{
public:
    uint16_t num_fields; //0x0030
    uint16_t num_init_data; //0x0032
    uint16_t num_inheritance; //0x0034
    uint16_t num_full_inheritance; //0x0036
    uint32_t num_unk; //0x0038
    char pad_003C[4]; //0x003C
    class ClassFieldDescriptor(*fields)[64]; //0x0040
    class ClassInitData(*init_data)[8]; //0x0048
    class HeirarchyDescriptor(*base_inheritance)[16]; //0x0050
    class HeirarchyDescriptor(*full_inheritance)[32]; //0x0058
    class ClassFunction(*functions)[16]; //0x0060
}; //Size: 0x0068

class Type_CLASS
{
public:
    uint16_t type_type; //0x0000
    uint16_t N00000197; //0x0002
    char pad_0004[4]; //0x0004
    class ClassDescriptor* descriptor; //0x0008
    class Type_CLASS* child; //0x0010
}; //Size: 0x0018

class ClassInitData
{
public:
    void* constructor; //0x0000
    char pad_0008[8]; //0x0008
    class InitDataThing* init_thing; //0x0010
}; //Size: 0x0018

class HeirarchyDescriptor
{
public:
    class Type_CLASS* klass; //0x0000
    int64_t offset; //0x0008
}; //Size: 0x0010

class ClassFunction
{
public:
    uint64_t hash; //0x0000
    void* func1; //0x0008
    void* func2; //0x0010
    char pad_0018[16]; //0x0018
}; //Size: 0x0028

class Type_PRIMITIVE
{
public:
    uint16_t type_type; //0x0000
    uint16_t N00000193; //0x0002
    char pad_0004[4]; //0x0004
    class BaseTypeDescriptor* descriptor; //0x0008
    int32_t N0000015A; //0x0010
    int32_t N00000189; //0x0014
}; //Size: 0x0018

class N000000D3
{
public:
    class ZTypeRegistry* N000000D4; //0x0000
}; //Size: 0x0008

class ZTypeRegistry
{
public:
    char pad_0008[56]; //0x0008
    int32_t num_types; //0x0040
    int32_t N000001ED; //0x0044
    int32_t num_allocated; //0x0048
    char pad_004C[12]; //0x004C
    class TypeRegistryType(*types)[5737]; //0x0058

    virtual void Function0();
    virtual void Function1();
    virtual void Function2();
    virtual void Function3();
    virtual void Function4();
}; //Size: 0x0060

class TypeRegistryType
{
public:
    int32_t N000001B9; //0x0000
    char pad_0004[12]; //0x0004
    char* name; //0x0010
    class Type_CLASS* type_info; //0x0018
}; //Size: 0x0020

class TArrayDescriptor : public BaseTypeDescriptor
{
public:
    class Type_CLASS* contained_type; //0x0030
    char(*funcptrs2)[1][8]; //0x0038
    void* unk_func; //0x0040
}; //Size: 0x0048

class InitDataThing
{
public:
    uint32_t unk_int; //0x0000
    char pad_0004[4]; //0x0004
    void* unk_func; //0x0008
    class Type_PRIMITIVE* maybe_func_ret; //0x0010
    class InitDataThing2* more_type_info; //0x0018
}; //Size: 0x0020

class InitDataThing2
{
public:
    uint32_t unk_int; //0x0000
    char pad_0004[12]; //0x0004
    class Type_CLASS* type_info; //0x0010
}; //Size: 0x0018