#include <windows.h>
#include <CommCtrl.h>
#include "patient.h"
#define PATIENTS_SIZE 5

const char g_szClassName[] = "myWindowClass";

enum
{
    STATIC_ID = 1,
    BUTTON_ID,
    BTN_DEL_ID,
    EDIT_ID,
    LIST_ID,
    STATIC_INDEX_S,
    STATIC_NAME_S,
    STATIC_SURNAME_S,
    STATIC_EXP_S,
    STATIC_SALARY_S,
    STATIC_NAME,
    STATIC_SURNAME,
    STATIC_EXP,
    STATIC_SALARY,
    LABLE_ID
};

HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    hInst = hInstance;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
               WS_EX_CLIENTEDGE,
               g_szClassName,
               "The title of my window",
               WS_OVERLAPPEDWINDOW,
               CW_USEDEFAULT, CW_USEDEFAULT, 700, 700,
               NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HWND hButton, hLable, hButtonDel, hList, hStaticIndS, hStaticNameS, hStaticSurnameS, hStaticDaysS, hStaticDiaS, hStaticName, hStaticSurname, hStaticDia, hStaticDays;
    static char buf[100];
    static int index;
    static patient_t * patient[PATIENTS_SIZE];
    switch(msg)
    {
    case WM_CREATE:
        hStaticIndS = CreateWindowEx(0,
                                     WC_STATIC,
                                     "Index:",
                                     WS_CHILD|WS_VISIBLE,
                                     10, 20, 130, 23,
                                     hwnd,
                                     (HMENU)STATIC_INDEX_S,
                                     hInst,
                                     NULL);

        hStaticNameS = CreateWindowEx(0,
                                      WC_STATIC,
                                      "Name:",
                                      WS_CHILD|WS_VISIBLE,
                                      10, 44, 130, 23,
                                      hwnd,
                                      (HMENU)STATIC_NAME_S,
                                      hInst,
                                      NULL);

        hStaticSurnameS = CreateWindowEx(0,
                                         WC_STATIC,
                                         "Surname:",
                                         WS_CHILD|WS_VISIBLE,
                                         10, 68, 130, 23,
                                         hwnd,
                                         (HMENU)STATIC_SURNAME_S,
                                         hInst,
                                         NULL);

        hStaticDaysS = CreateWindowEx(0,
                                      WC_STATIC,
                                      "Days:",
                                      WS_CHILD|WS_VISIBLE,
                                      10, 92, 130, 23,
                                      hwnd,
                                      (HMENU)STATIC_EXP_S,
                                      hInst,
                                      NULL);

        hStaticDiaS = CreateWindowEx(0,
                                     WC_STATIC,
                                     "Diagnosis:",
                                     WS_CHILD|WS_VISIBLE,
                                     10, 116, 130, 23,
                                     hwnd,
                                     (HMENU)STATIC_SALARY_S,
                                     hInst,
                                     NULL);

        hList = CreateWindowEx(0,
        WC_LISTBOX,
        "Listbox",
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        10, 140+10, 270, 160,
        hwnd, (HMENU)LIST_ID, hInst, NULL);

        patient[0] = patient_new(1, "Valeriy", "Babenko", "ORZ", 5);
        patient[1] = patient_new(2, "Misha", "Ivanov", "obesity", 7);
        patient[2] = patient_new(3, "Kolya", "Sherstiuk", "anorexia", 6);
        patient[3] = patient_new(4, "Daniel", "Jakobs", "cold", 5);
        patient[4] = patient_new(5, "Britney", "Behvandi", "addiction", 8);

        strcpy(buf, "Babenko");
        SendMessageA(hList, LB_ADDSTRING, 0, (LPARAM)buf);
        strcpy(buf, "Ivanov");
        SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)buf);
        strcpy(buf, "Sherstiuk");
        SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)buf);
        strcpy(buf, "Jakobs");
        SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)buf);
        strcpy(buf, "Behvandi");
        SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)buf);

        index=0;

        hLable = CreateWindowEx(0,
                                "STATIC",
                                itoa(patient_getIndex(patient[index]), buf, 10),
                                WS_CHILD|WS_VISIBLE,
                                150, 20, 130, 23,
                                hwnd,
                                (HMENU)LABLE_ID,
                                hInst,
                                NULL);

        hStaticName = CreateWindowEx(0,
                                     WC_STATIC,
                                     patient_getName(patient[index]),
                                     WS_CHILD|WS_VISIBLE,
                                     150, 44, 130, 23,
                                     hwnd,
                                     (HMENU)STATIC_NAME,
                                     hInst,
                                     NULL);

        hStaticSurname = CreateWindowEx(0,
                                        WC_STATIC,
                                        patient_getSurname(patient[index]),
                                        WS_CHILD|WS_VISIBLE,
                                        150, 68, 130, 23,
                                        hwnd,
                                        (HMENU)STATIC_SURNAME,
                                        hInst,
                                        NULL);
        hStaticDia = CreateWindowEx(0,
                                    WC_STATIC,
                                    patient_getDiagnosis(patient[index]),
                                    WS_CHILD|WS_VISIBLE,
                                    150, 116, 130, 23,
                                    hwnd,
                                    (HMENU)STATIC_SURNAME,
                                    hInst,
                                    NULL);

        hStaticDays = CreateWindowEx(0,
                                     WC_STATIC,
                                     itoa(patient_getDays(patient[index]), buf, 10),
                                     WS_CHILD|WS_VISIBLE,
                                     150, 92, 130, 23,
                                     hwnd,
                                     (HMENU)STATIC_EXP,
                                     hInst,
                                     NULL);

        break;
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case LIST_ID:
        {
             LRESULT res = SendMessage(hList, LB_GETCURSEL, 0, 0);
            SendMessageA(hList, LB_DELETESTRING, 0, res);
            SetWindowText(hStaticName, "Iana");
            SetWindowText(hStaticDays, "6");
            SetWindowText(hStaticSurname, "Petrovna");
            SetWindowText(hStaticDia, "addiction");
            SetWindowText(hLable, "1");
            break;
        }
        }
        break;
    }

    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
