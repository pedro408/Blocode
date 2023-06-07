#include <windows.h>

// Função de callback para processar mensagens da janela
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_COMMAND:
            if (LOWORD(wParam) == 1) // Verifica se o ID do controle é 1
            {
                MessageBox(hwnd, "Botão pressionado!", "Exemplo", MB_OK);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Registrar a classe da janela
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MainWindowClass";
    RegisterClass(&wc);

    // Criar a janela
    HWND hwnd = CreateWindowEx(0, "MainWindowClass", "Exemplo de Botão", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 500, 300,
                               NULL, NULL, hInstance, NULL);

    // Criar o botão
    HWND btn = CreateWindow("BUTTON", "Pressione-me", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            10, 10, 120, 40, hwnd, (HMENU)1, hInstance, NULL);

    // Mostrar a janela
    ShowWindow(hwnd, nCmdShow);

    // Loop de mensagens
    MSG msg = {};
	}

