#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;

int main() {
	/*
	빙고게임 AI vs Player
	1~25까지의 숫자가 있고 이 숫자를 골고루 섞어서 5X5로 출력한다
	플레이어는 1~25의 숫자를 입력하여야한다.
	0을 입력 받으면 종료한다

	숫자를 입력 받았으면 숫자 목록중 입력 받은 숫자를 찾아서 *로 만들어준다
	숫자를 *로 만든 후에 빙고 줄수를 체크한다. 5X5이기 때문에 가로5줄 세로5줄
	대각선 2줄이 나올 수 있다 빙고줄이 몇줄인지 체크해서 화면에 보여준다.
	5줄 이상일 경우 게임을 종료한다
	*/

	//필요조건 : 25칸의 랜덤한 숫자가 저장 된 배열ok, 줄이 완성된 걸 체크하는 변수 Line ok, 입력받은 숫자를 *로 변환
	//예외조건 : 1~25사이의 숫자만 입력ok, 0을 입력하면 종료ok

	int Bingo[25], AIBingo[25];
	int  AI_Input_Bingo[25] = { 0 };
	int Temp, Index1, Index2;
	int Line = 0, AILine = 0;
	int Input;

	srand((unsigned int)time(0));

	//배열 Bingo에 1~25의 숫자를 저장
	for (int i = 0; i < 25; i++) {
		Bingo[i] = i + 1; // 플레이어의 빙고판
		AIBingo[i] = i + 1;
	}

	//숫자를 랜덤하게 100번 섞음
	for (int i = 0; i < 100; i++) {
		//플레이어의 빙고판
		Index1 = rand() % 25;
		Index2 = rand() % 25;

		Temp = Bingo[Index1];
		Bingo[Index1] = Bingo[Index2];
		Bingo[Index2] = Temp;

		//AI의 빙고판
		Index1 = rand() % 25;
		Index2 = rand() % 25;

		Temp = AIBingo[Index1];
		AIBingo[Index1] = AIBingo[Index2];
		AIBingo[Index2] = Temp;
	}

	//계속해서 돌아갈 게임
	while (1) {
		system("cls");

		cout << "============AI 빙고판============" << endl;
		//저장된 유저의 숫자를 출력(단 0으로 모두 저장해두고 0이면 *을 출력, 숫자가 저장되면 숫자 출력)
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (AI_Input_Bingo[i * 5 + j] == 0) {
					cout << "*"<< "\t";
				}
				else
					cout << AI_Input_Bingo[i * 5 + j] << "\t";
			}
			cout << "" << endl;
		}
		cout << "" << endl;

		//맞춘 빙고수를 출력
		cout << endl << "맞춘 빙고 수 : " << AILine << " (5줄 맞출시 승리)" << endl;

		cout <<endl<< "=========플레이어 빙고판=========" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (Bingo[i * 5 + j] == 0) {
					cout << "*" << "\t";
				}
				else 
					cout << Bingo[i * 5 + j] << "\t";
			}
			cout << "" << endl;
		}
		cout << "" << endl;

		//빙고가 5개가 넘어가면 게임을 종료
		if (Line >= 5) {
			cout << "축하합니다! 5줄의 빙고를 완성하여 AI에게 승리하였습니다!" << endl;
			break;
		}
		else if (AILine >= 5) {
			cout << "안타깝게도 AI가 먼저 빙고를 완성하여 AI에게 패배하였습니다" << endl;
			break;
		}

		//맞춘 빙고수를 출력
		cout << endl << "맞춘 빙고 수 : " << Line << " (5줄 맞출시 승리)" << endl;

		//한 루프에서만 Line을 체크해줌
		Line = 0;
		AILine = 0;

		//숫자를 입력 받음(1~25의 숫자만)
		cout << "1~25의 숫자를 입력해주세요(0을 입력하면 게임 종료) : ";
		cin >> Input;

		//예외조건
		//잘못된 범위
		if (0 > Input || Input > 25) {
			cout << "잘못된 범위입니다. 다시 입력해주세요" << endl;
			continue;
		}
		//0을 입력
		else if (Input == 0) {
			cout << "게임을 종료하셨습니다" << endl;
			break;
		}
		bool Check_Overlap = true;
		//중복된 숫자 입력
		for (int i = 0; i < 25; i++) {
			if (Input == Bingo[i]) {
				Check_Overlap = false;
				break;
			}
		}
		if (Check_Overlap) {
			cout << "중복 입력하셨습니다 다시 입력해주세요." << endl;
			continue;
		}

		//플레이어 입력부분
		//입력받은 숫자(Input과 Bingo[25]의 위치를 비교해서 같은 위치에 있는걸 Input_Bingo[i]에 저장)
		for (int i = 0; i < 25; i++) {
			if (Bingo[i] == Input) {
				Bingo[i] = 0;
			}
		}

		//플레이어가 입력한 Input을 AI에도 입력하게 함
		for (int i = 0; i < 25; i++) {
			if (AIBingo[i] == Input) {
				AI_Input_Bingo[i] = Input;
			}
		}

		//AI입력부분

	

		//플레이어의 빙고 체크(내가 짠 코드)
		//가로줄 체크
		for (int i = 0; i < 5; i++) {
			if (Bingo[i * 5] == 0 && Bingo[i * 5 + 1] == 0 && Bingo[i * 5 + 2] == 0 &&
				Bingo[i * 5 + 3] == 0 && Bingo[i * 5 + 4] == 0) {
				Line++;
			}
		}
		//세로줄 체크
		for (int i = 0; i < 5; i++) {
			if (Bingo[i] == 0 && Bingo[5 * 1 + i] == 0 && Bingo[5 * 2 + i] == 0 &&
				Bingo[5 * 3 + i] == 0 && Bingo[5 * 4 + i] == 0) {
				Line++;
			}
		}
		//대각선 체크
		if (Bingo[0] == 0 && Bingo[6] == 0 && Bingo[12] == 0 &&
			Bingo[18] == 0 && Bingo[24] == 0) {
			Line++;
		}
		if (Bingo[4] == 0 && Bingo[8] == 0 && Bingo[12] == 0 &&
			Bingo[16] == 0 && Bingo[20] == 0) {
			Line++;
		}

		//AI의 빙고 체크(강의 코드)
		int check_width = 0, check_height = 0, check_diagonal1 = 0, check_diagonal2 = 0;
		//가로, 세로줄 체크
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (AI_Input_Bingo[i * 5 + j] != 0)//가로줄 체크
					check_width++;//만약 AI_Input_Bingo에 0이 아닌 숫자가 있다면 check_width++을 해줌
				if (AI_Input_Bingo[j * 5 + i] != 0)//세로줄 체크
					check_height++;//만약 AI_Input_Bingo에 0이 아닌 숫자가 있다면 check_height++을 해줌
			}
			if (check_width == 5) {
				AILine++;//한 가로줄에 숫자가 5개 있으면 빙고이므로 빙고에 1을 더해줌 
			}
			if (check_height == 5) {
				AILine++;//한 세로줄에 숫자가 5개 있으면 빙고이므로 빙고에 1을 더해줌 
			}
			check_width = 0;//한 줄의 체크가 끝나면 초기화
			check_height = 0;//한 줄의 체크가 끝나면 초기화
		}
		//하단 대각선 체크
		if (AI_Input_Bingo[0] > 0 && AI_Input_Bingo[6] > 0 && AI_Input_Bingo[12] > 0 &&
			AI_Input_Bingo[18] > 0 && AI_Input_Bingo[24] > 0) {
			AILine++;
		}
		if (AI_Input_Bingo[4] > 0 && AI_Input_Bingo[8] > 0 && AI_Input_Bingo[12] > 0 &&
			AI_Input_Bingo[16] > 0 && AI_Input_Bingo[20] > 0) {
			AILine++;
		}
	}
	while (1);
}
