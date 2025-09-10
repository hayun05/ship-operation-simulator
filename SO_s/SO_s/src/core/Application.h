#pragma once

#include <Windows.h>
#include <wrl/client.h>  // ComPtr ���
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

    // Win32 ���� ���
    HINSTANCE m_hInstance;
    HWND      m_hWnd;
    int       m_nCmdShow;
    bool m_running;

    // DirectX ���� ��� (��: ��ġ, ���ؽ�Ʈ ��)
    // ID3D11Device* m_device;
    // ID3D11DeviceContext* m_context;

    Microsoft::WRL::ComPtr<IDXGISwapChain>         m_swapChain;         // ȭ�� ���� ��ȯ ü��
    Microsoft::WRL::ComPtr<ID3D11Device>           m_device;            // GPU ��ġ
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>    m_context;           // ������ ���ؽ�Ʈ
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_renderTargetView;  // �� ���� ���� Ÿ��


    BoatPhysics m_boatPhysics;
    InputManager m_inputManager;
    Renderer m_renderer;
    UIManager m_uiManager;
};
