#pragma once

#include <Windows.h>
#include <wrl/client.h>  // ComPtr 헤더
#include <d3d11.h>

#include "../physics/BoatPhysics.h"
#include "../input/InputManager.h"
#include "../graphics/Renderer.h"
#include "../ui/UIManager.h"

class Application {
public:
    Application(HINSTANCE hInstance, int nCmdShow);
    ~Application();

    bool Initialize();
    void Run();
    void Shutdown();

private:
    bool InitWindow();
    bool InitDirectX();
    void Update();
    void Render();

    // Win32 관련 멤버
    HINSTANCE m_hInstance;
    HWND      m_hWnd;
    int       m_nCmdShow;
    bool m_running;

    // DirectX 관련 멤버 (예: 장치, 컨텍스트 등)
    // ID3D11Device* m_device;
    // ID3D11DeviceContext* m_context;

    Microsoft::WRL::ComPtr<IDXGISwapChain>         m_swapChain;         // 화면 버퍼 교환 체인
    Microsoft::WRL::ComPtr<ID3D11Device>           m_device;            // GPU 장치
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>    m_context;           // 렌더링 컨텍스트
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_renderTargetView;  // 백 버퍼 렌더 타겟


    BoatPhysics m_boatPhysics;
    InputManager m_inputManager;
    Renderer m_renderer;
    UIManager m_uiManager;
};
