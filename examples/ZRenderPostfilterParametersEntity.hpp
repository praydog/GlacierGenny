#pragma once
#include <cstdint>
#include <sdk/TArray.hpp>
#include <sdk/TEntityRef.hpp>
#include <sdk/ZString.hpp>
#include ".\SVector3.hpp"
#include ".\SVector2.hpp"
#include ".\ZEntityImpl.hpp"
#include ".\SColorRGB.hpp"
#include ".\IMiddleGrayCurveEntity.hpp"
#include ".\IRenderPostfilterParametersEntity.hpp"
#pragma pack(push, 1)
class ZRenderPostfilterParametersEntity : public ZEntityImpl, public IRenderPostfilterParametersEntity {
public:
    enum EHDRAdaptationType : uint32_t {
        eMedian = 0,
        eGeometricMean = 1,
    };

    enum EHDRToneMapType : uint32_t {
        eLinear = 0,
        eReinhardRGB = 1,
        eFilmicRGB = 2,
    };

    enum EDOFBlurType : uint32_t {
        eFastest = 0,
        eLowRezLensBlur = 1,
        eLowRezLensBlurSoft = 2,
        eHighRezLensBlur = 3,
    };

    enum EHDRGlareType : uint32_t {
        eCamera = 0,
        eNatural = 1,
        eCheapLens = 2,
        eFilterCrossScreen = 3,
        eFilterCrossScreenSpectral = 4,
        eFilterSnowCross = 5,
        eFilterSnowCrossSpectral = 6,
        eFilterSunnyCross = 7,
        eFilterSunnyCrossSpectral = 8,
        eCinecamVerticalSlits = 9,
        eCinecamHorizontalSlits = 10,
    };

    char pad_20[0x10];
    int32_t m_nParameterId; // 0x30
    char pad_34[0x1];
    bool m_bGaussianBlurEnabled; // 0x35
    char pad_36[0x2];
    float m_fGaussianBlurriness; // 0x38
    char pad_3c[0x9];
    bool m_bRadialBlurEnabled; // 0x45
    char pad_46[0x2];
    float m_fRadialBlurriness; // 0x48
    SVector2 m_vRadialBlurCenter; // 0x4c
    float m_fRadialBlurStart; // 0x54
    float m_fRadialBlurFadeFactor; // 0x58
    char pad_5c[0x1];
    bool m_bSpatialBlurEnabled; // 0x5d
    char pad_5e[0x2];
    SVector3 m_vSpatialBlurCenter; // 0x60
    float m_fSpatialBlurStart; // 0x6c
    float m_fSpatialBlurFade; // 0x70
    float m_fSpatialBlurriness; // 0x74
    char pad_78[0x1];
    bool m_bColorCorrectionEnabled; // 0x79
    char pad_7a[0x2];
    uint8_t BillboardTexture[8]; // 0x7c
    uint8_t ColorCorrectionTextureHDR[8]; // 0x84
    float m_fNeutralBlendWeight; // 0x8c
    char pad_90[0x1];
    bool m_bDepthOfFieldEnabled; // 0x91
    char pad_92[0x2];
    float m_fDepthOfFieldFocusStart; // 0x94
    float m_fDepthOfFieldFocusEnd; // 0x98
    float m_fDepthOfFieldFocalFadeNear; // 0x9c
    float m_fDepthOfFieldFocalFadeFar; // 0xa0
    float m_fDepthOfFieldBlurriness; // 0xa4
    float m_fLensBlur; // 0xa8
    EDOFBlurType m_eBlurQuality; // 0xac
    bool m_bForegroundBlur; // 0xb0
    bool m_bDepthOfFieldUseNew; // 0xb1
    char pad_b2[0x2];
    float m_fDepthOfFieldFocalDistance; // 0xb4
    float m_fDepthOfFieldAperture; // 0xb8
    float m_fLabsDofAnamorphic; // 0xbc
    float m_fLabsDofSwirl; // 0xc0
    char pad_c4[0x1];
    bool m_bDistortionBarrelEnabled; // 0xc5
    char pad_c6[0x2];
    float m_fDistortionBarrelScale; // 0xc8
    SVector2 m_vDistortionBarrel; // 0xcc
    bool m_bDistortionBarrelUseRealTime; // 0xd4
    char pad_d5[0x1];
    bool m_bDistortionWobbleEnabled; // 0xd6
    char pad_d7[0x1];
    float m_fDistortionWobbleScale; // 0xd8
    SVector2 m_vDistortionWobbleWaveLength; // 0xdc
    SVector2 m_vDistortionWobbleSpeed; // 0xe4
    bool m_bDistortionWobbleUseRealTime; // 0xec
    bool m_bDoubleVisionEnabled; // 0xed
    char pad_ee[0x2];
    float m_fDoubleVisionStrength; // 0xf0
    float m_fDoubleVisionSpeed; // 0xf4
    float m_fDoubleVisionEyeSeparation; // 0xf8
    float m_fDoubleVisionSpeed1; // 0xfc
    float m_fDoubleVisionSpeed2; // 0x100
    float m_fDoubleVisionScaleSpeed1; // 0x104
    float m_fDoubleVisionScaleSpeed2; // 0x108
    float m_fDoubleVisionMinScale; // 0x10c
    float m_fDoubleVisionMaxScale; // 0x110
    float m_fDoubleVisionBlendSpeed; // 0x114
    float m_fDoubleVisionBlendStrength; // 0x118
    float m_fDoubleVisionTrailStrength; // 0x11c
    char pad_120[0x1];
    bool m_bFogEnabled; // 0x121
    bool m_bFogUseQuarterRes; // 0x122
    bool m_bFogGlobal; // 0x123
    float m_fFogDensity; // 0x124
    SVector2 m_vFogNearDistances; // 0x128
    SColorRGB m_FogColor; // 0x130
    float m_fFogTurbulenceOpacity; // 0x13c
    SVector3 m_vFogTurbulenceNearScale; // 0x140
    SVector3 m_vFogTurbulenceVelocity; // 0x14c
    float m_fFogTurbulenceChaos; // 0x158
    char pad_15c[0x6d];
    bool m_bHDREnabled; // 0x1c9
    char pad_1ca[0x2];
    SVector2 m_vHDRAdaptationSpeed; // 0x1cc
    SVector2 m_vHDRAdaptationLuminanceMinMax; // 0x1d4
    SVector2 m_vHDRAdaptationMiddleGrayMinMax; // 0x1dc
    char pad_1e4[0x4];
    sdk::TEntityRef<IMiddleGrayCurveEntity> m_HDRAdaptionMiddleGrayCurveEntity; // 0x1e8
    float m_fHDRExposureMeteringSize; // 0x1f8
    EHDRToneMapType m_eHDRToneMapType; // 0x1fc
    float m_fHDRWhitePoint; // 0x200
    float m_fHDRBrightPassThreshold; // 0x204
    float m_fHDRBrightPassMaxPercentage; // 0x208
    SColorRGB m_HDRColorTint; // 0x20c
    bool m_bHDRGlareEnabled; // 0x218
    char pad_219[0x3];
    EHDRGlareType m_eHDRGlareType; // 0x21c
    float m_fHDRBloomFalloff; // 0x220
    float m_fHDRBloomScale; // 0x224
    float m_fHDRStarScale; // 0x228
    SVector2 m_vHDRBloomMinFalloffDistanceMinMax; // 0x22c
    float m_fHDRBloomFalloffDistancePower; // 0x234
    bool m_bHDRLensFlareEnabled; // 0x238
    char pad_239[0x3];
    float m_fHDRLensFlareAttenuation; // 0x23c
    SColorRGB m_HDRLensFlareColorA; // 0x240
    float m_fHDRLensFlareThresholdA; // 0x24c
    SColorRGB m_HDRLensFlareColorB; // 0x250
    float m_fHDRLensFlareThresholdB; // 0x25c
    SColorRGB m_HDRLensFlareColorC; // 0x260
    float m_fHDRLensFlareThresholdC; // 0x26c
    SColorRGB m_HDRLensFlareColorD; // 0x270
    float m_fHDRLensFlareThresholdD; // 0x27c
    char pad_280[0x1];
    bool m_bNoiseEnabled; // 0x281
    char pad_282[0x2];
    float m_fNoiseIntensity; // 0x284
    float m_fNoiseScale; // 0x288
    SVector2 m_vSSAOStrengthNearFar; // 0x28c
    SVector2 m_vSSAODistanceNearFar; // 0x294
    float m_fSSAOOcclusionRange; // 0x29c
    float m_fSSAOAngleOffset; // 0x2a0
    SVector2 m_vSSAOScreenSpaceRadiusLimits; // 0x2a4
    char pad_2ac[0x1];
    bool m_bSSAOEnabled; // 0x2ad
    char pad_2ae[0x2];
    SVector2 m_vASSAOFadeInRange; // 0x2b0
    SVector2 m_vASSAOFadeOutRange; // 0x2b8
    float m_fASSAORadius; // 0x2c0
    float m_fASSAOMultiplier; // 0x2c4
    float m_fASSAOPower; // 0x2c8
    float m_fSharpeningStrength; // 0x2cc
    float m_fVignetteSharpenStrength; // 0x2d0
    float m_fVignetteSharpenPower; // 0x2d4
    float m_fSSRIntensity; // 0x2d8
    float m_fSSRGlossFadeIn; // 0x2dc
    float m_fSSRGlossFadeOut; // 0x2e0
    float m_fSSRSharpenSides; // 0x2e4
    float m_fSSRSharpenTopBottom; // 0x2e8
    float m_fSSRGlossRoughThrd; // 0x2ec
    uint32_t m_nSSRNumStepsRough; // 0x2f0
    uint32_t m_nSSRNumStepsGloss; // 0x2f4
    char pad_2f8[0x1];
    bool m_bVignetteEnabled; // 0x2f9
    char pad_2fa[0x2];
    float m_fVignetteStrength; // 0x2fc
    float m_fVignetteMin; // 0x300
    float m_fVignetteMax; // 0x304
    SColorRGB m_VignetteColor; // 0x308
    float m_fVignetteGradientLightStrength; // 0x314
    float m_fVignetteGradientLightSize; // 0x318
    SColorRGB m_vVignetteGradientLightColor; // 0x31c
    char pad_328[0x38];
    static const char* get_short_name();
    static const char* get_full_name();
}; // Size: 0x360
#pragma pack(pop)
