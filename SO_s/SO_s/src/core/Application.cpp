#include "Application.h"

#include <d3d11.h>
#include <windows.h>

#pragma comment(lib, "d3d11.lib")


// 생성자: 인스턴스와 윈도우 쇼 플래그 저장
Application::Application(HINSTANCE hInstance, int nCmdShow)
    : m_hInstance(hInstance), m_nCmdShow(nCmdShow), m_hWnd(nullptr), m_running(false) {}

// 소멸자
Application::~Application() {
    Shutdown();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

        // 키보드, 마우스 입력 처리 추가 가능

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}


bool Application::Initialize() {
    if (!InitWindow()) return false;
    if (!InitDirectX()) return false;
    m_running = true;
    return true;
}

void Application::Run() {
    MSG msg = { 0 };
    while (m_running) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                m_running = false;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            Update();  // 게임 로직 & 시뮬레이션 업데이트
            Render();  // 화면 그리기
        }
    }
}

void Application::Shutdown() {
    // DirectX 및 윈도우 자원 해제
    m_running = false;

    m_renderTargetView.Reset();
    m_context.Reset();
    m_device.Reset();
    m_swapChain.Reset();


    if (m_hWnd) {
        DestroyWindow(m_hWnd);
        m_hWnd = nullptr;
    }

    UnregisterClass(L"MyAppWindowClass", m_hInstance);
 
}

bool Application::InitWindow() {
    WNDCLASSEX wc = { sizeof(WNDCLASSEX) };
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = m_hInstance;
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"MyAppWindowClass";
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(nullptr, L"윈도우 클래스 등록 실패", L"오류", MB_OK);
        return false;
    }

    RECT wr = { 0, 0, 1280, 720 };
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

    m_hWnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        L"3D 선박 시뮬레이터",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        wr.right - wr.left,
        wr.bottom - wr.top,
        nullptr,
        nullptr,
        m_hInstance,
        nullptr);

    if (!m_hWnd) {
        MessageBox(nullptr, L"윈도우 생성 실패", L"오류", MB_OK);
        return false;
    }

    ShowWindow(m_hWnd, m_nCmdShow);
    UpdateWindow(m_hWnd);

    return true;
}

bool Application::InitDirectX() {
    DXGI_SWAP_CHAIN_DESC scd = {};
    scd.BufferCount = 1;
    scd.BufferDesc.Width = 1280;
    scd.BufferDesc.Height = 720;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.RefreshRate.Numerator = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = m_hWnd;
    scd.SampleDesc.Count = 1;
    scd.SampleDesc.Quality = 0;
    scd.Windowed = TRUE;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &scd,
        m_swapChain.GetAddressOf(),
        m_device.GetAddressOf(),
        nullptr,
        m_context.GetAddressOf());

    if (FAILED(hr)) {
        MessageBox(nullptr, L"DirectX 초기화 실패", L"오류", MB_OK);
        return false;
    }

    // 렌더 타겟 뷰 생성 등 후처리 필요 (생략)

    // 백 버퍼로부터 렌더 타겟 뷰 생성
    Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer;
    hr = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(backBuffer.GetAddressOf()));
    if (FAILED(hr)) {
        MessageBox(nullptr, L"백버퍼 가져오기 실패", L"오류", MB_OK);
        return false;
    }

    hr = m_device->CreateRenderTargetView(backBuffer.Get(), nullptr, m_renderTargetView.GetAddressOf());
    if (FAILED(hr)) {
        MessageBox(nullptr, L"렌더 타겟 뷰 생성 실패", L"오류", MB_OK);
        return false;
    }

    // 렌더 타겟 바인딩
    m_context->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), nullptr);

    IDXGIFactory* dxgiFactory = nullptr;
    m_swapChain->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&dxgiFactory));
    dxgiFactory->MakeWindowAssociation(m_hWnd, DXGI_MWA_NO_ALT_ENTER);
    dxgiFactory->Release();

    // 뷰포트 설정
    D3D11_VIEWPORT viewport = {};
    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;
    viewport.Width = static_cast<float>(1280);
    viewport.Height = static_cast<float>(720);
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;

    m_context->RSSetViewports(1, &viewport);

    return true;
}

void Application::Update() {
    // 예: 물리 시뮬레이션 업데이트 (선박 위치/속도 계산)
    m_boatPhysics.UpdatePhysics();

    // 입력에 따라 카메라 이동 등 처리
    m_inputManager.Update();

    // UI 상태 업데이트 등 추가 가능
}

void Application::Render() {
    // 렌더 타겟 초기화 (초기화 색으로 클리어)
    float clearColor[4] = { 0.2f, 0.4f, 0.6f, 1.0f };
    m_context->ClearRenderTargetView(m_renderTargetView.Get(), clearColor);

    // 3D 선박 모델 렌더링 호출
    m_renderer.RenderScene();

    // UI 렌더링
    m_uiManager.Render();

    // 화면에 렌더링 결과 Present
    m_swapChain->Present(1, 0);
}
