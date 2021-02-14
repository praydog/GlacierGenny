#pragma once
#include <cstdint>
#include <sdk/TArray.hpp>
#include <sdk/TEntityRef.hpp>
#include ".\IChildNetworkEntity.hpp"
#include ".\ICharacterMovementState.hpp"
#include ".\IVariationResourceEntity.hpp"
#include ".\ZGuid.hpp"
#include ".\ZRepositoryID.hpp"
#include ".\ZHeroGuideController.hpp"
#include ".\ZEntityRef.hpp"
#include ".\ZHeroInteractionController.hpp"
#include ".\ZItemPlacementConfigurationEntity.hpp"
#include ".\ZPhysicsSystemEntity.hpp"
#include ".\ICharacterLocationState.hpp"
#include ".\ICharacterArrestState.hpp"
#include ".\ZBodyPartEntity.hpp"
#include ".\ZRuntimeResourceID.hpp"
#include ".\ZHeroIKController.hpp"
#include ".\ZCheatController.hpp"
#include ".\IControllableCharacter.hpp"
#include ".\ZHeroActorTagController.hpp"
#include ".\ZCharacter.hpp"
#include ".\ZHM5MainCamera.hpp"
#include ".\ZHM5BaseCharacter.hpp"
#include ".\IFutureCameraState.hpp"
#include ".\ICharacterCollision.hpp"
#include "genny\Generated5393658608.hpp"
#include ".\ICharacterCombatState.hpp"
#include "genny\Generated5393658624.hpp"
#include ".\IHM5ActionEntityListener.hpp"
#include ".\ICharacterIllegalInteractionsState.hpp"
#include ".\ISavableEntity.hpp"
#include ".\IAIGameplayConcept.hpp"
#include ".\ICharacterInventoryState.hpp"
#include ".\ICharacterFriskingState.hpp"
#include ".\ICharacterShowItemState.hpp"
#include ".\ICharacterCameraState.hpp"
#pragma pack(push, 1)
class ZHitman5 : public ZHM5BaseCharacter, public IFutureCameraState, public ICharacterCollision, public genny::Generated5393658608, public genny::Generated5393658624, public IControllableCharacter, public IHM5ActionEntityListener, public ISavableEntity, public IAIGameplayConcept, public ICharacterMovementState, public ICharacterCombatState, public ICharacterInventoryState, public ICharacterFriskingState, public ICharacterShowItemState, public ICharacterArrestState, public ICharacterIllegalInteractionsState, public ICharacterLocationState, public ICharacterCameraState {
public:
    char pad_348[0x3c8];
    ZRepositoryID m_InitialOutfitId; // 0x710
    ZEntityRef m_MorphemeEntityID; // 0x720
    ZEntityRef m_Animator; // 0x728
    sdk::TEntityRef<ZPhysicsSystemEntity> m_rRagdollEntity; // 0x730
    sdk::TEntityRef<IChildNetworkEntity> m_rDefaultPickupNetwork; // 0x740
    sdk::TEntityRef<ZItemPlacementConfigurationEntity> m_placementconfiguration; // 0x750
    bool m_bStreamableDisguiseGive; // 0x760
    char pad_761[0x7];
    sdk::TEntityRef<IVariationResourceEntity> m_DefaultWeaponVariationResource; // 0x768
    uint8_t m_EnvironmentClothColliders[24]; // 0x778
    char pad_790[0x18];
    ZGuid m_CharacterId; // 0x7a8
    char pad_7b8[0x68];
    sdk::TEntityRef<ZBodyPartEntity> m_pVRHeadReplacement; // 0x820
    sdk::TEntityRef<ZBodyPartEntity> m_pVROldHeadReplacement; // 0x830
    ZRuntimeResourceID m_SeasonOneHead1; // 0x840
    ZRuntimeResourceID m_SeasonOneHead2; // 0x848
    ZRuntimeResourceID m_SeasonOneHead3; // 0x850
    ZRuntimeResourceID m_SeasonOneHead4; // 0x858
    ZRuntimeResourceID m_SeasonOneHead5; // 0x860
    char pad_868[0x4d0];
    bool m_bIsInvincible; // 0xd38
    char pad_d39[0x7];
    sdk::TEntityRef<ZHeroGuideController> m_pGuideController; // 0xd40
    sdk::TEntityRef<ZHeroIKController> m_pIKController; // 0xd50
    sdk::TEntityRef<ZCheatController> m_pCheatController; // 0xd60
    sdk::TEntityRef<ZHeroInteractionController> m_pInteractionController; // 0xd70
    sdk::TEntityRef<ZHeroActorTagController> m_pActorTagController; // 0xd80
    sdk::TEntityRef<ZCharacter> m_pCharacter; // 0xd90
    char pad_da0[0x338];
    sdk::TEntityRef<ZHM5MainCamera> m_rMainCamera; // 0x10d8
    char pad_10e8[0x88];
    static const char* get_short_name();
    static const char* get_full_name();
}; // Size: 0x1170
#pragma pack(pop)
