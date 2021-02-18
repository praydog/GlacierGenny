// Created with ReClass.NET 1.1 by KN4CK3R

class ClassFieldDescriptor {
public:
    char* field_name;             // 0x0000
    uint64_t field_hash;          // 0x0008
    class Type_CLASS* field_type; // 0x0010
    uint32_t field_offset;        // 0x0018
    char pad_001C[4];             // 0x001C
    uint8_t flags;                // 0x0020
    uint8_t N000005AB;            // 0x0021
    char pad_0022[6];             // 0x0022
    void* set_field;              // 0x0028
    void* get_field;              // 0x0030
};                                // Size: 0x0038

class Type_ENUM {
public:
    uint16_t N0000007E;               // 0x0000
    uint16_t N0000019E;               // 0x0002
    char pad_0004[4];                 // 0x0004
    class EnumDescriptor* descriptor; // 0x0008
    int32_t N00000081;                // 0x0010
    int32_t N000000F0;                // 0x0014
};                                    // Size: 0x0018

class BaseTypeDescriptor {
public:
    void* funcptrs;               // 0x0000
    uint16_t size;                // 0x0008
    uint16_t unk_int;             // 0x000A
    uint32_t type_index;          // 0x000C
    char* name;                   // 0x0010
    class Type_CLASS* class_type; // 0x0018
    char pad_0020[8];             // 0x0020
    void* asdfadsg;               // 0x0028
};                                // Size: 0x0030

class EnumDescriptor : public BaseTypeDescriptor {
public:
    class EnumFieldDescriptor (*enum_start)[32]; // 0x0030
    class EnumFieldDescriptor* enum_end;         // 0x0038
};                                               // Size: 0x0040

class EnumFieldDescriptor {
public:
    char* name;     // 0x0000
    uint64_t value; // 0x0008
};                  // Size: 0x0010

class TypeDescriptor {
public:
    void* funcptrs;    // 0x0000
    char pad_0008[8];  // 0x0008
    char* name;        // 0x0010
    char pad_0018[40]; // 0x0018
};                     // Size: 0x0040

class ClassDescriptor : public BaseTypeDescriptor {
public:
    uint16_t num_fields;                               // 0x0030
    uint16_t num_init_data;                            // 0x0032
    uint16_t num_inheritance;                          // 0x0034
    uint16_t num_full_inheritance;                     // 0x0036
    uint32_t num_unk;                                  // 0x0038
    char pad_003C[4];                                  // 0x003C
    class ClassFieldDescriptor (*fields)[64];          // 0x0040
    class ClassInitData (*init_data)[8];               // 0x0048
    class HeirarchyDescriptor (*base_inheritance)[16]; // 0x0050
    class HeirarchyDescriptor (*full_inheritance)[32]; // 0x0058
    class ClassFunction (*functions)[16];              // 0x0060
};                                                     // Size: 0x0068

class Type_CLASS {
public:
    uint16_t type_type;                // 0x0000
    uint16_t N00000197;                // 0x0002
    char pad_0004[4];                  // 0x0004
    class ClassDescriptor* descriptor; // 0x0008
    class Type_CLASS* child;           // 0x0010
};                                     // Size: 0x0018

class ClassInitData {
public:
    void* constructor;               // 0x0000
    char pad_0008[8];                // 0x0008
    class InitDataThing* init_thing; // 0x0010
};                                   // Size: 0x0018

class HeirarchyDescriptor {
public:
    class Type_CLASS* klass; // 0x0000
    int64_t offset;          // 0x0008
};                           // Size: 0x0010

class ClassFunction {
public:
    uint64_t hash;     // 0x0000
    void* func1;       // 0x0008
    void* func2;       // 0x0010
    char pad_0018[16]; // 0x0018
};                     // Size: 0x0028

class Type_PRIMITIVE {
public:
    uint16_t type_type;                   // 0x0000
    uint16_t N00000193;                   // 0x0002
    char pad_0004[4];                     // 0x0004
    class BaseTypeDescriptor* descriptor; // 0x0008
    int32_t N0000015A;                    // 0x0010
    int32_t N00000189;                    // 0x0014
};                                        // Size: 0x0018

class N000000D3 {
public:
    class ZTypeRegistry* N000000D4; // 0x0000
};                                  // Size: 0x0008

class ZTypeRegistry {
public:
    char pad_0008[56];                     // 0x0008
    int32_t num_types;                     // 0x0040
    int32_t N000001ED;                     // 0x0044
    int32_t num_allocated;                 // 0x0048
    char pad_004C[12];                     // 0x004C
    class TypeRegistryType (*types)[5737]; // 0x0058

    virtual void Function0();
    virtual void Function1();
    virtual void Function2();
    virtual void Function3();
    virtual void Function4();
}; // Size: 0x0060

class TypeRegistryType {
public:
    int32_t N000001B9;           // 0x0000
    char pad_0004[12];           // 0x0004
    char* name;                  // 0x0010
    class Type_CLASS* type_info; // 0x0018
};                               // Size: 0x0020

class TArrayDescriptor : public BaseTypeDescriptor {
public:
    class Type_CLASS* contained_type; // 0x0030
    char (*funcptrs2)[1][8];          // 0x0038
    void* unk_func;                   // 0x0040
};                                    // Size: 0x0048

class InitDataThing {
public:
    uint32_t unk_int;                     // 0x0000
    char pad_0004[4];                     // 0x0004
    void* unk_func;                       // 0x0008
    class Type_PRIMITIVE* maybe_func_ret; // 0x0010
    class InitDataThing2* more_type_info; // 0x0018
};                                        // Size: 0x0020

class InitDataThing2 {
public:
    uint32_t unk_int;            // 0x0000
    char pad_0004[12];           // 0x0004
    class Type_CLASS* type_info; // 0x0010
};                               // Size: 0x0018

class TEntityRef_RECLASS {
public:
    class ZCameraEntity_RECLASS* base; // 0x0000
    void* ptr;                         // 0x0008
};                                     // Size: 0x0010

class N000000F7 {
public:
    char pad_0000[40];                  // 0x0000
    class TEntityRef_RECLASS N00000101; // 0x0028
    char pad_0038[8];                   // 0x0038
};                                      // Size: 0x0040

class ZCameraEntity_RECLASS {
public:
    char pad_0000[216]; // 0x0000
    uint32_t N00000142; // 0x00D8
    float N00000151;    // 0x00DC
    float N00000143;    // 0x00E0
    float N000001D7;    // 0x00E4
    float N00000144;    // 0x00E8
    float N000001DB;    // 0x00EC
    float N00000145;    // 0x00F0
    char pad_00F4[380]; // 0x00F4
};                      // Size: 0x0270

class ZActiveCameraController_RECLASS {
public:
    char pad_0000[24];                  // 0x0000
    class TEntityRef_RECLASS N000001E7; // 0x0018
    class TEntityRef_RECLASS N000001E8; // 0x0028
};                                      // Size: 0x0038

class ZHitman5_RECLASS {
public:
    char pad_0000[4312];                     // 0x0000
    class TEntityRef_RECLASS m_rMainCammera; // 0x10D8
    char pad_10E8[864];                      // 0x10E8
};                                           // Size: 0x1448

class ZHM5MainCamera_RECLASS : public ZCameraEntity_RECLASS {
public:
    bool active;        // 0x0270
    char pad_0271[463]; // 0x0271
};                      // Size: 0x0440

class ZActorManager {
public:
    char pad_0000[8];                   // 0x0000
    class TEntityRef_RECLASS N00000B49; // 0x0008
    char pad_0018[1072];                // 0x0018
};                                      // Size: 0x0448

class SaveSystem {
public:
    char pad_0000[200];                        // 0x0000
    class N00000E18 (*save_systems_start)[64]; // 0x00C8
    void* save_systems_end;                    // 0x00D0
    char pad_00D8[872];                        // 0x00D8
};                                             // Size: 0x0440

class N00000E18 {
public:
    class N00000E40* game_system; // 0x0000
    uint32_t hash;                // 0x0008
    char pad_000C[4];             // 0x000C
};                                // Size: 0x0010

class N00000E40 {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class ZEntityManager {
public:
    char pad_0000[16];                       // 0x0000
    class N00000E96* N00000E46;              // 0x0010
    char pad_0018[16];                       // 0x0018
    int32_t num_entities;                    // 0x0028
    int32_t N00000F37;                       // 0x002C
    int32_t max_entities;                    // 0x0030
    char pad_0034[4];                        // 0x0034
    class N00000FEC (*entities_hashes)[245]; // 0x0038
    class N00000F7F (*entities_array)[711];  // 0x0040
    char pad_0048[256];                      // 0x0048
};                                           // Size: 0x0148

class N00000E96 {
public:
    class N00000EDC* N00000E97; // 0x0000
    char pad_0008[264];         // 0x0008
};                              // Size: 0x0110

class N00000EDC {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class N00000F7F {
public:
    int32_t N00000F80; // 0x0000
    char pad_0004[20]; // 0x0004
};                     // Size: 0x0018

class N00000FEC {
public:
    char pad_0000[32]; // 0x0000
};                     // Size: 0x0020

class ModuleDescriptor {
public:
    uint16_t id_maybe;            // 0x0000
    char pad_0002[6];             // 0x0002
    char* name;                   // 0x0008
    class ZSimpleModuleBase* mod; // 0x0010
};                                // Size: 0x0018

class ZGlacierModuleManager {
public:
    class ZApplicationEngineWin32* application_engine; // 0x0000
    char pad_0008[8];                                  // 0x0008
    uint32_t num_modules;                              // 0x0010
    char pad_0014[4];                                  // 0x0014
    class ModuleDescriptor modules[72];                // 0x0018
};                                                     // Size: 0x06D8

class ZSimpleModuleBase {
public:
    char pad_0000[16];                  // 0x0000
    char* name;                         // 0x0010
    char pad_0018[72];                  // 0x0018
    class ModuleInterfaces* interfaces; // 0x0060
};                                      // Size: 0x0068

class ModuleInterfaces {
public:
    class IComponentInterface_RECLASS* (*systems)[64]; // 0x0000
    void* systems_last;                                // 0x0008
    void* systems_allocated_last;                      // 0x0010
};                                                     // Size: 0x0018

class IComponentInterface_RECLASS {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class ZApplicationEngineWin32 {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008