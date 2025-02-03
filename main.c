#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100 // Store up to 100 past records

// Structure to hold weather data
typedef struct {
    float temperature;
    float humidity;
    float windSpeed;
    float pressure;
    char prediction[256];
} WeatherData;

// Global variables
HWND hTemp, hHumidity, hWind, hPressure, hButton, hResult, hRunAgain, hHistory;
WeatherData records[MAX_RECORDS]; // Array to store records
int recordCount = 0; // Track number of records

void RunPrediction() {
    char command[256], output[256];
    WeatherData currentData; // Struct to store current input
    char tempStr[10], humidStr[10], windStr[10], pressStr[10];

    // Get text from input fields
    GetWindowText(hTemp, tempStr, 10);
    GetWindowText(hHumidity, humidStr, 10);
    GetWindowText(hWind, windStr, 10);
    GetWindowText(hPressure, pressStr, 10);

    // Convert to float and store in struct
    currentData.temperature = atof(tempStr);
    currentData.humidity = atof(humidStr);
    currentData.windSpeed = atof(windStr);
    currentData.pressure = atof(pressStr);

    // Prepare command
    sprintf(command, "python predict.py %.2f %.2f %.2f %.2f",
            currentData.temperature, currentData.humidity,
            currentData.windSpeed, currentData.pressure);

    // Open the Python script using popen
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        MessageBox(NULL, "Failed to run Python script", "Error", MB_OK | MB_ICONERROR);
        return;
    }

    // Read the output
    if (fgets(output, sizeof(output), fp) != NULL) {
        output[strcspn(output, "\n")] = 0; // Remove newline
        strcpy(currentData.prediction, output); // Store prediction in struct
        SetWindowText(hResult, output); // Display result
    }

    pclose(fp);

    // Store the record in the array if space is available
    if (recordCount < MAX_RECORDS) {
        records[recordCount++] = currentData;
    }
}

void ShowHistory() {
    char historyText[5000] = "History:\n";
    char entry[256];
    for (int i = 0; i < recordCount; i++) {
        sprintf(entry, "Temp: %.2f, Hum: %.2f, Wind: %.2f, Pres: %.2f -> %s\n",
                records[i].temperature, records[i].humidity,
                records[i].windSpeed, records[i].pressure,
                records[i].prediction);
        strcat(historyText, entry);
    }
    MessageBox(NULL, historyText, "Prediction History", MB_OK);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            if ((HWND)lp == hButton) {
                RunPrediction();
            } else if ((HWND)lp == hRunAgain) {
                // Clear the text boxes when "Run Again" button is clicked
                SetWindowText(hTemp, "");
                SetWindowText(hHumidity, "");
                SetWindowText(hWind, "");
                SetWindowText(hPressure, "");
            } else if ((HWND)lp == hHistory) {
                ShowHistory();
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.hInstance = hInstance;
    wc.lpszClassName = "WeatherPredictor";
    wc.lpfnWndProc = WindowProcedure;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wc);

    HWND hWnd = CreateWindow("WeatherPredictor", "Weather Predictor", WS_OVERLAPPEDWINDOW, 100, 100, 400, 350, NULL, NULL, hInstance, NULL);

    CreateWindow("STATIC", "Temperature:", WS_VISIBLE | WS_CHILD, 20, 20, 100, 20, hWnd, NULL, NULL, NULL);
    hTemp = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 130, 20, 100, 20, hWnd, NULL, NULL, NULL);

    CreateWindow("STATIC", "Humidity:", WS_VISIBLE | WS_CHILD, 20, 50, 100, 20, hWnd, NULL, NULL, NULL);
    hHumidity = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 130, 50, 100, 20, hWnd, NULL, NULL, NULL);

    CreateWindow("STATIC", "Wind Speed:", WS_VISIBLE | WS_CHILD, 20, 80, 100, 20, hWnd, NULL, NULL, NULL);
    hWind = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 130, 80, 100, 20, hWnd, NULL, NULL, NULL);

    CreateWindow("STATIC", "Pressure:", WS_VISIBLE | WS_CHILD, 20, 110, 100, 20, hWnd, NULL, NULL, NULL);
    hPressure = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 130, 110, 100, 20, hWnd, NULL, NULL, NULL);

    hButton = CreateWindow("BUTTON", "Predict", WS_VISIBLE | WS_CHILD, 130, 140, 100, 30, hWnd, NULL, NULL, NULL);
    hRunAgain = CreateWindow("BUTTON", "Run Again", WS_VISIBLE | WS_CHILD, 130, 180, 100, 30, hWnd, NULL, NULL, NULL);
    hHistory = CreateWindow("BUTTON", "History", WS_VISIBLE | WS_CHILD, 130, 220, 100, 30, hWnd, NULL, NULL, NULL);
    hResult = CreateWindow("STATIC", "Prediction: ", WS_VISIBLE | WS_CHILD, 20, 260, 300, 20, hWnd, NULL, NULL, NULL);

    ShowWindow(hWnd, nCmdShow);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
