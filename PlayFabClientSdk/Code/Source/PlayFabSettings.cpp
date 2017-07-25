#include "StdAfx.h"
#include "PlayFabSettings.h"

using namespace PlayFabClientSdk;

PlayFabSettings PlayFabSettings::playFabSettings; // Global settings for all Apis

PlayFabSettings::PlayFabSettings() :
    playFabSDKVersion("0.0.170530"),
    playFabVersionString("LumberyardSDK-0.0.170530"),
    useDevelopmentEnvironment(false),
    developmentEnvironmentURL(".playfabsandbox.com"),
    productionEnvironmentURL(".playfabapi.com"),
    titleId(), // You must set this value for PlayFab to work properly (Found in the Game Manager for your title, at the PlayFab Website)
    globalErrorHandler(nullptr),
    advertisingIdType(), // Set this to the appropriate AD_TYPE_X constant below
    advertisingIdValue(), // Set this to corresponding device value
    // DisableAdvertising is provided for completeness, but changing it is not suggested
    // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
    disableAdvertising(false),
    AD_TYPE_IDFA("Idfa"),
    AD_TYPE_ANDROID_ID("Adid"),
    serverURL()
{};
