
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_MatchmakerSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabMatchmakerApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_MatchmakerSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_MatchmakerSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_MatchmakerSysComponent>("PlayFabCombo_Matchmaker", "Provides access to the Matchmaker API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_MatchmakerSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_MatchmakerService"));
    }

    void PlayFabCombo_MatchmakerSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_MatchmakerService"));
    }

    void PlayFabCombo_MatchmakerSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_MatchmakerSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_MatchmakerSysComponent::Init()
    {
    }

    void PlayFabCombo_MatchmakerSysComponent::Activate()
    {
        PlayFabCombo_MatchmakerRequestBus::Handler::BusConnect();
        PlayFabCombo_MatchmakerSimpleRequestBus::Handler::BusConnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    void PlayFabCombo_MatchmakerSysComponent::Deactivate()
    {
        PlayFabCombo_MatchmakerRequestBus::Handler::BusDisconnect();
        PlayFabCombo_MatchmakerSimpleRequestBus::Handler::BusDisconnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    int PlayFabCombo_MatchmakerSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    int PlayFabCombo_MatchmakerSysComponent::AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::AuthUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_MatchmakerSysComponent::AuthUser(MatchmakerModels::AuthUserRequest& request)
    {
        return AuthUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_MatchmakerSysComponent::PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::PlayerJoined(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_MatchmakerSysComponent::PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request)
    {
        return PlayerJoined(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_MatchmakerSysComponent::PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::PlayerLeft(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_MatchmakerSysComponent::PlayerLeft(MatchmakerModels::PlayerLeftRequest& request)
    {
        return PlayerLeft(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_MatchmakerSysComponent::StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::StartGame(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_MatchmakerSysComponent::StartGame(MatchmakerModels::StartGameRequest& request)
    {
        return StartGame(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_MatchmakerSysComponent::UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::UserInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_MatchmakerSysComponent::UserInfo(MatchmakerModels::UserInfoRequest& request)
    {
        return UserInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
}
