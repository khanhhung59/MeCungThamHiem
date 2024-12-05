##include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    
    //freopen("MAZE.INP", "r", stdin);
    //freopen("MAZE.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long M, N, Res = LLONG_MAX;
    cin >> N >> M;
    long long F[N + 1][M + 1];
    queue<pair<long long, long long>> DongNuoc;
    queue<pair<pair<long long, long long>, pair<long long, long long>>> ThamHiem;
    bool CheckDongNuoc[N + 1][M + 1];
    bool CheckThamHiem[N + 1][M + 1];
    for(long long i = 1; i <= N; i++)
    {
        for(long long j = 1; j <= M; j++)
        {
            CheckDongNuoc[i][j] = false;
            CheckThamHiem[i][j] = false;
            char X;
            cin >> X;
            if(X == 'X'){
                F[i][j] = -1;
            }
            else if (X == 'S'){
                F[i][j] = 0;
                DongNuoc.push({i,j});
                CheckDongNuoc[i][j] = true;
            }
            else if(X == 'O'){
                F[i][j] = -2;
            }
            else {
                F[i][j] = -5;
                CheckThamHiem[i][j] = true;
                ThamHiem.push({{i,j},{1,0}});
            }
        }
    }
    
    //Danh Dau Vi Tri Dong Nuoc
    while (!DongNuoc.empty()) {
        pair<long long, long long> Resolve = DongNuoc.front();
        DongNuoc.pop();
        long long Row = Resolve.first;
        long long Col = Resolve.second;
        if(Row - 1 >= 1 && CheckDongNuoc[Row - 1][Col] == false && F[Row - 1][Col] != -1){
            F[Row - 1][Col] = F[Row][Col] + 1;
            CheckDongNuoc[Row - 1][Col] = true;
            DongNuoc.push({Row - 1,Col});
        }
        if(Row + 1 <= N && CheckDongNuoc[Row + 1][Col] == false && F[Row + 1][Col] != -1){
            F[Row + 1][Col] = F[Row][Col] + 1;
            CheckDongNuoc[Row + 1][Col] = true;
            DongNuoc.push({Row + 1,Col});
        }
        if(Col - 1 >= 1 && CheckDongNuoc[Row][Col - 1] == false && F[Row][Col - 1] != -1){
            F[Row][Col - 1] = F[Row][Col] + 1;
            CheckDongNuoc[Row][Col - 1] = true;
            DongNuoc.push({Row,Col - 1});
        }
        if(Col + 1 <= M && CheckDongNuoc[Row][Col + 1] == false && F[Row][Col + 1] != -1){
            F[Row][Col + 1] = F[Row][Col] + 1;
            CheckDongNuoc[Row][Col + 1] = true;
            DongNuoc.push({Row,Col + 1});
        }
    }
    
    //Duong Tham Hiem
    while (!ThamHiem.empty()) {
        pair<pair<long long, long long>, pair<long long, long long>> Resolve = ThamHiem.front();
        ThamHiem.pop();
        long long Row = Resolve.first.first;
        long long Col = Resolve.first.second;
        long long second = Resolve.second.second;
        long long Dodai = Resolve.second.first;
        
        //Kiem Tra Da Toi Bien Chua
        if(Row == 1 || Col == 1){
            Res = min(Res,Dodai);
        }
        else if(Row == N || Col == M){
            Res = min(Res,Dodai);
        }
        
        if(Row - 1 >= 1 && CheckThamHiem[Row - 1][Col] == false && F[Row - 1][Col] != -1 && F[Row - 1][Col] > second + 1){
            CheckThamHiem[Row - 1][Col] = true;
            ThamHiem.push({{Row - 1,Col},{Dodai + 1,second + 1}});
        }
        if(Row + 1 <= N && CheckThamHiem[Row + 1][Col] == false && F[Row + 1][Col] != -1 && F[Row + 1][Col] > second + 1){
            CheckThamHiem[Row + 1][Col] = true;
            ThamHiem.push({{Row + 1,Col},{Dodai + 1,second + 1}});
        }
        if(Col - 1 >= 1 && CheckThamHiem[Row][Col - 1] == false && F[Row][Col - 1] != -1 && F[Row][Col - 1] > second + 1){
            CheckThamHiem[Row][Col - 1] = true;
            ThamHiem.push({{Row,Col - 1},{Dodai + 1,second + 1}});
        }
        if(Col + 1 <= M && CheckThamHiem[Row][Col + 1] == false && F[Row][Col + 1] != -1 && F[Row][Col + 1] > second + 1){
            CheckThamHiem[Row][Col + 1] = true;
            ThamHiem.push({{Row,Col + 1},{Dodai + 1,second + 1}});
        }
    }
    if(Res != LLONG_MAX){
        cout << Res;
    }
    else{
        cout <<"-1";
    }
    return 0;
}
    

