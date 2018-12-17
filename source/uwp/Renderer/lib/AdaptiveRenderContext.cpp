#include "pch.h"

#include "AdaptiveRenderContext.h"
#include "AdaptiveError.h"
#include "AdaptiveWarning.h"
#include "InputValue.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveNamespace;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;

namespace AdaptiveNamespace
{
    HRESULT AdaptiveRenderContext::RuntimeClassInitialize() noexcept { return S_OK; }

    HRESULT AdaptiveRenderContext::RuntimeClassInitialize(IAdaptiveHostConfig* hostConfig,
                                                          IAdaptiveElementRendererRegistration* elementRendererRegistration,
                                                          IAdaptiveCardResourceResolvers* resourceResolvers,
                                                          IResourceDictionary* overrideDictionary,
                                                          IResourceDictionary* defaultActionSentimentStyles,
                                                          RenderedAdaptiveCard* renderResult) noexcept try
    {
        m_hostConfig = hostConfig;
        m_elementRendererRegistration = elementRendererRegistration;
        m_resourceResolvers = resourceResolvers;
        m_overrideDictionary = overrideDictionary;
        m_actionSentimentDefaultDictionary = defaultActionSentimentStyles;

        ComPtr<IRenderedAdaptiveCard> strongRenderResult = renderResult;
        RETURN_IF_FAILED(strongRenderResult.AsWeak(&m_weakRenderResult));

        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveActionInvoker>(&m_actionInvoker, renderResult));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveMediaEventInvoker>(&m_mediaEventInvoker, renderResult));

        return S_OK;
    }
    CATCH_RETURN;

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::get_HostConfig(IAdaptiveHostConfig** value)
    {
        return m_hostConfig.CopyTo(value);
    }

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::get_ElementRenderers(IAdaptiveElementRendererRegistration** value)
    {
        return m_elementRendererRegistration.CopyTo(value);
    }

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::get_ActionInvoker(IAdaptiveActionInvoker** value)
    {
        return m_actionInvoker.CopyTo(value);
    }

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::get_MediaEventInvoker(IAdaptiveMediaEventInvoker** value)
    {
        return m_mediaEventInvoker.CopyTo(value);
    }

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::get_ResourceResolvers(IAdaptiveCardResourceResolvers** value)
    {
        return m_resourceResolvers.CopyTo(value);
    }

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::get_OverrideStyles(_COM_Outptr_ IResourceDictionary** overrideDictionary)
    {
        return m_overrideDictionary.CopyTo(overrideDictionary);
    }

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::AddError(ABI::AdaptiveNamespace::ErrorStatusCode statusCode, HSTRING message)
    {
        ComPtr<AdaptiveError> error;
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveError>(&error, statusCode, message));
        ComPtr<IVector<ABI::AdaptiveNamespace::IAdaptiveError*>> errors;
        ComPtr<IRenderedAdaptiveCard> renderResult;
        RETURN_IF_FAILED(GetRenderResult(renderResult.GetAddressOf()));
        RETURN_IF_FAILED(renderResult->get_Errors(&errors));
        return (errors->Append(error.Detach()));
    }

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::AddWarning(ABI::AdaptiveNamespace::WarningStatusCode statusCode, HSTRING message)
    {
        ComPtr<AdaptiveWarning> warning;
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveWarning>(&warning, statusCode, message));
        ComPtr<IVector<ABI::AdaptiveNamespace::IAdaptiveWarning*>> warnings;
        ComPtr<IRenderedAdaptiveCard> renderResult;
        RETURN_IF_FAILED(GetRenderResult(renderResult.GetAddressOf()));
        RETURN_IF_FAILED(renderResult->get_Warnings(&warnings));
        return (warnings->Append(warning.Detach()));
    }

    _Use_decl_annotations_ HRESULT AdaptiveRenderContext::AddInputValue(IAdaptiveInputValue* inputValue)
    {
        ComPtr<IRenderedAdaptiveCard> renderResult;
        RETURN_IF_FAILED(GetRenderResult(renderResult.GetAddressOf()));
        ComPtr<RenderedAdaptiveCard> renderedAdaptiveCard = PeekInnards<RenderedAdaptiveCard>(renderResult);
        RETURN_IF_FAILED(renderedAdaptiveCard == nullptr ? E_NOINTERFACE : S_OK);
        return renderedAdaptiveCard->AddInputValue(inputValue);
    }

    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> AdaptiveRenderContext::GetDefaultActionSentimentDictionary()
    {
        return m_actionSentimentDefaultDictionary;
    }

    HRESULT AdaptiveRenderContext::GetRenderResult(IRenderedAdaptiveCard** renderResult)
    {
        ComPtr<IRenderedAdaptiveCard> strongRenderResult;
        RETURN_IF_FAILED(m_weakRenderResult.As(&strongRenderResult));
        RETURN_IF_FAILED(strongRenderResult == nullptr ? E_FAIL : S_OK);
        return strongRenderResult.CopyTo(renderResult);
    }
}
