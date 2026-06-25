#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
// triangle은 2차원 정수 배열 벡터,피라미드형 삼각형을 왼쪽 정렬로 바꿈
    int n = triangle.size();
// 피라미드의 층 수

    for (int i = n - 2; i >= 0; --i) {
/* 
왜 n-2 인가? 일단 피라미드의 인덱스는 0부터 시작,일단 먼저 1을 빼야함 
또 맨 아래에서부터 훑고 올라가므로 맨 아래행 아래로 더 내려갈수 없음
*/ 
        for (int j = 0; j <= i; ++j) {

            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
/* 
질문. for문 바깥은 n-2였다가 또 안에서는 왜 더하는가?
답. 맨 아래에서부터 연산을 시작하는것이 아니라 구조 자체가 
한칸 아래 숫자들을 탐색하고 더하고 더 높은 숫자를 고르는것이기 떄문
*/ 

    return triangle[0][0];
// 맨위 값을 반환
}
/*
왜 i++을 쓰던 ++i를 쓰던 동작 결과는 완전히 동일하지만 ++i가 i++보다 약간 더 빠르다고 하는가?
답. 복잡해질수록 증가시키지 전의 원래 값을 복사해서 저장하는 과정이 추가 되므로 더 가볍다
실제로 성능 차이가 나는 경우가 드물지만 안정빵이라고 한다
*/