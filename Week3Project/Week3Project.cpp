
#include <stdio.h>                  // 표준 입출력 함수 관련 헤더, printf 등을 사용할 수 있음.
#include <conio.h>                  // 콘솔 관련 헤더
#include <iostream>                 // C++ 입출력 관련 헤더
#include <chrono>                   // 시간 관리를 위해 사용되는 C++ 표준 라이브러리 헤더, 여기서는 키보드 입력한 순간부터 0.3초(300ms) 동안 입력 쌓는 용도로 사용됨.

#define ESC 27
#define ENTER 13
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

int main() {
	chrono::system_clock::time_point StartTime = chrono::system_clock::now();

	while (1) {

		int x, key = 0;
		printf("command>");
		int cnt = 0, cnt1 = 0, cnt2 = 0;						// 길이
		int EWGF = 0;											// 초풍
		int yaotome = 0;										// 팔치녀
		int DragonInstall = 0;											// 드래곤 인스톨

		while ((x = _getch()) != ESC) {

			/*printf("\EWGF:%d", EWGF);
			printf("\ncnt:%d", cnt);*/
			if (x != 224) {//방향키가 아닐때 
				key = x;
				printf("%c", key);
				if ((EWGF == 1 && key != DOWN) || (EWGF == 2 && key != RIGHT) || (EWGF == 3 && key != 115))													// 초풍 초기화
				{
					cnt = 0;
					EWGF = 0;
				}
				if ((yaotome == 1 && key != RIGHT) || (yaotome == 2 && key != DOWN) || (yaotome == 3 && key != LEFT) || (yaotome == 4 && key != 97))						// 팔치녀 초기화
				{
					cnt1 = 0;
					yaotome = 0;
				}
				if ((DragonInstall == 1 && key != LEFT) || (DragonInstall == 2 && key != DOWN) || (DragonInstall == 3 && key != LEFT) || (DragonInstall == 4 && key != 120))			// 드래곤 인스톨 초기화
				{
					cnt2 = 0;
					DragonInstall = 0;
				}
			}
			else { //방향키일때 
				key = _getch();
				if ((key == LEFT)) {								//왼쪽
					printf("←");
				}
				if ((key == RIGHT)) {								//오른쪽
					printf("→");
				}
				if ((key == UP)) {								//위
					printf("↑");
				}
				if ((key == DOWN)) {								//아래
					printf("↓");
				}

				if ((EWGF == 1 && key != DOWN) || (EWGF == 2 && key != RIGHT) || (EWGF == 3 && key != 115))													// 초풍 초기화
				{
					cnt = 0;
					EWGF = 0;
				}
				if ((yaotome == 1 && key != RIGHT) || (yaotome == 2 && key != DOWN) || (yaotome == 3 && key != LEFT) || (yaotome == 4 && key != 97))						// 팔치녀 초기화
				{
					cnt1 = 0;
					yaotome = 0;
				}
				if ((DragonInstall == 1 && key != LEFT) || (DragonInstall == 2 && key != DOWN) || (DragonInstall == 3 && key != LEFT) || (DragonInstall == 4 && key != 120))			// 드래곤 인스톨 초기화
				{
					cnt2 = 0;
					DragonInstall = 0;
				}


				//초풍 by 미시마 카즈야
				if ((key == RIGHT)) {
					EWGF++;
					cnt++;
					StartTime = chrono::system_clock::now();//시간 시작지점					
				}
				if ((key == DOWN) && (cnt == 1)) {
					EWGF++;
					cnt++;
				}
				if ((key == RIGHT) && (cnt == 2)) {
					EWGF++;
					cnt++;
				}
				// 팔치녀 by 야가미 이오리
				if ((key == DOWN)) {
					yaotome++;
					cnt1++;
					StartTime = chrono::system_clock::now();						//시간 시작지점
				}
				if ((key == RIGHT) && (cnt1 == 1)) {
					yaotome++;
					cnt1++;
				}
				if ((key == DOWN) && (cnt1 == 2)) {
					yaotome++;
					cnt1++;
				}
				if ((key == LEFT) && (cnt1 == 3)) {
					yaotome++;
					cnt1++;
				}
				// 드래곤 인스톨 by 솔 배드가이
				if ((key == DOWN)) {
					DragonInstall++;
					cnt2++;
					StartTime = chrono::system_clock::now();						//시간 시작시점
				}
				if ((key == LEFT) && (cnt2 == 1)) {
					DragonInstall++;
					cnt2++;
				}
				if ((key == DOWN) && (cnt2 == 2)) {
					DragonInstall++;
					cnt2++;
				}
				if ((key == LEFT) && (cnt2 == 3)) {
					DragonInstall++;
					cnt2++;
				}



			}
			if ((key == 115) && (cnt == 3) && (EWGF == 3)) {							// 초풍 버튼 입력
				break;
			}
			if ((key == 97) && (cnt1 == 4) && (yaotome == 4)) {					// 팔치녀 버튼 입력
				break;
			}
			if ((key == 120) && (cnt2 == 4) && (DragonInstall == 4)) {						// 볼카닉 바이퍼 버튼 입력
				break;
			}

			int sum = 0;





		}
		chrono::system_clock::time_point EndTime = chrono::system_clock::now();							//시간 끝나는지점 
		chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(EndTime - StartTime);	//시간 저장
		if ((key == 115) && (cnt == 3) && (EWGF == 3) && (mill.count() <= 300)) {						// 초풍 성립 조건 확인후 출력
			printf("\n또레아~~ \n");
			cnt = 0;																					// 출력후 값 다시 초기화
			EWGF = 0;

		}
		else if ((key == 97) && (cnt1 == 4) && (yaotome == 4) && (mill.count() <= 300)) {				// 팔치녀 성립 조건 확인후 출력
			printf("\n과소비가 원인이다! \n");
			cnt1 = 0;
			yaotome = 0;
		}
		else if ((key == 120) && (cnt2 == 4) && (DragonInstall == 4) && (mill.count() <= 300)) {				// 볼카닉 바이퍼 성립 조건 확인 후 출력
			printf("\n드래곤!!!\n");
			printf("\n인스톨!!!\n");
			cnt2 = 0;
			DragonInstall = 0;
		}
		else {
			cout << "\nYou Failed...\n Tip : 기술을 300ms(0.3초)안에 입력(커맨드를 빠르게 입력해보라는 뜻ㅎ) : " << mill.count() << endl; //콤보 시작후 총 입력시간
		}

		if (x == ESC) break;



	}



	return 0;
}

