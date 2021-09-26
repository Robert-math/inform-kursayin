#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void createArray(int N, int M, int (*A)[100]) {
    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j <= M - 1; j++) {
            *(*(A+i)+j) = rand() % 100;
        }
    }

    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j <= M - 1; j++) {
            cout << *(*(A + i) + j) << ' ' << ' ' << ' ' << ' ';
        }
        cout << endl;
        cout << endl;
    }
    Sleep(2000);
}
int maxNumbString(int N, int M, int(*A)[100]) {
    int max = *(*(A));
    int stringNumber = 0;
    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j <= M - 1; j++) {
            if (*(*(A + i) + j) >= max) {
                max = *(*(A + i) + j);
                stringNumber = i;
            }
        }
    }
    return (stringNumber);
}
void highlightMaxNumber(int N, int M, int maxNumStr,  int(*A)[100]) {
    int max = *(*(A));
    int maxi, maxj;
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j <= M - 1; j++) {
            if (*(*(A + i) + j) >= max) {
                max = *(*(A + i) + j);
                maxi = i;
                maxj = j;
            }
        }
    }
    system("cls");
    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j <= M - 1; j++) {
            Sleep(50);
            if (*(*(A + i) + j) == max && i == maxNumStr) {
                SetConsoleTextAttribute(hconsole, 14);
                cout << *(*(A + i) + j) << ' ' << ' ' << ' ' << ' ';
                SetConsoleTextAttribute(hconsole, 7);
            }
            else {
                cout << *(*(A + i) + j) << ' ' << ' ' << ' ' << ' ';
            }
        }
        cout << endl;
        cout << endl;
    }
    Sleep(1000);
}
void moveArrayStrings(int N, int M, int fromStr, int(*A)[100]) {
    if (fromStr != N - 1) {
        for (int i = N; i >= fromStr + 2; i--) {
            for (int j = 0; j <= M - 1; j++) {
                *(*(A + i) + j) = *(*(A + i - 1) + j);
            }
        }
    }
}
void renderArray(int N, int M, int emptyStringIndex,int highlightString, int(*A)[100]) {
    system("cls");
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i <= N-1; i++) {
        
        if(i == highlightString){ SetConsoleTextAttribute(hconsole, 14); }
        for (int j = 0; j <= M - 1; j++) {
            
            if (i != emptyStringIndex) { cout << *(*(A + i) + j) << ' ' << ' ' << ' ' << ' '; }
        }
        SetConsoleTextAttribute(hconsole, 7);
        cout << endl;
        cout << endl;
    }
    cout << "__________________________________________________________"<<endl;
    Sleep(1000);
}
void addStringAfterMax(int N, int M,int index, int(*A)[100]) {
    for (int j = 0; j <= M - 1; j++) {
        *(*(A + index + 1) + j) = *(*(A + index) + j);
    }
    renderArray(N, M, -1,index+1, A);
    for (int j = 0; j <= M - 2; j++) {
        if (*(*(A + index + 1) + j) > *(*(A + index + 1) + j + 1)) {
            int a = *(*(A + index + 1) + j);
            *(*(A + index + 1) + j) = *(*(A + index + 1) + j + 1);
            *(*(A + index + 1) + j + 1) = a;
            j -= 2;
       }
    }
    renderArray(N, M, -1,index+1, A);
}
void addStringMoved(int N, int M, int index, int(*A)[100]) {
    for (int j = 0; j <= M - 2; j++) {
        *(*(A + index + 1) + j+1) = *(*(A + index) + j);
    }
    *(*(A + index + 1) + 0) = *(*(A + index) + M - 1);
    renderArray(N, M, -1,index+1, A);
}
int main()
{
    srand(time(0));
    int A[100][100];
    int N, M;
    cout << "Insert N and M (N<M)"<<endl;
    cin >> N >> M;
    system("cls");
    createArray(N, M, A);
    int maxNumberString;
    maxNumberString = maxNumbString(N, M, A);
    highlightMaxNumber(N, M, maxNumberString, A);
    bool firststep = false;
    while (N != M) {
        moveArrayStrings(N, M, maxNumberString, A);
        N++;
        renderArray(N, M, maxNumberString+1,-1, A);
        if (!firststep) {
            addStringAfterMax(N, M, maxNumberString, A);
            firststep = true;
            cout << "Amenacmec tarr parunakox toxic heto avelacvec nmanatip tox achman kargov dasavorvac" << endl;
            Sleep(3000);
        }
        else {
            addStringMoved(N, M, maxNumberString, A);
        }
        maxNumberString++;
    }
    cout << "Fsyo";
    return 0;
}

