#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;

int main() {
	/*
	������� AI vs Player
	1~25������ ���ڰ� �ְ� �� ���ڸ� ���� ��� 5X5�� ����Ѵ�
	�÷��̾�� 1~25�� ���ڸ� �Է��Ͽ����Ѵ�.
	0�� �Է� ������ �����Ѵ�

	���ڸ� �Է� �޾����� ���� ����� �Է� ���� ���ڸ� ã�Ƽ� *�� ������ش�
	���ڸ� *�� ���� �Ŀ� ���� �ټ��� üũ�Ѵ�. 5X5�̱� ������ ����5�� ����5��
	�밢�� 2���� ���� �� �ִ� �������� �������� üũ�ؼ� ȭ�鿡 �����ش�.
	5�� �̻��� ��� ������ �����Ѵ�
	*/

	//�ʿ����� : 25ĭ�� ������ ���ڰ� ���� �� �迭ok, ���� �ϼ��� �� üũ�ϴ� ���� Line ok, �Է¹��� ���ڸ� *�� ��ȯ
	//�������� : 1~25������ ���ڸ� �Է�ok, 0�� �Է��ϸ� ����ok

	int Bingo[25], AIBingo[25];
	int  AI_Input_Bingo[25] = { 0 };
	int Temp, Index1, Index2;
	int Line = 0, AILine = 0;
	int Input;

	srand((unsigned int)time(0));

	//�迭 Bingo�� 1~25�� ���ڸ� ����
	for (int i = 0; i < 25; i++) {
		Bingo[i] = i + 1; // �÷��̾��� ������
		AIBingo[i] = i + 1;
	}

	//���ڸ� �����ϰ� 100�� ����
	for (int i = 0; i < 100; i++) {
		//�÷��̾��� ������
		Index1 = rand() % 25;
		Index2 = rand() % 25;

		Temp = Bingo[Index1];
		Bingo[Index1] = Bingo[Index2];
		Bingo[Index2] = Temp;

		//AI�� ������
		Index1 = rand() % 25;
		Index2 = rand() % 25;

		Temp = AIBingo[Index1];
		AIBingo[Index1] = AIBingo[Index2];
		AIBingo[Index2] = Temp;
	}

	//����ؼ� ���ư� ����
	while (1) {
		system("cls");

		cout << "============AI ������============" << endl;
		//����� ������ ���ڸ� ���(�� 0���� ��� �����صΰ� 0�̸� *�� ���, ���ڰ� ����Ǹ� ���� ���)
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

		//���� ������� ���
		cout << endl << "���� ���� �� : " << AILine << " (5�� ����� �¸�)" << endl;

		cout <<endl<< "=========�÷��̾� ������=========" << endl;
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

		//���� 5���� �Ѿ�� ������ ����
		if (Line >= 5) {
			cout << "�����մϴ�! 5���� ���� �ϼ��Ͽ� AI���� �¸��Ͽ����ϴ�!" << endl;
			break;
		}
		else if (AILine >= 5) {
			cout << "��Ÿ���Ե� AI�� ���� ���� �ϼ��Ͽ� AI���� �й��Ͽ����ϴ�" << endl;
			break;
		}

		//���� ������� ���
		cout << endl << "���� ���� �� : " << Line << " (5�� ����� �¸�)" << endl;

		//�� ���������� Line�� üũ����
		Line = 0;
		AILine = 0;

		//���ڸ� �Է� ����(1~25�� ���ڸ�)
		cout << "1~25�� ���ڸ� �Է����ּ���(0�� �Է��ϸ� ���� ����) : ";
		cin >> Input;

		//��������
		//�߸��� ����
		if (0 > Input || Input > 25) {
			cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���" << endl;
			continue;
		}
		//0�� �Է�
		else if (Input == 0) {
			cout << "������ �����ϼ̽��ϴ�" << endl;
			break;
		}
		bool Check_Overlap = true;
		//�ߺ��� ���� �Է�
		for (int i = 0; i < 25; i++) {
			if (Input == Bingo[i]) {
				Check_Overlap = false;
				break;
			}
		}
		if (Check_Overlap) {
			cout << "�ߺ� �Է��ϼ̽��ϴ� �ٽ� �Է����ּ���." << endl;
			continue;
		}

		//�÷��̾� �Էºκ�
		//�Է¹��� ����(Input�� Bingo[25]�� ��ġ�� ���ؼ� ���� ��ġ�� �ִ°� Input_Bingo[i]�� ����)
		for (int i = 0; i < 25; i++) {
			if (Bingo[i] == Input) {
				Bingo[i] = 0;
			}
		}

		//�÷��̾ �Է��� Input�� AI���� �Է��ϰ� ��
		for (int i = 0; i < 25; i++) {
			if (AIBingo[i] == Input) {
				AI_Input_Bingo[i] = Input;
			}
		}

		//AI�Էºκ�

	

		//�÷��̾��� ���� üũ(���� § �ڵ�)
		//������ üũ
		for (int i = 0; i < 5; i++) {
			if (Bingo[i * 5] == 0 && Bingo[i * 5 + 1] == 0 && Bingo[i * 5 + 2] == 0 &&
				Bingo[i * 5 + 3] == 0 && Bingo[i * 5 + 4] == 0) {
				Line++;
			}
		}
		//������ üũ
		for (int i = 0; i < 5; i++) {
			if (Bingo[i] == 0 && Bingo[5 * 1 + i] == 0 && Bingo[5 * 2 + i] == 0 &&
				Bingo[5 * 3 + i] == 0 && Bingo[5 * 4 + i] == 0) {
				Line++;
			}
		}
		//�밢�� üũ
		if (Bingo[0] == 0 && Bingo[6] == 0 && Bingo[12] == 0 &&
			Bingo[18] == 0 && Bingo[24] == 0) {
			Line++;
		}
		if (Bingo[4] == 0 && Bingo[8] == 0 && Bingo[12] == 0 &&
			Bingo[16] == 0 && Bingo[20] == 0) {
			Line++;
		}

		//AI�� ���� üũ(���� �ڵ�)
		int check_width = 0, check_height = 0, check_diagonal1 = 0, check_diagonal2 = 0;
		//����, ������ üũ
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (AI_Input_Bingo[i * 5 + j] != 0)//������ üũ
					check_width++;//���� AI_Input_Bingo�� 0�� �ƴ� ���ڰ� �ִٸ� check_width++�� ����
				if (AI_Input_Bingo[j * 5 + i] != 0)//������ üũ
					check_height++;//���� AI_Input_Bingo�� 0�� �ƴ� ���ڰ� �ִٸ� check_height++�� ����
			}
			if (check_width == 5) {
				AILine++;//�� �����ٿ� ���ڰ� 5�� ������ �����̹Ƿ� ���� 1�� ������ 
			}
			if (check_height == 5) {
				AILine++;//�� �����ٿ� ���ڰ� 5�� ������ �����̹Ƿ� ���� 1�� ������ 
			}
			check_width = 0;//�� ���� üũ�� ������ �ʱ�ȭ
			check_height = 0;//�� ���� üũ�� ������ �ʱ�ȭ
		}
		//�ϴ� �밢�� üũ
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
