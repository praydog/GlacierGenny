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
    class ZEntityImpl_Inner_RECLASS* base; // 0x0000
    class N00000778* ptr;                  // 0x0008
};                                         // Size: 0x0010

class N000000F7 {
public:
    char pad_0000[40];                  // 0x0000
    class TEntityRef_RECLASS N00000101; // 0x0028
    char pad_0038[8];                   // 0x0038
};                                      // Size: 0x0040

class ZEntityImpl_Inner_RECLASS {
public:
    class EntityData* entity_data; // 0x0000
    int32_t N000011FA;             // 0x0008
    int32_t impl_type;             // 0x000C
};                                 // Size: 0x0010

class ZSpatialEntity_RECLASS {
public:
    char pad_0000[8];                          // 0x0000
    class ZEntityImpl_Inner_RECLASS N000008B9; // 0x0008
    char pad_0018[84];                         // 0x0018
    uint32_t N000012EC;                        // 0x006C
    char pad_0070[16];                         // 0x0070
    class ZSceneEntity_RECLASS* N000008CB;     // 0x0080
    class N0000133B* N000008CC;                // 0x0088
    void* N000008CD;                           // 0x0090
    void* N000008CE;                           // 0x0098
};                                             // Size: 0x00A0

class ZBoundedEntity_RECLASS : public ZSpatialEntity_RECLASS {
public:
    char pad_00A0[24]; // 0x00A0
};                     // Size: 0x00B8

class ZCameraEntity_RECLASS : public ZBoundedEntity_RECLASS {
public:
    char pad_00B8[23];  // 0x00B8
    uint8_t N00001284;  // 0x00CF
    char pad_00D0[8];   // 0x00D0
    uint32_t N00000142; // 0x00D8
    float N00000151;    // 0x00DC
    float N00000143;    // 0x00E0
    float N000001D7;    // 0x00E4
    float N00000144;    // 0x00E8
    float N000001DB;    // 0x00EC
    float N00000145;    // 0x00F0
    char pad_00F4[27];  // 0x00F4
    bool N000011D5;     // 0x010F
    char pad_0110[352]; // 0x0110
};                      // Size: 0x0270

class ZActiveCameraController_RECLASS {
public:
    char pad_0000[24];                  // 0x0000
    class TEntityRef_RECLASS N000001E7; // 0x0018
    class TEntityRef_RECLASS N000001E8; // 0x0028
};                                      // Size: 0x0038

class ZHitman5_RECLASS {
public:
    char pad_0000[8];                          // 0x0000
    class ZEntityImpl_Inner_RECLASS N000011A4; // 0x0008
    char pad_0018[1816];                       // 0x0018
    class TEntityRef_RECLASS physics;          // 0x0730
    char pad_0740[2456];                       // 0x0740
    class TEntityRef_RECLASS m_rMainCammera;   // 0x10D8
    char pad_10E8[864];                        // 0x10E8
};                                             // Size: 0x1448

class ZHM5MainCamera_RECLASS : public ZCameraEntity_RECLASS {
public:
    bool active;                                                  // 0x0270
    char pad_0271[31];                                            // 0x0271
    class ZHM5CameraProfileBlendDatabase_RECLASS* blend_database; // 0x0290
    char pad_0298[16];                                            // 0x0298
    class TEntityRef_RECLASS peek;                                // 0x02A8
    char pad_02B8[24];                                            // 0x02B8
    class ZHM53rdPersonCamera* third_person_cam;                  // 0x02D0
    char pad_02D8[8];                                             // 0x02D8
    class ZHM5AnimCamera* anim_cam;                               // 0x02E0
    char pad_02E8[1164];                                          // 0x02E8
    float N000013D9;                                              // 0x0774
    char pad_0778[124];                                           // 0x0778
};                                                                // Size: 0x07F4

class ZActorManager {
public:
    char pad_0000[8];                        // 0x0000
    class TEntityRef_RECLASS actors[500];    // 0x0008
    char pad_1F48[32];                       // 0x1F48
    class TEntityRef_RECLASS N000017AF[500]; // 0x1F68
    char pad_3EA8[216];                      // 0x3EA8
};                                           // Size: 0x3F80

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
    int32_t N00000F80;                    // 0x0000
    char pad_0004[12];                    // 0x0004
    class ZEntityImpl_Inner_RECLASS* ent; // 0x0010
};                                        // Size: 0x0018

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
    char pad_0000[8];                                // 0x0000
    uint16_t id_maybe;                               // 0x0008
    char pad_000A[6];                                // 0x000A
    char* name;                                      // 0x0010
    class ModuleInterfaces2* interfaces_alternative; // 0x0018
    char pad_0020[64];                               // 0x0020
    class ModuleInterfaces* interfaces;              // 0x0060
    uint16_t index;                                  // 0x0068
    char pad_006A[6];                                // 0x006A
};                                                   // Size: 0x0070

class ModuleInterfaces {
public:
    class IComponentInterface_RECLASS* (*systems)[100]; // 0x0000
    void* systems_last;                                 // 0x0008
    void* systems_allocated_last;                       // 0x0010
};                                                      // Size: 0x0018

class IComponentInterface_RECLASS {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class ZApplicationEngineWin32 {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class ModuleInterfaces2 {
public:
    char pad_0000[48];                 // 0x0000
    class ModuleInterfaces interfaces; // 0x0030
    char pad_0048[8];                  // 0x0048
};                                     // Size: 0x0050

class TArrayZEntityImpl_Inner {
public:
    class ZEntityImpl_Inner_RECLASS* (*start)[256]; // 0x0000
    void* last;                                     // 0x0008
    void* allocated_end;                            // 0x0010
};                                                  // Size: 0x0018

class GameEntityListDesc {
public:
    void* unk;                              // 0x0000
    class TArrayZEntityImpl_Inner entities; // 0x0008
    char pad_0020[24];                      // 0x0020
};                                          // Size: 0x0038

class ZGameEntityManager {
public:
    char pad_0000[16];                         // 0x0000
    class GameEntityListDesc entity_lists[27]; // 0x0010 0 = doors, 1 = items, 2 = volume triggers 3 = math stuff...?, 8
                                               // = math distance stuff, 16 = evacuation nodes, 24 = bone attach
    char pad_05F8[296]; // 0x05F8
};                      // Size: 0x0720

class EntityData {
public:
    char pad_0000[8];                       // 0x0000
    class EntityDataFields* fields1;        // 0x0008
    class EntityDataFields* fields2;        // 0x0010
    char pad_0018[8];                       // 0x0018
    class EntityDataComponents* components; // 0x0020
    char pad_0028[16];                      // 0x0028
    class EntityDataFunctions* functions;   // 0x0038
    class EntityDataFunctions* functions2;  // 0x0040
    int64_t next_component_offset;          // 0x0048
    int64_t last_component_offset;          // 0x0050
    char pad_0058[8];                       // 0x0058
    class N000007A5* N000015EF;             // 0x0060
    char pad_0068[8];                       // 0x0068
    int32_t N0000146A;                      // 0x0070
};                                          // Size: 0x0074

class EntityDataFields {
public:
    class N00001372 (*start)[64]; // 0x0000
    void* last;                   // 0x0008
    void* allocated_last;         // 0x0010
};                                // Size: 0x0018

class N000012D3 {
public:
    char pad_0000[8];                        // 0x0000
    class TArrayZEntityImpl_Inner N00001238; // 0x0008
    char pad_0020[32];                       // 0x0020
    class TArrayZEntityImpl_Inner N0000114E; // 0x0040
    char pad_0058[32];                       // 0x0058
    class TArrayZEntityImpl_Inner N00001153; // 0x0078
    char pad_0090[32];                       // 0x0090
    class TArrayZEntityImpl_Inner N00001159; // 0x00B0
};                                           // Size: 0x00C8

class N00001372 {
public:
    char pad_0000[40]; // 0x0000
};                     // Size: 0x0028

class EntityDataComponents {
public:
    class HeirarchyDescriptor (*start)[64]; // 0x0000
    void* last;                             // 0x0008
    void* allocated_last;                   // 0x0010
};                                          // Size: 0x0018

class N0000143D {
public:
    class Type_CLASS* klass; // 0x0000
    char pad_0008[8];        // 0x0008
};                           // Size: 0x0010

class N00001753 {
public:
    char pad_0000[16]; // 0x0000
};                     // Size: 0x0010

class N00001755 {
public:
    char pad_0000[16]; // 0x0000
};                     // Size: 0x0010

class ZActorProxyEntity_RECLASS {
public:
    char pad_0000[8];                          // 0x0000
    class ZEntityImpl_Inner_RECLASS N000015CE; // 0x0008
    char pad_0018[8];                          // 0x0018
    class N00001753 m_rActor;                  // 0x0020
    class N00001755 m_AccidentContext;         // 0x0030
    char pad_0040[72];                         // 0x0040
};                                             // Size: 0x0088

class EntityDataFunctions {
public:
    class EntityDataFunction (*start)[64]; // 0x0000
    void* last;                            // 0x0008
    void* allocated_last;                  // 0x0010
};                                         // Size: 0x0018

class EntityDataFunction {
public:
    char pad_0000[8];               // 0x0000
    class N000016EC* func_data;     // 0x0008
    class Type_PRIMITIVE* ret_type; // 0x0010
    char pad_0018[8];               // 0x0018
    uint32_t hash;                  // 0x0020
    char pad_0024[4];               // 0x0024
};                                  // Size: 0x0028

class N000016EC {
public:
    void* unk;  // 0x0000
    void* func; // 0x0008
};              // Size: 0x0010

class N00000778 {
public:
    char pad_0000[40]; // 0x0000
};                     // Size: 0x0028

class N000007A5 {
public:
    class N0000083E (*start)[64]; // 0x0000
    void* last;                   // 0x0008
    void* allocated_last;         // 0x0010
};                                // Size: 0x0018

class N0000083E {
public:
    char pad_0000[32]; // 0x0000
};                     // Size: 0x0020

class ZActorProviderDirect_RECLASS {
public:
    char pad_0000[32];                  // 0x0000
    class TEntityRef_RECLASS N00000AB5; // 0x0020
};                                      // Size: 0x0030

class ClassTypeOut {
public:
    class Type_CLASS* klass; // 0x0000
    void* This;              // 0x0008
};                           // Size: 0x0010

class ZEntityProxy {
public:
    char pad_0000[8];                         // 0x0000
    class TArrayEntityProxyThing* components; // 0x0008
};                                            // Size: 0x0010

class TArrayEntityProxyThing {
public:
    class EntityProxyThing (*first)[64]; // 0x0000
    void* last;                          // 0x0008
    void* allocated_last;                // 0x0010
};                                       // Size: 0x0018

class EntityProxyThing {
public:
    int64_t offset;                // 0x0000
    class EntityData* entity_data; // 0x0008
};                                 // Size: 0x0010

class ZPlayerRegistry {
public:
    char pad_0000[248];                          // 0x0000
    class TEntityRef_RECLASS m_rHitmanCharacter; // 0x00F8
    char pad_0108[1336];                         // 0x0108
};                                               // Size: 0x0640

class TResourcePtr_RECLASS {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class ZPhysicsSystemEntity {
public:
    char pad_0000[52];                    // 0x0000
    class TResourcePtr_RECLASS N000011BA; // 0x0034
    char pad_003C[64];                    // 0x003C
};                                        // Size: 0x007C

class N000011D7 {
public:
    char pad_0000[60];  // 0x0000
    uint8_t N00001274;  // 0x003C
    uint8_t N00001276;  // 0x003D
    char pad_003E[322]; // 0x003E
    uint8_t N00001208;  // 0x0180
    uint8_t N00001261;  // 0x0181
    uint8_t N0000126D;  // 0x0182
    char pad_0183[701]; // 0x0183
};                      // Size: 0x0440

class N000012EF {
public:
    char pad_0000[108]; // 0x0000
    uint8_t N0000128B;  // 0x006C
    uint8_t N0000128E;  // 0x006D
    uint8_t N00001291;  // 0x006E
    uint8_t N0000128F;  // 0x006F
    char pad_0070[48];  // 0x0070
};                      // Size: 0x00A0

class ZSceneEntity_RECLASS {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class N0000133B {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class ZHM5GameCamPOI_RECLASS : public ZSpatialEntity_RECLASS {
public:
    float N0000133F;  // 0x00A0
    float N0000134A;  // 0x00A4
    bool N00001340;   // 0x00A8
    bool N00001352;   // 0x00A9
    bool N00001355;   // 0x00AA
    char pad_00AB[1]; // 0x00AB
    bool N0000134C;   // 0x00AC
    char pad_00AD[3]; // 0x00AD
};                    // Size: 0x00B0

class ZHM53rdPersonCamera {
public:
    char pad_0000[16];                    // 0x0000
    class TEntityRef_RECLASS main_camera; // 0x0010
    char pad_0020[12];                    // 0x0020
    Vector2 rotation;                     // 0x002C
    char pad_0034[4];                     // 0x0034
    int32_t N00001427;                    // 0x0038
    int32_t N000015D1;                    // 0x003C
    char pad_0040[464];                   // 0x0040
    uint32_t N00001462;                   // 0x0210
    char pad_0214[604];                   // 0x0214
    float N000014AE;                      // 0x0470
    char pad_0474[36];                    // 0x0474
    float trace_fraction;                 // 0x0498
    char pad_049C[28];                    // 0x049C
    float N000014B7;                      // 0x04B8
    float N0000162D;                      // 0x04BC
    char pad_04C0[1296];                  // 0x04C0
};                                        // Size: 0x09D0

class TArrayTEntityRef {
public:
    void* first;          // 0x0000
    void* last;           // 0x0008
    void* allocated_last; // 0x0010
};                        // Size: 0x0018

class N00000E08 {
public:
    char pad_0000[160]; // 0x0000
};                      // Size: 0x00A0

class GameCamProfileDesc {
public:
    bool has_data;                    // 0x0000
    char pad_0001[3];                 // 0x0001
    float f1;                         // 0x0004
    float f2;                         // 0x0008
    char pad_000C[4];                 // 0x000C
    class TEntityRef_RECLASS profile; // 0x0010
};                                    // Size: 0x0020

class N00000E4E {
public:
    char pad_0000[8];                          // 0x0000
    class GameCamProfileDesc main_profile;     // 0x0008
    class GameCamProfileDesc override_profile; // 0x0028
    char pad_0048[56];                         // 0x0048
};                                             // Size: 0x0080

class ZHM5CameraProfileBlendDatabase_RECLASS {
public:
    char pad_0000[8];                            // 0x0000
    class ZEntityImpl_Inner_RECLASS N00000BE3;   // 0x0008
    class TArrayTEntityRef m_GameCamProfiles;    // 0x0018
    class TArrayTEntityRef m_GameCamTransitions; // 0x0030
    class TArrayTEntityRef m_GameCamControls;    // 0x0048
    uint8_t array_of_ones[56];                   // 0x0060
    class N00000E08 unknown_data[58];            // 0x0098
    class N00000E4E m_GameCamProfilesEX[58];     // 0x24D8
};                                               // Size: 0x41D8

class ZPeekCameraProfile {
public:
    char pad_0000[8];                          // 0x0000
    class ZEntityImpl_Inner_RECLASS N000009E3; // 0x0008
    char pad_0018[124];                        // 0x0018
    float N00000A0E;                           // 0x0094
    char pad_0098[176];                        // 0x0098
};                                             // Size: 0x0148

class ZHM5AnimCamera {
public:
    char pad_0000[8]; // 0x0000
};                    // Size: 0x0008

class N00000B46 {
public:
    class TEntityRef_RECLASS (*first)[1]; // 0x0000
    void* last;                           // 0x0008
    void* allocated_last;                 // 0x0010
};                                        // Size: 0x0018

class ZHM5GameCamProfileEntity_RECLASS {
public:
    char pad_0000[1088]; // 0x0000
};                       // Size: 0x0440